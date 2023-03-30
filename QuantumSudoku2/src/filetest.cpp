#include "filetest.h"

#include <chrono>
#include <fstream>
#include <regex>
#include <cstdint>
#include <sstream>
#include <string>

#include "board.h"
#include "solver.h"





std::string from_solution(const solve_result& solution)
{
	std::stringstream output;
	for (const tile& tile : solution.solution.data)
	{
		if (const int val = tile.value())
			output.put(val + '0');
		else
			output.put('.');
	}
	output.put('\t');
	output << solution.deductions << '\t' << solution.total_guesses << '\t' << (solution.time.count() / 1000) << '.' << ((solution.time.count() / 100) % 10) << "us";

	return output.str();
}

void test_on_file(std::filesystem::path src_path)
{
	std::filesystem::path dst_path = src_path;
	if (src_path.extension() != "testsolution")
		dst_path.replace_extension("testsolution");
	else
		dst_path.replace_extension("solved");

	std::ifstream src_file(src_path);
	std::ofstream dst_file(dst_path);

	const std::regex puzzle_regex("[.*?[:d:]]{81}"); // Regex wizardry. Matches a sequence of 81 characters which are '.'s, '*'s, '?'s, or decimal digits.

	while (src_file.good())
	{
		std::string line;
		std::getline(src_file, line);

		std::smatch match;
		if (std::regex_search(line, match, puzzle_regex))
		{
			using namespace std::chrono_literals;
			std::string puzzle = match.str(0);

			dst_file << match.prefix() << puzzle << '\t' << from_solution(solve(puzzle)) << match.suffix() << '\n';
		}
		else
		{
			dst_file << line << '\n';
		}
	}

}