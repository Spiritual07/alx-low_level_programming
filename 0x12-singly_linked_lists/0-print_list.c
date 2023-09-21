#include "lists.h"

/**
 * print_list - function that prints all the elements of a list_t list.
 * @h: pointer to the first elemet in the list
 * Return: the number of nodes
 */

size_t print_list(const list_t *h)
{
	size_t count = 0; /*variable to keep track of number of nodes */

	/* transverse through the link list and print it elements */
	while (h != NULL)
	{
		if (h->str == NULL)
		{
			printf("[0] (nil)\n");
		}
		else
		{
			printf("[%d] %s\n", h->len, h->str);
		}
		h = h->next; /* goto the next element */
		count++; /* increemnet count to keep track of number of nodes */
	}
	return (count);
}
