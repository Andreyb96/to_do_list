#include "ToDoList.h"

#include <iostream>

void PrintHelp()
{
	std::cout << "add <task name> <date>: Add new task for specified day" << std::endl;
	std::cout << "add <task name>: Add new task for today" << std::endl;
}

int main(int argc, char *argv[])
{
	if (std::string(argv[1]) == "-h")
	{
		PrintHelp();
	}

	std::string command;

	while (command != "q")
	{
		std::cin >> command;
	}

	return 0;
}