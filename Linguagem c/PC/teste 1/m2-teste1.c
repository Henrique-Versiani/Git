#include <stdio.h>
#include <string.h>

int main() {

    char palavra[21];
    int i, codigo, codigo_ant;

    while (scanf("%s", palavra)==1) {
        codigo_ant=-1;
        for (i=0; i<strlen(palavra); i++) {
            if (palavra[i] == 'A' ||
            palavra[i] == 'E' ||
            palavra[i] == 'I' ||
            palavra[i] == 'O' ||
            palavra[i] == 'U' ||
            palavra[i] == 'H' ||
            palavra[i] == 'W' ||
            palavra[i] == 'Y') {
                codigo=0;
            } else if (palavra[i] == 'B' ||
            palavra[i] == 'F' ||
            palavra[i] == 'P' ||
            palavra[i] == 'V') {
                codigo=1;
            } else if (palavra[i] == 'C' ||
            palavra[i] == 'G' ||
            palavra[i] == 'J' ||
            palavra[i] == 'K' ||
            palavra[i] == 'Q' ||
            palavra[i] == 'S' ||
            palavra[i] == 'X' ||
            palavra[i] == 'Z') {
                codigo=2;
            } else if (palavra[i] == 'D' ||
            palavra[i] == 'T') {
                codigo=3;
            } else if (palavra[i] == 'L') {
                codigo=4;
            } else if (palavra[i] == 'M' ||
            palavra[i] == 'N') {
                codigo=5;
            } else if (palavra[i] == 'R') {
                codigo=6;
            }
            if (codigo != 0 && codigo != codigo_ant)
                printf("%d",codigo);

            codigo_ant = codigo;
        }
    }

    return 0;
}