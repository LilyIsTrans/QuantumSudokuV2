#include "board.h"

#include <stdexcept>
#include <iostream>

#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>


ftxui::Element from_possibility(const tile t, const int i)
{
	return t.get(i) ? ftxui::text(" " + std::to_string(i) + " ") : ftxui::text("   ");
};

ftxui::Element make_cell(ftxui::Element a, ftxui::Element b, ftxui::Element c, ftxui::Element d, ftxui::Element e, ftxui::Element f, ftxui::Element g, ftxui::Element h, ftxui::Element i)
{
	return ftxui::gridbox(
		{
			{a, b, c},
			{d, e, f},
			{g, h, i}
		}
	);
}


ftxui::Element from_tile(const tile t)
{
	return make_cell(
		from_possibility(t, 1), from_possibility(t, 2), from_possibility(t, 3),
		from_possibility(t, 4), from_possibility(t, 5), from_possibility(t, 6),
		from_possibility(t, 7), from_possibility(t, 8), from_possibility(t, 9)
	);
}

std::ostream& operator<<(std::ostream& os, const board& board)
{
	using namespace ftxui;

	// Define the document

	Elements tiles;
	for (size_t idx = 0; idx < 81; ++idx)
	{
		tiles.push_back(from_tile(board.data[idx]));
	}




	Element document = vbox(
		{
			separatorHeavy(),
			hbox({separatorHeavy(), from_tile(board.data[0 + (9 * 0)]), separator(), from_tile(board.data[1 + (9 * 0)]), separator(), from_tile(board.data[2 + (9 * 0)]), separatorHeavy(), from_tile(board.data[3 + (9 * 0)]), separator(), from_tile(board.data[4 + (9 * 0)]), separator(), from_tile(board.data[5 + (9 * 0)]), separatorHeavy(), from_tile(board.data[6 + (9 * 0)]), separator(), from_tile(board.data[7 + (9 * 0)]), separator(), from_tile(board.data[8 + (9 * 0)]), separatorHeavy(),}),
			separator(),
			hbox({separatorHeavy(), from_tile(board.data[0 + (9 * 1)]), separator(), from_tile(board.data[1 + (9 * 1)]), separator(), from_tile(board.data[2 + (9 * 1)]), separatorHeavy(), from_tile(board.data[3 + (9 * 1)]), separator(), from_tile(board.data[4 + (9 * 1)]), separator(), from_tile(board.data[5 + (9 * 1)]), separatorHeavy(), from_tile(board.data[6 + (9 * 1)]), separator(), from_tile(board.data[7 + (9 * 1)]), separator(), from_tile(board.data[8 + (9 * 1)]), separatorHeavy(),}),
			separator(),
			hbox({separatorHeavy(), from_tile(board.data[0 + (9 * 2)]), separator(), from_tile(board.data[1 + (9 * 2)]), separator(), from_tile(board.data[2 + (9 * 2)]), separatorHeavy(), from_tile(board.data[3 + (9 * 2)]), separator(), from_tile(board.data[4 + (9 * 2)]), separator(), from_tile(board.data[5 + (9 * 2)]), separatorHeavy(), from_tile(board.data[6 + (9 * 2)]), separator(), from_tile(board.data[7 + (9 * 2)]), separator(), from_tile(board.data[8 + (9 * 2)]), separatorHeavy(),}),
			separatorHeavy(),
			hbox({separatorHeavy(), from_tile(board.data[0 + (9 * 3)]), separator(), from_tile(board.data[1 + (9 * 3)]), separator(), from_tile(board.data[2 + (9 * 3)]), separatorHeavy(), from_tile(board.data[3 + (9 * 3)]), separator(), from_tile(board.data[4 + (9 * 3)]), separator(), from_tile(board.data[5 + (9 * 3)]), separatorHeavy(), from_tile(board.data[6 + (9 * 3)]), separator(), from_tile(board.data[7 + (9 * 3)]), separator(), from_tile(board.data[8 + (9 * 3)]), separatorHeavy(),}),
			separator(),
			hbox({separatorHeavy(), from_tile(board.data[0 + (9 * 4)]), separator(), from_tile(board.data[1 + (9 * 4)]), separator(), from_tile(board.data[2 + (9 * 4)]), separatorHeavy(), from_tile(board.data[3 + (9 * 4)]), separator(), from_tile(board.data[4 + (9 * 4)]), separator(), from_tile(board.data[5 + (9 * 4)]), separatorHeavy(), from_tile(board.data[6 + (9 * 4)]), separator(), from_tile(board.data[7 + (9 * 4)]), separator(), from_tile(board.data[8 + (9 * 4)]), separatorHeavy(),}),
			separator(),
			hbox({separatorHeavy(), from_tile(board.data[0 + (9 * 5)]), separator(), from_tile(board.data[1 + (9 * 5)]), separator(), from_tile(board.data[2 + (9 * 5)]), separatorHeavy(), from_tile(board.data[3 + (9 * 5)]), separator(), from_tile(board.data[4 + (9 * 5)]), separator(), from_tile(board.data[5 + (9 * 5)]), separatorHeavy(), from_tile(board.data[6 + (9 * 5)]), separator(), from_tile(board.data[7 + (9 * 5)]), separator(), from_tile(board.data[8 + (9 * 5)]), separatorHeavy(),}),
			separatorHeavy(),
			hbox({separatorHeavy(), from_tile(board.data[0 + (9 * 6)]), separator(), from_tile(board.data[1 + (9 * 6)]), separator(), from_tile(board.data[2 + (9 * 6)]), separatorHeavy(), from_tile(board.data[3 + (9 * 6)]), separator(), from_tile(board.data[4 + (9 * 6)]), separator(), from_tile(board.data[5 + (9 * 6)]), separatorHeavy(), from_tile(board.data[6 + (9 * 6)]), separator(), from_tile(board.data[7 + (9 * 6)]), separator(), from_tile(board.data[8 + (9 * 6)]), separatorHeavy(),}),
			separator(),
			hbox({separatorHeavy(), from_tile(board.data[0 + (9 * 7)]), separator(), from_tile(board.data[1 + (9 * 7)]), separator(), from_tile(board.data[2 + (9 * 7)]), separatorHeavy(), from_tile(board.data[3 + (9 * 7)]), separator(), from_tile(board.data[4 + (9 * 7)]), separator(), from_tile(board.data[5 + (9 * 7)]), separatorHeavy(), from_tile(board.data[6 + (9 * 7)]), separator(), from_tile(board.data[7 + (9 * 7)]), separator(), from_tile(board.data[8 + (9 * 7)]), separatorHeavy(),}),
			separator(),
			hbox({separatorHeavy(), from_tile(board.data[0 + (9 * 8)]), separator(), from_tile(board.data[1 + (9 * 8)]), separator(), from_tile(board.data[2 + (9 * 8)]), separatorHeavy(), from_tile(board.data[3 + (9 * 8)]), separator(), from_tile(board.data[4 + (9 * 8)]), separator(), from_tile(board.data[5 + (9 * 8)]), separatorHeavy(), from_tile(board.data[6 + (9 * 8)]), separator(), from_tile(board.data[7 + (9 * 8)]), separator(), from_tile(board.data[8 + (9 * 8)]), separatorHeavy(),}),
			separatorHeavy()
		}
	);

	auto screen = Screen::Create(
		Dimension::Fit(document),       // Width
		Dimension::Fit(document) // Height
	);
	Render(screen, document);
	os << screen.ToString();
	return os;

}




board::board(const std::string& puzzle)
{
	size_t idx = 0;
	for (const char elem : puzzle)
	{
		switch (elem)
		{
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			{
			data[idx++].set_to_value(elem - '0');
			break;
			}
		case '.':
		case '*':
		case '?':
		case '0':
			{
			data[idx++].set_all();
			break;
			}
		default: break;
		}
	}
#ifdef _DEBUG
	if (idx != 81)
	{
		std::cout << "\33[31m[WARNING] puzzle: " << puzzle << " did not set all tiles\33[0m" << std::endl;
	}
#endif
}

board& board::operator=(const board& other)
{
	std::ranges::copy(other.data, data.begin());
	return *this;
}





