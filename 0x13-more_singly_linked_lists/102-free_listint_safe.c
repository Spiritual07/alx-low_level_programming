#include "lists.h"

/**
 * free_listint_safe - function that frees a listint_t list.
 * @h: pointer to pointer to the first element in the list
 * Return: the size of the list that was free’d
 */

size_t free_listint_safe(listint_t **h)
{
	size_t n_count = 0;
	/* Declare pointers to the custom auxiliary linked list structure */
	Alist_t *head, *newNode, *temp;
	listint_t *curr;

	head = NULL;/* initialize head of auxiliary list to NULL */
	/* Traverse the original linked list */
	while (*h != NULL)
	{
		newNode = (Alist_t *)malloc(sizeof(Alist_t));
		if (newNode == NULL)
			exit(98);
	/* assign value of head to the p member of the newNode in auxiliary list. */
		newNode->p = (void *)*h;
	/* set newNode's next pointer to point to current head of auxiliary list */
		newNode->next = head;
	/* updates the head of the auxiliary list to the newly created node.*/
		head = newNode;
	/* initializes the temp pointer to the head of the auxiliary list. */
		temp = head;
	/* Check for a loop in the original linked list */
		while (temp->next != NULL)
		{
			temp = temp->next;
			if (*h == temp->p)
			{
				*h = NULL;
				free_Alist2(&head); /* free auxiliary link list */
				return (n_count);
			}
		}
		curr = *h;
		*h = (*h)->next;
		free(curr);
		n_count++;
	}
	*h = NULL;
	free_Alist2(&head);
	return (n_count);
}
/**
 * free_Alist2 - frees a linked list
 * @head: pointer to first element on the list
 */
void free_Alist2(Alist_t **head)
{
	Alist_t *temp, *curr_node;

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
