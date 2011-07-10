#include "traffictotal_xml.h"
#include "traffic_xml.h"
#include <libxml++/libxml++.h>
#include <assert.h>

static const char* const xmlteststrings[] = { 
"<summary>"
"<day total=\"500\" host_id=\"1\" hostname=\"host0\" day=\"02\" month=\"07\" year=\"2011\" DATE=\"02.07.2011\"/>"
"<day total=\"200\" host_id=\"1\" hostname=\"host0\" day=\"03\" month=\"07\" year=\"2011\" DATE=\"03.07.2011\"/>"
"<day total=\"100\" host_id=\"1\" hostname=\"host0\" day=\"04\" month=\"07\" year=\"2011\" DATE=\"04.07.2011\"/>"
"<day total=\"150\" host_id=\"2\" hostname=\"host1\" day=\"04\" month=\"07\" year=\"2011\" DATE=\"04.07.2011\"/>"
"<day total=\"250\" host_id=\"2\" hostname=\"host1\" day=\"05\" month=\"07\" year=\"2011\" DATE=\"05.07.2011\"/>"
"</summary>"
 };


int main()
{
	GHB::Host h0("host0", "00:00:...", 0, "open house");
	GHB::Host h1("host1", "00:01:...", 0, "open house");
	std::vector<GHB::Host> hosts;
	hosts.push_back(h0);
	hosts.push_back(h1);
	GHB::Account acc("morpheus", 10, hosts);


	{ // Test 1
		xmlpp::DomParser parser;
		parser.parse_memory(xmlteststrings[0]);
		xmlpp::Document* doc = parser.get_document();
		xmlpp::Element* root = doc->get_root_node();
	
		GHB::TrafficTotal total = GHB::TrafficTotalXML::parseXML(root, acc);
			
		assert(total.getTotal() == 1200);
		assert(total.getTotalByHost(h0) == 800 && total.getTotalByHost(h1) == 400);
		{
			GHB::Date d04072011(4, 7, 2011);
			assert(total.getTotalByDate(d04072011) == 250);
			
			GHB::Date d05072011(5, 7, 2011);
			assert(total.getTotalByDate(d05072011) == 250);
		}


	}
}

