#pragma once
#include <cstdint>
#include <bit>


struct tile
{
	/**
	 * \brief Reads whether a given value is a possibility for this tile
	 * \param idx The number to check
	 * \return true if idx is a possibility, false otherwise
	 */
	[[nodiscard]] inline bool get(const int idx) const
	{
		return m_data & (1 << (idx - 1));
	}

	/**
	 * \brief Sets whether a given value is a possibility for this tile
	 * \param idx The value to declare possibile
	 */
	inline void set(const int idx)
	{
		m_data |= (1 << (idx - 1));
	}

	/**
	 * \brief Unsets whether a given value is a possibility for this tile
	 * \param idx The value to declare impossibile
	 */
	inline void unset(const int idx)
	{
		m_data &= ((~0 - 1) << (idx - 1));
	}

	/**
	 * \brief Checks if the tile has only 1 possible value, and if so returns that value. Returns 0 if more than 1 possibility.
	 * \return The value of the tile if collapsed, 0 otherwise
	 */
	[[nodiscard]] inline int value() const
	{
		if (std::has_single_bit(m_data))
		{
			return std::bit_width(m_data);
		}
		return 0;
	}


	/**
	 * \brief Efficiently checks if other is a subset of this tile (has no possibilities that this tile does not)
	 * \param other A tile object
	 * \return true if other is a subset, false otherwise
	 */
	[[nodiscard]] inline bool is_subset(const tile other) const
	{
		const auto intersection = m_data & other.m_data;
		return intersection == other.m_data;
	}

	/**
	 * \brief Check how many possibilities this tile has
	 * \return The number of possibilities for this tile
	 */
	[[nodiscard]] inline int possibility_count() const
	{
		return std::popcount(m_data);
	}

	/**
	 * \brief Checks if there are any possibilities for this tile. If there are none, this tile is considered invalid.
	 * \return true if this tile is valid, false if this tile is invalid.
	 */
	[[nodiscard]] inline bool is_valid() const
	{
		return m_data;
	}

	/**
	 * \brief Removes from this tile each possibility of the tile other
	 */
	inline void remove_possibilities(const tile other)
	{
		m_data &= ~other.m_data;
	}

	/**
	 * \return The smallest value which is a possibility of this tile
	 */
	[[nodiscard]] inline int smallest_possibility() const
	{
		return std::countr_zero(m_data) + 1;
	}

	/**
	 * \brief Collapses tile to have only one possibility, determined by val
	 * \param val The value to take on
	 */
	inline void set_to_value(const int val)
	{
		m_data = (1 << (val - 1));
	}

	/**
	 * \brief Sets this tile to have all possibilities
	 */
	inline void set_all()
	{
		m_data = 0b111111111;
	}

	inline bool operator==(const tile other) const
	{
		return m_data == other.m_data;
	}

private:
	uint_fast16_t m_data = 0;
};