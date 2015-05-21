/*
 * Mr Pass.  Brain the size of yor mom!
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "game.h"
#include "mechanicalTurk.h"

#define PATH_INITIAL "RLRL"
#define PATH_SEQUENCE "RLLLLLRLLLLBLLLLBLLLLBLLLLBLLLLBLLLBLLLLBLLLLBLLLBLLLLBLLLBLLLLBLLLBLLLLBLLLBLLLLBLLLBLLL"

action decideAction (Game g) {

    action nextAction;

    path fullPath = 

    nextAction.actionCode = START_SPINOFF;

    if ( !isLegalAction( g, nextAction ) ) {
        nextAction.actionCode = PASS;
    }

    return nextAction;
}
