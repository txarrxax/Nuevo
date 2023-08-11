#include <stdio.h>

#define MAX 10

typedef struct {
    long x[MAX];
    long n;
} vector;

void minimoMaximo (vector *v, long *min, long *max){
    int i;

    *min = v->x[0];
    *max = v->x[0];

    for (i=0; i<v->n; i++){
        if (v->x[i] < *min){
            *min = v->x[i];
        }
        if (v->x[i] > *max){
            *max = v->x[i];
        }
    }
}

int main (){
    vector v;
    long min, max;
    int i, num=0;

    v.n = 0;

    do{
        printf("%ld Escribe un entero: ", v.n+1);
        scanf("%ld", &v.x[v.n]);
        v.n++;

        if (v.x[v.n-1] < 0){
            v.n--;
        }
    } while (v.x[v.n] >= 0 && v.n<MAX);

    minimoMaximo (&v, &min, &max);

    printf("Minimo: %ld\n", min);
    printf("Maximo: %ld\n", max);

    for (i=0; i<v.n; i++){
        if (v.x[i] > (min+max)/2){
            num++;
        }
    }

    printf("Numero de numeros mayores que (min+max)/2 (%ld) es: %d", (min+max)/2, num);

    return 0;
}