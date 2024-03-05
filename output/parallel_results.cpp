#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <thread>
#include <mutex>
#include <atomic>
#include <condition_variable>
#include <numeric>


// Implement Barrier Class:
// To Sync the Threads (Barrier Synchronization)
class Barrier {
public:
     // Count: No. of threads that must reach the barrier before continuing
    explicit Barrier(int thread_count) : barrier_threads(thread_count), 
                        pending_threads_(thread_count), barrier_gen_(0) {}

    // Destructor
    ~Barrier() = default;

    // Copy constructor
    Barrier(const Barrier& other) = default;

    // Copy assignment operator
    Barrier& operator=(const Barrier& other) = default;

    // Move constructor
    Barrier(Barrier&& other) noexcept = default;

    // Move assignment operator
    Barrier& operator=(Barrier&& other) noexcept = default;


    // Wait() function:
    // 1. Thread indicates reached the barrier
    // 2. And Block until Barrier in Sync (all threads reached)
    void Wait() 
    {
        std::unique_lock<std::mutex> lock(mutex_);
        int gen = barrier_gen_;
        // If last thread : 
        // Reset the barrier - reset initial count and increment generation
        // And notify!
        if (--pending_threads_ == 0) {
            pending_threads_ = barrier_threads;
            barrier_gen_++;
            cv_.notify_all(); // Notify all waiting threads
        } 
        else 
        {
            // If not the last thread, wait until generation changes
            cv_.wait(lock, [this, gen] { return gen != barrier_gen_; });
        }
    }

private:
    std::mutex mutex_; 
    std::condition_variable cv_; 
    // No of Threads Need to Reach Barrier
    int barrier_threads; 
    // No. of Threads Not Reached Barrier
    int pending_threads_; 
    // Barrier Count
    int barrier_gen_; 
};

// Solves Knapsack in Parallel
int parallel_knapsack(int n, int capacity, const std::vector<int> &weights, 
                        const std::vector<int> &values, int num_threads) 
{
    // DP array for the previous item
    std::vector<int> prev_dp(capacity + 1, 0);
    // DP array for the current item 
    std::vector<int> curr_dp(capacity + 1, 0); 
    // Barrier to synchronize threads
    Barrier barrier(num_threads); 

    for (int i = 1; i <= n; ++i) {
        std::vector<std::thread> threads;

        // Create threads
        for (int t = 0; t < num_threads; ++t) {
            int start_cap = (capacity * t) / num_threads + 1;
            int end_cap = (capacity * (t + 1)) / num_threads;

            // Each thread computes the DP values for a range of capacities
            threads.emplace_back([&](int row, int start_cap, int end_cap) {
                for (int w = start_cap; w <= end_cap; ++w) {
                    // If the current item can be included in the knapsack
                    if (weights[row - 1] <= w) {
                        // Update the DP value considering the current item
                        curr_dp[w] = std::max(prev_dp[w], prev_dp[w - weights[row - 1]] 
                                        + values[row - 1]);
                    } else {
                        // If the current item cannot be included, the DP value is 
                        // the same as without the item
                        curr_dp[w] = prev_dp[w];
                    }
                }
                // Thread Waits until all threads have reached Barrier
                barrier.Wait(); 
            }, i, start_cap, end_cap);
        }

        for (auto &thread : threads) {
            thread.join();
        }
        
        // Swap previous and current DP arrays
        // The current DP array becomes the previous DP array for the next item,
        // and the current DP array is reset to its initial state.
        std::swap(prev_dp, curr_dp);
    }

    // The maximum value that can be included 
    // in the knapsack is the last value in the DP array
    return prev_dp[capacity];
}


// Function to read input file and extract values
bool readInputFile(const std::string& filename, int& n, int& capacity, std::vector<int>& weights, std::vector<int>& values) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Could not open input file: " << filename << std::endl;
        return false;
    }

    // Read n and capacity
    if (!(file >> n >> capacity)) {
        std::cerr << "Error: Failed to read n and capacity from input file: " << filename << std::endl;
        return false;
    }

    // Read weights and values
    weights.resize(n);
    values.resize(n);
    for (int i = 0; i < n; ++i) {
        if (!(file >> weights[i] >> values[i])) {
            std::cerr << "Error: Failed to read weight and value for item " << i+1 << " from input file: " << filename << std::endl;
            return false;
        }
    }

    return true;
}

double average(const std::vector<double>& times) {
    double total = std::accumulate(times.begin(), times.end(), 0.0);
    return total / times.size();
}

int main() {
    std::vector<std::string> input_files = {"inputs/1.txt", "inputs/2.txt", "inputs/3.txt", "inputs/4.txt", "inputs/5.txt"};
    const std::vector<int> thread_counts = {1, 2, 4, 8, 16};
    const int repetitions = 10;

    std::ofstream parallel_output("parallel_results.txt");
    

    // Run parallel version
    for (const auto& file : input_files) {
        for (const auto& threads : thread_counts) {
            std::vector<double> parallel_times;
            parallel_output << "File: " << file << " Threads: " << threads << std::endl;
            for (int i = 0; i < repetitions; ++i) {
                int n, capacity;
                std::vector<int> weights, values;

                // Read input file
                if (!readInputFile(file, n, capacity, weights, values)) {
                    continue; // Skip to next input file if reading failed
                }

                auto start = std::chrono::high_resolution_clock::now();
                int result = parallel_knapsack(n, capacity, weights, values, threads);
                auto end = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double, std::milli> duration = end - start;
                double time_ms = duration.count();
                parallel_times.push_back(time_ms);
                parallel_output << "Value: " << result << "   Time: " << time_ms << std::endl;
            }

            // Calculate average execution time
            double parallel_avg_time = average(parallel_times);

            // Output parallel results
           
            parallel_output << "Average Execution Time: " << parallel_avg_time << " ms" << std::endl <<std::endl;
            
        }
    }

    // Close parallel output file
    parallel_output.close();

    return 0;
}
