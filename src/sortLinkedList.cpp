/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};
struct node* MergeSort(struct node** headref);//for performing sorting
struct node* SortedList(struct node* subist1, struct node* sublist2);//for sorting sublists.
void divide_list(struct node* start,
struct node** sublist1ref, struct node** sublist2ref);//for dividing given list into two parts
struct node * sortLinkedList(struct node *head)
{
	struct node *temp;
	temp = MergeSort(&head);
	return temp;
}
struct node* MergeSort(struct node** headref)
{
	struct node* subhead = *headref;
	struct node* sublist1;
	struct node* sublist2;
	if ((subhead == NULL) || (subhead->next == NULL))//basecase
	{
		return *headref;
	}
	divide_list(subhead, &sublist1, &sublist2);
	MergeSort(&sublist1);// Recursively sort the sublists
	MergeSort(&sublist2);
	*headref = SortedList(sublist1, sublist2);//merging sublists.
	return *headref;
}

struct node* SortedList(struct node* sublist1, struct node* sublist2)
{
	struct node* orderlist = NULL;
	if (sublist1 == NULL)//base case
		return(sublist2);
	else if (sublist2 == NULL)
		return(sublist1);
	if (sublist1->num <= sublist2->num)
	{
		orderlist = sublist1;
		orderlist->next = SortedList(sublist1->next, sublist2);
	}
	else
	{
		orderlist = sublist2;
		orderlist->next = SortedList(sublist1, sublist2->next);
	}
	return(orderlist);
}
void divide_list(struct node* start,
struct node** sublist1ref, struct node** sublist2ref)
{
	struct node* highlist;
	struct node* lowlist;
	if (start == NULL || start->next == NULL)
	{
		*sublist1ref = start;
		*sublist2ref = NULL;
	}
	else
	{
		lowlist = start;//dividing list into two parts
		highlist = start->next;
		while (highlist != NULL)
		{
			highlist = highlist->next;
			if (highlist != NULL)
			{
				lowlist = lowlist->next;
				highlist = highlist->next;
			}
		}

		*sublist1ref = start;
		*sublist2ref = lowlist->next;
		lowlist->next = NULL;
	}
}

