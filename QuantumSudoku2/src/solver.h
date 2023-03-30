#pragma once
#include "board.h"
#include <stack>
#include <list>

class solver
{
public:
	explicit solver(const board puzzle);

	void deduce();
	void make_guess();

	bool find_contradiction();

	bool is_solved();

	board m_currentBoard;
private:
	std::stack<board, std::list<board>> m_boards;
};