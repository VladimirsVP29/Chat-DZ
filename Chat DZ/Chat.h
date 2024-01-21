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