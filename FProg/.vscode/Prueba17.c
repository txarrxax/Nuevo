#include <stdio.h>
#include <math.h>

int esPrimo (int num) {
    int i;
    for (i=2; i<=sqrt(num); i++){
        if (num%i == 0){
            return 0;
        }
    }
    
    return 1;
}

int main (){
    int num;

    printf("Introduce un numero: ");
    scanf("%d", &num);

    if (esPrimo(num)){
        if (esPrimo(num+2) && esPrimo(num-2)){
            printf("El numero %d es primo y los numeros %d y %d son primos gemelos.", num, num-2, num+2);
        }
        else if (esPrimo(num+2)){
            printf("El numero %d es primo y el %d es primo gemelo.", num, num+2);
        }
        else if (esPrimo(num-2)){
            printf("El numero %d es primo y el %d es primo gemelo.", num, num-2);
        }
        else{
            printf("El numero %d es primo pero no tiene un primo gemelo.", num);
        }
    }
    else{
        printf("El numero %d no es primo.", num);
    }

    return 0;
}
