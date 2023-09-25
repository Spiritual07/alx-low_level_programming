#include "lists.h"

/**
 * pop_listint - function that deletes the head node of a listint_t
 * linked list.
 * @head: pointer to the first element
 * Return: the head node's data(n)
 */

int pop_listint(listint_t **head)
{
	listint_t *temp;
	int n;

	if (*head == NULL)
	{
		return (0);
	}
	else
	{
		temp = *head;
		*head = (*head)->next;
		n = temp->n;
		free(temp);
	}
	return (n);
}
