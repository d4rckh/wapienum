#pragma once

#include <windows.h>
#include <lmwksta.h>
#include <iostream>
#include <string>

int net_wkstagetinfo()
{
	WKSTA_INFO_100* buffer;
	NetWkstaGetInfo(NULL, 100, (LPBYTE*)&buffer);
	std::string computername = std::string(CW2A(buffer->wki100_computername));
	std::string langroup = std::string(CW2A(buffer->wki100_langroup));
	std::cout << "computername:" << computername << "\n";
	std::cout << "langroup:" << langroup << "\n";
	NetApiBufferFree(buffer);
	return 0;
}