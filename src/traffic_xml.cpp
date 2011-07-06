#include "traffic_xml.h"
#include <string>
#include <stdlib.h>
using namespace GHB;

TrafficDay TrafficDayXML::parseXML(xmlpp::Element* elem, const Account& acc)
{
	std::string hostname = elem->get_attribute_value("hostname");

	Date date(atoi(elem->get_attribute_value("day").c_str()), atoi(elem->get_attribute_value("month").c_str()), atoi(elem->get_attribute_value("year").c_str()));

	uint64_t total = atoll(elem->get_attribute_value("total").c_str());

	return (TrafficDay(total, acc[hostname], date));
}

