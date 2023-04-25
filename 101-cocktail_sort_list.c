#include "sort.h"
/**
 * cocktail_sort_list - perform cocktail sort algorithm
 * @list: pointer to the list to sort
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *head, *aux1, *aux2;
	int swap_bool;

	if (list == NULL || *list == NULL)
		return;

	do {
		head = *list;
		swap_bool = 0;
		for (aux1 = head; aux1->next != NULL; aux1 = aux1->next)
		{
			if (aux1->n > aux1->next->n)
			{
				swapped(aux1);
				swap_bool = 1;
				aux1 = aux1->prev;
				if (aux1->prev == NULL)
					*list = aux1;
				print_list(*list);
			}
			if (aux1->next == NULL)
				break;
		}
		if (swap_bool != 1)
			break;
		swap_bool = 0;
		for (aux2 = aux1->prev; aux2 != NULL; aux2 = aux2->prev)
		{
			if (aux2->n > aux2->next->n)
			{
				swapped(aux2);
				swap_bool = 1;
				aux2 = aux2->prev;
				if (aux2->prev == NULL)
					*list = aux2;
				print_list(*list);
			}
		}
	} while (swap_bool == 1);
}
/**
 * swapped - make swap between nodes
 * @list: pointer to the node to swap
 * Return: void
 */
void swapped(listint_t *list)
{
	listint_t *next;

	if (list->prev != NULL)
		list->prev->next = list->next;
	list->next->prev = list->prev;
	if (list->next->next != NULL)
		list->next->next->prev = list;
	list->prev = list->next;
	next = list->next->next;
	list->next->next = list;
	list->next = next;
}
