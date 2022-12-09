/*
    Player API
*/
#if defined PLAYER_API_INCLUDED
    #endinput 
#endif
#define PLAYER_API_INCLUDED

enum E_PLAYER {
    bool:P_LOGGED
};
new g_player[MAX_PLAYERS][E_PLAYER];
new g_player_default[E_PLAYER] = {
    false
};

stock Player_IsLogged(playerid)
    return g_player[playerid][P_LOGGED];

stock Player_SetLogged(playerid, bool:satus)
    g_player[playerid][P_LOGGED] = status;