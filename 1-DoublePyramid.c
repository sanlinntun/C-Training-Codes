// C program to print the full pyramid pattern of stars
#include <stdio.h>

int main()
{
    int size = 10;

    for (int i = 0; i < size; i++) {

        // inner loop 1 to print white spaces
        for (int x = 0; x < 2 * (size - i) - 1; x++) {
            printf(" ");
        }

        // inner loop 2 to print "* "
        for (int ii = 0; ii < 2 * i + 1; ii++) {
            printf("* ");
        }

        // inner loop 3 to print white spaces
        int spaces  = 2 * (size - i) - 2;
        for(int j = 0; j < spaces; j++)
        {
            printf("  ");
        }

        // inner loop 4 to print "* "
        for(int j = 0; j < 2 * i + 1; j++)
        {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}
