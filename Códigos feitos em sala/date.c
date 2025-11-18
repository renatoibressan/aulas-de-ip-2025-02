#include <stdio.h>

struct date {
    int dia, mes, ano;  
};

int validdate(struct date d);

void scandate(struct date d);

void printdate(struct date d);

int main() {
    struct date dd;
    int i, n;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scandate(dd);
        if (validdate(dd) == 1) printdate(dd);
        else printf("Data invalida!\n");
    }
    return 0;
}

int validdate(struct date d) {
    if (d.mes < 1 || d.mes > 12) return 0;
    switch (d.mes) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if (d.dia < 1 || d.dia > 31) return 0;
            break;
        case 2:
            if (d.ano % 4 == 0) {
                if (d.dia < 1 || d.dia > 29) return 0;
            } else {
                if (d.dia < 1 || d.dia > 28) return 0;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if (d.dia < 1 || d.dia > 30) return 0;
            break;
        default: return 0;
    }
    return 1;
}

void scandate(struct date d) {
    scanf("%d%*c%d%*c%d%*c", &d.dia, &d.mes, &d.ano);
}

void printdate(struct date d) {
    printf("%d/%d/%d\n", d.dia, d.mes, d.ano);
}