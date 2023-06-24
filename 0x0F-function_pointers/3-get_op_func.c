#include "3-calc.h"
#include "stdlib.h"
#include "stdio.h"

/**
 * get_op_func -  returns a pointer to the function of corresponding operation
 *
 * @s: string argument
 * @ops: operators
 */
int (*get_op_func(char *s))(int, int)
{
	 op_t ops[] = {
        {"+", op_add},
        {"-", op_sub},
        {"*", op_mul},
        {"/", op_div},
        {"%", op_mod},
        {NULL, NULL}
    };
    int i;

    while (ops[i].operator != NULL)
	
	    if (strcmp(s, ops[i].operator) == 0)
		    return ops[i].func_ptr;
	    
    	i++;

    return NULL;    
}
