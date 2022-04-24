#ifndef DATE_H
#define DATE_H

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

#endif // DATE_H
