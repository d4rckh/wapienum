#pragma once
#include <windows.h>
#include <Lmcons.h>
#include <iostream>
#include <string>

std::string get_username()
{
	char username[UNLEN + 1];
	DWORD username_len = UNLEN + 1;
	GetUserNameA(username, &username_len);
	return std::string(username);
}
