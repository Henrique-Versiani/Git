#include <stdio.h>

int main() {

    char c, palavra[100];
    int i, j;

    i=0;
    while (scanf("%c", &c) == 1) {
        if (c != ' ' && c != '\n') {
            palavra[i] = c;
            i++;
        } else {
            for (j=i-1; j>=0; j--)
                printf("%c", palavra[j]);
            if (c == ' ')
                printf(" ");
            if (c == '\n')
                printf("\n");
            i=0;
        }
    }


    return 0;
}