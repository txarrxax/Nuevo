#include <stdio.h>

#define DIM 1000 

typedef struct{
    char palabra[128];
    long vocales, consonantes;
}Word; 

int main () {
    

    Word tabla[DIM];
    int n, i, j;

    do{
        printf("Numero de palabras: ");
        scanf("%d", &n);

        if (n<0 || n>1000){
            printf("Error. Tienes que introducir un valor entre 0 y 1000.");
        }
    } while (n<0 || n>1000);

    for (i=0; i<n; i++){
        printf("Palabra [%d]: ", i+1);
        scanf("%s", tabla[i].palabra);
    }

    for (i=0; i<n; i++){
        for (j=0; j<128; j++){
            if (tabla[i].palabra[j] >= 'a' && tabla[i].palabra[j] <= 'z'){
                if (tabla[i].palabra[j] == 'a' || tabla[i].palabra[j] == 'e' || tabla[i].palabra[j] == 'i' || tabla[i].palabra[j] == 'o' || tabla[i].palabra[j] == 'u'){
                    tabla[i].vocales++;
                }
                else{
                    tabla[i].consonantes++;
                }
            }
        }
        printf("La palabra ""%s"" tiene %ld vocales y %ld consonantes.\n", tabla[i].palabra, tabla[i].vocales, tabla[i].consonantes);
    }
    
    return 0;
}