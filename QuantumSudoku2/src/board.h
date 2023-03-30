#pragma once
#include "tile.h"
#include <array>
#include <string>
#include <iostream>




struct board
{

	explicit board(const std::string&);
	board() = default;

	board& operator=(const board&);

	[[nodiscard]] static constexpr std::array<size_t, 9> row(const size_t idx)
	{
		return { 0 + idx * 9, 1 + idx * 9, 2 + idx * 9, 3 + idx * 9, 4 + idx * 9, 5 + idx * 9, 6 + idx * 9, 7 + idx * 9, 8 + idx * 9 };
	}

	[[nodiscard]] static constexpr std::array<size_t, 9> column(const size_t idx)
	{
		return { 0 + idx, 9 + idx, 18 + idx, 27 + idx, 36 + idx, 45 + idx, 54 + idx, 63 + idx, 72 + idx };
	}

	[[nodiscard]] static constexpr std::array<size_t, 9> square(const size_t idx)
	{
		size_t offset = 0;
		if (idx >= 3)
			offset += 18;
		if (idx >= 6)
			offset += 18;
		return { offset + 0 + idx * 3, offset + 1 + idx * 3, offset + 2 + idx * 3, offset + 9 + idx * 3, offset + 10 + idx * 3, offset + 11 + idx * 3, offset + 18 + idx * 3, offset + 19 + idx * 3, offset + 20 + idx * 3 };
	}

public:
	std::array<tile, 81> data;
};




consteval std::array<int, 81> which_row()
{
	const auto row1 = board::row(0);
	const auto row2 = board::row(1);
	const auto row3 = board::row(2);
	const auto row4 = board::row(3);
	const auto row5 = board::row(4);
	const auto row6 = board::row(5);
	const auto row7 = board::row(6);
	const auto row8 = board::row(7);
	const auto row9 = board::row(8);
	std::array<int, 81> output{};
	for (size_t i = 0; i < 81; ++i)
	{
		for (const auto idx : row1)
		{
			if (i == idx)
				output[i] = 0;
		}
		for (const auto idx : row2)
		{
			if (i == idx)
				output[i] = 1;
		}
		for (const auto idx : row3)
		{
			if (i == idx)
				output[i] = 2;
		}
		for (const auto idx : row4)
		{
			if (i == idx)
				output[i] = 3;
		}
		for (const auto idx : row5)
		{
			if (i == idx)
				output[i] = 4;
		}
		for (const auto idx : row6)
		{
			if (i == idx)
				output[i] = 5;
		}
		for (const auto idx : row7)
		{
			if (i == idx)
				output[i] = 6;
		}
		for (const auto idx : row8)
		{
			if (i == idx)
				output[i] = 7;
		}
		for (const auto idx : row9)
		{
			if (i == idx)
				output[i] = 8;
		}
	}
	return output;
}

consteval std::array<int, 81>  which_column()
{
	const auto column1 = board::column(0);
	const auto column2 = board::column(1);
	const auto column3 = board::column(2);
	const auto column4 = board::column(3);
	const auto column5 = board::column(4);
	const auto column6 = board::column(5);
	const auto column7 = board::column(6);
	const auto column8 = board::column(7);
	const auto column9 = board::column(8);
	std::array<int, 81> output{};
	for (size_t i = 0; i < 81; ++i)
	{
		for (const auto idx : column1)
		{
			if (i == idx)
				output[i] = 0;
		}
		for (const auto idx : column2)
		{
			if (i == idx)
				output[i] = 1;
		}
		for (const auto idx : column3)
		{
			if (i == idx)
				output[i] = 2;
		}
		for (const auto idx : column4)
		{
			if (i == idx)
				output[i] = 3;
		}
		for (const auto idx : column5)
		{
			if (i == idx)
				output[i] = 4;
		}
		for (const auto idx : column6)
		{
			if (i == idx)
				output[i] = 5;
		}
		for (const auto idx : column7)
		{
			if (i == idx)
				output[i] = 6;
		}
		for (const auto idx : column8)
		{
			if (i == idx)
				output[i] = 7;
		}
		for (const auto idx : column9)
		{
			if (i == idx)
				output[i] = 8;
		}
	}
	return output;
}

consteval std::array<int, 81> which_square()
{
	const auto square1 = board::square(0);
	const auto square2 = board::square(1);
	const auto square3 = board::square(2);
	const auto square4 = board::square(3);
	const auto square5 = board::square(4);
	const auto square6 = board::square(5);
	const auto square7 = board::square(6);
	const auto square8 = board::square(7);
	const auto square9 = board::square(8);
	std::array<int, 81> output{};
	for (size_t i = 0; i < 81; ++i)
	{
		for (const auto idx : square1)
		{
			if (i == idx)
				output[i] = 0;
		}
		for (const auto idx : square2)
		{
			if (i == idx)
				output[i] = 1;
		}
		for (const auto idx : square3)
		{
			if (i == idx)
				output[i] = 2;
		}
		for (const auto idx : square4)
		{
			if (i == idx)
				output[i] = 3;
		}
		for (const auto idx : square5)
		{
			if (i == idx)
				output[i] = 4;
		}
		for (const auto idx : square6)
		{
			if (i == idx)
				output[i] = 5;
		}
		for (const auto idx : square7)
		{
			if (i == idx)
				output[i] = 6;
		}
		for (const auto idx : square8)
		{
			if (i == idx)
				output[i] = 7;
		}
		for (const auto idx : square9)
		{
			if (i == idx)
				output[i] = 8;
		}
	}
	return output;
}


std::ostream& operator<<(std::ostream& os, const board& board);
