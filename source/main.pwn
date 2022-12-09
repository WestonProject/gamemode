/*
    Include's
*/
#include <a_samp>
#include <a_mysql>

#include <Pawn.CMD>

#include <mdialog>

/*
    Macro's
*/

// Include API's

/* Core */
#include "source/core/database/api.inc"

/* Systems */
#include "source/systems/player/api.inc"

#include "source/systems/player/user/api.inc"

// Include Entry's

/* Core */
#include "source/core/database/entry.inc"

/* Systems */
#include "source/systems/player/entry.inc"

#include "source/systems/player/user/entry.inc"

main() { }

public OnGameModeInit() {
    Database_GameModeInit();

    return true;
}

public OnPlayerConnect(playerid) {
    Player_PlayerConnect(playerid);

    return true;
}

// Callback in Query Error
public OnQueryError(errorid, const error[], const callback[], const query[], MySQL:handle) {
    return true;
}