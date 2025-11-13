/**
 * @file plib_state_machine.c
 * @brief Machine d'état générique
 * @author Ramiro Najera
 * @version 1.0.7
 * @date 2025-10-06
 */

#include "plib_state_machine.h"

void StateMachine_Init(StateMachine_t *sm)
{
    sm->currentState = 0;
    sm->entryFlag = 1;
}

void StateMachine(StateMachine_t *sm)
{
    const State *s = &sm->states[sm->currentState];

    if(sm->entryFlag)
    {
        if (s->action) s->action();
        sm->entryFlag = 0;
    }

    for(int i = 0; i < s->numTransitions; i++)
    {
        if(s->transitions[i].condition && s->transitions[i].condition())
        {
            sm->currentState = s->transitions[i].nextState;
            sm->entryFlag = 1;
            break;
        }
    }
}