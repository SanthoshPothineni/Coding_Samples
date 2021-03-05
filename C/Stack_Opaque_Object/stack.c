#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/*********************************
Program:Stack.c
Author: Santhosh Pothineni
Purpose: Linked list implementation of a stack.
**********************************/

struct node;
typedef struct node Node;

struct node
{
	char data;
	Node* next;
};

struct stack
{
	Node* head;
};

typedef struct stack Stack;

STACK* stack_init_default(void)
{
	Stack* pStack;
	pStack = (Stack*)malloc(sizeof(Stack));
	if (pStack != NULL)
	{
		pStack->head = NULL;
	}

	return pStack;
}

Status stack_push(STACK hStack, char ch)
{
	Stack* pStack = (Stack*)hStack;
	Node* temp = (Node*)malloc(sizeof(Node));
	if (temp == NULL)
	{
		return FAILURE;
	}

	temp->data = ch;
	temp->next = pStack->head;
	pStack->head = temp;

	return SUCCESS;
}

Status stack_pop(STACK hStack)
{
	Stack* pStack = (Stack*)hStack;
	Node* temp = (Node*)malloc(sizeof(Node));
	if (temp == NULL)
	{
		return FAILURE;
	}

	temp = pStack->head;
	pStack->head = pStack->head->next;
	free(temp);

	return SUCCESS;
}

Boolean stack_is_empty(STACK hStack)
{
	Stack* pStack = (Stack*)hStack;
	
	return (Boolean)(pStack->head == NULL);
}

char stack_top(STACK hStack, Status* pStatus)
{
	Stack* pStack = (Stack*)hStack;
	if (stack_is_empty(hStack))
	{
		if (pStatus != NULL)
		{
			*pStatus = FAILURE;
		}

		return '^';
		
	}

	if (pStatus != NULL)
	{
		*pStatus = SUCCESS;
	}
	return pStack->head->data;

}

void stack_destroy(STACK* phStack)
{
	Stack* pStack = (STACK*)*phStack;
	Node* temp;

	while (pStack->head != NULL)
	{
		temp = pStack->head;
		pStack->head = pStack->head->next;
		free(temp);
	}

	free(pStack);
	*phStack = NULL;
}