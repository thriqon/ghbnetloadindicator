#include "date.h"
#include "weekdays.h"
#include <stdexcept>
using namespace GHB;

Date::Date(const int& Day, const int& Month, const int& Year) throw (std::out_of_range)
	: Day(Day), Month(Month), Year(Year)
{
	if (Year < 1900)
	{
		throw std::out_of_range("years before 1900 not supported");
	}

	dayOfWeek = NULL;
		                          //   0-based    // since 1900
	std::tm time_in = {0,0,0, Day, Month - 1, Year - 1900};
	std::time_t time_temp = std::mktime(&time_in);
	std::tm const *time_out = std::localtime(&time_temp);
	t = *time_out;
}

const std::string& Date::getDayOfWeek()
{
	if (dayOfWeek == NULL)
	{
		dayOfWeek = new std::string(weekdays[t.tm_wday]);
	}
	return *dayOfWeek;
}

Date::~Date()
{
	if (dayOfWeek != NULL) delete dayOfWeek;
}
		
