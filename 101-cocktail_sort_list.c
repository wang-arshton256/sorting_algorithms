#include "sort.h"

/**
 * cocktail_sort_list - sorts a doubly linked list using cocktail_sort
 * in ascending order using the Cocktail shaker sort algorithm
 * @list: list to be sorted
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *temp;
	int swap = 0;

	if (!list || !(*list) || !(*list)->next)
		return;
	temp = *list;
	while (1)
	{
		swap = 0;
		while (temp->next)
		{
			if (temp->n > temp->next->n)
			{
				temp = swap_list(list, temp->next);
				print_list(*list);
				swap = 1;
			}
			temp = temp->next;
		}
		if (!swap)
			break;
		swap = 0;
		while (temp->prev)
		{
			if (temp->n < temp->prev->n)
			{
				temp = swap_list(list, temp);
				print_list(*list);
				swap = 1;
			}
			else
				temp = temp->prev;
		}
		if (!swap)
			break;
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
