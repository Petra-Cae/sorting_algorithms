#include "sort.h"

/**
* insertion_sort_list - Sorts a doubly linked list of integers in
*		ascending order using the Insertion sort algorithm
* @list: The doubly linked list to be sorted
*
* Return: void
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *nwnode = NULL, *tmp = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	nwnode = *list;
	nwnode = nwnode->next;
	while (nwnode)
	{
		while (nwnode->prev && nwnode->n < (nwnode->prev)->n)
		{
			tmp = nwnode;
			if (nwnode->next)
				(nwnode->next)->prev = tmp->prev;
			(nwnode->prev)->next = tmp->next;

			nwnode = nwnode->prev;
			tmp->prev = nwnode->prev;
			tmp->next = nwnode;

			if (nwnode->prev)
				(nwnode->prev)->next = tmp;

			nwnode->prev = tmp;

			if (tmp->prev == NULL)
				*list = tmp;

			print_list(*list);
			nwnode = nwnode->prev;
		}
		nwnode = nwnode->next;
	}

}
