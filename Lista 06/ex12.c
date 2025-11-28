#include <stdio.h>
#include <math.h>

typedef struct tRacional {
    int a, b;
} racionais;

racionais racional(int a, int b);

racionais negativo(racionais r);

racionais soma(racionais r1, racionais r2);

racionais mult(racionais r1, racionais r2);

racionais div(racionais r1, racionais r2);

int mdc(int x, int y);

void reduzFracao(racionais *r);

int main() {
    racionais r1, r2, rr;
    int i;
    char op;
    while (scanf("%d %d %c %d %d", &(r1.a), &(r1.b), &op, &(r2.a), &(r2.b)) != EOF) {
        if (op == '+') {
            rr = soma(r1, r2);
        } else if (op == '-') {
            r2 = negativo(r2);
            rr = soma(r1, r2);
        } else if (op == '*') {
            rr = mult(r1, r2);
        } else if (op == '/') {
            rr = div(r1, r2);
        }
        reduzFracao(&rr);
        printf("%d %d\n", rr.a, rr.b);
    }
    return 0;
}

racionais racional(int a, int b) {
    racionais r;
    r.a = a;
    r.b = b;
    return r;
}

racionais negativo(racionais r) {
    r.a = -r.a;
    return r;
}

racionais soma(racionais r1, racionais r2) {
    racionais rr;
    rr.b = r1.b * r2.b;
    rr.a = r1.a * r2.b + r2.a * r1.b;
    return rr;
}

racionais mult(racionais r1, racionais r2) {
    racionais rr;
    rr.a = r1.a * r2.a;
    rr.b = r1.b * r2.b;
    return rr;
}

racionais div(racionais r1, racionais r2) {
    racionais rr;
    rr.a = r1.a * r2.b;
    rr.b = r1.b * r2.a;
    return rr;
}

int mdc(int x, int y) {
    int aux;
    while (y != 0) {
        aux = y;
        y = x % y;
        x = aux;
    }
    return x;
}

void reduzFracao(racionais *r) {
    int m = mdc(r->a, r->b);
    r->a /= m;
    r->b /= m;
    if (r->b < 0) {
        r->a = -r->a;
        r->b = -r->b;
    }
}