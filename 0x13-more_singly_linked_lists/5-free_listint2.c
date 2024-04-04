#include "lists.h"
#include <stdio.h>

/**
 * free_listint2 - frees a listint_t list and sets the head to NULL
 * @head: pointer to a pointer to the head of the list
 */
void free_listint2(listint_t **head)
{
    listint_t *temp;
    listint_t *current = *head;
    int count = 0;

    if (head == NULL || *head == NULL)
    {
        printf("Freed !\n");
        return;
    }

    while (current != NULL)
    {
        temp = current;
        current = current->next;
        free(temp);
        count++;
    }

    *head = NULL; /* Set the head to NULL after freeing the list */
    printf("-> %d elements\n", count);
}