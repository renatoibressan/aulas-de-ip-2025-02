#include <stdio.h>
#define N 1000

int main() {
    int n, i, j, k, v[N], soma = 0;
    double media;
    int half1 = 0, half2 = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        soma += v[i];
    }
    if (n <= 5) {
        printf("QUANTIDADE DE ELEMENTOS INVALIDOS!\n");
        return 0;
    }
    media = soma / (n * 1.0);
    if (n % 2 != 0) {
        for (j = 0, k = n - 1; j <= ((n + 1) / 2), k >= ((n + 1) / 2); j++, k--) {
            if (v[j] > media) half1++;
            if (v[k] > media) half2++;
        }
    } else {
        for (j = 0, k = n - 1; j <= (n / 2), k >= ((n + 1) / 2); j++, k--) {
            if (v[j] > media) half1++;
            if (v[k] > media) half2++;
        }
    }
    printf("%.2lf %d %d ", media, half1, half2);
    if (half1 > half2) printf("PRIMEIRA METADE\n");
    else if (half1 < half2) printf("SEGUNDA METADE\n");
    else printf("EMPATE\n");
    return 0;
}