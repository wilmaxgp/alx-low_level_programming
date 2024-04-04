#include "lists.h"

/**
 * free_listint2 - Frees a listint_t list and sets the head to NULL
 * @head: A pointer to a pointer to the head of the list
 *
 * Description: This function frees a listint_t list and sets the head to NULL.
 *              It uses the listint_t struct defined in lists.h header file.
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
    printf("Freed %d elements\n", count);
}