#include <stdio.h>

int main () {
    int uno, dos, *u, *d;
    double media, *m;

    u = &uno;
    d = &dos;
    m = &media;

    printf("Introduce el valor uno: ");
    scanf("%d", u);
    printf("Introduce el valor dos: ");
    scanf("%d", d);

    *m = (*u + *d)/2;

    printf("La media de %d y %d es %.2lf.", *u, *d, *m);
}