#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j;
    int **m = NULL;
    m = (int**)malloc(3*sizeof(int*));
    for (i = 0; i < 3; i++) {
        m[i] = (int*)malloc(4*sizeof(int));
    }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
    free(m);
    return 0;
}