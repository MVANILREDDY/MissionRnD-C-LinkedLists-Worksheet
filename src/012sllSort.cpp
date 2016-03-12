/*
OVERVIEW:  Given a single linked list of 0s 1s and 2s ,Sort the SLL such that zeroes 
will be followed by ones and then twos.


INPUTS:  SLL head pointer

OUTPUT: Sorted SLL ,Head should Finally point to an sll of sorted 0,1,2


ERROR CASES:

NOTES: Only 0,1,2, will be in sll nodes
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int data;
	struct node *next;
};
void sll_012_sort(struct node *head)
{
	struct node *itr;

	int low = 0, mid = 0, high = 0, count = 0;
	itr = head;
	while (itr != NULL)
	{

		(itr->data == 2) ? high++ : itr->data == 1 ? mid++ : low++;
		itr = itr->next;
		count++;
	}
	itr = head;//itr node is used to traverse entire linkedlist
	while (count)
	{
		if (low)
		{
			itr->data = 0;
			itr = itr->next;
			low--;
		}
		else if (mid)
		{
			itr->data = 1;
			itr = itr->next;
			mid--;
		}
		else
		{
			itr->data = 2;
			itr = itr->next;
		}
		count--;
	}
}
