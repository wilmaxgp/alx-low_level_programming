#include "lists.h"

list_t *create_node(const char *str);
list_t *find_last_node(list_t *head);

/**
 * add_node_end - function that adds a new node at the end of a list_t list
 * @str: pointer to a constant character string to be stored in node
 * @head: pointer to a pointer to the head of the list
 *
 * Description: function that adds a new node at the end of a list_t list
 * Return: the address of the new element, or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_node, *last_node;

	if (str == NULL)
		return (NULL);

	new_node = create_node(str);
	if (new_node == NULL)
		return (NULL);
	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}

	last_node = find_last_node(*head);
	if (last_node == NULL)
	{
		free(new_node->str);
		free(new_node);
		return (NULL);
	}

	last_node->next = new_node;

	return (new_node);
}

/**
 * create_node - Creates a new node and duplicates the string.
 * @str: The string to be duplicated and stored in the new node.
 *
 * Return: The address of the new node, or NULL if it failed.
 */
list_t *create_node(const char *str)
{
	list_t *new_node;
	size_t len = strlen(str);

	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);

	new_node->str = strdup(str);
	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}

	new_node->len = len;
	new_node->next = NULL;

	return (new_node);
}

/**
 * find_last_node - Finds the last node in the list.
 * @head: The head of the list.
 *
 * Return: The address of the last node, or NULL if the list is empty.
 */
list_t *find_last_node(list_t *head)
{
	list_t *current = head;

	while (current->next != NULL)
		current = current->next;

	return (current);
}
