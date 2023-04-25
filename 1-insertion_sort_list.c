#include "sort.h"

void insert_node(listint_t **list, listint_t *j, listint_t *i);
void insertion_sort_list(listint_t **list)
{
	listint_t *i, *j;
	int swapped;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	j = (*list)->next;
	while (j)
	{
		i = *list;
		swapped = 0;
		while (1)
		{
			if (i == j)
			{
/*				print_list(*list);*/
				break;
			}
			if (i->n > j->n)
			{
				insert_node(list, j, i);
				swapped = 1;
/*				print_list(*list);*/
				break;
			}
			i = i->next;
		}
		if (swapped)
			print_list(*list);
		j = j->next;
	}
}

void insert_node(listint_t **list, listint_t *j, listint_t *i)
{
	j->prev->next = j->next;
	if (j->next)
		j->next->prev = j->prev;

	j->prev = i->prev;
	if (i->prev)
		i->prev->next = j;
	else
		*list = j;
	i->prev = j;
	j->next = i;
}
