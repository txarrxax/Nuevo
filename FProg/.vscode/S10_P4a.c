#include <stdio.h>

int mayusculasYminusculas (char a){
    if (a > 'a' && a < 'z'){
        return 1;
    }
    else if (a > 'A' && a < 'Z'){
        return 2;
    }
    else{
        return 0;
    }
}

int menorYmayor (char *a, char *b){
    if (mayusculasYminusculas(*a) == 0 || mayusculasYminusculas(*b) == 0){
        return 0;
    }
    if (mayusculasYminusculas(*a) == 2){
        *a = *a - ('A'-'a');
    }
    if (mayusculasYminusculas(*b) == 2){
        *b = *b - ('A'-'a');
    }
    if (*a < *b){
        return 1;
    }
    else if (*a > *b){
        return 2;
    }
    else if (*a == *b){
        return 3;
    }
    else{
        return 0;
    }
}

int main () {
    char c1, c2;
    int res;

    do{
        printf("Introduce una letra en minusculas o mayusculas: ");
        scanf("\n%c", &c1);
        printf("Introduce otra letra en minusculas o mayusculas: ");
        scanf("\n%c", &c2);

        res = menorYmayor(&c1, &c2);

        if (res == 0){
            printf("ERROR: Tienes que introducir dos letras\n");
        }
    } while (res == 0);

    if (res == 1){
        printf("La letra %c es anterior a la letra %c", c1, c2);
    }
    else if (res == 2){
        printf("La letra %c es anterior a la letra %c", c2, c1);
    }
    else if (res == 3){
        printf("La letra %c es igual a la letra %c", c1, c2);
    }

    return 0;
}