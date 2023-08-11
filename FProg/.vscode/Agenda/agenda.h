#ifndef AGENDA_H
#define AGENDA_H

#include <stdio.h>
#include <string.h>

#define NUM 100
#define TAM 30

//definición de estructuras Contacto y Agenda
typedef struct{
    char nombre[TAM]; //nombre del contacto
    char apellido[TAM]; //apellido del contacto
    int telefono; //teléfono del contacto
} Contacto;

typedef struct{
    Contacto lista[NUM]; //lista de contactos
    char archivo[TAM]; //archivo con los datos de los contactos
    int numero; //número de contactos
} Agenda;

//prototipos de funciones
int cargar_agenda (Agenda *ag);
int buscar (Agenda ag, char *nombre);
void agregar_contacto (Agenda *ag, Contacto c);

#endif