#include "host.h"
#include <assert.h>
#include <exception>

int main()
{
	GHB::Host h0("host0", "00:00:00...", 0, "open house");
	GHB::Host h1("host1", "00:00:01...", 1, "closed");

	std::vector<GHB::Host> hosts;
	hosts.push_back(h0);
	hosts.push_back(h1);

	int maxAmountOfHosts = 10;
	GHB::Account myacc("morpheus", maxAmountOfHosts, hosts);


	const GHB::Host& myacc0 = myacc[0]; // otherwise ambiguous
	assert(myacc0 == h0);
	
	try { const GHB::Host& ignored = myacc[99]; assert(false); }
	catch (std::out_of_range ex) 	{ assert(true); }
	catch (std::exception ex)	{ assert(false);}

}

