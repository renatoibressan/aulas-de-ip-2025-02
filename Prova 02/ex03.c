#include <stdio.h>
#include <stdlib.h>
 
int main() {
    int n, m, d, i, j, *t, soma = 0;
    double menor = 1000.0, maior = -1000.0;
    int mes_index, mm1, mm2;
    double media;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        soma = 0;
        scanf("%d %d", &m, &d);
        mes_index = m;
        t = (int *)malloc(d*sizeof(int));
        for (j = 0; j < d; j++) {
            scanf("%d", t + j);
            soma += t[j];
            if (t[j] > maior) {
                maior = t[j];
                mm1 = mes_index;
            }
            if (t[j] < menor) {
                menor = t[j];
                mm2 = mes_index;
            }
        }
        media = soma / (d * 1.0);
        printf("Mes %d: %.1lf\n", mes_index, media);
    }
    printf("Maxima: %.1lf(%d), Minima: %.1lf(%d)\n", maior, mm1, menor, mm2);
    free(t);
    return 0;
}