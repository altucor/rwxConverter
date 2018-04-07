#pragma once

#include <string>
#include <regex>

class rwxLibClass
{
public:
	rwxLibClass();
	~rwxLibClass();
	std::string help();
	std::string parse(std::string &input);
	std::string parseNumber(std::string input);
	std::string parseString(std::string input);
private:
	std::string parseNumericRightBlock(int inValue);
	bool containsSymbols(std::string target, std::string a, std::string b);
	int parseStringRightsBlock(std::string rights);
	
	std::string m_input = "";
};

