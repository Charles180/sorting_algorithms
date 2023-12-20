#include "sort.h"

void swaps_ahead_node(listint_t **list, listint_t **tail, listint_t **shaker);
void swaps_behind_node(listint_t **list, listint_t **tail, listint_t **shaker);
void cocktail_sort_list(listint_t **list);

/**
 * swaps_ahead_node - Swap a node in a listint_t doubly-linked list
 *                   list of integers with the node ahead of it.
 * @list: A ptr to the head of a doubly-linked list of integers.
 * @tail: A ptr to the tail of the doubly-linked list.
 * @shaker_s: A ptr to the current swap node of the cocktail shaker_sort.
 */
void swaps_ahead_node(listint_t **list, listint_t **tail, listint_t **shaker_s)
{
	listint_t *tmp = (*shaker_s)->next;

	if ((*shaker_s)->prev != NULL)
		(*shaker_s)->prev->next = tmp;
	else
		*list = tmp;
	tmp->prev = (*shaker_s)->prev;
	(*shaker_s)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *shaker_s;
	else
		*tail = *shaker_s;
	(*shaker_s)->prev = tmp;
	tmp->next = *shaker_s;
	*shaker_s = tmp;
}

/**
 * swap_behind_node - Swap a node in a listint_t doubly-linked
 *                    list of integers with the node behind it.
 * @list: A ptr to the head of a doubly-linked list of integers.
 * @tail: A ptr to the tail of the doubly-linked list.
 * @shaker_s: A ptr to the current swapping_node of the algorithm.
 */
void swap_behind_node(listint_t **list, listint_t **tail, listint_t **shaker_s)
{
	listint_t *tmp = (*shaker_s)->prev;

	if ((*shaker_s)->next != NULL)
		(*shaker_s)->next->prev = tmp;
	else
		*tail = tmp;
	tmp->next = (*shaker_s)->next;
	(*shaker_s)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *shaker_s;
	else
		*list = *shaker_s;
	(*shaker_s)->next = tmp;
	tmp->prev = *shaker_s;
	*shaker_s = tmp;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers in
 *                      ascending order using the cocktail shaker_s algorithm.
 * @list: A ptr to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *shaker_s;
	bool shaken_not_stirred = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (shaken_not_stirred == false)
	{
		shaken_not_stirred = true;
		for (shaker_s = *list; shaker_s != tail; shaker_s = shaker_s->next)
		{
			if (shaker_s->n > shaker_s->next->n)
			{
				swaps_ahead_node(list, &tail, &shaker_s);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
		for (shaker_s = shaker_s->prev; shaker_s != *list;
				shaker_s = shaker_s->prev)
		{
			if (shaker_s->n < shaker_s->prev->n)
			{
				swap_behind_node(list, &tail, &shaker_s);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
	}
}
