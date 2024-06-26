#include "lists.h"

/**
 * reverse_listint - Reverses a listint_t linked list.
 * @head: A pointer to a pointer to the head of the list.
 *
 * Return: A pointer to the first node of the reversed list.
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL;
	listint_t *next = NULL;

	while (*head != NULL)
	{
		next = (*head)->next; /* Store next node */
		(*head)->next = prev; /* Change next of current node */
		prev = *head; /* Move pointers one position ahead */
		*head = next;
	}

	*head = prev; /* Make head point to last node (prev) */
	return (*head);
}
