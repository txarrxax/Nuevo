#include <stdio.h>

#define INC 3
#define DIM 3

void incremento (int *p, int num, int inc){
    int i;

    for (i=0; i<num; i++){
        p[i] += inc;
    } 
}

int main (){
    int i, tabla[DIM] = {1,2,3};

    printf("Tabla: ");
    for (i=0; i<DIM; i++){
        printf("%d | ", tabla[i]);
    }

    incremento(tabla, DIM, INC);

    printf("\nTabla: ");
    for (i=0; i<DIM; i++){
        printf("%d | ", tabla[i]);
    }

    return 0;
}