#include <stdio.h>
#include <stdlib.h>
/**********************************************************************
Program:Reverse_Linked_List
Author:Santhosh Pothineni
Purpose: This program creates a linked list then calls a the reverse_list function
to reverse the list before printing out the reveresed list.
***********************************************************************/

struct node;
typedef struct node Node;

struct node
{
	int data;
	Node* next;
};

void reverse_list(Node** pNode);


int main(int argc, char* argv[])
{
	Node* head = NULL;
	int i;
	Node* temp;
	for (i = 0; i < 10; i++)
	{
		temp = (Node*)malloc(sizeof(Node));
		if (temp == NULL)
		{
			printf("out of memory?\n");
			exit(1);
		}
		temp->data = i;
		temp->next = head;
		head = temp;
	}

	reverse_list(&head);

	temp = head;
	while (temp != NULL)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	}

	return 0;
}

void reverse_list(Node** pNode)
{
	if ((*pNode) == NULL || (*pNode)->next == NULL)
	{
		return;
	}
	Node* prev = NULL;
	Node* next = NULL;
	Node* current = *pNode;

	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	*pNode = prev;
	

}