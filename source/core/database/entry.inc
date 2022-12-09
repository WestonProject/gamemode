/*
    Database Entry
*/
#if defined DATABASE_ENTRY_INCLUDED
    #endinput 
#endif
#define DATABASE_ENTRY_INCLUDED

stock Database_GameModeInit() {
    new MySQLOpt:option_id = mysql_init_options();
    
    mysql_set_option(option_id, E_MYSQL_OPTION:AUTO_RECONNECT, true);

    Database_SetHandle(
        mysql_connect(DATABASE_HOST, DATABASE_USER, DATABASE_PASSWORD, DATABASE_NAME, option_id)
    );

    if(!mysql_errno(Database_GetHandle())) 
        return print("MySQL not connected...");

    return true;
}
