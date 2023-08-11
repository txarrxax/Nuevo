#include <stdio.h>
#include <stdlib.h>

#define STR_MAX 64

typedef struct{
    char nombre[STR_MAX]; //Nombre del articulo comprado
    int cantidad; //Cantidad de articulos comprados
    float precio; //Precio por unidad
} Compra;

typedef struct{
    Compra *articulos; //Puntero a tabla de articulos comprados
    int cantidadArticulos; //Cantidad de elementos guardados en la tabla
} ListaCompra;

int leeListaCompra (char *fichero, ListaCompra *pListaCompra){
    FILE *f;
    int i;

    if (fichero == NULL || pListaCompra == NULL)
        return 0;

    f = fopen(fichero, "r");
    if (f == NULL)
        return 0;

    fscanf(f, "%d", &pListaCompra->cantidadArticulos);

    if ((pListaCompra->articulos = (Compra*) calloc(pListaCompra->cantidadArticulos, sizeof(Compra))) == NULL)
        return 0;
    
    for (i=0; fscanf(f, "%s %d %f", pListaCompra->articulos[i].nombre, &pListaCompra->articulos[i].cantidad, &pListaCompra->articulos[i].precio) == 3;)
        i++;
    
    fclose(f);  
    return 1;
}

int calculaListaCompra (ListaCompra lista, float *precioTotal, int *numArticulos, float *barato, float *caro){
    //Comprueba los argumentos
    if (lista.cantidadArticulos < 0 || precioTotal == NULL || numArticulos == NULL || barato == NULL || caro == NULL)
        return 0;

    //Definimos *caro y *barato como el primer articulo de la lista
    *caro = lista.articulos[0].precio;
    *barato = lista.articulos[0].precio;

    //Comprobamos totos los articulos para:
    for (*numArticulos=0, *precioTotal=0.0; *numArticulos<lista.cantidadArticulos; (*numArticulos)++){ //calcular el total de articulos
        *precioTotal += lista.articulos[*numArticulos].precio*lista.articulos[*numArticulos].cantidad; //calcular el precio total
        if (lista.articulos[*numArticulos].precio < *barato)
            *barato = lista.articulos[*numArticulos].precio; //encontrar el mas barato
        if (lista.articulos[*numArticulos].precio > *caro)
            *caro = lista.articulos[*numArticulos].precio; //encontrar el mas caro
    }

    return 1;
}

int main (){
    char fichero[STR_MAX];
    ListaCompra lista;
    float total, barato, caro;
    int num, i;

    printf("Introduce el nombre del fichero con la lista de la compra: ");
    scanf("%s", fichero);

    if (leeListaCompra(fichero, &lista) == 0)
        return 1;
    if (calculaListaCompra(lista, &total, &num, &barato, &caro) == 0)
        return 1;

    printf("La lista de la compra está compuesta por: \n");
    for (i=0; i<lista.cantidadArticulos; i++)
        printf("Articulo %d: %s, con %d unidad(es), a %.2f€ la unidad\n", i+1, lista.articulos[i].nombre, lista.articulos[i].cantidad, lista.articulos[i].precio);
    
    printf("El precio total de los %d articulos diferentes de la lista de la compra es %.2f€\n", num, total);
    printf("El articulo mas barato cuesta %.2f€ y el articulo mas caro cuesta %.2f€", barato, caro);

    free(lista.articulos);

    return 0;
}