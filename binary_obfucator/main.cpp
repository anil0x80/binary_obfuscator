#include <iostream>
#include <string>

#include "pe.h"
#include "rtti.h"
#include "filesystem"

using namespace std;

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		cout << "Not enough arguments, please provide a valid path to a PE file!" << std::endl;
		return -1;
	}
	
	const string path = argv[1];
	try
	{
		/* read file into buffer */
		pe_file file(path);

		/* do magic */
		rtti::obfuscate_rtti(&file);

		/* overwrite the original file, hope it works */
		file.overwrite_original();
	}
	catch (std::exception& e)
	{
		cout << e.what() << endl;
		return -1;
	}
	

	// create pe representation.

	return 0;
}