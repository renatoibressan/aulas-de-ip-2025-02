#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int likes, retweets, mentions;
} interact;

int main() {
    int m, n;
    int i, j, k;
    int u1, u2, likes, retweets, mentions;
    int vazios, users = 0;
    int tl = 0, tr = 0, tm = 0, sl = 0, sr = 0, sm = 0;
    double ml, mr, mm;
    scanf("%d", &n);
    scanf("%d", &m);
    vazios = (n * n) - m;
    interact ***mat = (interact ***)malloc(n*sizeof(interact **));
    if (mat == NULL) exit(1);
    for (i = 0; i < n; i++) {
        mat[i] = (interact **)malloc(n*sizeof(interact *));
        if (mat[i] == NULL) exit(1);
        for (j = 0; j < n; j++) {
            mat[i][j] = NULL;
        }
    }
    for (i = 0; i < m; i++) {
        scanf("%d %d %d %d %d", &u1, &u2, &likes, &retweets, &mentions);
        if (mat[u1][u2] == NULL) {
            mat[u1][u2] = (interact *)malloc(sizeof(interact));
            if (mat[u1][u2] == NULL) exit(1);
            (*mat[u1][u2]).likes = 0;
            (*mat[u1][u2]).retweets = 0;
            (*mat[u1][u2]).mentions = 0;
        }
        (*mat[u1][u2]).likes += likes;
        (*mat[u1][u2]).retweets += retweets;
        (*mat[u1][u2]).mentions += mentions;
    }
    for (i = 0; i < n; i++) {
        tl = 0;
        tr = 0;
        tm = 0;
        for (j = 0; j < n; j++) {
            if (mat[i][j] != NULL) {
                tl += (*mat[u1][u2]).likes;
                tr += (*mat[u1][u2]).retweets;
                tm += (*mat[u1][u2]).mentions;
                sl += (*mat[u1][u2]).likes;
                sr += (*mat[u1][u2]).retweets;
                sm += (*mat[u1][u2]).mentions;
            }
        }
        if (tl > 0 || tr > 0 || tm > 0) {
            printf("Usuario %d - num. likes: %d, num. retweets: %d e num. mencoes: %d\n", i, tl, tr, tm);
            users++;
        }
    }
    if (users > 0) {
        ml = (double)sl / users;
        mr = (double)sr / users;
        mm = (double)sm / users;
    }
    printf("Slots vazios: %d\n", vazios);
    printf("Media de likes por usuario: %.2lf\n", ml);
    printf("Media de retweets por usuario: %.2lf\n", mr);
    printf("Media de mencoes por usuario: %.2lf\n", mm);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (mat[i][j] != NULL) free(mat[i][j]);
        }
        free(mat[i]);
    }
    free(mat);
    return 0;
}