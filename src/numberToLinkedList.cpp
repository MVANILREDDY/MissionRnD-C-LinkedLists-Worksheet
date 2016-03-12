/*
OVERVIEW:  Given a number convert that to single linked list (each digit as a node).
E.g.: Input: 234, Output: 2->3->4.

INPUTS:  A number.

OUTPUT: Create linked list from given number, each digit as a node.

ERROR CASES: 

NOTES: For negative numbers ignore negative sign.
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * numberToLinkedList(int N) 
{
	struct node* store, *head = NULL;
	if (N == 0)
	{
		store = (struct node*)malloc(1 * sizeof(struct node));
		store->num = 0;
		store->next = head;
		head = store;
	}
	else{
		if (N<0)
		{
			N = N*-1;
		}
		while (N)
		{
			store = (struct node*)malloc(1 * sizeof(struct node));
			store->next = head;
			store->num = N % 10;
			N = N / 10;
			head = store;
		}
	}

	return head;
}
