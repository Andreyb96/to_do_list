#include "Utils.h"

#include <ctime>

namespace Utils
{
	Date GetTodaysDate()
	{
		auto t = std::time(0);
		auto currentTime = std::localtime(&t);
		return { currentTime->tm_mday,  currentTime->tm_mon + 1, currentTime->tm_year + 1900 };
	}

	Date BuildDate(const std::string& date)
	{
		auto firstIt = date.find('-');
		auto lastIt = date.find_last_of('-');
		return { std::stoi(date.substr(0, firstIt))
		, std::stoi(date.substr(firstIt + 1, lastIt))
		, std::stoi(date.substr(lastIt + 1)) };
	}

	std::string BuildDateStr(const Date& date)
	{
		return std::to_string(date.day) +
			'-' + std::to_string(date.month) +
			'-' + std::to_string(date.year);
	}
}