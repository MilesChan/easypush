// stdafx.cpp : source file that includes just the standard includes
// ConsoleApplication1.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"
#include <Windows.h>

// TODO: reference any additional headers you need in STDAFX.H
// and not in this file
#pragma comment(lib,"ws2_32.lib")

#ifdef _DEBUG
#pragma comment(lib,"../Debug/libevent.lib")
#else
#pragma comment(lib,"../Release/libevent.lib")
#endif

boolean WSAInit();

boolean g_bWSAInited = WSAInit();

boolean WSAInit() {
	WORD  request;
	WSADATA  ws;
	request = MAKEWORD(2,2);
	int err = WSAStartup(request,&ws);
	if(err != 0) {
		return false;
	}
	if(LOBYTE(ws.wVersion) != 2||HIBYTE(ws.wVersion) != 2) {
		WSACleanup(); 
		return false;
	}
	return true;
}
