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
			const Host& host;
			Date date;
		protected:
			TrafficDay();
		public:
			TrafficDay(const uint64_t& total, const Host& host, Date& date) : total(total), host(host), date(date) { };
		
		public:
			const uint64_t& getTotal() const { return total; };
			const Host& getHost() const { return host; };
			const Date& getDate() const { return date; };
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
