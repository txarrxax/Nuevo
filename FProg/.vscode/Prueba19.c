#include <stdio.h>

typedef struct {
    int dia;
    int mes;
    int anyo;
} Fecha;

void incrementaDia (Fecha *f){
    f->dia ++;
}



int main (){
    Fecha x;

    printf("Introduce una fecha:\n");
    printf("=====================\n");
    printf("Dia: ");
    scanf("%d", &x.dia);
    printf("Mes: ");
    scanf("%d", &x.mes);
    printf("Anyo: ");
    scanf("%d", &x.anyo);

    incrementaDia(&x);

    printf("La nueva fecha es: %d/%d/%d", x.dia, x.mes, x.anyo);

    return 0;
}