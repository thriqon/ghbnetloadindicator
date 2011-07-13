#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "host.h"

#include <libxml++/libxml++.h>

namespace GHB
{
	/** \brief constructs an Account with XML-date */
	class AccountXML
	{
		private:
			AccountXML();
		public:
			/** \brief parses the XML and returns an Account object */
			static Account* parseXML(xmlpp::Element* elem);
	};
}

#endif
