#include <stdio.h>
#include <stdlib.h>

int main() {
    int *v = NULL;
    v = (int*) malloc(3*sizeof(int)); // int v[3];
    free(v);
    return 0;
}