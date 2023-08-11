#include <stdio.h>
#include <stdlib.h>

#define DIM 3

typedef struct{
    long n;
    long d;
} fraccion;

void sumFraccion (fraccion *x){
    x[2].d = x[0].d * x[1].d;
    x[2].n = (x[0].n * x[1].d)+(x[1].n * x[0].d);
}

int main (){
    fraccion *frac;
    int i;

    frac = (fraccion*) calloc(DIM, sizeof(fraccion));

    for (i=0; i<DIM-1; i++){
        printf("fraccion %d, numerador: ", i+1);
        scanf("%ld", &frac[i].n);
        printf("fraccion %d, denominador: ", i+1);
        scanf("%ld", &frac[i].d);
    }

    sumFraccion (frac);

    printf("%ld/%ld + %ld/%ld = %ld/%ld", frac[0].n, frac[0].d, frac[1].n, frac[1].d, frac[2].n, frac[2].d);

    free(frac);
    return 0;

}