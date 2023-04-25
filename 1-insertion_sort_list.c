#include "sort.h"
/**
 * insertion_sort_list - perform insertion sort algorithm
 * @list: list passed by reference
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *previous, *next, *insert_nxt, *temp;
	int movement, go_swap;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	for (temp = *list; temp != NULL; temp = next)
	{
		movement = 0;
		go_swap = 0;
		previous = temp->prev;
		next = temp->next;
		if (previous != NULL && previous->n > temp->n)
			go_swap = 1;
		while (previous != NULL && go_swap == 1)
		{
			if (previous->n < temp->n)
				break;
			if (previous->prev == NULL)
				insert_nxt = previous;
			previous = previous->prev;
			if (previous)
				insert_nxt = previous->next;
			movement++;
			if (movement != 0)
			{
				if (previous == NULL)
					*list = temp;
				temp->prev->next = temp->next;
				if (temp->next != NULL)
					temp->next->prev = temp->prev;
				temp->next = insert_nxt;
				temp->prev = previous;
				if (previous)
					previous->next = temp;
				insert_nxt->prev = temp;
				print_list(*list);
			}
		}
	}
}
