#include <stdio.h>
#include <math.h>
#define N1 2005
#define N2 1005

int main() {
    char str1[N1], str2[N2], str3[N1];
    int i, count, aux = 0;
    int vogais1[5] = {0, 0, 0, 0, 0}, vogais2[5] = {0, 0, 0, 0, 0};
    double d = 0.0;
    scanf("%[^\n]%*c", str1);
    for (i = 0; str1[i] != ';' && str1[i] != '\0'; i++) {
        str2[i] = str1[i];
    }
    if (str1[i] != ';') {
        printf("FORMATO INVALIDO!\n");
        return 0;
    }
    str2[i] = '\0';
    count = i + 1;
    for (i = count; str1[i] != '\0'; i++) {
        str3[i] = str1[i];
        if (str1[i] == ';') aux++;
    }
    str3[i] = '\0';
    if (aux > 0) {
        printf("FORMATO INVALIDO!\n");
        return 0;
    }
    for (i = 0; str2[i] != '\0'; i++) {
        if (str2[i] == 'A' || str2[i] == 'a') vogais1[0]++;
        if (str2[i] == 'E' || str2[i] == 'e') vogais1[1]++;
        if (str2[i] == 'I' || str2[i] == 'i') vogais1[2]++;
        if (str2[i] == 'O' || str2[i] == 'o') vogais1[3]++;
        if (str2[i] == 'U' || str2[i] == 'u') vogais1[4]++;
    }
    for (i = count; str3[i] != '\0'; i++) {
        if (str3[i] == 'A' || str3[i] == 'a') vogais2[0]++;
        if (str3[i] == 'E' || str3[i] == 'e') vogais2[1]++;
        if (str3[i] == 'I' || str3[i] == 'i') vogais2[2]++;
        if (str3[i] == 'O' || str3[i] == 'o') vogais2[3]++;
        if (str3[i] == 'U' || str3[i] == 'u') vogais2[4]++;
    }
    for (i = 0; i < 5; i++) {
        if (i == 0) printf("(%d", vogais1[i]);
        else if (i == 4) printf(",%d)\n", vogais1[i]);
        else printf(",%d", vogais1[i]);
    }
    for (i = 0; i < 5; i++) {
        if (i == 0) printf("(%d", vogais2[i]);
        else if (i == 4) printf(",%d)\n", vogais2[i]);
        else printf(",%d", vogais2[i]);
    }
    for (i = 0; i < 5; i++) {
        d += ((vogais1[i] - vogais2[i]) * (vogais1[i] - vogais2[i]));
    }
    printf("%.2lf\n", sqrt(d));
    return 0;
}