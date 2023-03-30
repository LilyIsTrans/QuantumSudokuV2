#include "solver.h"
#include <algorithm>

void solver::deduce()
{
	for (size_t board_idx = 0; board_idx < 81; ++board_idx)
	{
		const tile& tile = m_currentBoard.data[board_idx];
		if (tile.possibility_count() == 9)
			continue;
		const auto row = board::row(which_row()[board_idx]);
		const auto column = board::column(which_column()[board_idx]);
		const auto square = board::square(which_square()[board_idx]);

		int subset_count = 0;
		for (const size_t idx : row)
		{
			subset_count += tile.is_subset(m_currentBoard.data[idx]);
		}
		if (subset_count >= tile.possibility_count())
		{
			for (const size_t idx : row)
			{
				if (!tile.is_subset(m_currentBoard.data[idx]))
					m_currentBoard.data[idx].remove_possibilities(tile);
			}
		}

		subset_count = 0;
		for (const size_t idx : column)
		{
			subset_count += tile.is_subset(m_currentBoard.data[idx]);
		}
		if (subset_count >= tile.possibility_count())
		{
			for (const size_t idx : column)
			{
				if (!tile.is_subset(m_currentBoard.data[idx]))
					m_currentBoard.data[idx].remove_possibilities(tile);
			}
		}

		subset_count = 0;
		for (const size_t idx : square)
		{
			subset_count += tile.is_subset(m_currentBoard.data[idx]);
		}
		if (subset_count >= tile.possibility_count())
		{
			for (const size_t idx : square)
			{
				if (!tile.is_subset(m_currentBoard.data[idx]))
					m_currentBoard.data[idx].remove_possibilities(tile);
			}
		}
	}
}

void solver::make_guess()
{
	size_t idx_of_min_entropy = 81;
	int min_entropy = 10;
	for (size_t idx = 0; idx < 81; ++idx)
	{
		if (m_currentBoard.data[idx].possibility_count() < min_entropy && m_currentBoard.data[idx].possibility_count() > 1)
		{
			min_entropy = m_currentBoard.data[idx].possibility_count();
			idx_of_min_entropy = idx;
		}
	}
	if (idx_of_min_entropy == 81)
		return;
	const int smallest_possibility = m_currentBoard.data[idx_of_min_entropy].smallest_possibility();
	board new_curr_board = m_currentBoard;
	new_curr_board.data[idx_of_min_entropy].set_to_value(smallest_possibility);
	board checkpoint = m_currentBoard;
	checkpoint.data[idx_of_min_entropy].unset(smallest_possibility);
	m_boards.push(checkpoint);
	m_currentBoard = new_curr_board;
}

bool solver::find_contradiction()
{
	for (size_t board_idx = 0; board_idx < 81; ++board_idx)
	{
		const tile& tile = m_currentBoard.data[board_idx];
		if (tile.possibility_count() == 9)
			continue;
		const auto row = board::row(which_row()[board_idx]);
		const auto column = board::column(which_column()[board_idx]);
		const auto square = board::square(which_square()[board_idx]);

		int subset_count = 0;
		for (const size_t idx : row)
		{
			subset_count += tile.is_subset(m_currentBoard.data[idx]);
		}
		if (subset_count > tile.possibility_count())
		{
			m_currentBoard = m_boards.top();
			m_boards.pop();
			return true;
		}

		subset_count = 0;
		for (const size_t idx : column)
		{
			subset_count += tile.is_subset(m_currentBoard.data[idx]);
		}
		if (subset_count > tile.possibility_count())
		{
			m_currentBoard = m_boards.top();
			m_boards.pop();
			return true;
		}

		subset_count = 0;
		for (const size_t idx : square)
		{
			subset_count += tile.is_subset(m_currentBoard.data[idx]);
		}
		if (subset_count > tile.possibility_count())
		{
			m_currentBoard = m_boards.top();
			m_boards.pop();
			return true;
		}
	}
	return false;
}

bool solver::is_solved()
{
	return std::ranges::count_if(m_currentBoard.data, [](const tile& t)
	{
		return static_cast<bool>(t.value());
	}) == 81;
}

solver::solver(const board puzzle)
{
	m_currentBoard = puzzle;
}

