#include <stdio.h>
#include <stdlib.h>

#define MAX_CAD 64

//estructura de tipo Porducto
typedef struct{
    char prod[MAX_CAD]; //nombre del producto
    char tipo[MAX_CAD]; //tipo de producto
    char marca[MAX_CAD]; //marca del producto
} Producto;

typedef struct{
    Producto producto; //información del producto
    char comercio[MAX_CAD]; //comercio donde se compra el producto
    double precio; //precio del producto
    int num; //número de productos
} CompraProd;

//función que lee el fichero, guarda el número de elementos y los almacena en una tabla
CompraProd *leerFichero (char *nombreFichero, long *num){
    FILE *f;
    CompraProd *compra;
    int i;

    //comprobar los argumentos
    if (!nombreFichero || !num)
        return NULL;
        
    //abrir y comprobar el fichero
    f = fopen(nombreFichero, "r");
    if (!f)
        return NULL;
        
    
    //leer el número de compras contenidas en el fichero
    fscanf(f, "%ld", num);

    //reservar memoria dinámica para una tabla del tamaño deseado y comprobarla
    compra = (CompraProd*) calloc(*num, sizeof(CompraProd));
    if (!compra)
        return NULL;

    //leer la información del fichero y guardarla en la tabla
    for (i=0; i<*num; i++)
        fscanf(f, "%s %s %s %s %lf %d", compra[i].producto.prod, compra[i].producto.tipo, compra[i].producto.marca, compra[i].comercio, &compra[i].precio, &compra[i].num);
    
    //cerrar el fichero
    fclose(f);
    return compra;
}

//función que calcula el importe de la compra
double importeCompra (CompraProd *compras, long num){
    long i;
    double total;

    //comprobar los argumentos
    if (!compras || num == 0)
        return -1;
    
    //sumar el precio de todos los productos de la tabla
    for (i=0, total=0.0; i<num; i++){
        total += compras[i].precio * compras[i].num;
    }

    //liberar la memoria reservada en la tabla
    free(compras);

    //devolver el valor total de la compra
    return total;
}

//programa principal
int main (){
    char fichero[MAX_CAD];
    long num;
    double total;
    CompraProd *compra;

    //solicitar el nombre del fichero
    printf("Nombre del fichero de datos: ");
    scanf("%s", fichero);

    //leer el fichero y comprobar
    compra = leerFichero(fichero, &num);
    if (!compra){
        printf("Error de lectura del fichero: %s", fichero);
        free(compra); //liberar la memoria en caso de error
        return 1;
    }

    //calcular la suma del importe de la compra y comprobar
    total = importeCompra(compra, num);
    if (total == -1){
        printf("Error en la ejecucion del programa");
        free(compra); //liberar la memoria en caso de error
        return 1;
    }

    //mostrar la información por pantalla
    printf("El importe total de las compras del fichero %s es: %.2lf", fichero, total);
    return 0;
}