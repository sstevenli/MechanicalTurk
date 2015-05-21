/*
 * Mr Pass.  Brain the size of yor mom!
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "Game.h"
#include "mechanicalTurk.h"

#define PATH_INITIAL "RLRL"
#define PATH_SEQUENCE "RLLLLLRLLLLBLLLLBLLLLBLLLLBLLLLBLLLBLLLLBLLLLBLLLBLLLLBLLLBLLLLBLLLBLLLLBLLLBLLLLBLLLBLLL"

static void nextPath( path previousPath, int index );

action decideAction (Game g) {

    action nextAction;

    /*Order of actions:
     * Go8 
     * Campuses
     * Arc
     * Patents
     * (trading)
     */
    int myID = getWhoseTurn(g);
    int THDs = getStuents (g, myID, STUDENT_THD);
    int BPSs = getStuents (g, myID, STUDENT_BPS);
    int BQNs = getStuents (g, myID, STUDENT_BQN);
    int MJs = getStuents (g, myID, STUDENT_MJ);
    int MTVs = getStuents (g, myID, STUDENT_MTV);
    int MMONEYs = getStuents (g, myID, STUDENT_MMONEY);

    if (MJs >= 2 && MMONEYs >=3) {
        //build Go8
    } else if (BPSs >=1 && BQNs >=1 && MJs >=1 && MTVs >=1) {
        //build campus
    } else if (BQNs >=1 && BPSs >=1) {
        //build arc
    } else if (MJs >=1 && MTVs >=1 && MMONEYs>=1) {
        //make patent
    } else {
        //trade
    }
/*
>>>>>>> actionOrder
    nextAction.actionCode = START_SPINOFF;

    if ( !isLegalAction( g, nextAction ) ) {
        nextAction.actionCode = PASS;
    }
*/
    return nextAction;
}

// index is the index of PATH_SEQUENCE
// i.e. the current iteration of the pathing loop
static void nextPath( path previousPath, int index ) {

    path pathSequence = PATH_SEQUENCE;
    previousPath[index + 4]      = pathSequence[index];
    previousPath[index + 4 + 1] = '\0';

}
