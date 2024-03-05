#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <numeric>
#include <chrono>

std::vector<int> weights;
std::vector<int> values;
std::vector<std::vector<int>> opt;

int knapsack(int n, int curr, int c) {
    // Base case
    if (curr == n - 1) {
        if (weights[curr] <= c) {
            return values[curr];
        } else {
            return 0;
        }
    }

    if (opt[curr][c] != -1) {
        return opt[curr][c];
    }

    int leave = knapsack(n, curr + 1, c);
    int take = -1;

    if (c >= weights[curr]) {
        take = knapsack(n, curr + 1, c - weights[curr]) + values[curr];
    }

    if (leave > take) {
        opt[curr][c] = leave;
    } else {
        opt[curr][c] = take;
    }

    return opt[curr][c];
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

    const int repetitions = 10;

    std::ofstream serial_output("serial_results.txt");

    // Run serial version
    for (const auto& file : input_files) {
        std::vector<double> serial_times;
        // Output serial results
        serial_output << "File: " << file << std::endl;

        for (int i = 0; i < repetitions; ++i) {
            int n, capacity;
            std::vector<int> weights, values;

            // Read input file
            if (!readInputFile(file, n, capacity, weights, values)) {
                continue; // Skip to next input file if reading failed
            }

            // Print read values
            std::cout << "Read values from file: " << file << std::endl;
            std::cout << "n: " << n << ", capacity: " << capacity << std::endl;
            std::cout << "Weights:";
            for (int w : weights) {
                std::cout << " " << w;
            }
            std::cout << std::endl;
            std::cout << "Values:";
            for (int v : values) {
                std::cout << " " << v;
            }
            std::cout << std::endl;

            auto start = std::chrono::high_resolution_clock::now();
            // Initialize opt vector
            opt.resize(n, std::vector<int>(capacity + 1, -1));
            int result = knapsack(n, 0, capacity);
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double, std::milli> duration = end - start;
            double time_ms = duration.count();
            serial_times.push_back(time_ms);
            serial_output << "Value: " << result << "   Time: " << time_ms << std::endl;
        }

        // Calculate average execution time
        double serial_avg_time = average(serial_times);
        serial_output << "Average Execution Time: " << serial_avg_time << " ms" << std::endl << std::endl;
        // Clear vectors for next iteration
        opt.clear();
    }

    // Close serial output file
    serial_output.close();

    return 0;
}
