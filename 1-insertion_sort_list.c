#include "sort.h"

void insert_node(listint_t **list, listint_t *j, listint_t *i);

/**
* insertion_sort_list - function that sorts a doubly linked list of
* integers in ascending order
* @list: pointer to pointer at head of list
*
* Return: void
*/
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
			if (i->n > j->n)
			{
				insert_node(list, j, i);
				print_list(*list);
				break;
			}
			i = i->next;
		}
		j = j->next;
	}
}

/**
* insert_node - insert a node before another in a list
* @list: pointer to pointer at head of list
* @j: node to insert
* @i: node before insertion
*
* Return: void
*/
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
