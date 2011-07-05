#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <iostream>
#include <unistd.h>
#include <panel-applet.h>
#include <gtk/gtk.h>
#include <stdlib.h>
#include <libxml++/libxml++.h>

#include "applet_gtk.h"
#include "api_client.h"

#define STANDARD_REFRESH_DELAY 600

using namespace std;

void parseConfigFile();
Glib::ustring findConfigFile();

PanelAppletGTK* mapplet;

ApiClient* api;

char apikey[MAX_API_KEY_LENGTH+1];
double maxTraffic = MAXTRAFFIC;
int uploadTimer = STANDARD_REFRESH_DELAY;

/*static const char context_menu_xml[] = 
	"<popup name=\"button3\"\n"
	" <menuitem name=\"Properties Item\" verb=\"GhbNetloadProperties\" label=\"_Preferences\" pixtype=\"stock\" pixname=\"gnome-stock-properties\"/>\n"
	" <menuitem name=\"About Item\" verb=\"GhbNetloadAbout\" label=\"_About\" pixtype=\"stock\" pixname=\"gnome-stock-about\" />\n"
	"</popup>\n";

static const BonoboUIVerb mymenu_verbs[] = {
	BONOBO_UI_VERB("GhbNetloadProperties", display_properties_dialog),
	BONOBO_UI_VERB("GhbNetloadAbout", display_about_dialog),
	BONOBO_UI_VERB_END};*/

void refresh(int sig)
{
	cout << "reloading...";
	api->refresh();
	
	mapplet->setCurSum(api->getWeekSum());
	mapplet->setSumThisDay(api->getThisDaySum());

	signal(SIGALRM, refresh);
	alarm(uploadTimer);
	cout << "..finished" << endl;
}


static gboolean applet_fill(PanelApplet *applet, const gchar* iid, gpointer data)
{
	apikey[0] = '\0';
	parseConfigFile();
	if (apikey[0] == '\0')
	{
		cerr << "no API-Key given. mandatory!" << endl;
	}
	api = new ApiClient(apikey, MAX_API_KEY_LENGTH);
	mapplet = new PanelAppletGTK(GTK_CONTAINER(applet));
	mapplet->setMaxSum(maxTraffic);
	refresh(0);
}


PANEL_APPLET_BONOBO_FACTORY ("OAFIID:GhbNetloadApplet_Factory", PANEL_TYPE_APPLET, "display the current netload", "0", applet_fill, NULL);


void parseConfigFile()
{
	Glib::ustring filename = findConfigFile();
	if (filename == "") return;

	xmlpp::DomParser parser(filename);
	xmlpp::Document* doc = parser.get_document();

	xmlpp::Element* root = doc->get_root_node();
	xmlpp::Node::NodeList entries = root->get_children();
	for (xmlpp::Node::NodeList::iterator it = entries.begin(); it != entries.end(); it++)
	{
		xmlpp::Element* elem = static_cast<xmlpp::Element*>(*it);
		const char* name = elem->get_name().c_str();

		cout << "name: " << name << endl;


		if (strcmp("key", name) == 0)
		{
			strncpy(apikey, elem->get_child_text()->get_content().c_str(), MAX_API_KEY_LENGTH);
		}
		if (strcmp("host", name) == 0)
		{
			cout << "host-selection not yet implemented" << endl;
		}
		if (strcmp("update", name) == 0)
		{
			uploadTimer = atoi(elem->get_child_text()->get_content().c_str());
		}
		if (strcmp("maxtraffic", name) == 0)
		{
			maxTraffic = atof(elem->get_child_text()->get_content().c_str());
		}
	}
}
		
Glib::ustring findConfigFile()
{
	Glib::ustring inHome;
	inHome = getenv("HOME");
	inHome += "/.ghbnetloadapplet.xml";
	
	printf("homeconf: %s\n", inHome.c_str());

	if (access(inHome.c_str(), R_OK) == 0)
		return inHome;

	if (access("./ghbnetloadapplet.xml", R_OK) == 0)
		return Glib::ustring("./ghbnetloadapplet.xml");

	return Glib::ustring();
}
