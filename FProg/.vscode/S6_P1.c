#include <stdio.h>

#define MIN 5
#define MAX 10

int main (){
    int lista[MAX], n, i, j, v, repetido; 

    do{
        printf("Escribe la longitud de la lista: ");
        scanf("%d", &n);
        if (n < MIN || n > MAX){
            printf("Error, el numero introducido no eta entre %d y %d\n", MIN, MAX);
        }
    } while (n < MIN || n > MAX);

    for (i=0; i<n; i++){
        printf("Escribe el numero %d-esimo de la lista: ", i+1);
        scanf("%d", &lista[i]);
    }
    
    for (i=0; i<n; i++){
        repetido = 0;
        for (j=0; j<i; j++){
            if (lista[i]==lista[j]){
                repetido = 1;
            }
        }
        if (repetido == 0){
            v = 0;
            for (j=0; j<n; j++){
                if (lista[i] == lista[j]){
                    v++;
                }
            }
            printf("Numero de veces que %d aparece en la lista: %d\n", lista[i], v);
        }
    }

    return 0;
}