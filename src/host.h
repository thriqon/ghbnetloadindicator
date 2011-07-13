#ifndef HOST_H
#define HOST_H

#include <string>
#include <vector>
#include <stdexcept>

namespace GHB
{
	/** \brief represents a host, as used in the GHB
	  *
	  * The host is read in during refresh(), also via API
	  */
	class Host
	{
		private:
			std::string hostname;
			std::string mac;
			int fwrule;
			std::string fwrulename;
		public:
			/** \brief constructs new host 
			  *
			  * \param hostname The name given to the host (during registration)
			  * \param mac the registered MAC-address of this host
			  * \param fwrule a numeric id for the chosen firewall
			  * \param fwrulename a verbose name for the firewall
			  */
			Host(const std::string& hostname, const std::string& mac, const int& fwrule, const std::string fwrulename);

			/** \brief compare two hosts assuming hostname is unique */
			bool operator== (const Host& o) const { return hostname == o.getHostname(); };
		
			/** \brief return the hostname */
			const std::string& getHostname() const { return hostname; };

			/** \brief return the MAC-address */
			const std::string& getMac() const { return mac; };

			/** \brief return the firewall-rule-id */
			const int& getFWRule() const { return fwrule; };
			/** \brief return the firewall-rule-name */
			const std::string& getFWRuleName() const { return fwrulename; }

	};


	class Account
	{
		private:
			std::string userid;
			int maxAmountOfHosts;

			std::vector<Host> hosts;
		public:
			Account(const std::string& userid, const int& maxAmountOfHosts, const std::vector<Host>& hosts) : userid(userid), maxAmountOfHosts(maxAmountOfHosts), hosts(hosts) { };
			
			const std::string& getUserid() const { return userid; };
			const int& getMaxAmountOfHosts() const { return maxAmountOfHosts; };
		
			const Host& operator[] (const int& index) const throw (std::out_of_range)
			{ return hosts.at(index); };

			const Host& operator[] (const std::string& name) const throw (std::out_of_range);

			const std::vector<Host>& getHosts() const { return hosts; };
	};
			

}			
		

#endif
