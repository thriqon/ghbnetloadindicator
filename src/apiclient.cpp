#include "apiclient.h"
#include "account_xml.h"
#include <libxml++/libxml++.h>

using namespace GHB;

const std::string APIHOSTPATH ("http://ghb.fh-furtwangen.de/api/call");

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

xmlpp::Element* callApi(const std::string& method, const std::string& key, xmlpp::DomParser& parser) throw (std::exception, std::runtime_error)
{
	std::string url = (APIHOSTPATH + "?method=" + method + "&key=" + key);
	parser.parse_file(url);

	const xmlpp::Document* doc = parser.get_document();
	xmlpp::Element* root = doc->get_root_node();

	xmlpp::Element* realroot = dynamic_cast<xmlpp::Element*> (root->get_children(method).front());

	std::string success = (dynamic_cast<xmlpp::Element*> (realroot->get_children("status").front()))->get_child_text()->get_content();
	if (success != "success")
	{
		throw std::runtime_error("method unsuccessfull: " + success);
	}

	return realroot;
}

void ApiClient::refresh()
{
	xmlpp::DomParser parser;
	xmlpp::Element* u = callApi("u", getApiKey(), parser);

	xmlpp::Element* h = callApi("h", getApiKey(), parser);
	if (acc != NULL) delete acc;
	acc = AccountXML::parseXML(h);

	initialized = true;	
}



