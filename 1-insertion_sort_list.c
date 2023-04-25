#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

void insert_node(listint_t **list, listint_t *j, listint_t *i);
void insertion_sort_list(listint_t **list)
{
	listint_t *i, *j;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	j = (*list)->next;
	while (j)
	{
		i = *list;
		while (1)
		{
			if (i == j)
				break;
			if (i == NULL)
				printf("i is NULL\n"), exit(1);
			if (j == NULL)
				printf("j is NULL\n"), exit(1);
			if (i->n > j->n)
			{
				insert_node(list, j, i);
				print_list(*list);
			}
			i = i->next;
		}
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
