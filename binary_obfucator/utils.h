#pragma once
#include <string>
#include <vector>
#include <iostream>

using std::byte;

namespace utils
{
	byte* find_pattern(byte* start, const size_t size, std::vector<byte> pattern);

	void log(std::string log);

	std::string get_random_string_with_random_length(unsigned int min_length, unsigned int max_length);
}
