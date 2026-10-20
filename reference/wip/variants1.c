//@@ netMsgChatHandler A-draft
int netMsgChatHandler(int unused0, int unused1, int client, void* text) {
    NetChatLine line;

    func_001188C0(&line);
    if (client != 0x100) {
        strcpy(line.name, D_003156D8 + client * 0x220);
        line.client = client;
        func_00118380(&line, text);
        func_001186C8(D_002B90A0, &line);
    }
    return 0x44;
}
//@@ netMsgChatHandler B-early-return
int netMsgChatHandler(int unused0, int unused1, int client, void* text) {
    NetChatLine line;

    func_001188C0(&line);
    if (client == 0x100) {
        return 0x44;
    }
    strcpy(line.name, D_003156D8 + client * 0x220);
    line.client = client;
    func_00118380(&line, text);
    func_001186C8(D_002B90A0, &line);
    return 0x44;
}
//@@ netMsgChatHandler C-pointer
int netMsgChatHandler(int unused0, int unused1, int client, void* text) {
    NetChatLine line;
    NetChatLine* p = &line;

    func_001188C0(p);
    if (client != 0x100) {
        strcpy(p->name, D_003156D8 + client * 0x220);
        p->client = client;
        func_00118380(p, text);
        func_001186C8(D_002B90A0, p);
    }
    return 0x44;
}
//@@ netSendGameEvent A-draft
int netSendGameEvent(NetState* state, int client, NetGameEvent* event) {
    int err;

    if (*state->myClientIndexPtr == client) {
        netMsgGameEventHandler(state->mConnectionIndex, state->unk129C, client, event);
    } else {
        err = dmeSendMsgToClient(0x40, state->mConnectionIndex, client, D_004F9D84, 0x50, event);
        if (err != 0) {
            printf("NETWORK WARNING: Failed to send command %d to client %d NetError = %d\n", event->command, client, err);
        }
    }
    return 1;
}
//@@ netSendGameEvent B-early-return
int netSendGameEvent(NetState* state, int client, NetGameEvent* event) {
    int err;

    if (*state->myClientIndexPtr == client) {
        netMsgGameEventHandler(state->mConnectionIndex, state->unk129C, client, event);
        return 1;
    }
    err = dmeSendMsgToClient(0x40, state->mConnectionIndex, client, D_004F9D84, 0x50, event);
    if (err != 0) {
        printf("NETWORK WARNING: Failed to send command %d to client %d NetError = %d\n", event->command, client, err);
    }
    return 1;
}
//@@ netSendGameEvent C-assign-in-if
int netSendGameEvent(NetState* state, int client, NetGameEvent* event) {
    int err;

    if (*state->myClientIndexPtr == client) {
        netMsgGameEventHandler(state->mConnectionIndex, state->unk129C, client, event);
    } else if ((err = dmeSendMsgToClient(0x40, state->mConnectionIndex, client, D_004F9D84, 0x50, event)) != 0) {
        printf("NETWORK WARNING: Failed to send command %d to client %d NetError = %d\n", event->command, client, err);
    }
    return 1;
}
//@@ netSendGameEvent D-client-first
int netSendGameEvent(NetState* state, int client, NetGameEvent* event) {
    int err;

    if (client == *state->myClientIndexPtr) {
        netMsgGameEventHandler(state->mConnectionIndex, state->unk129C, client, event);
    } else {
        err = dmeSendMsgToClient(0x40, state->mConnectionIndex, client, D_004F9D84, 0x50, event);
        if (err != 0) {
            printf("NETWORK WARNING: Failed to send command %d to client %d NetError = %d\n", event->command, client, err);
        }
    }
    return 1;
}
