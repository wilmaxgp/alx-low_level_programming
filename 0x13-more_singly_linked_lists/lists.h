#ifndef LISTS_H
#define LISTS_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h>

/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 *
 * Description: singly linked list node structure 
 */
typedef struct listint_s
{
	int n;
	struct listint_s *next;
} listint_t;


int _putchar(char c);
size_t print_listint(const listint_t *h);
int main(void);

#endif
