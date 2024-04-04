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

	if (*head == NULL) /* If the list is empty */
		return (-1);

	if (index == 0) /* If deleting the head node */
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
		return (1);
	}

	current = *head;
	for (i = 0; current != NULL && i < index - 1; i++)
		current = current->next;

	if (current == NULL || current->next == NULL) /* If index is out of range */
		return (-1);

	temp = current->next; /* Node to be deleted */
	current->next = temp->next; /* Link previous node to next of the node to be deleted */
	free(temp);
	return (1);
}