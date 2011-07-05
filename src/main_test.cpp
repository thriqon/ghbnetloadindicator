#include "traffic.h"
#include "host.h"
#include <list>
#include <vector>

#include <iostream>

int main()
{
	GHB::Host h0("host0", "00:00:00...", 0, "open house");
	GHB::Host h1("host1", "00:00:01...", 1, "closed");

	std::vector<GHB::Host> hosts;
	hosts.push_back(h0);
	hosts.push_back(h1);

	int maxAmountOfHosts = 10;
	GHB::Account myacc("morpheus", maxAmountOfHosts, hosts);


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
	
	std::cout << "Today: " << total.getTotalByDate(today) << std::endl
		<< "Host0: " << total.getTotalByHost(h0) << std::endl
		<< "Yesterday: " << total.getTotalByDate(yesterday) << std::endl;

}

