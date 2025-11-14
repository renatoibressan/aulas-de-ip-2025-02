#include <stdio.h>
#define N 100000

int main() {
    int n, i, j, v[N];
    int qtd_par = 0, qtd_impar = 0;
    int even[N], odd[N];
    int temp1, temp2;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        if (v[i] % 2 == 0) {
            even[qtd_par] = v[i];
            qtd_par++;
        } else if (v[i] % 2 == 1) {
            odd[qtd_impar] = v[i];
            qtd_impar++;
        }
    }
    for (i = 0; i < qtd_par - 1; i++) {
        for (j = i + 1; j < qtd_par; j++) {
            if (even[i] > even[j]) {
                temp1 = even[i];
                even[i] = even[j];
                even[j] = temp1;
            }
        }
    }
    for (i = 0; i < qtd_impar - 1; i++) {
        for (j = i + 1; j < qtd_impar; j++) {
            if (odd[i] < odd[j]) {
                temp2 = odd[i];
                odd[i] = odd[j];
                odd[j] = temp2;
            }
        }
    }
    for (i = 0; i < qtd_par; i++) {
        printf("%d\n", even[i]);
    }
    for (i = 0; i < qtd_impar; i++) {
        printf("%d\n", odd[i]);
    }
    return 0;
}