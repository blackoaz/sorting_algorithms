#include "sort.h"

/**
 * swap_node - function for swapping a doubly linked list
 * @list: list to be sorted
 * @first_n: left list to be sorted
 * @next_n: next list to be sorted
 * Return: returns a void
 */
void swap_node(listint_t **list, listint_t *first_n, listint_t *next_n)
{
	first_n->next = next_n->next;
	if (next_n->next != NULL)
		next_n->next->prev = first_n;
	next_n->prev = first_n->prev;
	next_n->next = first_n;
	if (first_n->prev != NULL)
		first_n->prev->next = next_n;
	else
		*list = next_n;
	first_n->prev = next_n;
	first_n = next_n->prev;
}

/**
 * insertion_sort_list - function that sorts a doubly linked list of
 * integers in ascending order using the Insertion sort algorithm
 *
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
			swap_node(list, next, node);
			print_list(*list);
			node = (*list)->next;
		}
		else
			node = node->next;
	}
}
