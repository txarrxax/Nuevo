#include <stdio.h>
#include <string.h>

#define STR_MAX 64
#define VC 5

void numeroDeVocales (int *vocales, char *palabra){
    int i;
    
    for (i=0; i<strlen(palabra); i++){
        if (palabra[i] == 'A' || palabra[i] == 'a'){
            vocales[0]++;
        }
        else if (palabra[i] == 'E' || palabra[i] == 'e'){
            vocales[1]++;
        }
        else if (palabra[i] == 'I' || palabra[i] == 'i'){
            vocales[2]++;
        }
        else if (palabra[i] == 'O' || palabra[i] == 'o'){
            vocales[3]++;
        }
        else if (palabra[i] == 'U' || palabra[i] == 'u'){
            vocales[4]++;
        }
    }
}

int main (){
    char cadena[STR_MAX];
    int vocales[VC]={0,0,0,0,0};

    printf("Introduce una palabra: ");
    scanf("%s", cadena);

    numeroDeVocales(vocales, cadena);

    printf("La palabra %s tiene:\n", cadena);

    printf("A/a: %d\n", vocales[0]);
    printf("E/e: %d\n", vocales[1]);
    printf("I/i: %d\n", vocales[2]);
    printf("O/o: %d\n", vocales[3]);
    printf("U/u: %d\n", vocales[4]);

    return 0;
}