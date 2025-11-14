#include <stdio.h>
#define N 10

int main() {
    double m1[N][N], m2[N][N], aux[N][N];
    int n, p, i, j, k, helper;
    scanf("%d %d", &n, &p);
    helper = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%lf", &m1[i][j]);
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            m2[i][j] = 0;
        }
    }
    while (p > 1) {
        if (helper == 0) {
            for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) {
                    for (k = 0; k < n; k++) {
                        m2[i][j] += m1[i][k] * m1[k][j];
                    }
                }
            }
        } else {
            for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) {
                    aux[i][j] = m2[i][j];
                }
            }
            for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) {
                    m2[i][j] = 0;
                }
            }
            for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) {
                    for (k = 0; k < n; k++) {
                        m2[i][j] += aux[i][k] * m1[k][j];
                    }
                }
            }
        }
        helper++;
        p--;
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%.3lf ", m2[i][j]);
        }
        printf("\n");
    }
    return 0;
}