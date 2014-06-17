// stdafx.cpp : source file that includes just the standard includes
// ConsoleApplication1.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"
#include <Windows.h>

// TODO: reference any additional headers you need in STDAFX.H
// and not in this file
#pragma comment(lib,"ws2_32.lib")

#ifndef _DLL
#ifdef _DEBUG
#pragma comment(lib,"libevent\\MTd\\libevent.lib")
#pragma comment(lib,"libevent\\MTd\\libevent_core.lib")
#pragma comment(lib,"libevent\\MTd\\libevent_extras.lib")
#else
#pragma comment(lib,"libevent\\MT\\libevent.lib")
#pragma comment(lib,"libevent\\MT\\libevent_core.lib")
#pragma comment(lib,"libevent\\MT\\libevent_extras.lib")
#endif
#else
#ifdef _DEBUG
#pragma comment(lib,"libevent\\MDd\\libevent.lib")
#pragma comment(lib,"libevent\\MDd\\libevent_core.lib")
#pragma comment(lib,"libevent\\MDd\\libevent_extras.lib")
#else
#pragma comment(lib,"libevent\\MD\\libevent.lib")
#pragma comment(lib,"libevent\\MD\\libevent_core.lib")
#pragma comment(lib,"libevent\\MD\\libevent_extras.lib")
#endif
#endif

boolean WSAInit();

boolean g_bWSAInited = WSAInit();

boolean WSAInit() {
	WORD  request;
	WSADATA  ws;
	request = MAKEWORD(1,1);
	int err = WSAStartup(request,&ws);
	if(err != 0) {
		return false;
	}
	if(LOBYTE(ws.wVersion) != 1||HIBYTE(ws.wVersion) != 1) {
		WSACleanup(); 
		return false;
	}
	return true;
}
