#include <stdio.h>
#include <string.h>

#define DIM 64

char codificar (char original, char codigo) {
    char x; 

    if (codigo >= 'a' && codigo <= 'z'){
        if (original >= 'a' && original <='z'){
            x = original + (codigo  - 'a');
            return x;
        }
        else if (original >= 'A' && original <= 'Z'){
            original = original - ('A' - 'a');
            x = original + (codigo - 'a');
            return x;
        }
        else{
            return original;
        }
    }

    else if (codigo >= 'A' && codigo <= 'Z'){
        if (original >= 'A' && original <='Z'){
            x = original + (codigo  - 'A');
            return x;
        }
        else if (original >= 'a' && original <= 'z'){
            original = original + ('A' - 'a');
            x = original + (codigo - 'A');
            return x;
        }
        else{
            return original;
        }
    }
    
    else{
        return original;
    }

    
}

int main () {
    char cadena[DIM];
    char letra, x;
    int i;

    printf("Introduce una palabra: ");
    scanf("%s", cadena);

    printf("Introduce una letra para codificar: ");
    scanf("\n%c", &letra);

    printf("La palabra %s codificada con la letra %c es ", cadena, letra);

    for (i=0; i<strlen(cadena); i++){
        x = codificar(cadena[i], letra);
        printf("%c", x);
    }

    return 0;
}