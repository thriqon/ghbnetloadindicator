#include "host_xml.h"

#include <assert.h>

static const char* hostlines[] = {
"<host hostname=\"host0\" mac=\"00:01:...\" fwrule=\"2\" fwrulename=\"Classic Server\"/>",
};

int main()
{
	{
		xmlpp::DomParser parser; parser.parse_memory(hostlines[0]);
		xmlpp::Document* doc = parser.get_document();
		xmlpp::Element* root = doc->get_root_node();

		GHB::Host h0 = GHB::HostXML::parseXML(root);

		assert(h0.getHostname() == "host0");
		assert(h0.getMac() == "00:01:...");
		assert(h0.getFWRule() == 2);
		assert(h0.getFWRuleName() == "Classic Server");
	}
}

	
