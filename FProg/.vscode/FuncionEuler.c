#include <stdio.h>

int coprimos (int a, int b){
    int i, test=1;

    for (i=2; i<=a; i++){
        if (a%i == 0 && b%i == 0){
            test = 0;
        }
    }

    return test;
}

int funcion_euler (int num){
    int i, card=0;

    for (i=1; i<num; i++){
        if (coprimos(i, num)){
            card++;
        }
    }

    return card;
}

int main (){
    int num;

    printf("*** FUNCION DE EULER ***\n");
    printf("Introduce el numero en el que quieres evaluar la funcion: ");
    scanf("%d", &num);

    printf("La funcion de Euler evaluada en %d es: %d", num, funcion_euler(num));

    return 0;
}