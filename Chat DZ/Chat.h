#pragma once
#include<exception>
#include<vector>
#include<memory>
#include "Message.h"

struct UserLoginExp : public std::exception
{
	const char* what() const noexcept override
	{
		return "error: user login is busy";
	}
};

struct UserNameExp : public std::exception
{
	const char* what() const noexcept override
	{
		return "error: user name is busy";
	}
};

class Chat
{
public:
	void start();
	void showLoginMenu();
	void showUserMenu();
	bool isChatWork() const 
	{ 
		return isChatWork_;
	}
	std::shared_ptr<User> getCurrentUser() const
	{
		return currentUser_;
	}

private:
	bool isChatWork_ = false;
	std::vector<User> users_;
	std::vector<Message> messages_;
	std::shared_ptr<User> currentUser_ = nullptr;

	void login();
	void signUp();
	void showChat() const;
	void showAllUsersName() const;
	void addMessage();
	std::vector<User>& getAllUsers()
	{
		return users_;
	}
	std::vector<Message>& getAllMessages()
	{
		return messages_;
	}
	std::shared_ptr<User> getUserByLogin(const std::string& login) const;
	std::shared_ptr<User> getUserByName(const std::string& name) const;

};
