#include "lists.h"

/**
 * print_listint_safe - function that prints a listint_t linked list.
 * @head: pointer to the first element in the list
 * Return: the number of nodes in the list
 */

size_t print_listint_safe(const listint_t *head)
{
	size_t n_count = 0;
	/* Declare pointers to the custom auxiliary linked list structure */
	Alist_t *h, *newNode, *temp;

	h = NULL;/* initialize head of auxiliary list to NULL */
	/* Traverse the original linked list */
	while (head != NULL)
	{
		/* allocate memory for new node in the auxiliary list */
		newNode = (Alist_t *)malloc(sizeof(Alist_t));
		/* check if memory allocation failed */
		if (newNode == NULL)
			exit(98);
	/* assign value of head to the p member of the newNode in auxiliary list. */
		newNode->p = (void *)head;
	/* set newNode's next pointer to point to current head of auxiliary list */
		newNode->next = h;
	/* updates the head of the auxiliary list to the newly created node.*/
		h = newNode;
	/* initializes the temp pointer to the head of the auxiliary list. */
		temp = h;
	/* Check for a loop in the original linked list */
		while (temp->next != NULL)
		{
			temp = temp->next;
			if (head == temp->p)
			{
				/* If a loop is found, print the node causing the loop */
				printf("-> [%p] %d\n", (void *)head, head->n);
				free_Alist(&h); /* free auxiliary link list */
				return (n_count);
			}
		}
	/* Print the current node of the original linked list */
		printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
		n_count++;
	}
	free_Alist(&h);
	return (n_count);
}

/**
 * free_Alist - frees a linked list
 * @head: pointer to first element on the list
 */
void free_Alist(Alist_t **head)
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
