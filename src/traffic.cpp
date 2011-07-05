#include "traffic.h"

using namespace GHB;

const TrafficDay& TrafficTotal::getTrafficDay(const Host& host, const Date& date) const throw(std::out_of_range)
{
	for (std::list<TrafficDay>::const_iterator it = traffics.begin(); it != traffics.end(); it++)
	{
		if (it->getHost() == host && it->getDate() == date)
			return *it;
	}
	throw std::out_of_range("TrafficTotal::getTrafficDay");
}

const uint64_t TrafficTotal::getTotalByHost(const Host& host) const
{
	uint64_t sum = 0;
	for (std::list<TrafficDay>::const_iterator it = traffics.begin(); it != traffics.end(); it++)
	{
		if (it->getHost() == host)
			sum += it->getTotal();
	}
	return sum;
}
const uint64_t TrafficTotal::getTotalByDate(const Date& date) const
{
	
	uint64_t sum = 0;
	for (std::list<TrafficDay>::const_iterator it = traffics.begin(); it != traffics.end(); it++)
	{
		if (it->getDate() == date)
			sum += it->getTotal();
	}
	return sum;
}


const uint64_t TrafficTotal::getTotal() const
{
	
	uint64_t sum = 0;
	for (std::list<TrafficDay>::const_iterator it = traffics.begin(); it != traffics.end(); it++)
	{
		sum += it->getTotal();
	}
	return sum;
}

