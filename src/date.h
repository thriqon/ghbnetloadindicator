#ifndef DATE_H
#define DATE_H

#include <ctime>
#include <string>

#include <stdexcept>

namespace GHB
{
	class Date
	{
		private:
			std::tm t;
			std::string* dayOfWeek;
			
			int Day; int Month; int Year;
		public:
			Date(const int& Day, const int& Month, const int& Year) throw (std::out_of_range);
			virtual ~Date();
			
			const std::string& getDayOfWeek();

			bool operator==(const Date& o) const { return ((o.getDay() == getDay()) && (o.getMonth() == getMonth()) && (o.getYear() == getYear())); };

			const int getDay() const { return t.tm_mday ; };
			const int getMonth() const { return t.tm_mon + 1; };
			const int getYear()  const { return t.tm_year + 1900; };
	};
}

#endif
