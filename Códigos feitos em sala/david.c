#include <stdio.h>

int main() {
    int n, energy;
    scanf("%d", &n);
    while (n < 1 || n > 100) scanf("%d", &n);
    energy = n / 5;
    if (n % 5 != 0) energy++;
    printf("David will lose %d points of energy\n", energy);
    return 0;
}