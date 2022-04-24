#ifndef UTILS_H
#define UTILS_H

#include <string>

#include "Date.h"

namespace Utils
{
	Date GetTodaysDate();

	Date BuildDate(const std::string& date);

	std::string BuildDateStr(const Date& date);
}

#endif // UTILS_H

