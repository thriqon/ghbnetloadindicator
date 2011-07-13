
#include "userinfo_xml.h"

using namespace GHB;

UserInfo UserInfoXML::parseXML(xmlpp::Element* elem)
{
	std::string id = elem->get_attribute_value("id");
	std::string name = elem->get_attribute_value("name");
	std::string room = elem->get_attribute_value("room");
	std::string email = elem->get_attribute_value("email");


	return UserInfo(id,name,room,email);
}

