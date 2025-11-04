#include <stdio.h>

void maxmin(int a, int b, int c, int *max, int *min) {
    *max = a;
    if (b > *max) *max = b;
    if (c > *max) *max = c;
    *min = a;
    if (b < *min) *min = b;
    if (c < *min) *min = c;
}

int main() {
    int a, b, c, max, min;
    scanf("%d%d%d", &a, &b, &c);
    maxmin(a, b, c, &max, &min);
    printf("Maior: %d\nMenor: %d\n", max, min);
    return 0;
}