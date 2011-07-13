#ifndef USERINFO_XML_H
#define USERINFO_XML_H

#include "userinfo.h"
#include <libxml++/libxml++.h>

namespace GHB
{
	class UserInfoXML
	{
		private:
			UserInfoXML();
		public:
			UserInfo parseXML(xmlpp::Element* elem);
	};
}

#endif
