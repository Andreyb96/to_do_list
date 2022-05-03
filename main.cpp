#include "ToDoList.h"
#include "Utils.h"
#include "easylogging++.h"

#include <iostream>

INITIALIZE_EASYLOGGINGPP

constexpr auto BACKUP_FILENAME = "backup.txt";

constexpr auto SPACE = " ";

constexpr auto ADD_TASK = "add";
constexpr auto DELETE_TASK = "delete";
constexpr auto HELP = "help";
constexpr auto QUIT = "q";

namespace
{
	void PrintHelp()
	{
		std::cout << "add <date> <task name>: Add new task for specified day" << std::endl;
		std::cout << "add <task name>: Add new task for today" << std::endl;
		std::cout << "delete <date> <task name>: Delete specified task for specified day" << std::endl;
		std::cout << "delete <date>: Delete all tasks for date" << std::endl;
		std::cout << "delete: Delete all tasks for today" << std::endl;
	}
} //anonymos

int main(int argc, char *argv[])
{
	if (argc > 1 && std::string(argv[1]) == "-h")
	{
		PrintHelp();
	}

	ToDoList list;
	list.LoadBackup(BACKUP_FILENAME);

	std::string command;

	while (command != QUIT)
	{
		std::getline(std::cin, command);
		if (command.find(HELP) != std::string::npos)
		{
			PrintHelp();
			continue;
		}

		if (command.find(ADD_TASK) != std::string::npos)
		{
			command = command.substr(command.find(SPACE) + 1);
			auto firstSpaceIt = command.find(SPACE);
			if (firstSpaceIt == std::string::npos)
			{
				list.AddTaskForToday(command);
			}
			else
			{
				auto date = command.substr(0, firstSpaceIt);
				if (Utils::IsValidDate(date))
				{
					auto task = command.substr(firstSpaceIt + 1);
					list.AddTask(date, task);
				}
				else
				{
					list.AddTaskForToday(command);
				}
			}
		}

		if (command.find(DELETE_TASK) != std::string::npos)
		{
			auto firstSpaceIt = command.find(SPACE);
			if (firstSpaceIt != std::string::npos)
			{
				command = command.substr(firstSpaceIt + 1);
				firstSpaceIt = command.find(SPACE);
				if (firstSpaceIt == std::string::npos)
				{
					list.RemoveAllTasksForDate(command);
				}
				else
				{
					auto date = command.substr(0, firstSpaceIt);
					if (Utils::IsValidDate(date))
					{
						auto task = command.substr(firstSpaceIt + 1);
						list.RemoveTask(date, task);
					}
				}
			}
			else
			{
				list.RemoveAllTasksForToday();
			}
		}
	}

	list.MakeBackup(BACKUP_FILENAME);

	return 0;
}