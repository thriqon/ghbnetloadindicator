#ifndef TRAFFIC_H
#define TRAFFIC_H

#include "host.h"
#include "date.h"

#include <stdint.h>
#include <stdexcept>
#include <list>

namespace GHB
{
	class TrafficDay
	{
		private:
			uint64_t total;
			Host& host;
			Date& date;
//		protected:
		public:
			TrafficDay(const uint64_t& total, Host& host, Date& date) : total(total), host(host), date(date) { };
		
		public:
			const uint64_t& getTotal() const { return total; };
			Host& getHost() const { return host; };
			Date& getDate() const { return date; };
	};
			
	class TrafficTotal
	{
		private:
			std::list<TrafficDay> traffics;
		//protected:
		public:
			TrafficTotal(const std::list<TrafficDay>& traffics) : traffics(traffics) { };
		public:
			const TrafficDay& getTrafficDay(const Host& host, const Date& date) const throw(std::out_of_range);
			
			const uint64_t getTotalByHost (const Host& host) const;
			const uint64_t getTotalByDate (const Date& date) const;
		
			const uint64_t getTotal () const;
	};
}

#endif
