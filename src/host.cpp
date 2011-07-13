#include "host.h"

using namespace GHB;

Host::Host(const std::string& hostname, const std::string& mac, const int& fwrule, const std::string fwrulename) 
	: hostname(hostname), mac(mac), fwrule(fwrule), fwrulename(fwrulename)
{
}


const Host& Account::operator[] (const std::string& name) const throw (std::out_of_range)
{
	for (std::vector<Host>::const_iterator it = hosts.begin(); it != hosts.end(); it++)
	{
		if (it->getHostname() == name) return *it;
	}
	throw std::out_of_range("GHB::Account[]");
}

