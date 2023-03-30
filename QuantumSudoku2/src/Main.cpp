#include <iostream>
#include "board.h"
#include "solver.h"
#include "filetest.h"
#include <filesystem>

void display_mode()
{
	solver test(board("3..8.9..1"
								"4.......7"
								".69...45."
								"..6.5.8.."
								"...1.3..."
								"..8.7.2.."
								".14...37."
								"6.......2"
								"5..3.7..4"));

	system("pause");
	bool deduce_successful = true;
	std::cout << test.m_currentBoard << '\n';
	while (!test.is_solved())
	{
		const board temp = test.m_currentBoard;
		test.deduce();
		deduce_successful = temp.data != test.m_currentBoard.data;
		std::cout << test.m_currentBoard << '\n';
		if (deduce_successful)
		{
			test.find_contradiction();
		}
		else
		{
			test.make_guess();
		}
		
	}
	std::cout << test.m_currentBoard << '\n';
	system("pause");
}

int main()
{
	auto result = solve<true>(""
		".12.3.45."
		"56......."
		"3.......2"
		".7..15..."
		"...6.9..."
		"...42..8."
		"1.......3"
		".......24"
		".83.4.57."
	);

	std::cout << from_solution(result);

	return 0;
	for (std::filesystem::path path : std::filesystem::directory_iterator(R"(.\tests)"))
	{
		if (path.extension() == ".testsolution")
			continue;
		std::cout << "\33[2m" << path.parent_path() << "\33[0m" << "\33[33m" << path.filename() << "\33[0m" << '\n';
		test_on_file(path);
		std::cout << "\33[2m" << path.parent_path() << "\33[0m" << "\33[32m" << path.filename() << "\33[0m" << '\n';
	}
}