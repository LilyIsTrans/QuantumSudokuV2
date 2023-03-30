#pragma once
#include <iostream>
#include <filesystem>
#include "solver.h"
#include "board.h"

void test_on_file(std::filesystem::path);

struct solve_result
{
	uint64_t deductions = 0;
	uint64_t total_guesses = 0;
	std::chrono::high_resolution_clock::duration time{};
	board solution{};
};


template<bool Interactive=false>
solve_result solve(const std::string& puzzle)
{
	solve_result results;
	solver test = solver(board(puzzle));

	bool deduce_successful = true;
	const std::chrono::high_resolution_clock::time_point start_t = std::chrono::high_resolution_clock::now();
	while (!test.is_solved())
	{
		if constexpr (Interactive)
		{
			std::cout << test.m_currentBoard << '\n';
		}
		const board temp = test.m_currentBoard;
		test.deduce();
		++results.deductions;
		deduce_successful = temp.data != test.m_currentBoard.data;
		if constexpr (Interactive)
		{
			std::cout << test.m_currentBoard << '\n';
		}
		if (deduce_successful)
		{
			test.find_contradiction();
		}
		else
		{
			test.make_guess();
			++results.total_guesses;
			if constexpr (Interactive)
			{
				std::cout << test.m_currentBoard << '\n';
			}
		}

	}
	const std::chrono::high_resolution_clock::time_point end_t = std::chrono::high_resolution_clock::now();
	results.time = end_t - start_t;
	results.solution = test.m_currentBoard;

	return results;
}


std::string from_solution(const solve_result& solution);