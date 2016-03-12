/*
OVERVIEW:  Given a single linked list (two digits as a node).Convert that to number


INPUTS:  SLL head pointer

OUTPUT: Create a number from the linked list given ,In each node there are two numbers ,digit1 and digit1 ,
So if the nodes are 12->34->56->78 , Final number would be 12345678 ( Integer)

ERROR CASES:

NOTES: Only Postive Numbers
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int digit1;
	int digit2;
	struct node *next;
};

int convert_sll_2digit_to_int(struct node *head)
{
	int n = 0;
	struct node *load;
	load = head;
	while (load != NULL)
	{
		printf("load values are%d\t%d\n", load->digit1, load->digit2);
		n = n + (10 * load->digit1) + (load->digit2);
		printf("n value is %d\n", n);
		load = load->next;
		n = n * 100;
	}
	n = n / 100;
	return n;
}
