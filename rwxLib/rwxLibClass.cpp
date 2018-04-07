#include "rwxLibClass.h"

const static std::regex numericRe("[0-7][0-7][0-7]");
const static std::regex stringRe("[Rr-][Ww-][Xx-][Rr-][Ww-][Xx-][Rr-][Ww-][Xx-]");

rwxLibClass::rwxLibClass()
{
	//
}

rwxLibClass::~rwxLibClass()
{
	//
}

std::string rwxLibClass::help()
{
	std::string help =
	"Supported numeric sequence example: 755\n"
	"Supported text sequence example #1: rwxr-xr-x\n"
	"Supported text sequence example #2: RWXR-XR-X\n"
	"Supported text sequence example #3: RwXr-XR-x\n";
	return help;
}

std::string rwxLibClass::parse(std::string &input)
{
	std::string out = "";
	if (std::regex_match(input, numericRe)) {
		out = parseNumber(input);
	}
	else if (std::regex_match(input, stringRe)) {
		out = parseString(input);
	}
	else {
		out = help();
	}
	return out;
}

std::string rwxLibClass::parseNumericRightBlock(int inValue)
{
	std::string outValue = "";
	if (inValue & 0b100)
		outValue += "r";
	else
		outValue += "-";

	if (inValue & 0b010)
		outValue += "w";
	else
		outValue += "-";

	if (inValue & 0b001)
		outValue += "x";
	else
		outValue += "-";
	return outValue;
}

std::string rwxLibClass::parseNumber(std::string input)
{
	std::string outRights = "";
	for (auto i = 0; i < 3; i++)
		outRights += parseNumericRightBlock(std::stoi(input.substr(i, 1)));
	return outRights;
}

bool rwxLibClass::containsSymbols(std::string target, std::string a, std::string b)
{
	if (target.find(a) != std::string::npos || target.find(b) != std::string::npos)
		return true;
	else
		return false;
}

int rwxLibClass::parseStringRightsBlock(std::string rights)
{
	int outputRights = 0b000;
	if (containsSymbols(rights, "r", "R"))
		outputRights |= 0b100;
	else
		outputRights |= 0b000;

	if (containsSymbols(rights, "w", "W"))
		outputRights |= 0b010;
	else
		outputRights |= 0b000;

	if (containsSymbols(rights, "x", "X"))
		outputRights |= 0b001;
	else
		outputRights |= 0b000;
	return outputRights;
}

std::string rwxLibClass::parseString(std::string input)
{
	std::string output = "";

	for (auto i = 0; i<3; i++) {
		output += std::to_string(parseStringRightsBlock(input.substr(i * 3, 3)));
	}

	return output;
}