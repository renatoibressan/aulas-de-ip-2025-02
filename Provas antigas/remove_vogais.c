#include <stdio.h>
#include <string.h>
#define N 260

void isLower(char *ch);

void remove_vogais(char *str, int vogais[5]);

int main() {
    char txt[N];
    int vogais[5];
    scanf("%[^\n]", txt);
    remove_vogais(txt, vogais);
    printf("%s\na: %d\ne: %d\ni: %d\no: %d\nu: %d\n", txt, vogais[0], vogais[1], vogais[2], vogais[3], vogais[4]);
    return 0;
}

void isLower(char *ch) {
    if (*ch >= 'A' && *ch <= 'Z') *ch += 32;
}

void remove_vogais(char *str, int vogais[5]) {
    int k, l;
    int a = 0, e = 0, i = 0, o = 0, u = 0;
    int size = strlen(str);
    for (k = 0; k < size; k++) {
        if (str[k] == 'A') isLower(&str[k]);
        if (str[k] == 'E') isLower(&str[k]);
        if (str[k] == 'I') isLower(&str[k]);
        if (str[k] == 'O') isLower(&str[k]);
        if (str[k] == 'U') isLower(&str[k]);
        if (str[k] == 'a') a++;
        if (str[k] == 'e') e++;
        if (str[k] == 'i') i++;
        if (str[k] == 'o') o++;
        if (str[k] == 'u') u++;
        if (str[k] == 'a' || str[k] == 'e' || str[k] == 'i' || str[k] == 'o' || str[k] == 'u') {
            for (l = k; l < size; l++) {
                str[l] = str[l + 1];
            }
            size--;
            k--;
        }
    }
    vogais[0] = a;
    vogais[1] = e;
    vogais[2] = i;
    vogais[3] = o;
    vogais[4] = u;
}