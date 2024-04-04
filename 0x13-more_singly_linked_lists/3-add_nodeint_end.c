#include "lists.h"

/**
i * add_nodeint_end - adds a new node at the end of a listint_t list
 * @head: pointer to a pointer to the head of the list
 * @n: integer value to be stored in the new node
 *
 * Return: address of the new element, or NULL if it fails
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_node;
	listint_t *temp;

	/* Allocate memory for new node */
	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);

	/* Assign data to the new node */
	new_node->n = n;
	new_node->next = NULL;

	/* If the list is empty, new node becomes the head */
	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}

	/* Otherwise, traverse the list to find the last node */
	temp = *head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	/* Update the next pointer of the last node to point to the new node */
	temp->next = new_node;

	return (new_node);
}
