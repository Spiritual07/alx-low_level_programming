#include "lists.h"

/**
 * free_list - function that frees a list_t list.
 * @head: pointer to the first member of the list
 */


void free_list(list_t *head)
{
	list_t *temp;
	list_t *next;

	temp = head;
	while (temp != NULL)
	{
		next = temp->next;
		free(temp->str); /* free the string */
		free(temp); /* free the node */
		temp = next;
	}
}
