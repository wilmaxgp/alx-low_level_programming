#include "lists.h"

/**
 * pop_listint - deletes the head node of a listint_t linked list
 *               and returns the head node’s data (n)
 * @head: pointer to a pointer to the head of the list
 *
 * Return: the head node’s data (n), or 0 if the linked list is empty
 */
int pop_listint(listint_t **head)
{
    int data = 0;
    listint_t *temp;

    if (head == NULL || *head == NULL)
        return 0;

    temp = *head;
    data = temp->n;
    *head = (*head)->next;
    free(temp);

    return data;
}