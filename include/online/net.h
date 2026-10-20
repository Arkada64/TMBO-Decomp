#ifndef ONLINE_NET_H
#define ONLINE_NET_H

#include "common.h"

/*
 * Twisted Metal: Black Online network module (Incog), on top of SCE-RT DME.
 * Struct layouts are partial: only fields seen in decompiled code are named.
 * Names marked (orig) come from the game's own debug strings.
 */

typedef struct NetState {
    /* 0x0000 */ char pad0[4];
    /* 0x0004 */ int* myClientIndexPtr;      /* points at this console's slot */
    /* 0x0008 */ char pad8[0x129C - 0x8];
    /* 0x129C */ int unk129C;
    /* 0x12A0 */ char pad12A0[0x2CF0 - 0x12A0];
    /* 0x2CF0 */ int mConnectionIndex;       /* (orig) DME connection handle */
} NetState;

/* Message 0 payload: a gameplay "command" (orig: "Failed to send command %d") */
typedef struct NetGameEvent {
    /* 0x00 */ int unk0;
    /* 0x04 */ int command;                  /* event id, 20..60 */
    /* 0x08 */ char data[0x50 - 0x8];
} NetGameEvent;                              /* 0x50 bytes on the wire */

/* Chat line as handed to the on-screen message list */
typedef struct NetChatLine {
    /* 0x00 */ int client;
    /* 0x04 */ char name[0x5C];
} NetChatLine;

int printf(const char* fmt, ...);
char* strcpy(char* dst, const char* src);

/* SCE-RT DME (descriptive names, not original) */
int dmeGetTime(int* outTime);                                          /* 0x00266C58 */
int dmeGetMyClientIndex(int* outIndex, int connection);                /* 0x00266378 */
int dmeSendMsgToClient(int flags, int connection, int client, int msgId, int size, void* data);

/* game side */
int netMsgGameEventHandler(int connection, int unk, int client, NetGameEvent* event);
void func_001188C0(NetChatLine* line);
void func_00118380(NetChatLine* line, void* text);
void func_001186C8(void* list, NetChatLine* line);

extern int D_004F9D84;                       /* DME message id: game event */
extern char D_003156D8[];                    /* player slot names, stride 0x220 */
extern char D_002B90A0[];                    /* on-screen chat list */
extern int* D_00321018[];                    /* per-slot tables, indexed by my slot */

#endif
