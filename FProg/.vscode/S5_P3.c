#include <stdio.h>
#include <string.h>

#define DIM 128

int main() {
    char cadena[DIM];
    char min, may;
    int i=0;

    printf("Introduce una cadena de caracteres en minusculas: ");
    scanf("%s", cadena);

    do{
        printf("Introduce un caracter en minusculas: ");
        scanf("\n%c", &min);
        if (min<'a' || min>'z'){
            printf("Error, el caracter tiene que estar comprendido entra a y z.\n");
        }
    } while (min<'a' || min>'z');

    do{
        printf("Introduce un caracter en mayusculas: ");
        scanf("\n%c", &may);
        if (may<'A' || may>'Z'){
            printf("Error, el caracter tiene que estar comprendido entra A y Z.\n");
        }
    } while (may<'A' || may>'Z');

    while (i<strlen(cadena)){
        if (cadena[i]==min){
            cadena[i] = may;   
        }
        printf("%c", cadena[i]);
        i++;
    }

    printf("\n");

    while (i>0){
        if (cadena[i-1]==min){
            cadena[i-1] = may;    
        }
        printf("%c", cadena[i-1]);
        i--;
    }
    return 0;
}