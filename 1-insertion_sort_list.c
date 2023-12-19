#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked
 * list of integers in ascending order using the Insertion sorting
 * @list: to be sorted
 * Return: no return
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *ptr;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	ptr = (*list)->next;
	while (ptr != NULL)
	{
		while (ptr->prev != NULL && ptr->n < ptr->prev->n)
		{
			ptr = swap_list(list, ptr);
			print_list(*list);
		}
		ptr = ptr->next;
	}
}


/**
 * swap_list - swaps the node with the previous node
 * @list: the linked list
 * @node: node to be swaped
 * Return: The current node
 */

listint_t *swap_list(listint_t **list, listint_t *node)
{
	listint_t  *current = node, *back = node->prev;

	current->prev = back->prev;
	back->next = current->next;
	if (current->next)
		current->next->prev = back;
	current->next = back;
	if (back->prev)
		back->prev->next = current;
	else
		*list = current;
	back->prev = current;

	return (current);

}
