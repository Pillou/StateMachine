#include <stdio.h>
#include <stdlib.h>

#include "StateMachine.h"

#define STATE_OK      0
#define STATE_FAIL    1
#define STATE_REPEAT  2

int entry_state(void){
  printf("entry_state\n");
  return STATE_OK;
}
int state_1(void){
  printf("state_1\n");
  return STATE_OK;
}

int state_2(void){
  printf("state_2\n");
  return STATE_FAIL;
}
int exit_state(void){
  printf("exit_state\n");
  return STATE_OK;
}
int error(void);


int main()
{
  StateTransition transtion_table[] = {
    {entry_state,   STATE_OK,     state_1},
    {entry_state,   STATE_FAIL,   exit_state},
    {state_1,       STATE_OK,     state_2},
    {state_1,       STATE_FAIL,   exit_state},
    {state_1,       STATE_REPEAT, state_1},
    {state_2,       STATE_OK,     exit_state},
    {state_2,       STATE_FAIL,   exit_state},
    {state_2,       STATE_REPEAT, state_1}
  };
  int table_size = sizeof(transtion_table)/sizeof(StateTransition);

  return StateMachine(transtion_table, table_size, entry_state, exit_state);
}
