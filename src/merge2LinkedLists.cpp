/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	if (head1==NULL && head2==NULL) //if both the lists are empty then return NULL as an error case
		return NULL;
	if (head1 == NULL)//if either of the list is empty return the other the list
		return head2;
	if (head2 == NULL)
		return head1;
	struct node *current;
	current = head1;//take a pointer and assign to starting of the first list
	while (current->next != NULL)// tranverse the first list until we reach the last node
		current = current->next;
	current->next = head2;// to last node attach new list2 or head2 
	struct node *temp1, *temp2;//take two temporary node pointers
	int temp;//an integer for sorting 
	for (temp1 = head1; temp1->next != NULL; temp1 = temp1->next)//sort the list1
	{
		for (temp2 = temp1->next; temp2 != NULL; temp2 = temp2->next)
		{
			if (temp1->num > temp2->num)
			{
				temp = temp1->num;
				temp1->num = temp2->num;
				temp2->num = temp;
			}
		}
	}
	return head1;//return list1 or head1
}
