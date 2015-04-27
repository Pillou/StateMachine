/** \file StateMachine.c
 *  \brief table driven state machine source file
 */

/// TODO (guillaume#1#): Sort look up table and put a smarter _LookupTransition function

#include "StateMachine.h"

#if !defined(NULL)
  #define NULL ((void*)0)
#endif

/** \brief static StateFunction _LookupTransition( const StateTransition *table, \
 *                                      int table_size, \
 *                                      StateFunction cur_state, \
 *                                      StateReturn rc){
 * \param const StateTransition *table
 * \param int table_size
 * \param StateFunction cur_state
 * \param StateReturn rc
 * \return StateFunction : pointer to next function to execute, 0 if error
 */
static StateFunction _LookupTransition( const StateTransition *table, \
                                        int table_size, \
                                        StateFunction cur_state, \
                                        StateReturn rc){
  int i=0;
  for(i=0; i<table_size; i++){
    if( cur_state == table[i].src_state && \
        rc == table[i].ret_code){
      return table[i].next_state;
    }
  }
  return NULL;
}

/** \brief StateReturn StateMachine( const StateTransition *table, \
 *                                   int table_size, \
 *                                   StateFunction starting_state, \
 *                                   StateFunction exit_state)
 * \param const StateTransition *table
 * \param int table_size
 * \param StateFunction starting_state
 * \param StateFunction exit_state
 * \return StateReturn
 */
StateReturn StateMachine( const StateTransition *table, \
                          int table_size, \
                          StateFunction starting_state, \
                          StateFunction exit_state){
  StateReturn return_code = 0;
  StateFunction current_state = starting_state;

  while(current_state != NULL){
    return_code = current_state();
    if( current_state == exit_state){
      return return_code;
    }
    current_state = _LookupTransition(table, table_size, current_state, return_code);
  }
  for(;;){}; // catch error in lookup table
}

