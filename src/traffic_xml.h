#include "traffic.h"
#include "host.h"
#include <libxml++/libxml++.h>

namespace GHB
{
	class TrafficDayXML
	{
		private:
			TrafficDayXML();
		public:
			static TrafficDay parseXML(xmlpp::Element* elem, const Account& acc);

			virtual ~TrafficDayXML();
	};
}
