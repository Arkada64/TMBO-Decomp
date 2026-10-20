//@@ netGetMyClientIndex final
int netGetMyClientIndex(NetState* state) {
    int index;
    int err;

    err = dmeGetMyClientIndex(&index, state->mConnectionIndex);
    if (err == 0) {
        if ((unsigned int)index >= 8) {
            printf("NETWORK:  ERROR:  GetMyClientIndex() RETURNING %d\n", index);
        }
        return index;
    } else {
        printf("NETWORK: NetGetMyClientIndex returned an error of %d index = %d mConnectionIndex = %d\n", err, index, state->mConnectionIndex);
        return 0;
    }
}
//@@ netGetDmeTime final
int netGetDmeTime(NetState* state) {
    int time;

    dmeGetTime(&time);
    return time;
}
//@@ func_00174268 final
int func_00174268(NetState* state, int index) {
    return D_00321018[netGetMyClientIndex(state)][index];
}
//@@ netMsgChatHandler final
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
//@@ netSendGameEvent final
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
