#ifndef TO_DO_LIST_H
#define TO_DO_LIST_H

#include <map>
#include <string>
#include <vector>

struct Date
{
	int day;
	int month;
	int year;

	const bool operator < (const Date& date) const
	{
		if (year < date.year)
		{
			return true;
		}
		else if (year > date.year)
		{
			return false;
		}
		else
		{
			if (month < date.month)
			{
				return true;
			}
			else if (month > date.month)
			{
				return false;
			}
			else
			{
				if (day < date.day)
				{
					return true;
				}
				return false;
			}
		}
	}
	const bool operator == (const Date& date) const
	{
		return year == date.year && month == date.month && day == date.day;
	}
};

struct Task
{
	std::string name;
};

class ToDoList
{
public:
	ToDoList();

	void AddTask(const std::string& dateStr, const std::string& task);
	void AddTaskForToday(const std::string& task);

	void MakeBackup(const std::string& filename);
private:
	void AddTask(const Date& date, const Task& task);
private:
	std::map<Date, std::vector<Task>> _tasks;
};

#endif // TO_DO_LIST_H