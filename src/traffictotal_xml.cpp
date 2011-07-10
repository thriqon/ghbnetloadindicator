#include "traffictotal_xml.h"
#include "traffic_xml.h"

using namespace GHB;

#include <list>

static const Glib::ustring subnodename("day");

TrafficTotal TrafficTotalXML::parseXML(xmlpp::Element* elem, const Account& acc)
{
	std::list<TrafficDay> traffics;
	xmlpp::Node::NodeList nodes = elem->get_children(subnodename);

	for (xmlpp::Node::NodeList::const_iterator it = nodes.begin(); it != nodes.end(); it++)
	{
		traffics.push_back(TrafficDayXML::parseXML((xmlpp::Element*) *it, acc));
	}

	return TrafficTotal(traffics);
}

