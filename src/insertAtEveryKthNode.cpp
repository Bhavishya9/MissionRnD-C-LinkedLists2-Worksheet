/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * insertAtEveryKthNode(struct node *head, int K) {
	if (head==NULL || K<=0)//if the list is empty or if the value of k is less than or equal
		return NULL;//to zero identify as an error case and return NULL
	int length=0;//length variable is used to find the length of the list
	struct node *current;
	current = head;
	while (current != NULL)//find the length of the list by tranversing the entire list
	{
		length++;
		current = current->next;
	}
	if (K > length)//check if the value of the K is greater than length
		return head; //return the list as it is
	current = head;//else insert the values into the list
	int pos = 0;//use pos variable to keep a track of the list
	while (current != NULL)//tranverse the list till the end
	{
		pos++;//increment the pos at every iteration to value of current position
		if (pos%K == 0)//if the value of position of pointer is divisible by K then insert 
		{				//node into the list
			struct node *temp = (struct node*)malloc(sizeof(struct node));//create a node using temp variable
			temp->num = K;//in the num field assign the value of K 
			temp->next = current->next;//temp address field holds the address which is held by current pointer
			current->next = temp; //attach the temp node to the list
			current = temp;//assign the current to temp node
		}
		current = current->next;//tranverse to the next node 
	}
	return head;//return the modified list 
}
