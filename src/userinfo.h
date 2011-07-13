#ifndef USERINFO_H
#define USERINFO_H

#include <string>

namespace GHB
{
	class UserInfo
	{
		private:
			std::string id;
			std::string name;
			std::string room;
			std::string email;
		public:
			UserInfo(const std::string& id, const std::string& name,const std::string& room, const std::string& email)
				: id(id), name(name), room(room), email(email) { };

			const std::string& getId()	{ return id; };
			const std::string& getName()	{ return name; };
			const std::string& getRoom()	{ return room; };
			const std::string& getEmail()	{ return email; };


	};
}

#endif
