/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * removeEveryKthNode(struct node *head, int K) 
{
	struct node *con, *precon;
	int count = 0;
	if (K>0&&head!=NULL)
	{
		if (K == 1)
		{
			return NULL;
		}
		else{
			con = head;
			precon = con;
			while (con->next != NULL)
			{
				if (count == K - 1)
				{
					count = 0;
					precon->next = con->next;//deleting K th node;
					con = con->next;
				}
				else
				{
					precon = con;
					con = con->next;
					count++;
				}
			}
			if (count == K - 1)
			{
				precon->next = NULL;
			}
			return head;
		}
	}
	else
	{
		return NULL;
	}

}
