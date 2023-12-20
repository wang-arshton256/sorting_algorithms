#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/**
 * enum kind_e - kinds of cards
 * @SPADE: - spade
 * @HEART: - heart
 * @CLUB: - club
 * @DIAMOND: - diamond
 */

typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Playing card
 *
 * @value: Value of the card
 * From "Ace" to "King"
 * @kind: Kind of the card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;


/**
 * struct deck_node_s - Deck of card
 *
 * @card: Pointer to the card of the node
 * @prev: Pointer to the previous node of the list
 * @next: Pointer to the next node of the list
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;


void print_list(const listint_t *list);
void print_array(const int *array, size_t size);

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
void sort_deck(deck_node_t **deck);


void swap(int *array, int idx);
listint_t *swap_list(listint_t **list, listint_t *back);
void swap_selection(int *arr, size_t min, size_t i);
void sort(int *arr, int low, int high, size_t size);
int partition(int *arr, size_t low, size_t high, size_t size);

void sort_list(int *arr, int left, int right, int *ptr);
void merge(int *arr, int left, int mid, int right, int *ptr);

void countingSort(int *arr, size_t size, int exp, int *output);
int findMax(int *arr, size_t size);
void bitonic_swap(int *arr, int i, int j, int order);
void bitonic_sequence(int *arr, int start, int no_elem, int order, int size);
void bitonic_merge(int *arr, int start, int no_elem, int order);
int hoare_partition(int *arr, int low, int high, size_t size);
void q_sort(int *arr, int low, int high, size_t size);

#endif

