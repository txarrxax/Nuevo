#include <stdio.h>

int main(){
    char tabla[3][2] = {{'X','O'},{'O','X'},{'X','X'}};
    int fila, columna;

    printf("Introduce una fila: ");
    scanf("%d", &fila);
    printf("Introduce una columna: ");
    scanf("%d", &columna);

    printf("En la fia %d, columna %d encontramos: %c", fila, columna, tabla[fila-1][columna-1]);

    return 0;
}