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

void nextPath( path previousPath, int index );

action decideAction (Game g) {

    action nextAction;

    nextAction.actionCode = START_SPINOFF;

    if ( !isLegalAction( g, nextAction ) ) {
        nextAction.actionCode = PASS;
    }

    return nextAction;
}

// index is the index of PATH_SEQUENCE
// i.e. the current iteration of the pathing loop
void nextPath( path previousPath, int index ) {

    path pathSequence = PATH_SEQUENCE;
    (previousPath*)[index + 4]      = pathSequence[index];
    (previousPath*)[index + 4 + 1] = '\0';

}
