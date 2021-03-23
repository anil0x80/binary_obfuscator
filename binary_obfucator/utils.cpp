#include "utils.h"

#include <algorithm>
#include <intrin.h>

byte* utils::find_pattern(byte* start, const size_t size, std::vector<byte> pattern)
{
	auto* end = start + size;

	for (auto* p = start; p < end; p++)
	{
		if (p + pattern.size() > end)
			break;

		if (std::memcmp(p, pattern.data(), pattern.size()) == 0)
			return p;
	}

	return nullptr;
}

void utils::log(std::string log)
{

	std::cout << log << std::endl;

}

std::string utils::get_random_string_with_random_length(unsigned min_length, unsigned max_length)
{
	srand(__rdtsc()); // cpu timestamp counter
	const auto length = rand() % (max_length - min_length + 1) + min_length;
	auto randChar = []() -> char
	{
		const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ""abcdefghijklmnopqrstuvwxyz";
		const auto maxIdx = (sizeof(charset) - 1);
		return charset[rand() % maxIdx];
	};
	std::string str(length, 0);
	std::generate_n(str.begin(), length, randChar);
	return str;
}
