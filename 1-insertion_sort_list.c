#include "sort.h"

/**
 * insertion_sort_list -  Sorts a doubly linked list of integers
 * in ascending order using the Insertion Sort algorithm
 * @list: The pointer to head of doubly linked list
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *head, *headprev, *headcpy;

	if (list == NULL || *list == NULL)
		return;
	head = *list;
	head = head->next;
	while (head != NULL)
	{
		headcpy = head;
		head = head->next;
		/* Traverse backward and move nodes forward until the right place is found*/
		while (headcpy->prev != NULL)
		{
			headprev = headcpy->prev;
			if (headcpy->n < headprev->n)
			{ /* Swap nodes if the current node is smaller than the previous one */
				headprev->next = headcpy->next;
				if (headcpy->next != NULL)
				{
					headcpy->next->prev = headprev;
				}
				headcpy->next = headprev;
				headcpy->prev = headprev->prev;
				if (headcpy->prev == NULL)
				{
					*list = headcpy;
				}
				else
					headprev->prev->next = headcpy;
				headprev->prev = headcpy;
				print_list(*list); /* Print the list after the swap */
			}
			else
				/* Break the loop if the current node is not smaller than the previous one */
				break;
		}
	}
}
