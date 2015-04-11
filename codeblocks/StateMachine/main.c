#include <stdio.h>
#include <stdlib.h>

#include "StateMachine.h"

enum ret_codes { ok, fail, repeat};

int entry_state(void){
    printf("entry_state\n");
    return ok;
}
int state_1(void){
    printf("state_1\n");
    return ok;
}

int state_2(void){
    printf("state_2\n");
    return fail;
}
int exit_state(void){
    printf("exit_state\n");
    return ok;
}
int error(void);


int main()
{
    transition_t state_transitions[] = {
        {entry_state,   ok,     state_1},
        {entry_state,   fail,   exit_state},
        {state_1,       ok,     state_2},
        {state_1,       fail,   exit_state},
        {state_1,       repeat, state_1},
        {state_2,       ok,     exit_state},
        {state_2,       fail,   exit_state},
        {state_2,       repeat, state_1}
    };
    int table_size = sizeof(state_transitions)/sizeof(transition_t);

    return state_machine(state_transitions, table_size, entry_state, exit_state);
}
