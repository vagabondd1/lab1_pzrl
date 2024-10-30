#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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
        printf("ERROR: FLAG IS IN THE WRONG PLACE\n");
        return 0;
    }
    }
    if ((argc - 3) % 3 != 0) {
        printf("EROR: INCORRECT NUMBER OF ARGUMENTS\n");
    }
}