#include "lists.h"

/**
 * free_listint2 - function that frees a listint_t list.
 * @head: pointer to the pointer to head
 */

void free_listint2(listint_t **head)
{
	listint_t *temp, *curr_node;

	if (head != NULL)
	{
		curr_node = *head;
		while ((temp = curr_node) != NULL)
		{
			curr_node = curr_node->next;
			free(temp);
		}
	*head = NULL;
	}
}
