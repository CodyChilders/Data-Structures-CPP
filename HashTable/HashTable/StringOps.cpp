#include <vector>
#include <sstream>
#include <string>
#include <unordered_map>
#include "StringOps.h"

std::hash<std::string> hasher;

int GetHashCode(std::string s)
{
	size_t code = hasher(s);
	int returnCode = static_cast<int>(code);
	if (returnCode < 0)
		returnCode *= -1;
	return returnCode;
}

//the following two functions have been taken from:
//http://stackoverflow.com/questions/236129/split-a-string-in-c
std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems)
{
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim))
	{
		elems.push_back(item);
	}
	return elems;
}


std::vector<std::string> split(const std::string &s, char delim)
{
	std::vector<std::string> elems;
	split(s, delim, elems);
	return elems;
}
//end of what was taken from stack overflow
