/** \file StateMachine.h
 *  \brief table driven state machine header
 */

#ifndef STATEMACHINE_H_INCLUDED
#define STATEMACHINE_H_INCLUDED

/**< type returned by state function (can be changed by user) */
typedef int StateReturn;


/**< state function pointer typedef */
typedef StateReturn (*StateFunction)(void);


/**< transition between two state structure */
typedef struct {
    StateFunction src_state;
    StateReturn ret_code;
    StateFunction next_state;
} StateTransition;


StateReturn StateMachine( const StateTransition *table, \
                          int table_size, \
                          StateFunction starting_state, \
                          StateFunction exit_state);

#endif // STATEMACHINE_H_INCLUDED
