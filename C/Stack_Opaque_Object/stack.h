#ifndef STACK_H
#define STACK_H

enum Boolean{FALSE, TRUE};
typedef enum Boolean Boolean;

enum Status{FAILURE, SUCCESS};
typedef enum Status Status;

typedef void* STACK;

STACK* stack_init_default(void);

Status stack_push(STACK hStack, char ch);

Status stack_pop(STACK hStack);

Boolean stack_is_empty(STACK hStack);

char stack_top(STACK hStack, Status* pStatus);

void stack_destroy(STACK* phStack);

#endif