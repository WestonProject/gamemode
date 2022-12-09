/*
    Database API
*/
#if defined DATABASE_API_INCLUDED
    #endinput 
#endif
#define DATABASE_API_INCLUDED

#define DATABASE_HOST                       "localhost"       
#define DATABASE_USER                       "root"            
#define DATABASE_PASSWORD                   ""               
#define DATABASE_NAME                       "main"           

#define DATABASE_USERS_TABLE                "`users`"
#define DATABASE_USERS_CHARACTERS_TABLE     "`users_characters`"

static MySQL:gHandle;

stock Database_SetHandle(MySQL:handle)
    gHandle = handle;

stock MySQL:Database_GetHandle() 
    return gHandle;

