/*
    Player User API
*/
#if defined PLAYER_USER_API_INCLUDED
    #endinput 
#endif
#define PLAYER_USER_API_INCLUDED

forward OnUserJoin(playerid);

forward OnUserCharactersFind(playerid);

enum E_PLAYER_USER {
    U_ID,
    U_NAME[MAX_PLAYER_NAME]
};
new g_player_user[MAX_PLAYERS][E_PLAYER_USER];
