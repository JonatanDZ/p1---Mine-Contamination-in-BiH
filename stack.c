#include "stack.h"
#include <stdio.h>


#define STACKSIZE 1024

/**
 * User defined struct type in c
*/
typedef struct {
  // Array storing stack elements
  int array[STACKSIZE]; // TODO: OBS PÅ TYPE
  // Index for top element of stack
  int top;
} stack_t;

/**
* Function initializing stack
*/
void initialize(stack_t *stack){
  // Sets top index of stack to -1 indicating an empty stack
  stack->top = -1;
}

/** Checks if the stack is empty
*   Returns 1(true) if stack is empty, otherwise 0(false)
*/
int isEmpty(stack_t *stack){
  // If top is == -1, stack is empty
  return (stack->top == -1);
}

// Checks if the stack is full
int isFull(stack_t *stack){
  // If top is == -1, stack is empty
  return stack->top == STACKSIZE - 1;
}

void push(stack_t *stack, int value){
  if (isFull(stack)) {
    printf("Stack Overflow\n");
    return;
  }
}