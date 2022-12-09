/*
    Player Entry
*/
#if defined PLAYER_ENTRY_INCLUDED
    #endinput 
#endif
#define PLAYER_ENTRY_INCLUDED

stock Player_PlayerConnect(playerid) {
    g_player[playerid] = g_player_default;

    User_PlayerConnect(playerid);

    return true;
}