/*
    Player User Entry
*/
#if defined PLAYER_USER_ENTRY_INCLUDED
    #endinput 
#endif
#define PLAYER_USER_ENTRY_INCLUDED

public OnUserJoin(playerid) {
    new rows = cache_num_rows();

    if(!rows) 
        return Dialog_Show(playerid, Dialog:D_REG);

    Dialog_Show(playerid, Dialog:D_AUTH);

    return true;
}

stock User_PlayerConnect(playerid) {
    GetPlayerName(playerid, g_player_user[playerid][U_NAME], MAX_PLAYER_NAME);

    static const query[] = "\
        SELECT us.id, us.name FROM users us WHERE us.name = '%s' \
        UNION( \
            SELECT uc.id, uc.name \
                FROM users_characters uc \
        LEFT JOIN users u on u.id = uc.user_id)\
    ";            
    new string[sizeof(query) + (-2 + MAX_PLAYER_NAME)];

    mysql_format(Database_GetHandle(), string, sizeof(string), query, g_player_user[playerid][U_NAME]);
    mysql_tquery(Database_GetHandle(), string, "OnUserJoin", "d", playerid);

    return true;
}

DialogCreate:D_REG(playerid) {
    Dialog_Open(
        playerid, Dialog:D_REG, DIALOG_STYLE_PASSWORD, 
        !"Registration account", 
        !"Please enter password:", 
        !"Enter", !"Close"
    );

    return true;
}

DialogResponse:D_REG(playerid, response, listitem, inputtext[]) {
    if(!response)
        return Kick(playerid);

    return true;
}

DialogCreate:D_AUTH(playerid) {
    Dialog_Open(
        playerid, Dialog:D_AUTH, DIALOG_STYLE_PASSWORD,
        !"Auth to account",
        !"Please enter password:",
        !"Enter", !"Close"
    );

    return true;
}

DialogResponse:D_AUTH(playerid, response, listitem, inputtext[]) {
    if(!response)
        return Kick(playerid);


    return true;
}