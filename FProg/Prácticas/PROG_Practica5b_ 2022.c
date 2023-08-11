#include <stdio.h>

#define STR_MAX 64

typedef struct{
    char prod[STR_MAX]; //nombre del producto
    char tipo[STR_MAX]; //tipo de producto
    char marca[STR_MAX]; //marca del producto
} Producto;

typedef struct{
    Producto producto; //información del producto
    char comercio[STR_MAX]; //comercio donde se compra el producto
    double precio; //precio del producto
    int num; //número de productos
} CompraProd;

//función que copia la información de un fichero a otro
int copiarCompra (char *origen, char *destino){
    FILE *f, *g;
    CompraProd compra;
    int i, num;

    //comprobar los argumentos
    if (!origen || !destino)
        return 1;

    //abrir y comprobar los ficheros
    f = fopen(origen, "r");
    g = fopen(destino, "w");
    if (!f || !g)
        return 1;

    //leer el número de productos del primer fichero
    fscanf(f, "%d", &num);

    //copiar la información de un fichero a otro
    for (i=0; i<num; i++){
        fscanf(f, "%s %s %s %s %lf %d", compra.producto.prod, compra.producto.tipo, compra.producto.marca, compra.comercio, &compra.precio, &compra.num);
        fprintf(g, "%s %s %s %s %lf %d\n", compra.producto.prod, compra.producto.tipo, compra.producto.marca, compra.comercio, compra.precio, compra.num);
    }

    //cerrar los ficheros
    fclose(f);
    fclose(g);
    return 0;
}

//función que añade una linea nueva al fichero
int anadirProducto (char *fichero, CompraProd *nuevo){
    FILE *f;

    //abrir y comprobar los argumentos
    if (!fichero)
        return 1;

    //abrir y comprobar el fichero
    f = fopen(fichero, "a");
    if (!f)
        return 1;
    
    //añadir la información nueva al fichero
    fprintf(f, "%s %s %s %s %lf %d\n", nuevo->producto.prod, nuevo->producto.tipo, nuevo->producto.marca, nuevo->comercio, nuevo->precio, nuevo->num);

    //cerrar el fichero
    fclose(f);
    return 0;
}

//programa principal
int main (){
    char origen[STR_MAX], destino[STR_MAX];
    CompraProd nuevo;
    char sn;

    //solicitar los nombres de los fichero
    printf("Nombre del fichero de datos: ");
    scanf("%s", origen);
    printf("Nombre del fichero de la lista ampliada: ");
    scanf("%s", destino);

    //copiar los datos de un fichero a otro y comprobar
    if (copiarCompra(origen, destino)){
        printf("Error en la apertura de los archivos %s y %s", origen, destino);
        return 1;
    }

    //solicitar nuevos datos y añadirlos al fichero
    do{
        printf("Desea anadir mas productos a la lista? (s/n): ");
        scanf("\n%c", &sn);

        if(sn == 's'){
            printf("Introduzca los datos del producto separados por espacios (producto, tipo, marca, supermercado, precio y nº unidades):\n");
            scanf("%s %s %s %s %lf %d", nuevo.producto.prod, nuevo.producto.tipo, nuevo.producto.marca, nuevo.comercio, &nuevo.precio, &nuevo.num);
            
            //añadir el producto y comprobar
            if(anadirProducto(destino, &nuevo)){
                printf("Error en la apertura del archivo %s", destino);
                return 1;
            }
        }
    } while (sn == 's');

    return 0;
}