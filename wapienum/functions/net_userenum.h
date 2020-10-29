#pragma once
#include <windows.h>
#include <lmaccess.h>
#include <lmapibuf.h>
#include <Sddl.h>
#include <stdio.h>
#include <string>
#include <atlstr.h>
#include <iostream>

int net_userenum()
{

    USER_INFO_0* buffer;
    DWORD entries;
    DWORD total_entries;
    DWORD resume_handle = 0;

    NetUserEnum(NULL,
        0,
        0,
        (BYTE**)&buffer,
        4096,
        &entries,
        &total_entries,
        &resume_handle);

    for (unsigned i = 0; i < entries; i++) {
        USER_INFO_23* info;
        NetUserGetInfo(NULL, buffer[i].usri0_name, 23, (LPBYTE*)&info);
        std::string username = std::string(CW2A(info->usri23_name));
        LPTSTR string_sid;
        ConvertSidToStringSid(info->usri23_user_sid, &string_sid);

        std::cout << username << ":" << string_sid << "\n";
        NetApiBufferFree(info);
    }
    NetApiBufferFree(buffer);
	return 0;
}