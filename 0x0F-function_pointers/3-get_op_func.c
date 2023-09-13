#include "3-calc.h"
#include <stddef.h>

/**
 * get_op_func - function that selects the correct function
 * to perform the operation asked by the user
 * @s: operator passed as an argument
 * Return: returns a pointer to the function that corresponds
 * to the operator given as a parameter.
 */

int (*get_op_func(char *s))(int, int)
{
	/* define operators and their corresponding functions */
		op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};
	int i = 0;

/* loop to iterate over the operators */
	while (i < 5)
	{
	/* check for operator match and if the next character is the end of string */
		if (ops[i].op[0] == s[0] && s[1] == '\0')
		{
			return (ops[i].f); /* return the corresponding function */
		}
		i++;
	}
	return (NULL); /* return NULL if no match is found */
}
