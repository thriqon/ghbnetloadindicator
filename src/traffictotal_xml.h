#ifndef TRAFFICTOTAL_XML_H
#define TRAFFICTOTAL_XML_H

#include "traffic.h"
#include "host.h"
#include <libxml++/libxml++.h>

namespace GHB
{
	class TrafficTotalXML : public TrafficTotal
	{
		private:
			TrafficTotalXML();
		public:
			static TrafficTotal parseXML(xmlpp::Element* elem, const Account& acc);

			virtual ~TrafficTotalXML() { };
	};
}

#endif
