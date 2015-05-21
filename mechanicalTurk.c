/*
 * Mr Pass.  Brain the size of yor mom!
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "Game.h"
#include "mechanicalTurk.h"

#define PATH_INITIAL "RLRL"
#define PATH_SEQUENCE "RLLLLLRLLLLBLLLLBLLLLBLLLLBLLLLBLLLBLLLLBLLLLBLLLBLLLLBLLLBLLLLBLLLBLLLLBLLLBLLLLBLLLBLLL"

static void nextPath( path previousPath);
static action iterateLegal (int actionCode, Game g);

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
    int THDs = getStudents (g, myID, STUDENT_THD);
    int BPSs = getStudents (g, myID, STUDENT_BPS);
    int BQNs = getStudents (g, myID, STUDENT_BQN);
    int MJs = getStudents (g, myID, STUDENT_MJ);
    int MTVs = getStudents (g, myID, STUDENT_MTV);
    int MMONEYs = getStudents (g, myID, STUDENT_MMONEY);

    int Go8Legal = TRUE;
    int CampusLegal = TRUE;
    int ArcLegal = TRUE;

    if (MJs >= 2 && MMONEYs >=3 && Go8Legal == TRUE) {
        //build Go8
        action tempAction = iterateLegal(BUILD_GO8, g);
        if (tempAction.actionCode = PASS) {
            Go8Legal = FALSE;
        }
    } 
    if (BPSs >=1 && BQNs >=1 && MJs >=1 && MTVs >=1 && CampusLegal == TRUE) {
        //build campus
        action tempAction = iterateLegal(BUILD_CAMPUS, g);
        if (tempAction.actionCode = PASS) {
            CampusLegal = FALSE;
        }
    } 
    if (BQNs >=1 && BPSs >=1 && ArcLegal == TRUE) {
        //build arc
        action tempAction = iterateLegal(OBTAIN_ARC, g);
        if (tempAction.actionCode = PASS) {
            ArcLegal = FALSE;
        }
    } 
    if (MJs >=1 && MTVs >=1 && MMONEYs>=1) {
        //make patent
        action tempAction = iterateLegal(START_SPINOFF, g);
    }
    //trade
    //tempAction = iterateLegal(RETRAIN STUDENTS, g);
}

static action iterateLegal (int actionCode, Game g) {
    path tempPath = PATH_INITIAL;
    action tempAction;
    tempAction.actionCode = actionCode;
    strcpy(tempAction.destination, tempPath);
    //tempAction.disciplineFrom = from;
    //tempAction.disciplineTo = to;
    int legal = FALSE;

    while (strlen(tempPath) <= strlen(PATH_INITIAL) + strlen(PATH_SEQUENCE) && legal == FALSE) {
        legal = isLegalAction(g, tempAction);
        if (legal == FALSE) {
            nextPath(tempPath);
            strcpy(tempAction.destination, tempPath);
        }
    }
    if (legal == FALSE) {
       tempAction.actionCode = 0; 
    }
    return tempAction;
}
// index is the index of PATH_SEQUENCE
// i.e. the current iteration of the pathing loop
static void nextPath(path previousPath) {
    int index = strlen(previousPath);
    path pathSequence = PATH_SEQUENCE;
    previousPath[index + 4]      = pathSequence[index];
    previousPath[index + 4 + 1] = '\0';

}
