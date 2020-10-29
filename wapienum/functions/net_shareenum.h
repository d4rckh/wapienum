#pragma once

#include <windows.h>
#include <lmshare.h>
#include <lmapibuf.h>
#include <Sddl.h>
#include <stdio.h>
#include <string>
#include <atlstr.h>
#include <iostream>


int net_shareenum ()
{
    SHARE_INFO_1* buffer;
    DWORD entries;
    DWORD total_entries;
    DWORD resume_handle = 0;
    //wchar_t wtext[20];
    //mbstowcs_s(wtext, (*SERVER_NAME).c_str(), (*SERVER_NAME).length());//includes null
    //LPWSTR ptr = wtext;

    NetShareEnum(NULL,
        1,
        (LPBYTE*)&buffer,
        MAX_PREFERRED_LENGTH,
        &entries,
        &total_entries,
        &resume_handle);


    for (unsigned i = 0; i < entries; i++) {
        std::string netname = std::string(CW2A(buffer[i].shi1_netname));
        std::string type; // = buffer[i].shi1_type;

        switch (buffer[i].shi1_type)
        {
            case 0x00000000:
                type = "DiskDrive";
                break;
            case 0x00000001:
                type = "PrintQueue";
                break;
            case 0x00000002:
                type = "CommunicationDevice";
                break;
            case 0x80000003: 
                // Not sure what's happening here. The docs say 0x00000003, but an actual IPC$ interface has type 0x8000003
                type = "InterprocessCommunication";
                break;
            case 0x80000000:
                type = "SpecialShare";
                break;
            case 0x40000000:
                type = "TemporaryShare";
                break;
            default:
                type = "No match.";
                break;
        }

        std::cout << netname << " (" << type << ") " << buffer[i].shi1_type << "\n";
    }
    NetApiBufferFree(buffer);

    return 0;
}