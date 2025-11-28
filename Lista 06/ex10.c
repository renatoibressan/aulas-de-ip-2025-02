#include <stdio.h>
#include <stdlib.h>

typedef struct polinomio {
    float coef;
    int exp;
} poly;

void poly_order(poly *p, int n);

int main() {
    int n, n1, n2, i, j, k;
    char op;
    poly *p1, *p2, *pr;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%*c%c", &op);
        scanf("%d", &n1);
        p1 = (poly *)malloc(n1*sizeof(poly));
        for (j = 0; j < n1; j++) {
            scanf("%f %d", &(p1[j].coef), &(p1[j].exp));
        }
        scanf("%d", &n2);
        p2 = (poly *)malloc(n2*sizeof(poly));
        for (j = 0; j < n2; j++) {
            scanf("%f %d", &(p2[j].coef), &(p2[j].exp));
            if (op == '-') p2[j].coef *= -1;
        }
        for (j = 0; j < n1; j++) {
            for (k = 0; k < n2; k++) {
                if (p1[j].exp == p2[k].exp) {
                    p1[j].coef += p2[k].coef;
                    p2[k].coef = 0;
                }
            }
        }
        pr = (poly *)malloc((n1+n2)*sizeof(poly));
        k = 0;
        for (j = 0; j < n1; j++) {
            if (p1[j].coef != 0) {
                pr[k].coef = p1[j].coef;
                pr[k].exp = p1[j].exp;
                k++;
            }
        }
        for (j = 0; j < n2; j++) {
            if (p2[j].coef != 0) {
                pr[k].coef = p2[j].coef;
                pr[k].exp = p2[j].exp;
                k++;
            }
        }
        poly_order(pr, k);
        for (j = 0; j < k; j++) {
            if (pr[j].exp > 0) printf("%+.2fX^%d", pr[j].coef, pr[j].exp);
            else printf("%+.2f", pr[j].coef);
        }
        printf("\n");
        free(p1);
        free(p2);
        free(pr);
    }
    return 0;
}

void poly_order(poly *p, int n) {
    int i, j;
    poly aux;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (p[i].exp < p[j].exp) {
                aux = p[i];
                p[i] = p[j];
                p[j] = aux;
            }
        }
    }
}