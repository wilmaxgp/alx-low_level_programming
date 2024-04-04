#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_listint_safe - Prints a listint_t linked list safely
 * @head: A pointer to the head of the list
 *
 * Return: The number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
    const listint_t *slow, *fast;
    size_t count = 0;
    int loop_detected = 0;

    if (head == NULL)
        return (0);

    slow = head;
    fast = head;

    while (slow != NULL && fast != NULL && fast->next != NULL)
    {
        printf("[%p] %d\n", (void *)slow, slow->n);
        slow = slow->next;
        fast = fast->next->next;

        /* If slow and fast meet, it means there is a loop */
        if (slow == fast)
        {
            loop_detected = 1;
            break;
        }
        count++;
    }

    if (loop_detected)
    {
        /* Count the nodes in the loop */
        size_t loop_count = 1;
        const listint_t *temp = slow->next;
        while (temp != slow)
        {
            loop_count++;
            temp = temp->next;
        }

        /* Print the looped node only once */
        printf("[%p] %d\n", (void *)slow, slow->n);

        /* Adjust the count to exclude the loop */
        count += loop_count;
    }

    /* Print the remaining nodes after the loop */
    while (slow != NULL)
    {
        printf("[%p] %d\n", (void *)slow, slow->n);
        slow = slow->next;
        count++;
    }

    return count;
}
