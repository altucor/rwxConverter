// rwxConverter.cpp : Defines the entry point for the console application.
//

#include "rwxLibClass.h"

#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
	rwxLibClass rwx;

	if (argc == 1 || std::string(argv[1]) == std::string("-h")) {
		std::cout << rwx.help() << std::endl;
		return 0;
	}

	std::string input = argv[1];
	
	std::cout << rwx.parse(input) << std::endl;

    return 0;
}

