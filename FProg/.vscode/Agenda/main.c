#include "agenda.h"

//función principal
int main (){
    Agenda ag;
    int codigo;
    char nombre[TAM];
    Contacto cont;

    //solicitar el nombre del fichero
    printf("Introduzca el nombre del archivo con los datos de la agenda: ");
    scanf("%s", ag.archivo);

    //llamar a la función cargar_agenda y comprobar el valor devuelto
    codigo = cargar_agenda (&ag);
    if (codigo == 1){
        printf("Error en la apertura del fichero\n");
        return 1;
    }
    else if (codigo == 2){
        printf("Error en la lectura del fichero\n");
        return 2;
    }

    //solicitar el nombre a buscar
    printf("Introduzca un nombre para buscar en la agenda: ");
    scanf("%s", nombre);

    //llamar a la función buscar y comprobar el valor devuelto
    codigo = buscar(ag, nombre);
    if (codigo == 0)
        printf("%s no se encuentra en la agenda\n", nombre);
    else
        printf("El telefono de %s es %d\n", nombre, codigo);
    
    //solicitar el contacto a agregar
    printf("Introduce el nombre del nuevo contacto: ");
    scanf("%s", cont.nombre);
    printf("Introduce el apellido del nuevo contacto: ");
    scanf("%s", cont.apellido);
    printf("Introduce el telefono del nuevo contacto: ");
    scanf("%d", &cont.telefono);

    //llamar a la funcion agregar_contacto
    agregar_contacto(&ag, cont);


    return 0;
}