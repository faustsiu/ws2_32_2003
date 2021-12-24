// dllmain.cpp : 定義 DLL 應用程式的進入點。
#include "stdafx.h"

#pragma pack(1)



#define HOOK_BIND 0x00
#define HOOK_SEND 0x01
#define HOOK_RECV 0x02
#define MAXHOOKFUNC 0x03
#pragma data_seg (".ws2_hookdata")
FARPROC hook_callout[MAXHOOKFUNC] = {NULL, NULL, NULL};
#pragma data_seg()

#define MAXPROC 500
HINSTANCE hLThis = 0;
HINSTANCE hLMod = 0;
HMODULE hL = 0;
FARPROC ws2_32proc[MAXPROC];

// Hook 

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:

		hLThis = hModule;
		hL = LoadLibrary("ws2_2003.dll");
		hLMod = GetModuleHandle(0);
		if (!hL) return false;

		ws2_32proc[1-1] = GetProcAddress(hL,"accept"); 
		ws2_32proc[2-1] = GetProcAddress(hL,"bind"); 
		ws2_32proc[3-1] = GetProcAddress(hL,"closesocket"); 
		ws2_32proc[4-1] = GetProcAddress(hL,"connect"); 
		ws2_32proc[5-1] = GetProcAddress(hL,"getpeername"); 
		ws2_32proc[6-1] = GetProcAddress(hL,"getsockname"); 
		ws2_32proc[7-1] = GetProcAddress(hL,"getsockopt"); 
		ws2_32proc[8-1] = GetProcAddress(hL,"htonl"); 
		ws2_32proc[9-1] = GetProcAddress(hL,"htons"); 
		ws2_32proc[10-1] = GetProcAddress(hL,"ioctlsocket"); 
		ws2_32proc[11-1] = GetProcAddress(hL,"inet_addr"); 
		ws2_32proc[12-1] = GetProcAddress(hL,"inet_ntoa"); 
		ws2_32proc[13-1] = GetProcAddress(hL,"listen"); 
		ws2_32proc[14-1] = GetProcAddress(hL,"ntohl"); 
		ws2_32proc[15-1] = GetProcAddress(hL,"ntohs"); 
		ws2_32proc[16-1] = GetProcAddress(hL,"recv"); 
		ws2_32proc[17-1] = GetProcAddress(hL,"recvfrom"); 
		ws2_32proc[18-1] = GetProcAddress(hL,"select"); 
		ws2_32proc[19-1] = GetProcAddress(hL,"send"); 
		ws2_32proc[20-1] = GetProcAddress(hL,"sendto"); 
		ws2_32proc[21-1] = GetProcAddress(hL,"setsockopt"); 
		ws2_32proc[22-1] = GetProcAddress(hL,"shutdown"); 
		ws2_32proc[23-1] = GetProcAddress(hL,"socket"); 
		ws2_32proc[24-1] = GetProcAddress(hL,"WSApSetPostRoutine"); 
		ws2_32proc[25-1] = GetProcAddress(hL,"FreeAddrInfoW"); 
		ws2_32proc[26-1] = GetProcAddress(hL,"GetAddrInfoW"); 
		ws2_32proc[27-1] = GetProcAddress(hL,"GetNameInfoW"); 
		ws2_32proc[28-1] = GetProcAddress(hL,"WPUCompleteOverlappedRequest"); 
		ws2_32proc[29-1] = GetProcAddress(hL,"WSAAccept"); 
		ws2_32proc[30-1] = GetProcAddress(hL,"WSAAddressToStringA"); 
		ws2_32proc[31-1] = GetProcAddress(hL,"WSAAddressToStringW"); 
		ws2_32proc[32-1] = GetProcAddress(hL,"WSACloseEvent"); 
		ws2_32proc[33-1] = GetProcAddress(hL,"WSAConnect"); 
		ws2_32proc[34-1] = GetProcAddress(hL,"WSACreateEvent"); 
		ws2_32proc[35-1] = GetProcAddress(hL,"WSADuplicateSocketA"); 
		ws2_32proc[36-1] = GetProcAddress(hL,"WSADuplicateSocketW"); 
		ws2_32proc[37-1] = GetProcAddress(hL,"WSAEnumNameSpaceProvidersA"); 
		ws2_32proc[38-1] = GetProcAddress(hL,"WSAEnumNameSpaceProvidersW"); 
		ws2_32proc[39-1] = GetProcAddress(hL,"WSAEnumNetworkEvents"); 
		ws2_32proc[40-1] = GetProcAddress(hL,"WSAEnumProtocolsA"); 
		ws2_32proc[41-1] = GetProcAddress(hL,"WSAEnumProtocolsW"); 
		ws2_32proc[42-1] = GetProcAddress(hL,"WSAEventSelect"); 
		ws2_32proc[43-1] = GetProcAddress(hL,"WSAGetOverlappedResult"); 
		ws2_32proc[44-1] = GetProcAddress(hL,"WSAGetQOSByName"); 
		ws2_32proc[45-1] = GetProcAddress(hL,"WSAGetServiceClassInfoA"); 
		ws2_32proc[46-1] = GetProcAddress(hL,"WSAGetServiceClassInfoW"); 
		ws2_32proc[47-1] = GetProcAddress(hL,"WSAGetServiceClassNameByClassIdA"); 
		ws2_32proc[48-1] = GetProcAddress(hL,"WSAGetServiceClassNameByClassIdW"); 
		ws2_32proc[49-1] = GetProcAddress(hL,"WSAHtonl"); 
		ws2_32proc[50-1] = GetProcAddress(hL,"WSAHtons"); 
		ws2_32proc[51-1] = GetProcAddress(hL,"gethostbyaddr"); 
		ws2_32proc[52-1] = GetProcAddress(hL,"gethostbyname"); 
		ws2_32proc[53-1] = GetProcAddress(hL,"getprotobyname"); 
		ws2_32proc[54-1] = GetProcAddress(hL,"getprotobynumber"); 
		ws2_32proc[55-1] = GetProcAddress(hL,"getservbyname"); 
		ws2_32proc[56-1] = GetProcAddress(hL,"getservbyport"); 
		ws2_32proc[57-1] = GetProcAddress(hL,"gethostname"); 
		ws2_32proc[58-1] = GetProcAddress(hL,"WSAInstallServiceClassA"); 
		ws2_32proc[59-1] = GetProcAddress(hL,"WSAInstallServiceClassW"); 
		ws2_32proc[60-1] = GetProcAddress(hL,"WSAIoctl"); 
		ws2_32proc[61-1] = GetProcAddress(hL,"WSAJoinLeaf"); 
		ws2_32proc[62-1] = GetProcAddress(hL,"WSALookupServiceBeginA"); 
		ws2_32proc[63-1] = GetProcAddress(hL,"WSALookupServiceBeginW"); 
		ws2_32proc[64-1] = GetProcAddress(hL,"WSALookupServiceEnd"); 
		ws2_32proc[65-1] = GetProcAddress(hL,"WSALookupServiceNextA"); 
		ws2_32proc[66-1] = GetProcAddress(hL,"WSALookupServiceNextW"); 
		ws2_32proc[67-1] = GetProcAddress(hL,"WSANSPIoctl"); 
		ws2_32proc[68-1] = GetProcAddress(hL,"WSANtohl"); 
		ws2_32proc[69-1] = GetProcAddress(hL,"WSANtohs"); 
		ws2_32proc[70-1] = GetProcAddress(hL,"WSAProviderConfigChange"); 
		ws2_32proc[71-1] = GetProcAddress(hL,"WSARecv"); 
		ws2_32proc[72-1] = GetProcAddress(hL,"WSARecvDisconnect"); 
		ws2_32proc[73-1] = GetProcAddress(hL,"WSARecvFrom"); 
		ws2_32proc[74-1] = GetProcAddress(hL,"WSARemoveServiceClass"); 
		ws2_32proc[75-1] = GetProcAddress(hL,"WSAResetEvent"); 
		ws2_32proc[76-1] = GetProcAddress(hL,"WSASend"); 
		ws2_32proc[77-1] = GetProcAddress(hL,"WSASendDisconnect"); 
		ws2_32proc[78-1] = GetProcAddress(hL,"WSASendTo"); 
		ws2_32proc[79-1] = GetProcAddress(hL,"WSASetEvent"); 
		ws2_32proc[80-1] = GetProcAddress(hL,"WSASetServiceA"); 
		ws2_32proc[81-1] = GetProcAddress(hL,"WSASetServiceW"); 
		ws2_32proc[82-1] = GetProcAddress(hL,"WSASocketA"); 
		ws2_32proc[83-1] = GetProcAddress(hL,"WSASocketW"); 
		ws2_32proc[84-1] = GetProcAddress(hL,"WSAStringToAddressA"); 
		ws2_32proc[85-1] = GetProcAddress(hL,"WSAStringToAddressW"); 
		ws2_32proc[86-1] = GetProcAddress(hL,"WSAWaitForMultipleEvents"); 
		ws2_32proc[87-1] = GetProcAddress(hL,"WSCDeinstallProvider"); 
		ws2_32proc[88-1] = GetProcAddress(hL,"WSCEnableNSProvider"); 
		ws2_32proc[89-1] = GetProcAddress(hL,"WSCEnumProtocols"); 
		ws2_32proc[90-1] = GetProcAddress(hL,"WSCGetProviderPath"); 
		ws2_32proc[91-1] = GetProcAddress(hL,"WSCInstallNameSpace"); 
		ws2_32proc[92-1] = GetProcAddress(hL,"WSCInstallProvider"); 
		ws2_32proc[93-1] = GetProcAddress(hL,"WSCUnInstallNameSpace"); 
		ws2_32proc[94-1] = GetProcAddress(hL,"WSCUpdateProvider"); 
		ws2_32proc[95-1] = GetProcAddress(hL,"WSCWriteNameSpaceOrder"); 
		ws2_32proc[96-1] = GetProcAddress(hL,"WSCWriteProviderOrder"); 
		ws2_32proc[97-1] = GetProcAddress(hL,"freeaddrinfo"); 
		ws2_32proc[98-1] = GetProcAddress(hL,"getaddrinfo"); 
		ws2_32proc[99-1] = GetProcAddress(hL,"getnameinfo"); 
		ws2_32proc[101-1] = GetProcAddress(hL,"WSAAsyncSelect"); 
		ws2_32proc[102-1] = GetProcAddress(hL,"WSAAsyncGetHostByAddr"); 
		ws2_32proc[103-1] = GetProcAddress(hL,"WSAAsyncGetHostByName"); 
		ws2_32proc[104-1] = GetProcAddress(hL,"WSAAsyncGetProtoByNumber"); 
		ws2_32proc[105-1] = GetProcAddress(hL,"WSAAsyncGetProtoByName"); 
		ws2_32proc[106-1] = GetProcAddress(hL,"WSAAsyncGetServByPort"); 
		ws2_32proc[107-1] = GetProcAddress(hL,"WSAAsyncGetServByName"); 
		ws2_32proc[108-1] = GetProcAddress(hL,"WSACancelAsyncRequest"); 
		ws2_32proc[109-1] = GetProcAddress(hL,"WSASetBlockingHook"); 
		ws2_32proc[110-1] = GetProcAddress(hL,"WSAUnhookBlockingHook"); 
		ws2_32proc[111-1] = GetProcAddress(hL,"WSAGetLastError"); 
		ws2_32proc[112-1] = GetProcAddress(hL,"WSASetLastError"); 
		ws2_32proc[113-1] = GetProcAddress(hL,"WSACancelBlockingCall"); 
		ws2_32proc[114-1] = GetProcAddress(hL,"WSAIsBlocking"); 
		ws2_32proc[115-1] = GetProcAddress(hL,"WSAStartup"); 
		ws2_32proc[116-1] = GetProcAddress(hL,"WSACleanup"); 
		ws2_32proc[151-1] = GetProcAddress(hL,"__WSAFDIsSet"); 
		ws2_32proc[500-1] = GetProcAddress(hL,"WEP"); 
		break;

	case DLL_THREAD_ATTACH:
		break;

	case DLL_THREAD_DETACH:
		break;
	
	case DLL_PROCESS_DETACH:
		FreeLibrary(hL);
		break;
	}

	return TRUE;
}

extern "C" void __stdcall __hook_bind (FARPROC FuncAddress)
{
	hook_callout[HOOK_BIND] = FuncAddress;
}

extern "C" void __stdcall __hook_send (FARPROC FuncAddress)
{
	hook_callout[HOOK_SEND] = FuncAddress;
}

extern "C" void __stdcall __hook_recv (FARPROC FuncAddress)
{
	hook_callout[HOOK_RECV] = FuncAddress;
}

extern "C" __declspec(naked) void __stdcall  __bind () 
{
	if (hook_callout[HOOK_BIND] != NULL) 
		__asm jmp hook_callout[HOOK_BIND * 4] 
	else 
		__asm jmp ws2_32proc[(2-1)*4] 
}

extern "C" __declspec(naked) void __stdcall  __send () 
{ 
	if (hook_callout[HOOK_SEND] != NULL) 
		__asm jmp hook_callout[HOOK_SEND * 4] 
	else 
		__asm jmp ws2_32proc[(19-1)*4] 
}

extern "C" __declspec(naked) void __stdcall  __recv () 
{
	if (hook_callout[HOOK_RECV] != NULL) 
		__asm jmp hook_callout[HOOK_RECV * 4] 
	else 
		__asm jmp ws2_32proc[(16-1)*4] 
}

extern "C" __declspec(naked) void __stdcall  __accept                           ()
{ __asm {
	nop; 
	jmp ws2_32proc[(1-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __closesocket                      () 
{ __asm {
	nop; 
	jmp ws2_32proc[(3-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __connect                          () 
{ __asm {
	nop; 
	jmp ws2_32proc[(4-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __getpeername                      () 
{ __asm {
	nop; 
	jmp ws2_32proc[(5-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __getsockname                      () 
{ __asm {
	nop; 
	jmp ws2_32proc[(6-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __getsockopt                       () 
{ __asm {
	nop; 
	jmp ws2_32proc[(7-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __htonl                            () 
{ __asm {
	nop; 
	jmp ws2_32proc[(8-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __htons                            () 
{ __asm {
	nop; 
	jmp ws2_32proc[(9-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __ioctlsocket                      () 
{ __asm {
	nop; 
	jmp ws2_32proc[(10-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __inet_addr                        () 
{ __asm {
	nop; 
	jmp ws2_32proc[(11-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __inet_ntoa                        () 
{ __asm {
	nop; 
	jmp ws2_32proc[(12-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __listen                           () 
{ __asm {
	nop; 
	jmp ws2_32proc[(13-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __ntohl                            () 
{ __asm {
	nop; 
	jmp ws2_32proc[(14-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __ntohs                            () 
{ __asm {
	nop; 
	jmp ws2_32proc[(15-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __recvfrom                         () 
{ __asm {
	nop; 
	jmp ws2_32proc[(17-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __select                           () 
{ __asm {
	nop; 
	jmp ws2_32proc[(18-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __sendto                           () 
{ __asm {
	nop; 
	jmp ws2_32proc[(20-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __setsockopt                       () 
{ __asm {
	nop; 
	jmp ws2_32proc[(21-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __shutdown                         () 
{ __asm {
	nop; 
	jmp ws2_32proc[(22-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __socket                           () { __asm {nop; 
jmp ws2_32proc[(23-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSApSetPostRoutine               () { __asm {nop; 
jmp ws2_32proc[(24-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __FreeAddrInfoW                    () { __asm {nop; 
jmp ws2_32proc[(25-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __GetAddrInfoW                     () { __asm {nop; 
jmp ws2_32proc[(26-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __GetNameInfoW                     () { __asm {nop; 
jmp ws2_32proc[(27-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WPUCompleteOverlappedRequest     () { __asm {nop; 
jmp ws2_32proc[(28-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSAAccept                        () { __asm {nop; 
jmp ws2_32proc[(29-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSAAddressToStringA              () { __asm {nop; 
jmp ws2_32proc[(30-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSAAddressToStringW              () { __asm {nop; 
jmp ws2_32proc[(31-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSACloseEvent                    () { __asm {nop; 
jmp ws2_32proc[(32-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSAConnect                       () { __asm {nop; 
jmp ws2_32proc[(33-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSACreateEvent                   () { __asm {nop; 
jmp ws2_32proc[(34-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSADuplicateSocketA              () { __asm {nop; 
jmp ws2_32proc[(35-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSADuplicateSocketW              () { __asm {nop; 
jmp ws2_32proc[(36-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSAEnumNameSpaceProvidersA       () { __asm {nop; 
jmp ws2_32proc[(37-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSAEnumNameSpaceProvidersW       () { __asm {nop; 
jmp ws2_32proc[(38-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSAEnumNetworkEvents             () { __asm {nop; 
jmp ws2_32proc[(39-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSAEnumProtocolsA                () { __asm {nop; 
jmp ws2_32proc[(40-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSAEnumProtocolsW                () { __asm {nop; 
jmp ws2_32proc[(41-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSAEventSelect                   () { __asm {nop; 
jmp ws2_32proc[(42-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSAGetOverlappedResult           () { __asm {nop; 
jmp ws2_32proc[(43-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSAGetQOSByName                  () { __asm {nop; 
jmp ws2_32proc[(44-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSAGetServiceClassInfoA          () { __asm {nop; 
jmp ws2_32proc[(45-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSAGetServiceClassInfoW          () { __asm {nop; 
jmp ws2_32proc[(46-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSAGetServiceClassNameByClassIdA () { __asm {nop; 
jmp ws2_32proc[(47-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSAGetServiceClassNameByClassIdW () { __asm {nop; 
jmp ws2_32proc[(48-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSAHtonl                         () { __asm {nop; 
jmp ws2_32proc[(49-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSAHtons                         () { __asm {nop; 
jmp ws2_32proc[(50-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __gethostbyaddr                    () { __asm {nop; 
jmp ws2_32proc[(51-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __gethostbyname                    () { __asm {nop; 
jmp ws2_32proc[(52-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __getprotobyname                   () { __asm {nop; 
jmp ws2_32proc[(53-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __getprotobynumber                 () { __asm {nop; 
jmp ws2_32proc[(54-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __getservbyname                    () { __asm {nop; 
jmp ws2_32proc[(55-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __getservbyport                    () { __asm {nop; 
jmp ws2_32proc[(56-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __gethostname                      () { __asm {nop; 
jmp ws2_32proc[(57-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSAInstallServiceClassA          () { __asm {nop; 
jmp ws2_32proc[(58-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSAInstallServiceClassW          () { __asm {nop; 
jmp ws2_32proc[(59-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSAIoctl                         () { __asm {nop; 
jmp ws2_32proc[(60-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSAJoinLeaf                      () { __asm {nop; 
jmp ws2_32proc[(61-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSALookupServiceBeginA           () { __asm {nop; 
jmp ws2_32proc[(62-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSALookupServiceBeginW           () { __asm {nop; 
jmp ws2_32proc[(63-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSALookupServiceEnd              () { __asm {nop; 
jmp ws2_32proc[(64-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSALookupServiceNextA            () { __asm {nop; 
jmp ws2_32proc[(65-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSALookupServiceNextW            () { __asm {nop; 
jmp ws2_32proc[(66-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSANSPIoctl                      () { __asm {nop; 
jmp ws2_32proc[(67-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSANtohl                         () { __asm {nop; 
jmp ws2_32proc[(68-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSANtohs                         () 
{ __asm {
	nop; 
	jmp ws2_32proc[(69-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSAProviderConfigChange          () 
{ __asm {
	nop; 
	jmp ws2_32proc[(70-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSARecv                          () 
{ __asm {
	nop; 
	jmp ws2_32proc[(71-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSARecvDisconnect                () 
{ __asm {
	nop; 
	jmp ws2_32proc[(72-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSARecvFrom                      () 
{ __asm {
	nop; 
	jmp ws2_32proc[(73-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSARemoveServiceClass            () 
{ __asm {
	nop; 
	jmp ws2_32proc[(74-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSAResetEvent                    () 
{ __asm {
	nop; 
	jmp ws2_32proc[(75-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSASend                          () 
{ __asm {
	nop; 
	jmp ws2_32proc[(76-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSASendDisconnect                () 
{ __asm {
	nop; 
	jmp ws2_32proc[(77-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSASendTo                        () 
{ __asm {
	nop; 
	jmp ws2_32proc[(78-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSASetEvent                      () 
{ __asm {
	nop; 
	jmp ws2_32proc[(79-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSASetServiceA                   () 
{ __asm {
	nop; 
	jmp ws2_32proc[(80-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSASetServiceW                   () 
{ __asm {
	nop; 
	jmp ws2_32proc[(81-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSASocketA                       () 
{ __asm {
	nop; 
	jmp ws2_32proc[(82-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSASocketW                       () 
{ __asm {
	nop; 
	jmp ws2_32proc[(83-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSAStringToAddressA              () 
{ __asm {
	nop; 
	jmp ws2_32proc[(84-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSAStringToAddressW              () 
{ __asm {
	nop; 
	jmp ws2_32proc[(85-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSAWaitForMultipleEvents         () 
{ __asm {
	nop; 
	jmp ws2_32proc[(86-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSCDeinstallProvider             () 
{ __asm {
	nop; 
	jmp ws2_32proc[(87-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSCEnableNSProvider              () 
{ __asm {
	nop; 
	jmp ws2_32proc[(88-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSCEnumProtocols                 () 
{ __asm {
	nop; 
	jmp ws2_32proc[(89-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSCGetProviderPath               () 
{ __asm {
	nop; 
	jmp ws2_32proc[(90-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSCInstallNameSpace              () 
{ __asm {
	nop; 
	jmp ws2_32proc[(91-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSCInstallProvider               () 
{ __asm {
	nop; 
	jmp ws2_32proc[(92-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSCUnInstallNameSpace            () 
{ __asm {
	nop; 
	jmp ws2_32proc[(93-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSCUpdateProvider                () 
{ __asm {
	nop; 
	jmp ws2_32proc[(94-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSCWriteNameSpaceOrder           () 
{ __asm {
	nop; 
	jmp ws2_32proc[(95-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSCWriteProviderOrder            () 
{ __asm {
	nop; 
	jmp ws2_32proc[(96-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __freeaddrinfo                     () 
{ __asm {
	nop; 
	jmp ws2_32proc[(97-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __getaddrinfo                      () 
{ __asm {
	nop; 
	jmp ws2_32proc[(98-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __getnameinfo                      () 
{ __asm {
	nop; 
	jmp ws2_32proc[(99-1)*4];
}}
extern "C" __declspec(naked) void __stdcall  __WSAAsyncSelect                   () 
{ __asm {
	nop; 
	jmp ws2_32proc[(101-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSAAsyncGetHostByAddr            () 
{ __asm {
	nop; 
	jmp ws2_32proc[(102-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSAAsyncGetHostByName            () 
{ __asm {
	nop; 
	jmp ws2_32proc[(103-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSAAsyncGetProtoByNumber         () 
{ __asm {
	nop; 
	jmp ws2_32proc[(104-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSAAsyncGetProtoByName           () 
{ __asm {
	nop; 
	jmp ws2_32proc[(105-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSAAsyncGetServByPort            () 
{ __asm {
	nop; 
	jmp ws2_32proc[(106-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSAAsyncGetServByName            () 
{ __asm {
	nop; 
	jmp ws2_32proc[(107-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSACancelAsyncRequest            () 
{ __asm {
	nop; 
	jmp ws2_32proc[(108-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSASetBlockingHook               () 
{ __asm {
	nop; 
	jmp ws2_32proc[(109-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSAUnhookBlockingHook            () 
{ __asm {
	nop; 
	jmp ws2_32proc[(110-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSAGetLastError                  () 
{ __asm {
	nop; 
	jmp ws2_32proc[(111-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSASetLastError                  () 
{ __asm {
	nop; 
	jmp ws2_32proc[(112-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSACancelBlockingCall            () 
{ __asm {
	nop; 
	jmp ws2_32proc[(113-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSAIsBlocking                    () 
{ __asm {
	nop; 
	jmp ws2_32proc[(114-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSAStartup                       () 
{ __asm {
	nop; 
	jmp ws2_32proc[(115-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WSACleanup                       () 
{ __asm {
	nop; 
	jmp ws2_32proc[(116-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  ____WSAFDIsSet                     () 
{ __asm {
	nop; 
	jmp ws2_32proc[(151-1)*4];
} }
extern "C" __declspec(naked) void __stdcall  __WEP                              () 
{ __asm {
	nop; 
	jmp ws2_32proc[(500-1)*4];
} }
