#include "agenda.h"

//definición de funciones
//función que cargar y comprueba lo datos de la Agenda
int cargar_agenda (Agenda *ag){
    FILE *f;

    //abrir y comprobar el fichero
    f = fopen(ag->archivo, "r");
    if (!f)
        return 1;

    //cargar los datos del fichero en la estructura de tipo Agenda
    for (ag->numero=0; fscanf(f, "%s", ag->lista[ag->numero].nombre) == 1; ag->numero++){
        if (fscanf(f, "%s", ag->lista[ag->numero].apellido) != 1)
            return 2;
        if (fscanf(f, "%d", &ag->lista[ag->numero].telefono) != 1)
            return 2;
    }

    //cerrar el fichero
    fclose(f);
    return 0;
}

//función que busca un nombre en la Agenda
int buscar (Agenda ag, char *nombre){
    int i;

    //buscar coincidencias en la Agenda y devuelve el número de teléfono si la ecuentra
    for (i=0; i<ag.numero; i++){
        if (!(strcmp(nombre, ag.lista[i].nombre)))
            return ag.lista[i].telefono;
    }

    return 0;
}

//función que agrega un contacto al fichero
void agregar_contacto (Agenda *ag, Contacto c){
    FILE *f;

    //abrir el fichero
    f = fopen(ag->archivo, "a");

    //añadir el nuevo contacto al fichero
    fprintf(f, "%s %s %d\n", c.nombre, c.apellido, c.telefono);

    //cerrar el fichero
    fclose(f);
}