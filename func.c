#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "func.h"

int convert_expression(const char *ptr1, const char *ptr2, const char *ptr3, int n1, int n2, int n3, int *ptr_err)
{
    int a1 = 0, a2 = 0;
    *ptr_err = 0;
    for (int i = 0; i < n1; ++i)
    {
        if (!isdigit(ptr1[i]))
        {
            *ptr_err = 1;
            return 0;
        }
    }
    a1 = atoi(ptr1);
    for (int i = 0; i < n3; ++i)
    {
        if (!isdigit(ptr3[i]))
        {
            *ptr_err = 1;
            return 0;
        }
    }
    a2 = atoi(ptr3);
    switch (*ptr2)
    {
    case '+':
        return a1 + a2;
    case '-':
        return a1 - a2;
    case '*':
        return a1 * a2;
    case '%':
        if (a2 == 0)
        {
            *ptr_err = 3; // Division by zero error
            return 0;
        }
        return a1 % a2;
    default:
        *ptr_err = 4;
        return 0;
    }
    return 0;
}

void print_result_string(int *ptr, int argc, int flag_value)
{
    for (int i = 0; i < (argc - 3) / 3; ++i)
    {
        printf("%c", ptr[i] - flag_value);
    }
}

void print_results_expr(int *ptr, int argc)
{
    for (int i = 0; i < (argc - 3) / 3; ++i)
    {
        printf("Ответ №%d: %d\n", i + 1, ptr[i]);
    }
}