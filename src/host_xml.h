#ifndef HOSTXML_H
#define HOSTXML_H

#include "host.h"

#include <libxml++/libxml++.h>

namespace GHB
{
	class HostXML
	{
		private:
			HostXML();
		public:
			static Host parseXML(xmlpp::Element* elem);
	};
}

#endif
