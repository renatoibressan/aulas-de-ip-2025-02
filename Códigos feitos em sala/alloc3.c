#include <stdio.h>
#include <stdlib.h>

// Criar vetores
int * vect_new(int n) {
    int *v = NULL;
    v = (int*) malloc(n*sizeof(int));
    return v;
}

// Criar matrizes
int ** mat_new(int nl, int nc) {
    int **m = NULL;
    m = (int**) malloc(nl*sizeof(int));
    for (int i = 0; i < nl; i++) {
        m[i] = (int*) malloc(nc*sizeof(int));
    }
    return m;
}

// Imprime o vetor
void vect_print(int *v, int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        if (i == 0) printf("%d", v[0]);
        else printf(",%d", v[i]);
    }
    printf("]\n");
}

// Imprime a matriz
void mat_print(int **m, int nl, int nc) {
    for (int i = 0; i < nl; i++) {
        for (int j = 0; j < nc; j++) {
            if (j == 0) printf("[");
            if (j > 0) printf(",");
            printf("%d", m[i][j]);
            if (j == nc - 1) printf("]");
        }
        printf("\n");
    }
}

// Libera vetores
void vect_free(int *v) {
    free(v);
}

// Libera matrizes
void mat_free(int **m, int nl) {
    for (int i = 0; i < nl; i++) {
        free(m[i]);
    }
    free(m);
}

// Função main
int main() {
    int n;
    scanf("%d", &n);
    int *V = vect_new(n);
    int nl, nc;
    scanf("%d%d", &nl, &nc);
    int **M = mat_new(nl, nc);
    vect_print(V, n);
    mat_print(M, nl, nc);
    vect_free(V);
    mat_free(M, nl);
}