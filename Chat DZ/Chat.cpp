#include<iostream>
#include "Chat.h"

void Chat::start()
{
	isChatWork_ = true;
}

void Chat::showLoginMenu()
{
	currentUser_ = nullptr;
	char operation;

	do
	{
		std::cout << "(1)Login" << std::endl;
		std::cout << "(2)SignUp" << std::endl;
		std::cout << "(0)Shutdown" << std::endl;
		std::cin >> operation;

		switch (operation)
		{
		case '1':
			login();
			break;
		case '2':
			try
			{
				signUp();
			}
			catch (const std::exception &e)
			{
				std::cout << e.what() << std::endl;
			}
			break;
		case '0':
			isChatWork_ = false;
			break;
		default:
			std::cout << "1 or 2..." << std::endl;
			break;
		}
	} while (!currentUser_ && isChatWork_);
}

void Chat::login()
{
	std::string login, password;
	char operation;

	do
	{
		std::cout << "login: ";
		std::cin >> login;
		std::cout << "password: ";
		std::cin >> password;

		currentUser_ = getUserByLogin(login);

		if (currentUser_ == nullptr || (password != currentUser_->getUserPassword()))
		{
			currentUser_ = nullptr;

			std::cout << "login failed..." << std::endl;
			std::cout << "(0)exit or (any key)repeat: ";
			std::cin >> operation;

			if (operation == '0')
				break;
		}
	} while (!currentUser_);
}

void Chat::signUp()
{
	std::string login, password, name;

	std::cout << "login: ";
	std::cin >> login;
	std::cout << "password: ";
	std::cin >> password;
	std::cout << "name: ";
	std::cin >> name;

	if (getUserByLogin(login) || login == "all")
	{
		throw UserLoginExp();
	}
	if (getUserByName(name) || name == "all")
	{
		throw UserNameExp();
	}

	User user = User(login, password, name);
	users_.push_back(user);
	currentUser_ = std::make_shared<User>(user);
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

std::shared_ptr<User> Chat::getUserByName(const std::string& name) const
{
	for (auto& user : users_)
	{
		if (name == user.getUserName())
		{
			return std::make_shared<User>(user);
		}
	}
	return nullptr;
}

