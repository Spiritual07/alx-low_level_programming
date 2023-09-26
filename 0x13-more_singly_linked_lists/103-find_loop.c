#include "lists.h"

/**
 * find_listint_loop - A function that finds the loop in a list
 * @head: pointer to the first element in the list
 * Return: The address of the node where the loop start, or NULL
 */
listint_t *find_listint_loop(listint_t *head)
{
	/* initialize two pointer to the head of the list */
	listint_t *slow = head, *fast = head;

	if (head == NULL)
	{
		return (NULL);
	}
/* Traverse the list with two pointers moving at different speeds.*/
	while (slow && fast && fast->next)
	{
		/* move slow pointer one step forward and fast pointer two step forward */
		slow = slow->next;
		fast = fast->next->next;
		/* if both pointer meets it means there is a loop */
		if (slow == fast)
		{
			slow = head; /* reset slow pointer back to be head */
			/* Move both pointers at the same speed until they meet again */
			while (slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}
			/* Return the node where the loop starts.*/
			return (slow);
		}
	}
	return (NULL);/* return NULL if no loop was found */
}
