#include <stdio.h>
#include <stdlib.h>

void ordenar (int *tabla, int dim){
    int i, j, menor, aux;

    for (i=0; i<dim; i++){
        menor = tabla[i];
        for (j=i; j<dim; j++){
            if (tabla[j] < menor){
                menor = tabla[j];
                aux = tabla[i];
                tabla[i] = tabla[j];
                tabla[j] = aux;          
            }
        }
    }
}

int main (){
    int i, dim, *tabla;

    printf("Cuantos numeros quieres introducir? ");
    scanf("%d", &dim);

    tabla = (int*) calloc(dim, sizeof(int));

    for (i=0; i<dim; i++){
        printf("Introduce el numero %d: ", i+1);
        scanf("%d", &tabla[i]);
    }

    ordenar(tabla, dim);

    printf("Numeros ordenados de menor a mayor: ");

    for (i=0; i<dim; i++){
        printf("%d ", tabla[i]);
    }

    return 0;
}