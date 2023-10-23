#include "sort.h"


/**
 *swap - swap a node for his previous one
 *@node: node
 *@list: node list
 *Return: return a pointer to a node which was enter it
 */
listint_t *swap(listint_t *node, listint_t **list)
{
	listint_t *prev_node = node->prev, *current_node = node;

	prev_node->next = current_node->next;
	if (current_node->next)
		current_node->next->prev = prev_node;
	current_node->next = prev_node;
	current_node->prev = prev_node->prev;
	prev_node->prev = current_node;
	if (current_node->prev)
		current_node->prev->next = current_node;
	else
		*list = current_node;
	return (current_node);
}


/**
 * insertion_sort_list - function that sorts a doubly linked list
 * of integers in ascending order using the Insertion sort algorithm
 * @list: Dobule linked list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node;

	if (list == NULL || (*list)->next == NULL)
		return;
	node = (*list)->next;
	while (node)
	{
		while ((node->prev) && (node->prev->n > node->n))
		{
			node = swap(node, list);
			print_list(*list);
		}
		node = node->next;
	}
}
