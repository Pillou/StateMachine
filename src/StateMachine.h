/** \file StateMachine.h
 *  \brief table driven state machine header
 */

#ifndef STATEMACHINE_H_INCLUDED
#define STATEMACHINE_H_INCLUDED

/**< transition between two state structure */
typedef struct {
    int (*src_state)(void);
    int ret_code;
    int (*next_state)(void);
} transition_t;

/**< state function pointer typedef */
typedef int (*state_fn)(void);

int state_machine(const transition_t *table, int table_size, state_fn starting_state, state_fn exit_state);

#endif // STATEMACHINE_H_INCLUDED
