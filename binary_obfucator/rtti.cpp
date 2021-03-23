#include "rtti.h"

#include <algorithm>

#include "utils.h"

using utils::get_random_string_with_random_length;
using utils::find_pattern;

bool rtti::obfuscate_rtti(pe_file* pe_file)
{
	if (!pe_file)
		return false;

	const auto data_section = pe_file->get_section(".data");
	if (!data_section)
	{
		utils::log("PE has no data section, therefore no RTTI info is present!");
		return false;
	}

	unsigned obfuscated_types = 0;
	const std::string rtti_prefixes[] = { ".?AV", ".?AU", ".PEAV", ".?AVOS" };
	for(const auto& rtti_prefix : rtti_prefixes)
	{
		std::vector<std::byte> rtti_prefix_pattern(rtti_prefix.size());
		std::transform(rtti_prefix.begin(), rtti_prefix.end(), rtti_prefix_pattern.begin(),[](char c){ return byte(c); });
		
		auto* search_start = data_section->start;
		auto search_size = data_section->size;
		while(auto* found = find_pattern(search_start, search_size, rtti_prefix_pattern))
		{
			auto obfuscated = get_random_string_with_random_length(3, 5);
			memset(found, 0, strlen(reinterpret_cast<char*>(found)) + 1);
			std::copy(obfuscated.begin(), obfuscated.end(), reinterpret_cast<char*>(found));

			search_size -= found - search_start;
			search_start = found;
			obfuscated_types++;
		}
	}
	
	utils::log("Successfully obfuscated RTTI, total obfuscated strings: " + std::to_string(obfuscated_types));
	return true;
}
