#include <stdio.h>
#include <stdlib.h>

#define STR_MAX 64

typedef struct{
    int dia;
    int mes;
    int anyo;
} Fecha;

typedef struct{
    Fecha *fechasInicio;
    Fecha *fechasFin;
    int *distancias;
    int numFechas;
} Fechas;

int contarFechas (char *nomFichero){
    FILE *f;
    Fecha a, b;
    int intervalos;

    //comprobar argumentos
    if (!nomFichero)
        return -1;
    
    //abrir fichero y comprobarlo
    f = fopen(nomFichero, "r");
    if (!f)
        return -2;
    
    for (intervalos=0; fscanf(f, "%d %d %d %d %d %d", &a.dia, &a.mes, &a.anyo, &b.dia, &b.mes, &b.anyo) == 6; intervalos++);

    return intervalos;
}

int leerFechas (char *nomFichero, Fechas *fechas){
    FILE *f;

    //comprobar argumentos
    if (!nomFichero || !fechas)
        return -1;
    
    //abrir fichero y comprobarlo
    f = fopen(nomFichero, "r");
    if (!f)
        return -2;
    
    //guardar los datos en *fechas
    for (fechas->numFechas=0; fscanf(f, "%d %d %d %d %d %d", &fechas->fechasInicio[fechas->numFechas].dia, &fechas->fechasInicio[fechas->numFechas].mes, &fechas->fechasInicio[fechas->numFechas].anyo, &fechas->fechasFin[fechas->numFechas].dia, &fechas->fechasFin[fechas->numFechas].mes, &fechas->fechasFin[fechas->numFechas].anyo) == 6; fechas->numFechas++);

    return 1;
}

int esBisiesto (int anyo){
    if (anyo%4 == 0){
        if (anyo%100 == 0){
            if (anyo%400 == 0)
                return 1;
            else
                return 0;
        }
        else
            return 1;
    }
    else
        return 0;
}

int numeroDias (Fecha *f){
    const int diasAnyo[2] = {365, 366};
    const int diasMes[2][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
    int numdias = 0, i;
    //comprobar argumentos
    if (!f || f->anyo < 1900)
        return -1;

    //sumar años enteros
    for (i=1900; i<f->anyo; i++){
        if (esBisiesto(i) == 1)
            numdias += diasAnyo[1];
        else
            numdias += diasAnyo[0];
    }

    //sumar meses enteros
    for (i=0; i<f->mes-1; i++){
        if (esBisiesto(f->anyo) == 1)
            numdias += diasMes[1][i];
        else
            numdias += diasMes[0][i];
    }

    //sumar dias sueltos
    numdias += f->dia - 1;

    return numdias;
}

int diasEntreFechas (Fecha *f1, Fecha *f2, int *nDias){
    //comprobar argumentos
    if (!f1 || !f2 || !nDias)
        return 1;
    if (f1->anyo < 1900 || f2->anyo < 1900)
        return 1;
    
    *nDias = numeroDias(f2) - numeroDias(f1);

    return 0;
}

int calcularDistancias (Fechas *f){
    int i;

    //comprobar argumentos
    if (!f || !f->fechasInicio || !f->fechasFin || !f->distancias || f->numFechas == 0)
        return 0;
    
    //calcular y almacenar las distancias
    for (i=0; i<f->numFechas; i++){
        if (diasEntreFechas(&f->fechasInicio[i], &f->fechasFin[i], &f->distancias[i]))
            return 0;
    }

    return 1;
}

int escribirFechasYDistancias (char *nombre, Fechas fechas){
    FILE *f;
    int i;

    //comprobar argumentos
    if (!nombre || !fechas.fechasInicio || !fechas.fechasFin || !fechas.distancias || fechas.numFechas == 0)
        return -1;

    //abrir y comprobar el fichero
    f = fopen(nombre, "w");
    if (!f)
        return -2;
    
    //escribir los datos en el fichero
    for (i=0; i<fechas.numFechas; i++){
        fprintf(f, "Entre el %d/%d/%d y el %d/%d/%d hay %d dias.\n", fechas.fechasInicio[i].dia, fechas.fechasInicio[i].mes, fechas.fechasInicio[i].anyo, fechas.fechasFin[i].dia, fechas.fechasFin[i].mes, fechas.fechasFin[i].anyo, fechas.distancias[i]);
    }

    //cerrar fichero
    fclose(f);
    return 1;
}

void liberarMemorias (Fechas *f){
    free(f->fechasInicio);
    free(f->fechasFin);
    free(f->distancias);
}

int main (){
    Fechas f;
    char nombre[STR_MAX];

    //solicitar nombre del fichero
    printf("Introduce el nombre del fichero con la fechas: ");
    scanf("%s", nombre);

    //reservar memoria dinamica para las tablas de la estructura de tipo Fechas y comprobarlas
    if (!(f.fechasInicio = (Fecha*) calloc(contarFechas(nombre), sizeof(Fecha))))
        return 0;
    if(!(f.fechasFin = (Fecha*) calloc(contarFechas(nombre), sizeof(Fecha)))){
        free(f.fechasInicio);
        return 0;
    }
    if (!(f.distancias = (int*) calloc (contarFechas(nombre), sizeof(int)))){
        free(f.fechasInicio);
        free(f.fechasFin);
        return 0;
    }

    //guardar los datos del fichero en la estructura de tipo Fechas
    if (!leerFechas(nombre, &f)){
        printf("Ha ocurrido un error.");
        liberarMemorias(&f);
        return 0;
    }
    
    //calcular la distancia entre las fechas de la estructura de tipo Fechas
    if (!calcularDistancias(&f)){
        printf("Ha ocurrido un error.");
        liberarMemorias(&f);
        return 0;
    }

    //solicitar el nombre de un nuevo archivo
    printf("Introduce el nombre del fichero donde vas a guardar las distancias: ");
    scanf("%s", nombre);

    //guardar los resultados en el fichero nuevo
    if (!escribirFechasYDistancias(nombre, f)){
        printf("Ha ocurrido un error.");
        liberarMemorias(&f);
        return 0;
    }

    //imprimir mensaje de confirmación y liberar memoria
    printf("Informacion guardada correctamente en el fichero. Gracias por usar este programa.");
    liberarMemorias(&f);
    return 1;
}