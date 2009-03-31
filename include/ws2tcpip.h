/*
 * Copyright (C) 2001 Francois Gouget
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

#ifndef __WS2TCPIP__
#define __WS2TCPIP__

#include <winsock2.h>
#include <ws2ipdef.h>
#include <limits.h>

#ifdef USE_WS_PREFIX
#define WS(x)    WS_##x
#else
#define WS(x)    x
#endif

/* FIXME: This gets defined by some Unix (Linux) header and messes things */
#undef s6_addr

/* for addrinfo calls */
typedef struct WS(addrinfo)
{
    int                ai_flags;
    int                ai_family;
    int                ai_socktype;
    int                ai_protocol;
    size_t             ai_addrlen;
    char *             ai_canonname;
    struct WS(sockaddr)*   ai_addr;
    struct WS(addrinfo)*   ai_next;
} ADDRINFOA, *PADDRINFOA;

typedef struct WS(addrinfoW)
{
    int                ai_flags;
    int                ai_family;
    int                ai_socktype;
    int                ai_protocol;
    size_t             ai_addrlen;
    PWSTR              ai_canonname;
    struct WS(sockaddr)*   ai_addr;
    struct WS(addrinfoW)*   ai_next;
} ADDRINFOW, *PADDRINFOW;

typedef int WS(socklen_t);

typedef ADDRINFOA ADDRINFO, *LPADDRINFO;

/* Possible Windows flags for getaddrinfo() */
#ifndef USE_WS_PREFIX
# define AI_PASSIVE     0x0001
# define AI_CANONNAME   0x0002
# define AI_NUMERICHOST 0x0004
/* getaddrinfo error codes */
# define EAI_AGAIN	WSATRY_AGAIN
# define EAI_BADFLAGS	WSAEINVAL
# define EAI_FAIL	WSANO_RECOVERY
# define EAI_FAMILY	WSAEAFNOSUPPORT
# define EAI_MEMORY	WSA_NOT_ENOUGH_MEMORY
# define EAI_NODATA	EAI_NONAME
# define EAI_NONAME	WSAHOST_NOT_FOUND
# define EAI_SERVICE	WSATYPE_NOT_FOUND
# define EAI_SOCKTYPE	WSAESOCKTNOSUPPORT
#else
# define WS_AI_PASSIVE     0x0001
# define WS_AI_CANONNAME   0x0002
# define WS_AI_NUMERICHOST 0x0004
/* getaddrinfo error codes */
# define WS_EAI_AGAIN	WSATRY_AGAIN
# define WS_EAI_BADFLAGS	WSAEINVAL
# define WS_EAI_FAIL	WSANO_RECOVERY
# define WS_EAI_FAMILY	WSAEAFNOSUPPORT
# define WS_EAI_MEMORY	WSA_NOT_ENOUGH_MEMORY
# define WS_EAI_NODATA	WS_EAI_NONAME
# define WS_EAI_NONAME	WSAHOST_NOT_FOUND
# define WS_EAI_SERVICE	WSATYPE_NOT_FOUND
# define WS_EAI_SOCKTYPE	WSAESOCKTNOSUPPORT
#endif

/* Possible Windows flags for getnameinfo() */
#ifndef USE_WS_PREFIX
# define NI_NOFQDN          0x01
# define NI_NUMERICHOST     0x02
# define NI_NAMEREQD        0x04
# define NI_NUMERICSERV     0x08
# define NI_DGRAM           0x10
#else
# define WS_NI_NOFQDN       0x01
# define WS_NI_NUMERICHOST  0x02
# define WS_NI_NAMEREQD     0x04
# define WS_NI_NUMERICSERV  0x08
# define WS_NI_DGRAM        0x10
#endif


#ifdef __cplusplus
extern "C" {
#endif

void WINAPI WS(freeaddrinfo)(LPADDRINFO);
#define     FreeAddrInfoA WS(freeaddrinfo)
void WINAPI FreeAddrInfoW(PADDRINFOW);
#define     FreeAddrInfo WINELIB_NAME_AW(FreeAddrInfo)
int WINAPI  WS(getaddrinfo)(const char*,const char*,const struct WS(addrinfo)*,struct WS(addrinfo)**);
#define     GetAddrInfoA WS(getaddrinfo)
int WINAPI  GetAddrInfoW(PCWSTR,PCWSTR,const ADDRINFOW*,PADDRINFOW*);
#define     GetAddrInfo WINELIB_NAME_AW(GetAddrInfo)
int WINAPI  WS(getnameinfo)(const SOCKADDR*,WS(socklen_t),PCHAR,DWORD,PCHAR,DWORD,INT);
#define     GetNameInfoA WS(getnameinfo)
INT WINAPI  GetNameInfoW(const SOCKADDR*,WS(socklen_t),PWCHAR,DWORD,PWCHAR,DWORD,INT);
#define     GetNameInfo WINELIB_NAME_AW(GetNameInfo)
PCSTR WINAPI WS(inet_ntop)(INT,PVOID,PSTR,size_t);
#define     InetNtopA WS(inet_ntop)
PCWSTR WINAPI InetNtopW(INT,PVOID,PWSTR,size_t);
#define     InetNtop WINELIB_NAME_AW(InetNtop)
int WINAPI  WS(inet_pton)(INT,PCSTR,PVOID);
#define     InetPtonA WS(inet_pton)
int WINAPI  InetPtonW(INT,PCWSTR,PVOID);
#define     InetPton WINELIB_NAME_AW(InetPton)

/*
 * Ws2tcpip Function Typedefs
 *
 * Remember to keep this section in sync with the
 * prototypes above.
 */
#if INCL_WINSOCK_API_TYPEDEFS

typedef void (WINAPI *LPFN_FREEADDRINFO)(LPADDRINFO);
#define LPFN_FREEADDRINFOA LPFN_FREEADDRINFO
typedef void (WINAPI *LPFN_FREEADDRINFOW)(PADDRINFOW);
#define LPFN_FREEADDRINFOT WINELIB_NAME_AW(LPFN_FREEADDRINFO)
typedef int (WINAPI *LPFN_GETADDRINFO)(const char*,const char*,const struct WS(addrinfo)*,struct WS(addrinfo)**);
#define LPFN_GETADDRINFOA LPFN_GETADDRINFO
typedef int (WINAPI *LPFN_GETADDRINFOW)(PCWSTR,PCWSTR,const ADDRINFOW*,PADDRINFOW*);
#define LPFN_GETADDRINFOT WINELIB_NAME_AW(LPFN_GETADDRINFO)
typedef int (WINAPI *LPFN_GETNAMEINFO)(const struct sockaddr*,socklen_t,char*,DWORD,char*,DWORD,int);
#define LPFN_GETNAMEINFOA LPFN_GETNAMEINFO
typedef int (WINAPI *LPFN_GETNAMEINFOW)(const SOCKADDR*,socklen_t,PWCHAR,DWORD,PWCHAR,DWORD,INT);
#define LPFN_GETNAMEINFOT WINELIB_NAME_AW(LPFN_GETNAMEINFO)

#endif

#ifdef __cplusplus
}
#endif

#endif /* __WS2TCPIP__ */
