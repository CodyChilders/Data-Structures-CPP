#include <iostream>
#include <vector>
#include <sstream>
#include "HashTable.h"
#include "StringOps.h"

int main()
{
	HashTable ht;
	std::cout << "Enter a line of text, each with each token separated by spaces" << std::endl;
	std::string line;
	std::getline(std::cin, line);
	std::vector<std::string> tokens = split(line, ' ');
	std::string token;
	for (int i = 0; i < static_cast<int>(tokens.size()); i++)
	{
		token = tokens[i];
		ht.AddString(token);
	}
	std::cout << "Enter a string to test if it is in the table" << std::endl << std::endl;
	while (true)
	{
		std::cin >> token;
		if (token.compare("exit") == 0)
		{
			break;
		}
		else if (token.compare("print") == 0)
		{
			ht.PrintTable();
		}
		else if (ht.ContainsString(token))
		{
			std::cout << "Yes: " << token << std::endl;
		}
		else
		{
			std::cout << "No: " << token << std::endl;
		}
	}
}

