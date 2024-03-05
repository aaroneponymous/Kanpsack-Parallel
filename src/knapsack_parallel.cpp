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


int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        std::cerr << "Provide Expected Arguments: " << argv[0] << " <input_file> <num_threads>" << std::endl;
        return 1;
    }

    std::string file = argv[1]; 
    int num_threads = std::stoi(argv[2]); 
    std::ifstream input_file(file);

    if (!input_file.is_open())
    {
        std::cerr << "Error: Could not open file " << file << std::endl;
        return 1;
    }

    int n, c;
    input_file >> n >> c;

    std::vector<int> weights;
    std::vector<int> values;
    std::vector<std::vector<int>> opt(n, std::vector<int>(c + 1, 0));

    std::string line;
    while (getline(input_file, line))
    {
        if (line.empty())
        {
            continue;
        }

        std::stringstream line_stream(line);
        int weight, value;
        line_stream >> weight >> value;
        weights.push_back(weight);
        values.push_back(value);
    }

    using std::chrono::high_resolution_clock;
    using std::chrono::duration;
    auto start = high_resolution_clock::now();

    int highest = parallel_knapsack(n, c, weights, values, num_threads);

    auto end = high_resolution_clock::now();
    duration<double, std::milli> time = end - start;

    std::cout << "The maximum value is " << highest << "." << std::endl;
    std::cout << "Duration: " << time.count() << " miliseconds." << std::endl;

    return 0;
}
