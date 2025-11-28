#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *arq = NULL;
    arq = fopen("notas", "w");
    fprintf(arq, "40 60 80");
    fclose(arq);
    return 0;
}