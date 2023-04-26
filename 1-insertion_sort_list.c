#include "sort.h"
/**
 * swap_nodes - function for swapping nodes
 * @head: head of the list
 * @val1: the first node
 * @val2: the second node
 * Return: returns a void
 */
void swap_nodes(listint_t **list, listint_t *val1, listint_t *val2)
{
	val1->next = val2->next;
	if (val2->next != NULL)
		val2->next = val1;
	val2->prev = val1->prev;
	val2->next = val1;

	if (val1->prev != NULL)
		val1->prev->next = val2;
	else
		*list = val2;
	val1->prev = val2;
	val1 = val2->prev;
}

/**
 * insertion_sort_list - function for performing insertion sort
 * @list: list to be sorted
 * Return: returns a void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *node, *next;

	node = malloc(sizeof(listint_t));
	next = malloc(sizeof(listint_t));

	if (list == NULL || node == NULL || next == NULL)
		return;
	node = *list;
	node = node->next;
	while (node)
	{
		next = node->prev;
		if (next->n > node->n)
		{
			swap_nodes(list, next, node);
			print_list(*list);
			node = (*list)->next;
		}
		else
			node = node->next;
	}
}
