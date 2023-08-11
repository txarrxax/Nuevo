#include <stdio.h>

int main () {
    int a, r, n, m, s, i;

    printf("Para una serie geometríca del tipo a + ar + ar^2 +...\n");
    printf("Introduzca el valor de a: ");
    scanf("%d", &a);
    printf("Introduzca el valor de r: ");
    scanf("%d", &r);
    printf("Introduzca el numero de terminos que desea sumar: ");
    scanf("%d", &n);

    m = 1;
    s = 5;
    for (i=1; i<n; i++){
        m = m*r;
        s = s + (a*m);
    }
    
    printf("La suma de %d terminos es %d.", n, s);

    return 0;
}