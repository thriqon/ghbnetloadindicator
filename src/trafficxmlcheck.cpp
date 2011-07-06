#include "traffic_xml.h"
#include <libxml++/libxml++.h>
#include <assert.h>

static const char* const xmlteststrings[] = { "<day total=\"100\" host_id=\"1\" hostname=\"host0\" day=\"04\" month=\"07\" year=\"2011\" DATE=\"04.07.2011\"/>" };


int main()
{
	GHB::Host h0("host0", "00:00:...", 0, "open house");
	std::vector<GHB::Host> hosts;
	hosts.push_back(h0);
	GHB::Account acc("morpheus", 10, hosts);


	{ // Test 1
		xmlpp::DomParser parser;
		parser.parse_memory(xmlteststrings[0]);
		xmlpp::Document* doc = parser.get_document();
		xmlpp::Element* root = doc->get_root_node();
		
		GHB::TrafficDay day = GHB::TrafficDayXML::parseXML(root, acc);

		assert(day.getTotal() == 100);
		assert(day.getHost().getHostname() == "host0");
		assert(day.getDate().getDay() == 4);
		assert(day.getDate().getMonth() == 7);
		assert(day.getDate().getYear() == 2011);
	}
}

