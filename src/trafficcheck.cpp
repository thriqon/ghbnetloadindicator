#include "traffic.h"

#include <assert.h>
#include <exception>

int main()
{
	GHB::Host h0("host0", "00:00:00...", 0, "open house");
	GHB::Host h1("host1", "00:00:01...", 1, "closed");


	GHB::Date today(5, 7, 2011);
	GHB::Date yesterday(4,7, 2011);

	GHB::TrafficDay t1(100, h0, today);
	GHB::TrafficDay t2(200, h0, today);
	GHB::TrafficDay t3(300, h1, today);
	GHB::TrafficDay t4(400, h0, yesterday);

	std::list<GHB::TrafficDay> traffics;
	traffics.push_back(t1);
	traffics.push_back(t2);
	traffics.push_back(t3);
	traffics.push_back(t4);
	
	GHB::TrafficTotal total(traffics);

	assert(total.getTotalByDate(today) == 600);
	assert(total.getTotalByHost(h0) == 700);
	assert(total.getTotal() == 1000);
	
	GHB::Host hx("hostx", "00:00:00...", 3, "not existent");
	assert(total.getTotalByHost(hx) == 0);


	GHB::Date someday(1,1,2001);
	assert(total.getTotalByDate(someday) == 0);


	try { const GHB::TrafficDay& ignored = total.getTrafficDay(h0, today); assert(true); }
	catch (std::exception ex) { assert(false); }

	try { const GHB::TrafficDay& ignored = total.getTrafficDay(h0, someday); } 
	catch (std::out_of_range ex) 	{ assert(true); }
	catch (std::exception ex) 	{ assert(false);}
	
	try { const GHB::TrafficDay& ignored = total.getTrafficDay(hx, today); } 
	catch (std::out_of_range ex) 	{ assert(true); }
	catch (std::exception ex) 	{ assert(false);}
	
	try { const GHB::TrafficDay& ignored = total.getTrafficDay(hx, someday); } 
	catch (std::out_of_range ex) 	{ assert(true); }
	catch (std::exception ex) 	{ assert(false);}
}
