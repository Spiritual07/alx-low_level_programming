#include "lists.h"

/**
 * add_node_end -  function that adds a new node
 * at the end of a list_t list.
 * @head: pointer to the first member of the linked list
 * @str: pointer to string in the linked list
 * Return: address of the new element, or NULL if it failed
 */

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *node1;
	/* temporary pointer to keep track of the node */
   /* we are currently at while traversing the list */
	list_t *temp;

	node1 = (list_t *)malloc(sizeof(list_t));
	if (node1 == NULL)
	{
		return (NULL);
	}

	node1->str = strdup(str);
	node1->len = strlen(str);
	node1->next = NULL;/* set next member to null to signify end of list */

	/* check if the list is empty and asign node1 as head */
	if (*head == NULL)
	{
		*head = node1;
		return (node1);
	}
	temp = *head;
	/* traverse the list till the end and set */
	/* the next member of the last node to node1 */
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = node1;

	return (node1);
}
