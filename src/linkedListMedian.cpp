/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {

	if (head == NULL)//check if the list is empty
		return -1;
	struct node *temp;
	temp = head;
	int pos, flag = 0, median, count = 0;
	while (temp != NULL)//count the no of elements in the list
	{
		count++;
		temp = temp->next;
	}
	if (count % 2 != 0)//check if the no of elements in the list are odd or even.
	{
		pos = (count + 1) / 2;// if no of elements in the list are odd then store the position of  mid element
	}
	else
	{
		pos = (count + 1) / 2;// if no of elements in the list are even then store the position of  mid element and
		flag = 1;//set flag to 1 to know that no of elements are even.
	}
	temp = head;
	int index = 1;
	while (index<pos)//traverse the list
	{
		temp = temp->next;
		index++;
	}
	median = temp->num; // store the value of mid element in median
	if (flag == 0) // if no of elements is odd then return the value of median
		return median;
	else //if no of elements is even the take of average of the two mid elements 
	{
		temp = temp->next;
		median = (median + temp->num) / 2;
		return median; // return the mid element
	}
}
