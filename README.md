# StateMachine
This project is a simple library to create table driven state machine.
There is an example of application using the IDE codeblocks.


HOW TO USE:

You need to add StateMachine.c and StateMachine.h to your poject.

Then create the transition table. Each transitions of you state machine will
be described by a line in the transition table.

Example:
transition_t state_transitions[] = {
//      current_states | transition condition   |   next state
        {entry_state,       ok,                     state_1},
        {entry_state,       fail,                   exit_state},
        {state_1,           ok,                     state_2},
        {state_1,           fail,                   exit_state},
        {state_1,           repeat,                 state_1},
        {state_2,           ok,                     exit_state},
        {state_2,           fail,                   exit_state},
        {state_2,           repeat,                 state_1}
    };
Each state must be of type "int example_state(void)".
The transition condition are the return value of the state functions.

Finally you can start the machine state. The state machine will stop when the
exit_state has been executed and will return the return value of this state.
/!\ If there is an error in the transition table, the function will catch it and
stay in a while(1){}.

int table_size = sizeof(state_transitions)/sizeof(transition_t);

return state_machine(state_transitions, table_size, entry_state, exit_state);
