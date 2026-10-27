//@@ netSendGameEvent E-local-msgid
int netSendGameEvent(NetState* state, int client, NetGameEvent* event) {
    int err;
    int msgId;

    if (*state->myClientIndexPtr == client) {
        netMsgGameEventHandler(state->mConnectionIndex, state->unk129C, client, event);
    } else {
        msgId = D_004F9D84;
        err = dmeSendMsgToClient(0x40, state->mConnectionIndex, client, msgId, 0x50, event);
        if (err != 0) {
            printf("NETWORK WARNING: Failed to send command %d to client %d NetError = %d\n", event->command, client, err);
        }
    }
    return 1;
}
//@@ netSendGameEvent F-volatile
int netSendGameEvent(NetState* state, int client, NetGameEvent* event) {
    int err;

    if (*state->myClientIndexPtr == client) {
        netMsgGameEventHandler(state->mConnectionIndex, state->unk129C, client, event);
    } else {
        err = dmeSendMsgToClient(0x40, state->mConnectionIndex, client, *(volatile int*)&D_004F9D84, 0x50, event);
        if (err != 0) {
            printf("NETWORK WARNING: Failed to send command %d to client %d NetError = %d\n", event->command, client, err);
        }
    }
    return 1;
}
//@@ netSendGameEvent G-struct-global
typedef struct NetMsgIds { int gameEvent; } NetMsgIds;
extern NetMsgIds D_004F9D84_s __asm__("D_004F9D84");
int netSendGameEvent(NetState* state, int client, NetGameEvent* event) {
    int err;

    if (*state->myClientIndexPtr == client) {
        netMsgGameEventHandler(state->mConnectionIndex, state->unk129C, client, event);
    } else {
        err = dmeSendMsgToClient(0x40, state->mConnectionIndex, client, D_004F9D84_s.gameEvent, 0x50, event);
        if (err != 0) {
            printf("NETWORK WARNING: Failed to send command %d to client %d NetError = %d\n", event->command, client, err);
        }
    }
    return 1;
}
//@@ netSendGameEvent H-conn-local
int netSendGameEvent(NetState* state, int client, NetGameEvent* event) {
    int err;
    int conn;

    if (*state->myClientIndexPtr == client) {
        netMsgGameEventHandler(state->mConnectionIndex, state->unk129C, client, event);
    } else {
        conn = state->mConnectionIndex;
        err = dmeSendMsgToClient(0x40, conn, client, D_004F9D84, 0x50, event);
        if (err != 0) {
            printf("NETWORK WARNING: Failed to send command %d to client %d NetError = %d\n", event->command, client, err);
        }
    }
    return 1;
}
