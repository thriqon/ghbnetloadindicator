#include "host_xml.h"

#include <stdlib.h>
using namespace GHB;

Host HostXML::parseXML(xmlpp::Element* elem)
{
	const std::string hostname = elem->get_attribute_value("hostname");
	const std::string mac = elem->get_attribute_value("mac");
	const int fwrule = atoi(elem->get_attribute_value("fwrule").c_str());
	const std::string fwrulename = elem->get_attribute_value("fwrulename");

	return Host(hostname, mac, fwrule, fwrulename);
}
	
