#include <stdio.h>
#include <stdlib.h>

#define TAM 64

typedef struct{
    char nombre[TAM]; //Nombre del artículo
    int cantidad; //Cantidad de artículo
    float precio; //Precio por unidad
} Compra;

typedef struct{
    Compra *articulos; //Puntero a tabla de artículos
    int cantidadArticulos; //Cantidad de articulos guardados en la tabla
} ListaCompra;

//Función que lee un fichero y almacena su datos en una estructura del tipo ListaCompra
int leeListaCompra (char *fichero, ListaCompra *pListaCompra){
    FILE *f;
    int i;

    //Comprobar argumentos
    if (fichero == NULL || pListaCompra == NULL)
        return 0;

    //Abrir el fichero y comprobarlo
    f = fopen(fichero, "r");
    if (f == NULL)
        return 0;
    
    //Ver el número de artículos de la lista (primera línea)
    fscanf(f, "%d", &pListaCompra->cantidadArticulos);

    //Reservar memoria dinámica para la tabla de artículos
    pListaCompra->articulos = (Compra*) calloc(pListaCompra->cantidadArticulos, sizeof(Compra));
    if (pListaCompra->articulos == NULL)
        return 0;

    //Leer y guardar los artículos de la lista en la tabla
    for (i=0; i<pListaCompra->cantidadArticulos; i++)
        fscanf(f, "%s %d %f", pListaCompra->articulos[i].nombre, &pListaCompra->articulos[i].cantidad, &pListaCompra->articulos[i].precio);
    
    //Cerrar el fichero
    fclose(f);
    return 1;
}

//Función que analiza una estructura del tipo ListaCompra
int calculaListaCompra (ListaCompra lista, float *precioTotal, int *numArticulos, float *barato, float *caro){
    //Comprobar argumentos
    if (lista.cantidadArticulos < 1 || precioTotal == NULL || numArticulos == NULL || barato == NULL || caro == NULL)
        return 0;
    
    //Asignar el valor del primer artículo a *barato y *caro
    *barato = lista.articulos[0].precio;
    *caro = lista.articulos[0].precio;

    //Operar con todos los punteros
    for (*numArticulos=0, *precioTotal=0.0; *numArticulos<lista.cantidadArticulos; (*numArticulos)++){
        *precioTotal += lista.articulos[*numArticulos].precio * lista.articulos[*numArticulos].cantidad; //Sumar el valor de todos los artículo

        //Actualizar los valores de *barato y *caro
        if (lista.articulos[*numArticulos].precio < *barato)
            *barato = lista.articulos[*numArticulos].precio;
        
        if (lista.articulos[*numArticulos].precio > *caro)
            *caro = lista.articulos[*numArticulos].precio;
    }

    return 1;
}

//Función principal
int main (){
    char fichero[TAM];
    ListaCompra lista;
    float precioTotal, barato, caro;
    int num, i;

    //Leer el nombre del fichero
    printf("Introduce el nombre del fichero con la lista de la compra: ");
    scanf("%s", fichero);

    //Llamar a la primera función y comprobar el valor devuelto
    if (leeListaCompra(fichero, &lista) == 0){
        printf("Error ejecutando el programa.");
        return 1;
    }

    //Llamar a la segunda función y comprobar el valor devuelto
    if (calculaListaCompra(lista, &precioTotal, &num, &barato, &caro) == 0){
        printf("Error ejecutando el programa.");
        return 1;
    }

    //Imprimar la información de la estructura y los datos obtenidos
    printf("La lista de la compra esta compuesta por: \n");
    for (i=0; i<num; i++){
        printf("Articulo %d: %s, con %d unidad(es), a %.2fe la unidad\n", i+1, lista.articulos[i].nombre, lista.articulos[i].cantidad, lista.articulos[i].precio);
    }
    printf("El precio total de los %d articulos diferentes de la lista de la compra es %.2fe\n", num, precioTotal);
    printf("El articulo más barato cuesta %.2fe y el articulo mas caro cuesta %.2fe\n", barato, caro);

    //Liberar la memoria dinámica de la estructura de tipo Compra
    free(lista.articulos);
    return 0;

}