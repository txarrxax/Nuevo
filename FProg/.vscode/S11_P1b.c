#include <stdio.h>
#include <string.h>

#define STR 64

int letrasRepetidas (char *a, char *b){
    int i, j, num=0, test;

    for (i=0; i<strlen(a); i++){
        test = 0;
        for (j=0; j<i; j++){
            if (a[i] == a[j]){
                test = 1;
            }
        }
        if (test == 0){
            for (j=0; j<strlen(b); j++){
                if (a[i] == b[j]){
                    test = 1;
                }
            }
            if (test == 1){
                num++;
            }
        }
    }

    return num;
}

int main (){
    char word1[STR], word2[STR];
    int num;

    printf("Introduce una palabra en minusculas: ");
    scanf("%s", word1);
    printf("Introduce otra palabra en minusculas: ");
    scanf("%s", word2);

    num = letrasRepetidas (word1, word2);

    printf("Las palabras %s y %s tienen %d letras en comun.", word1, word2, num);

    return 0;
}