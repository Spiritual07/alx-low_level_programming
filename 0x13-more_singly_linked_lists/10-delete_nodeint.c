#include "lists.h"

/**
 * delete_nodeint_at_index - function that deletes the node at
 * index index of a listint_t linked list
 * @head: pointer to the pointer to the first element
 * @index: index of the node that should be deleted. Index starts at 0
 * Return: 1 if it succeeded, -1 if it failed
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int x;
	listint_t *temp, *delNode;

	temp = *head;
	if (temp == NULL)
	{
		return (-1);
	}
	if (index == 0)
	{
		*head = temp->next;
		free(temp);
		return (1);
	}
	/* find the node before the node to be deleted */
	for (x = 0; temp != NULL && x < index - 1; x++)
	{
		temp = temp->next;
	}
	/* check if position is more than the number of nodes */
	if (temp == NULL || temp->next == NULL)
	{
		return (-1);
	}
	/* temp->next is node to be deleted */
	/* store pointer to next of node to be deleted */
	delNode = temp->next->next;
	free(temp->next); /* free memory allocated to deleted node */
	temp->next = delNode; /* unlink deleted node from list */

	return (1);
}
