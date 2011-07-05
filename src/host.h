#ifndef HOST_H
#define HOST_H

#include <string>
#include <vector>
#include <stdexcept>

namespace GHB
{
	class Host
	{
		private:
			std::string hostname;
			std::string mac;
			int fwrule;
			std::string fwrulename;
		public:
			Host(const std::string& hostname, const std::string& mac, const int& fwrule, const std::string fwrulename) : hostname(hostname), mac(mac), fwrule(fwrule), fwrulename(fwrulename) { };

			// assumes hostname is unique
			bool operator== (const Host& o) const { return hostname == o.getHostname(); };
			
			const std::string& getHostname() const { return hostname; };
			const std::string& getMac() const { return mac; };
			const int& getFWRule() const { return fwrule; };
			const std::string& getFWRuleName() const { return fwrulename; }

	};


	class Account
	{
		private:
			std::string userid;
			int maxAmountOfHosts;

			const std::vector<Host> hosts;
		public:
			Account(const std::string& userid, const int& maxAmountOfHosts, const std::vector<Host>& hosts) : userid(userid), maxAmountOfHosts(maxAmountOfHosts), hosts(hosts) { };
			
			const std::string& getUserid() const { return userid; };
			const int& getMaxAmountOfHosts() const { return maxAmountOfHosts; };
		
			const Host& operator[] (const int& index) const throw (std::out_of_range)
			{ return hosts.at(index); };

			const Host& operator[] (const std::string& name) const throw (std::out_of_range);
	};
			

}			
		

#endif
