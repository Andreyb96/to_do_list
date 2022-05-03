#ifndef UTILS_H
#define UTILS_H

#include <string>

#include "Date.h"

namespace Utils
{
	Date GetTodaysDate();

	Date BuildDate(const std::string& date);

	std::string BuildDateStr(const Date& date);

	bool IsValidDate(const std::string& date);
}

#endif // UTILS_H

