#include "deck.h"

/**
 * sort_deck - sorts a deck of calrds in acsending order
 * @deck: pointer to the deck of cards
 */

void sort_deck(deck_node_t **deck)
{
	deck_node_t *temp = *deck;
	int i;
	const card_t **cards = malloc(sizeof(card_t *) * 52);

	if (!deck || !(*deck))
		return;

	create_array(*deck, cards);
	qsort(cards, 52, sizeof(const card_t *), comp);
	for (i = 0; i < 52; i++, temp = temp->next)
		temp->card = cards[i];


}

/**
 * create_array - creates an array from a linked list
 * @deck: deck of cards
 * @cards: array of cards to be created
 */

void create_array(deck_node_t *deck, const card_t **cards)
{
	int i;
	deck_node_t *temp = deck;

	for (i = 0; i < 52; i++, temp = temp->next)
		cards[i] = temp->card;
}

/**
 * comp - comparison function
 * @a: first item
 * @b: second item
 * Return: a negetive, positive or 0
 */

int comp(const void *a, const void *b)
{
	const card_t *A = *(const card_t **)a;
	const card_t *B = *(const card_t **)b;
	int value_a, value_b, i;
	static const char * const values[] = {"Ace", "2", "3",
		"4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

	if (A->kind != B->kind)
		return (A->kind - B->kind);


	for (i = 0; i < 13; i++)
	{
		if (my_strcmp(A->value, values[i]) == 0)
			value_a = i;
		if (my_strcmp(B->value, values[i]) == 0)
			value_b = i;
	}
	return (value_a - value_b);

}

/**
 * my_strcmp -this function compares two strings.
 * @str1: the first to be string
 * @str2: second string.
 * Return: 0 on success 1 on failure
 */

int my_strcmp(const char *str1, const char *str2)
{
	if (str1 == NULL || str2 == NULL)
		return (1);
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return ((const unsigned char)*str1 - (const unsigned char)*str2);
}
