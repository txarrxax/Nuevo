#include <stdio.h>
enum{dolar=1, yen, libra};

int main(){
    float euros;
    int moneda;

    printf("Introduce una cantidad en euros: ");
    scanf("%f", &euros);
    printf("Selecciona una opcion:\n1. Dolar\n2. Yen japones\n3. Libra esterlina\n");
    scanf("\n%d", &moneda);

    switch (moneda) {
        case dolar:
            printf("%.2f euros son %.2f dolares", euros, euros*1.35);
            break;
        case yen:
            printf("%.2f euros son %.2f yenes japoneses", euros, euros*115);
            break;
        case libra:
            printf("%.2f euros son %.2f libras esterlinas", euros, euros*0.89);
            break;
    }
    return 0;
}