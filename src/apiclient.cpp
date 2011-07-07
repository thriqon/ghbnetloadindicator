#include "apiclient.h"

using namespace GHB;

ApiClient::ApiClient() : acc(NULL), traffics(NULL), apikey(""), initialized(false)
{
}

ApiClient::ApiClient(const std::string& apikey) : acc(NULL), traffics(NULL), apikey(apikey), initialized(true)
{
	refresh();
}

Account& ApiClient::getAccount() throw (ApiClientNotInitialized)
{
	if (acc == NULL)
	{
		if (initialized)
		{	refresh(); } 
			else { throw ApiClientNotInitialized(); }
		}

	return *acc;
}

TrafficTotal& ApiClient::getTotal() throw (ApiClientNotInitialized)
{
	if (traffics == NULL)
	{
		if (initialized)
			refresh();
		else
			throw ApiClientNotInitialized();
	}
	return *traffics;
}

ApiClient::~ApiClient()
{
	if (acc != NULL) delete acc;
	if (traffics != NULL) delete traffics;
}

void ApiClient::setApiKey(const std::string& newkey)
{
	initialized = true;
	apikey = newkey;
}

const std::string& ApiClient::getApiKey() const {
	if (!initialized) throw ApiClientNotInitialized();

	return apikey;
}

void ApiClient::refresh()
{
};

