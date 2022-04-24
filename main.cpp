#include "ToDoList.h"
#include "easylogging++.h"

#include <iostream>

INITIALIZE_EASYLOGGINGPP

constexpr auto BACKUP_FILENAME = "backup.txt";

namespace
{
	void PrintHelp()
	{
		std::cout << "add <task name> <date>: Add new task for specified day" << std::endl;
		std::cout << "add <task name>: Add new task for today" << std::endl;
	}
} //anonymos

int main(int argc, char *argv[])
{
	if (argc > 1 && std::string(argv[1]) == "-h")
	{
		PrintHelp();
	}

	std::string command;

	while (command != "q")
	{
		ToDoList list;
		list.LoadBackup(BACKUP_FILENAME);
		list.AddTask("23-05-2022", "task name");
		list.AddTaskForToday("task name");
		list.AddTaskForToday("task name");
		list.MakeBackup(BACKUP_FILENAME);
		std::cin >> command;
	}

	return 0;
}