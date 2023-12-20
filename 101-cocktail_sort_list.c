#include "sort.h"

void swaps_ahead_node(listint_t **list, listint_t **tail, listint_t **shaker);
void swaps_behind_node(listint_t **list, listint_t **tail, listint_t **shaker);
void cocktail_sort_list(listint_t **list);

/**
 * swaps_ahead_node - Swap a node in a listint_t doubly-linked list
 *                   list of integers with the node ahead of it.
 * @list: A ptr to the head of a doubly-linked list of integers.
 * @tail: A ptr to the tail of the doubly-linked list.
 * @shaker_sort: A ptr to the current swap node of the cocktail shaker_sort.
 */
void swaps_ahead_node(listint_t **list, listint_t **tail, listint_t **shaker_sort)
{
	listint_t *tmp = (*shaker_sort)->next;

	if ((*shaker_sort)->prev != NULL)
		(*shaker_sort)->prev->next = tmp;
	else
		*list = tmp;
	tmp->prev = (*shaker_sort)->prev;
	(*shaker_sort)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *shaker_sort;
	else
		*tail = *shaker_sort;
	(*shaker_sort)->prev = tmp;
	tmp->next = *shaker_sort;
	*shaker_sort = tmp;
}

/**
 * swaps_behind_node - Swap a node in a listint_t doubly-linked
 *                    list of integers with the node behind it.
 * @list: A ptr to the head of a doubly-linked list of integers.
 * @tail: A ptr to the tail of the doubly-linked list.
 * @shaker_sort: A pointer to the current swapping node of the cocktail shaker_sort algo.
 */
void swaps_behind_node(listint_t **list, listint_t **tail, listint_t **shaker_sort)
{
	listint_t *tmp = (*shaker_sort)->prev;

	if ((*shaker_sort)->next != NULL)
		(*shaker_sort)->next->prev = tmp;
	else
		*tail = tmp;
	tmp->next = (*shaker_sort)->next;
	(*shaker_sort)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *shaker_sort;
	else
		*list = *shaker_sort;
	(*shaker_sort)->next = tmp;
	tmp->prev = *shaker_sort;
	*shaker_sort = tmp;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers in
 *                      ascending order using the cocktail shaker_sort algorithm.
 * @list: A ptr to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *shaker_sort;
	bool shaken_not_stirred = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (shaken_not_stirred == false)
	{
		shaken_not_stirred = true;
		for (shaker_sort = *list; shaker_sort != tail; shaker_sort = shaker_sort->next)
		{
			if (shaker_sort->n > shaker_sort->next->n)
			{
				swaps_ahead_node(list, &tail, &shaker_sort);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
		for (shaker_sort = shaker_sort->prev; shaker_sort != *list;
				shaker_sort = shaker_sort->prev)
		{
			if (shaker_sort->n < shaker_sort->prev->n)
			{
				swaps_behind_node(list, &tail, &shaker_sort);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
	}
}
