#include "host.h"

using namespace GHB;

const Host& Account::operator[] (const std::string& name) const throw (std::out_of_range)
{
	for (std::vector<Host>::const_iterator it = hosts.begin(); it != hosts.end(); it++)
	{
		if (it->getHostname() == name) return *it;
	}
	throw std::out_of_range("GHB::Account[]");
}

