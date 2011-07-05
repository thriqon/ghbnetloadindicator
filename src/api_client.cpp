#include "api_client.h"

#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <libxml++/libxml++.h>

ApiClient::ApiClient(char* apikey, int length)
{
	strncpy(mapikey, apikey, (length > MAX_API_KEY_LENGTH ?  length : MAX_API_KEY_LENGTH));
}

void ApiClient::formatDate(char buf[11])
{
	time_t now;
	now = time(NULL);

	struct tm time_v;
	localtime_r(&now, &time_v);

	snprintf(buf, 11, "%02i.%02i.%i", time_v.tm_mday, time_v.tm_mon+1, time_v.tm_year+1900); // 1900&+1: man localtime
}

void ApiClient::refresh()
{
	weekSum = 0;

	xmlpp::DomParser parser(Glib::ustring("http://ghb.fh-furtwangen.de/api/call?method=t&key=") + Glib::ustring(mapikey));

	xmlpp::Document* doc;
	doc = parser.get_document();
	xmlpp::NodeSet summarychilds = doc->get_root_node()->find("t/summary/*");

	char datebuf[11]; formatDate(datebuf); 
	
	thisDaySum = -1;
	char xmldate[11];
	for (xmlpp::NodeSet::iterator it = summarychilds.begin(); it != summarychilds.end(); it++)
	{

		xmlpp::Element* elem = static_cast<xmlpp::Element*> (*it);
		
		strcpy(xmldate,  elem->get_attribute_value("DATE").c_str());
		double load = atof(elem->get_attribute_value("total").c_str()) / (1024 * 1024);
		if (strcmp(xmldate, datebuf) == 0)
		{
			thisDaySum = load;
		}
		weekSum += load;
	}

		
}

