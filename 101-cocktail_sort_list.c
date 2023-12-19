#include "sort.h"

void swap_node_fwd(listint_t **list, listint_t **tail, listint_t **cnode);
void swap_node_bwd(listint_t **list, listint_t **tail, listint_t **cnode);
void cocktail_sort_list(listint_t **list);

/**
 * swap_node_fwd - Swap a node in a listint_t doubly-linked list
 * with the node ahead of it.
 * @list: A pointer to head of doubly-linked list
 * @tail: A pointer to the tail of doubly-linked list.
 * @cnode: A pointer to the current swapping node
 */

void swap_node_fwd(listint_t **list, listint_t **tail, listint_t **cnode)
{
	listint_t *tempo = (*cnode)->next;

	if ((*cnode)->prev != NULL)
		(*cnode)->prev->next = tempo;
	else
		*list = tempo;
	tempo->prev = (*cnode)->prev;
	(*cnode)->next = tempo->next;
	if (tempo->next != NULL)
		tempo->next->prev = *cnode;
	else
		*tail = *cnode;
	(*cnode)->prev = tempo;
	tempo->next = *cnode;
	*cnode = tempo;
}

/**
 * swap_node_bwd - Swap a node in a doubly-linked
 * with the node behind it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @cnode: A pointer to the current swapping node
 */

void swap_node_bwd(listint_t **list, listint_t **tail, listint_t **cnode) 
{
	listint_t *tempo = (*cnode)->prev;

	if ((*cnode)->next != NULL)
		(*cnode)->next->prev = tempo;
	else
		*tail = tempo;
	tempo->next = (*cnode)->next;
	(*cnode)->prev = tempo->prev;
	if (tempo->prev != NULL)
		tempo->prev->next = *cnode;
	else
		*list = *cnode;
	(*cnode)->next = tempo;
	tempo->prev = *cnode;
	*cnode = tempo;
}

/**
 * cocktail_sort_list - Sort a doubly-linked list in
 * ascending order using the cocktail shaker algorithm.
 * @list: A pointer to the head of doubly-linked list.
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *cnode;
	bool sns = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (sns == false)
	{
		sns = true;
		for (cnode = *list; cnode != tail; cnode = cnode->next)
		{
			if (cnode->n > cnode->next->n)
			{
				swap_node_fwd(list, &tail, &cnode);
				print_list((const listint_t *)*list);
				sns = false;
			}
		}
		for (cnode = cnode->prev; cnode != *list;
				cnode = cnode->prev)
		{
			if (cnode->n < cnode->prev->n)
			{
				swap_node_bwd(list, &tail, &cnode);
				print_list((const listint_t *)*list);
				sns = false;
			}
		}
	}
}
