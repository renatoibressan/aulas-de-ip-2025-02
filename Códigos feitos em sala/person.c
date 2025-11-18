#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

typedef int logic;

typedef struct date {
    int dia, mes, ano;
} Date;

typedef struct person {
    char nome[128];
    double altura, peso;
    Date nasc;
} Person;

void printdate(Date d, char *post);

Date scandate(void);

void printperson(Person p, char *post);

Person scanperson(void);

int main() {
    Person p;
    while (1) {
        p = scanperson();
        printperson(p, "\n\n");
    }
    return 0;
}

void printdate(Date d, char *post) {
    printf("%d/%d/%d", d.dia, d.mes, d.ano);
    if (post != NULL) printf("%s", post);
}

Date scandate(void) {
    Date D;
    scanf("%d%*c%d%*c%d%*c", &(D.dia), &(D.mes), &(D.ano));
    return D;
}

void printperson(Person p, char *post) {
    printf("----------------------\n");
    printf("%s\n%.1lf kg\n%.2lf m\n", p.nome, p.altura, p.peso);
    printdate(p.nasc, "\n");
    if (post != NULL) printf("%s", post);
}

Person scanperson(void) {
    Person P;
    scanf("%[^\n]%*c%lf%*c%lf%*c", (P.nome), &(P.altura), &(P.peso));
    P.nasc = scandate();
    return P;
}