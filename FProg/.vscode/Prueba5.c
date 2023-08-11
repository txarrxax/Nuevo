#include <stdio.h>

int main() {
    int d1, m1, a1, d2, m2, a2;
    printf("Introduce la fecha de nacimiento del primer usuario separada por espacios: ");
    scanf("%d %d %d", &d1, &m1, &a1);
    printf("Introduce la fecha de nacimiento del segundo usuario separada por espacios: ");
    scanf("%d %d %d", &d2, &m2, &a2);

    if (d1==d2 && m1==m2){
        if (a1==a2){
            printf("¡Felicidades! Ambos habeis nacido el mismo dia.");
        }
        else{
            printf("Ambos cumplis años el mismo dia. Os llevais %d años de diferencia.", a1-a2);
        }
    }
    else{
        printf("Vaya, no compartis cumpleaños.");
    }

    return 0;
}