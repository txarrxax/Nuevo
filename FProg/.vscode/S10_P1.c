#include <stdio.h>
#include <math.h>

int esPrimo (int num){
    int i;

    for (i=2; i<=sqrt(num); i++){
        if (num%i == 0){
            return 0;
        }
    }
    
    return 1;
}

int CuantosPrimos (int num, int *a){
    int i, x=0;

    for (i=2; i<num; i++){
        if (esPrimo(i) == 1){
            x++;
        }
    }

    (*a) = x;
    if (num > 0){
        return 1;
    }
    else{
        return 0;
    }
}

int main (){
    int num, a, test;

    do{
        printf("Introduce un numero: ");
        scanf("%d", &num);

        test = CuantosPrimos(num, &a);

        if (test == 1){
            printf("Hay %d numeros primos inferiores a %d", a, num);
        }
        else{
            printf("Error, el numero introducido no es valido\n");
        } 
    } while (test == 0);
}