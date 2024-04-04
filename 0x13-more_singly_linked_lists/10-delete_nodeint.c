#include "lists.h"

/**
 * delete_nodeint_at_index - deletes the node at index of a listint_t list
 * @head: double pointer to the head of the list
 * @index: index of the node to delete
 *
 * Return: 1 if successful, -1 if failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current, *temp;
	unsigned int i;

	/* If the list is empty */
	if (*head == NULL)
		return (-1);

	/* If deleting the head node */
	if (index == 0)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
		return (1);
	}

	current = *head;
	for (i = 0; current != NULL && i < index - 1; i++)
		current = current->next;

	/* If index is out of range */
	if (current == NULL || current->next == NULL)
		return (-1);

	/* Node to be deleted */
	temp = current->next;

	/* Link previous node to next of the node to be deleted */
	current->next = temp->next;
	free(temp);
	return (1);
}
