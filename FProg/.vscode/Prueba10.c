#include <stdio.h>

#define MAX_STR 128
#define DIM 2

typedef struct {
    int dia, mes, anyo;
} Fecha;

typedef struct {
    char nombre[MAX_STR];
    Fecha fecha[DIM];
} Citas;

int main () {
    Citas x;

    printf("Introduce tu nombre: ");
    scanf("%s", &x.nombre);
    printf("Introduce un dia: ");
    scanf("%d", &x.fecha[0].dia);
    printf("Introduce un mes: ");
    scanf("%d", &x.fecha[0].mes);
    printf("Introduce un año: ");
    scanf("%d", &x.fecha[0].anyo);
    printf("Introduce otro dia: ");
    scanf("%d", &x.fecha[1].dia);
    printf("Introduce otro mes: ");
    scanf("%d", &x.fecha[1].mes);
    printf("Introduce otro año: ");
    scanf("%d", &x.fecha[1].anyo);

    printf("Hola %s\n", x.nombre);
    printf("Tienes una cita el %d/%d/%d y otra e %d/%d/%d", x.fecha[0].dia, x.fecha[0].mes, x.fecha[0].anyo, x.fecha[1].dia, x.fecha[1].mes, x.fecha[1].anyo);

    return 0;
}
