/** \file StateMachine.c
 *  \brief table driven state machine source file
 */

/// TODO (guillaume#1#): Sort look up table and put a smarter _lookup_transitions function

#include "StateMachine.h"

/** \brief static state_fn _lookup_t ransitions(const transition_t *table, int table_size, state_fn cur_state, int rc)
 *
 * \param const transition_t *table
 * \param int table_size
 * \param state_fn cur_state
 * \param int rc
 * \return state_fn : pointer to next function to execute, 0 if error
 */
static state_fn _lookup_transitions(const transition_t *table, int table_size, state_fn cur_state, int rc){
    int i=0;
    state_fn return_fn;
    for(i=0; i<table_size; i++){
        if(cur_state == table[i].src_state && rc == table[i].ret_code){
            return_fn = table[i].next_state;
            return return_fn;
        }
    }
    return 0;
}

/** \brief int state_machine(const transition_t *table, int table_size, state_fn starting_state, state_fn exit_state)
 *
 * \param const transition_t *table
 * \param int table_size
 * \param state_fn starting_state
 * \param state_fn exit_state
 * \return int
 */
int state_machine(const transition_t *table, int table_size, state_fn starting_state, state_fn exit_state){
    int return_code = 0;
    state_fn current_state = starting_state;

    while(current_state != 0){
        return_code = current_state();
        if( current_state == exit_state){
            return return_code;
        }
        current_state = _lookup_transitions(table, table_size, current_state, return_code);
    }
    while(1){}; // catch error in lookup table
}

