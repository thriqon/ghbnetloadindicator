#ifndef APICLIENT_H
#define APICLIENT_H

#include "host.h"
#include "traffic.h"

#include <string>
#include <exception>

namespace GHB
{
	class ApiClientNotInitialized : public std::exception
	{
		virtual const char* what() throw () { return "ApiClient was not initialized!"; };
	};

	class ApiClient
	{
		private:
			Account* acc;
			TrafficTotal* traffics;

			std::string apikey;
			bool initialized;


		public:
			Account& getAccount() throw (ApiClientNotInitialized);
			TrafficTotal& getTotal() throw  (ApiClientNotInitialized);

			ApiClient();
			ApiClient(const std::string& apikey);
			virtual ~ApiClient();

			void setApiKey (const std::string& newkey);
			const std::string& getApiKey() const;
			
			void refresh();
	};
}	

#endif
