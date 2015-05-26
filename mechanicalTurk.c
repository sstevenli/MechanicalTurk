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

    // Test GO8
    action tempAction = iterateLegal(BUILD_GO8, g);
    nextAction.actionCode = tempAction.actionCode;
    strcpy( nextAction.destination, tempAction.destination );

    if (nextAction.actionCode == PASS) {

        // Test Campus
        action tempAction = iterateLegal(BUILD_CAMPUS, g);
        nextAction.actionCode = tempAction.actionCode;
        strcpy( nextAction.destination, tempAction.destination );

        if (nextAction.actionCode == PASS) {

            // Test ArC
            action tempAction = iterateLegal(OBTAIN_ARC, g);
            nextAction.actionCode = tempAction.actionCode;
            strcpy( nextAction.destination, tempAction.destination );

            if (nextAction.actionCode == PASS) {

                // test Spinoff
                nextAction.actionCode = START_SPINOFF;

                if ( !isLegalAction( g, nextAction ) ) {

                    nextAction.actionCode = RETRAIN_STUDENTS;

                    if ( getStudents(g, getWhoseTurn(g), STUDENT_BPS) > getStudents(g, getWhoseTurn(g), STUDENT_BQN) ) {
                        nextAction.disciplineTo = STUDENT_BQN;
                    } else {
                        nextAction.disciplineTo = STUDENT_BPS;
                    }

                    nextAction.disciplineFrom = STUDENT_MMONEY;
                    if ( !isLegalAction( g, nextAction ) ) {
                        nextAction.disciplineFrom = STUDENT_MTV;
                        if ( !isLegalAction( g, nextAction ) ) {
                            nextAction.disciplineFrom = STUDENT_MJ;
                            if ( !isLegalAction( g, nextAction ) ) {
                                nextAction.actionCode = PASS;
                            }
                        }
                    }

                    nextAction.actionCode = PASS;
                }
            }
        }
    }

    return nextAction;
}

static action iterateLegal (int actionCode, Game g) {

    path pathSequence = PATH_SEQUENCE;
    path tempPath = PATH_INITIAL;

    action tempAction;
    tempAction.actionCode = actionCode;
    strcpy(tempAction.destination, tempPath);

    int legal = FALSE;
    int index = 0;

    while ( index < strlen(PATH_SEQUENCE) && legal == FALSE) {

        legal = isLegalAction(g, tempAction);

        if (legal == FALSE) {
            strncat( tempPath, pathSequence+index, 1 );
            /*
            tempPath[index + strlen(PATH_INITIAL)]     = pathSequence[index];
            tempPath[index + strlen(PATH_INITIAL) + 1] = '\0';
            */
            strcpy(tempAction.destination, tempPath);
        }

        index++;
    }

    if (legal == FALSE) {
       tempAction.actionCode = PASS; 
    }

    strcpy(tempAction.destination, tempPath);

    return tempAction;
}
