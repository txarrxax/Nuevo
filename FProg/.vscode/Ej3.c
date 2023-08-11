#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 64

int cuentaLetrasNumeros (char *cadena, int *nLetras, int *nNumeros){
    int i;

    for (i=0; i<strlen(cadena); i++){
        if (cadena[i] < '0' || (cadena[i] > '9' && cadena[i] < 'A') || (cadena[i] > 'Z' && cadena[i] < 'a') || cadena[i] > 'z' || cadena == NULL){
            return -1;
        }
    }

    for (i=0; i<strlen(cadena); i++){
        if (cadena[i] > '0' && cadena[i] < '9'){
            *nNumeros += 1;
        }
        else if ((cadena[i] > 'a' && cadena[i] < 'z') || (cadena[i] > 'A' && cadena[i] < 'Z')){
            *nLetras += 1;
        }
    }

    return 0;
}

int main (){
    char cont[DIM];
    int letras, num, test;

    printf("Introduce una password: ");
    scanf("%s", cont);

    test = cuentaLetrasNumeros(cont, &letras, &num);

    if ((cont[0] > '0' && cont[0] < '9') || test == -1 || letras == 0 || num == 0){
        printf("Password no valido.");
    }
    else{
        printf("Numero de letras: %d\n", letras);
        printf("Numero de digitos: %d\n", num);
        printf("Password valido.");
    }

    return 0;
}