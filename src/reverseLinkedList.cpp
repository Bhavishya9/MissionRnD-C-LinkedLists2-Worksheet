/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * reverseLinkedList(struct node *head) {
	if (head==NULL)//if the input list is empty identify as error case and return NULL
		return NULL;
	struct node *current, *prev, *successor;//take three pointers of type structure node
	prev = NULL;
	current = head;//assign the current to start of the list
	while (current != NULL)//tranverse till the end of the list
	{
		successor = current->next;//node next to present node is assigned as successor
		current->next = prev;//break the connection with node and the list and make it point to its predecessor
		prev = current;//prev is the present node
		current = successor;//continue to tranverse list by re assigning the present with successor node
	}
	head = prev;//reassign the head pointer or change the start of the list
	return head;//return the reversed list
}
