#include <stdio.h>
#include <string.h>

#define STR_MAX 64

// Creamos la función que nos permite comprobar si una letra es menor/mayor que otra o si son iguales (sin tener en cuenta MAY/MIN)
int letraMenor (char letra1, char letra2){
    int res;

    // Eliminamos las distinciones entre MAY y MIN
    if (letra1 >= 'A' && letra1 <= 'Z'){
        letra1 = letra1 - ('A'-'a');
    }
    if (letra2 >= 'A' && letra2 <= 'Z'){
        letra2 = letra2 - ('A'-'a');
    }
    
    // Comparamos las letras
    if (letra1 < letra2){
        res = 1;
    }
    else if (letra1 > letra2){
        res = 2;
    }
    else{
        res = 0;
    }

    // Devolvemos el valor obtenido
    return res;
}

//Creamos la función principal
int main () {
    char p1[STR_MAX], p2[STR_MAX];
    int i, len, res;
    
    // solicitamos dos palabras por teclado
    printf("Introduce la primera palabra: ");
    scanf("%s", p1);
    printf("Introducela la segunda palabra: ");
    scanf("%s", p2);

    // Vemos cual es la longitud de la palabra mas corta
    if (strlen(p1) < strlen(p2)){
        len = strlen(p1);
    }
    else{
        len = strlen(p2);
    }

    // Comparamos cada par de letras para ver su relacion
    for (i=0; i<len; i++){
        res = letraMenor(p1[i], p2[i]);
        if (res == 1){
            printf("La letra %c es menor que la letra %c\n", p1[i], p2[i]);
        }
        else if (res == 2){
            printf("La letra %c es mayor que la letra %c\n", p1[i], p2[i]);
        }
        else{
            printf("Las letras %c y %c son iguales\n", p1[i], p2[i]);
        }
    }

    return 0;
}