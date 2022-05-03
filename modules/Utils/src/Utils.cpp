#include "Utils.h"

#include <ctime>

constexpr auto HYPHEN = '-';

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
		if (!IsValidDate(date))
		{
			return Date();
		}

		auto firstIt = date.find(HYPHEN);
		auto lastIt = date.find_last_of(HYPHEN);
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

	bool IsValidDate(const std::string& date)
	{
		if (std::count(date.begin(), date.end(), HYPHEN) != 2)
		{
			return false;
		}

		auto firstHyphenIt = date.find_first_of(HYPHEN);
		auto secondHyphenIt = date.find_last_of(HYPHEN);
		if (firstHyphenIt + 1 == secondHyphenIt
			|| firstHyphenIt == 0
			|| secondHyphenIt == date.length())
		{
			return false;
		}

		for (const auto& symbol : date)
		{
			if (symbol != HYPHEN)
			{
				if (!isdigit(symbol))
				{
					return false;
				}
			}
		}

		return true;
	}
}