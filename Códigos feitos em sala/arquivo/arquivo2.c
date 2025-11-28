#include <stdio.h>
#include <stdlib.h>

int main() {
    int n1, n2, n3;
    FILE *arq = NULL;
    arq = fopen("notas", "r");
    fscanf(arq, "%d %d %d", &n1, &n2, &n3);
    printf("Notas: %d %d %d\n", n1, n2, n3);
    fclose(arq);
    return 0;
}