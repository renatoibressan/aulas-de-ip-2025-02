#include <stdio.h>
#include <stdlib.h>
 
void is_upper(char *ch);
 
int str_len(char *str);
 
void remove_vogais(char *str, int *vogais);
 
int main() {
    char *txt;
    int i, *v;
    txt = (char *)malloc(sizeof(char)*256);
    v = (int *)malloc(sizeof(int)*5);
    scanf("%[^\n]", txt);
    remove_vogais(txt, v);
    printf("%s\na: %d\ne: %d\ni: %d\no: %d\nu: %d\n", txt, v[0], v[1], v[2], v[3], v[4]);
    free(txt);
    free(v);
    return 0;
}
 
void is_upper(char *ch) {
    if (*ch >= 'a' && *ch <= 'z') *ch -= 32;
}
 
int str_len(char *str) {
    int i = 0;
    while (str[i] != '\0') i++;
    return i;
}
 
void remove_vogais(char *str, int *vogais) {
    int i, j, length;
    int va = 0, ve = 0, vi = 0, vo = 0, vu = 0;
    length = str_len(str);
    for (i = 0; i < length; i++) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') is_upper(&str[i]);
        if (str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
            if (str[i] == 'A') va++;
            else if (str[i] == 'E') ve++;
            else if (str[i] == 'I') vi++;
            else if (str[i] == 'O') vo++;
            else if (str[i] == 'U') vu++;
            for (j = i; j < length; j++) {
                str[j] = str[j + 1];
            }
            length--;
            i--;
        } 
    }
    vogais[0] = va;
    vogais[1] = ve;
    vogais[2] = vi;
    vogais[3] = vo;
    vogais[4] = vu;
}