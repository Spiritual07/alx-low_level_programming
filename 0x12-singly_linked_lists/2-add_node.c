#include "lists.h"

/**
 * add_node - function that adds a new node at
 * the beginning of a list_t list.
 * @head: pointer to the first element
 * @str: pointer tp element in the linked list
 * Return: pointer to the newly created node
 */

list_t *add_node(list_t **head, const char *str)
{
	list_t *node1;/* declare pointer to the new node */

	/* allocate memory to the new node */
	node1 = (list_t *)malloc(sizeof(list_t));
	/* check if memory allocation failed and return NULL */
	if (node1 == NULL)
	{
		return (NULL);
	}
	/* initialize members of the new node */
	node1->str = strdup(str);
	node1->len = strlen(str);

	/* sets the next member of the new node to point */
	/* to the current head of the linked list. */
	node1->next = *head;
	/* update the head of the linked list to be the new node. */
	*head = node1;

	return (node1);
}
