#include "lists.h"

/**
 * insert_nodeint_at_index - function that inserts a new
 * node at a given position.
 * @head: pointer to the pointer to the first element
 * @idx:  index of the list where the new node should be added.
 * @n: place holder for integer element of new node.
 * Return: address of the new node, or NULL if it failed
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *newNode, *temp;
	unsigned int x;

	newNode = (listint_t *)malloc(sizeof(listint_t));
	if (newNode == NULL)
	{
		return (NULL);
	}
	newNode->n = n;
	newNode->next = NULL;
	if (*head == NULL)
	{
		if (idx > 0)
		{
			free(newNode);
			return (NULL);
		}
		*head = newNode;
		return (newNode);
	}
	if (idx == 0)
	{
		newNode->next = *head;
		*head = newNode;
		return (newNode);
	}
	temp = *head;
	for (x = 0; x < idx - 1; x++)
	{
		if (temp == NULL)
		{
			free(newNode);
			return (NULL);
		}
		temp = temp->next;
	}
	newNode->next = temp->next;
	temp->next = newNode;

	return (newNode);
}
