#include "account_xml.h"
#include <libxml++/libxml++.h>

#include <assert.h>

static const char* xmlstring =
"<h>"
" <status>success</status>"
" <userid>0101</userid>"
" <hosts maxAmountOfHosts=\"2\">"
"  <host hostname=\"host0\" mac=\"00:01:...\" fwrule=\"2\" fwrulename=\"Classic Server\"/>"
"  <host hostname=\"host1\" mac=\"00:02:...\" fwrule=\"4\" fwrulename=\"Unix/Linux Workstation\"/>"
" </hosts>"
"</h>";

int main()
{
	{
		xmlpp::DomParser parser; parser.parse_memory(xmlstring);
		xmlpp::Document* doc = parser.get_document();
		xmlpp::Element* elem = doc->get_root_node();

		GHB::Account acc = GHB::AccountXML::parseXML(elem);

		assert(acc.getUserid() == "0101");
		assert(acc.getMaxAmountOfHosts() == 2);
		assert(acc[0] == acc[0] && ! (acc[0] == acc[1])); // acc[0] is the same as itself, but not acc[1]
		assert(acc["host0"].getFWRule() == 2);
		
		try { const GHB::Host& ig = acc[123]; assert(false); }
		catch (std::out_of_range ex) 	{ assert(true); }
		catch (std::exception ex)	{ assert(false); }

		try { const GHB::Host& ig = acc["notexistent"]; assert(false); }
		catch (std::out_of_range ex) 	{ assert(true); }
		catch (std::exception ex)	{ assert(false); }
	}
	
}
	
