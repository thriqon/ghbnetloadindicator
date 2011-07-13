#include "account_xml.h"
#include "host_xml.h"

using namespace GHB;

#include <string>
#include <vector>
#include <stdlib.h>


static const Glib::ustring useridstagname("userid");


/**
 * \param elem an element in a xml-tree. must be <h>
 * \return An Account
 */
Account* AccountXML::parseXML(xmlpp::Element* elem)
{
	const std::string userid = (dynamic_cast<xmlpp::Element*> (elem->get_children("userid").front()))->get_child_text()->get_content();

	const xmlpp::Element* hosts = dynamic_cast<xmlpp::Element*> (elem->get_children("hosts").front());

	const int maxAmountOfHosts = atoi(hosts->get_attribute_value("maxAmountOfHosts").c_str());

	std::vector<Host> vhosts;

	const xmlpp::Node::NodeList hostslines = hosts->get_children("host");
	for (xmlpp::Node::NodeList::const_iterator it = hostslines.begin(); it != hostslines.end(); it++)
	{
		vhosts.push_back(HostXML::parseXML(dynamic_cast<xmlpp::Element*> (*it)));
	}

	return new Account(userid, maxAmountOfHosts, vhosts);
}



