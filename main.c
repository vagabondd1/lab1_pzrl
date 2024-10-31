#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "func.h"

int main(int argc, char *argv[argc])
{
    if (argc < 6) {
        printf("ERROR: NOT ENOUGH ARGUMENTS\n");
        return 0;
    }
    if (argv[argc-2][1] != 'k') {
        if (isalpha(argv[argc-2][1])) {
            printf("ERROR: INCORRECT FLAG\n");
            return 0;
        }
        else {
            printf("ERROR: FLAG IS IN THE WRONG PLACE/FLAG IS NOT IN THE EXPRESSION\n");
            return 0;
        }
    }
    if ((argc - 3) % 3 != 0) {
        printf("EROR: INCORRECT NUMBER OF ARGUMENTS\n");
        return 0;
    }
    int *array_rs = (int*)calloc((argc - 3) / 3,sizeof(int));
    int flag_err = 0;
    int index_of_expr = 1;
    for (int i = 1; i < argc - 2 - 2; i += 3) {
        int res1 = convert_expression(argv[i],argv[i+1],argv[i+2],strlen(argv[i]),strlen(argv[i+1]),strlen(argv[i+2]),&flag_err);
        if (flag_err == 1) {
            printf("ERROR: IN EXPRESSION No %d THERE IS NO NUMBER\n",index_of_expr);
            free(array_rs);
            return 0;
        }
        else if (flag_err == 2) {
            printf("ERROR: IN EXPRESSION NO %d THERE IS NO OPERATION ON THE NUMBERS",index_of_expr);
            free(array_rs);
            return 0;
        }
        array_rs[index_of_expr - 1] = res1;
        ++index_of_expr;
    }
     printf("Результаты выражений:\n");
    for (int i = 0; i < (argc - 3) / 3; ++i) {
        printf("Результат %d: %d\n", i + 1, array_rs[i]);
    }

    free(array_rs);  // Освобождаем память
    return 0;
}