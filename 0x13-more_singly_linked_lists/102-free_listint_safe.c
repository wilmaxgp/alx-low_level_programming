#include "lists.h"
#include <stdlib.h>

/**
 * free_listint_safe - Frees a listint_t list safely
 * @h: A pointer to the pointer to the head of the list
 *
 * Return: The size of the list that was freed
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *slow, *fast, *temp;
	size_t count = 0;

	if (h == NULL || *h == NULL)
		return (0);

	slow = *h;
	fast = (*h)->next;

	while (fast != NULL && fast->next != NULL)
	{
		temp = slow;
		slow = slow->next;
		fast = fast->next->next;
		free(temp);
		count++;

		if (slow == fast)
		{
			*h = NULL;
			break;
		}
	}

	if (slow == fast)
	{
		/* Loop detected */
		slow = *h;
		while (slow != fast)
		{
			temp = fast;
			fast = fast->next;
			free(temp);
			count++;
		}
	}

	/* Free the remaining nodes */
	while (slow != NULL)
	{
		temp = slow;
		slow = slow->next;
		free(temp);
		count++;
	}

	*h = NULL;
	return (count);
}
