#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "func.h"

int convert_expression(const char *ptr1, const char *ptr2, const char *ptr3, int n1, int n2, int n3, int *ptr_err) 
{
    int a1 = 0, a2 = 0;
    *ptr_err = 0;
    for (int i = 0; i < n1; ++i) {
        if (!isdigit(ptr1[i])) { 
            *ptr_err = 1; 
            return 0;
        }
    }
    a1 = atoi(ptr1);
    for (int i = 0; i < n3; ++i) {
        if (!isdigit(ptr3[i])) {
            *ptr_err = 1;
            return 0;
        }
    }

    a2 = atoi(ptr3);

    if (n2 != 1 || (*ptr2 != '+' && *ptr2 != '-' && *ptr2 != '*' && *ptr2 != '/')) {
        *ptr_err = 2; 
        return 0;
    }
    switch (*ptr2) {
        case '+': return a1 + a2;
        case '-': return a1 - a2;
        case '*': return a1 * a2;
        case '/': return a2 != 0 ? a1 / a2 : 0;
    }

    return 0;
}
