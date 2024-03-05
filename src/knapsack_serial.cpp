#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <vector>
#include <sstream>
#include <fstream>


std::vector<int> weights;
std::vector<int> values;
std::vector<std::vector<int>> opt;

int knapsack(int n, int curr, int c)
{
    // Base case
    if (curr == n - 1)
    {
        if (weights[curr] <= c)
        {
        
            return values[curr];
        }
        else
        {
           
            return 0;
        }
    }

    if (opt[curr][c] != -1)
    {
        return opt[curr][c];
    }

    int leave = knapsack(n, curr + 1, c);
    int take = -1;

    if (c >= weights[curr])
    {
        take = knapsack(n, curr + 1, c - weights[curr]) + values[curr];
    }

    if (leave > take)
    {
        opt[curr][c] = leave;
    }
    else
    {
        opt[curr][c] = take;
    }

    return opt[curr][c];
}


int main(int argc, char* argv[])
{

	if (argc != 2)
	{
		std::cerr << "Provide Expected Arguments: " << argv[0] << " " 
				  << "<input_file" << std::endl;
		return 1;

	}

	std::string file = argv[1];
	std::ifstream input_file(file);

	if (!input_file.is_open())
	{
		std::cerr << "Error: Could not open file " << file << std::endl;
		return 1;
	}

	int n; // number of items in the knapsack
	int c; // capacity of the sack
	input_file >> n >> c;
    opt.resize(n, std::vector<int>(c + 1, -1));

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

	int highest = knapsack(n, 0, c);
	
	auto end = high_resolution_clock::now();
	duration<double, std::milli> time = end - start;
	
	std::cout << "The maximum value is " << highest << "." << std::endl;
	std::cout<<"Duration: "<<time.count() <<" miliseconds."<< std::endl;
}