#include<iostream>
#include "Chat.h"

void Chat::start()
{
	isChatWork_ = true;
}

std::shared_ptr<User> Chat::getUserByLogin(const std::string& login) const
{
	for (auto &user : users_)
	{
		if (login == user.getUserLogin())
		{
			return std::make_shared<User>(user);
		}
	}
	return nullptr;
}
