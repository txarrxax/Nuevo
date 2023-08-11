#include <stdio.h>

float area (float base, float altura) {
    float area;

    area = (base*altura)/2;

    return area;
}

int main () {
    float base, altura, res;

    printf("Introduce la medida de la base (en cm): ");
    scanf("%f", &base);

    printf("Introduce la medida de la altura (en cm): ");
    scanf("%f", &altura);

    res = area(base, altura);

    printf("El area de un triangulo de %.2f cm de base y %.2f cm de altura es %.2f cm cuadrados.", base, altura, res);

    return 0;
}