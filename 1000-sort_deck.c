#include "deck.h"

int _strcmp(const char *s1, const char *s2);
char get_value(deck_node_t *card);
void insertion_sort_deck_kind(deck_node_t **deck);
void insertion_sort_deck_value(deck_node_t **deck);
void sort_deck(deck_node_t **deck);

/**
  *_strcmp - The function that compares two strings
  *
  *@s1: The first string to be compared
  *
  *@s2: The second string to be compared.
  *
  *Return: +ve byte diff if s1 > s2
  *		0 if s1 == s2
  *		-ve byte difference if s1 < s2
  */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (*s1 != *s2)
		return (*s1 - *s2);
	return (0);
}

/**
  *get_value - Fuction that gets num var of cards
  *
  *@card: Pointer for deck_node_t card.
  *
  *Return: The numerical value of the card.
  */
char get_value(deck_node_t *card)
{
	if (_strcmp(card->card->value, "Ace") == 0)
		return (0);
	if (_strcmp(card->card->value, "1") == 0)
		return (1);
	if (_strcmp(card->card->value, "2") == 0)
		return (2);
	if (_strcmp(card->card->value, "3") == 0)
		return (3);
	if (_strcmp(card->card->value, "4") == 0)
		return (4);
	if (_strcmp(card->card->value, "5") == 0)
		return (5);
	if (_strcmp(card->card->value, "6") == 0)
		return (6);
	if (_strcmp(card->card->value, "7") == 0)
		return (7);
	if (_strcmp(card->card->value, "8") == 0)
		return (8);
	if (_strcmp(card->card->value, "9") == 0)
		return (9);
	if (_strcmp(card->card->value, "10") == 0)
		return (10);
	if (_strcmp(card->card->value, "Jack") == 0)
		return (11);
	if (_strcmp(card->card->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
  *insertion_sort_deck_kind - Fuction that Sort a deck.
  *
  *@deck: A pointer to the head of a deck_node_t doubly-linked list.
  */
void insertion_sort_deck_kind(deck_node_t **deck)
{
	deck_node_t *iteration, *insert, *temporary;

	for (iteration = (*deck)->next; iteration != NULL; iteration = temporary)
	{
		temporary = iteration->next;
		insert = iteration->prev;
		while (insert != NULL && insert->card->kind > iteration->card->kind)
		{
			insert->next = iteration->next;
			if (iteration->next != NULL)
				iteration->next->prev = insert;
			iteration->prev = insert->prev;
			iteration->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = iteration;
			else
				*deck = iteration;
			insert->prev = iteration;
			insert = iteration->prev;
		}
	}
}

/**
 * insertion_sort_deck_value - Sort a deck of cards sorted from
 *                             spades to diamonds from ace to king.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void insertion_sort_deck_value(deck_node_t **deck)
{
	deck_node_t *iteration, *insert, *temporary;

	for (iteration = (*deck)->next; iteration != NULL; iteration = temporary)
	{
		temporary = iteration->next;
		insert = iteration->prev;
		while (insert != NULL &&
		       insert->card->kind == iteration->card->kind &&
		       get_value(insert) > get_value(iteration))
		{
			insert->next = iteration->next;
			if (iteration->next != NULL)
				iteration->next->prev = insert;
			iteration->prev = insert->prev;
			iteration->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = iteration;
			else
				*deck = iteration;
			insert->prev = iteration;
			insert = iteration->prev;
		}
	}
}

/**
  *sort_deck - Another sort function
  *
  *@deck: Pointer to the head of a deck_node_t doubly-linked list.
  */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	insertion_sort_deck_kind(deck);
	insertion_sort_deck_value(deck);
}
