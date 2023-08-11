#include <stdio.h>

#define DIM 100

typedef struct {
    char nombre;
    char apellido;
} Contacto;

typedef struct {
    Contacto contactos[DIM];
    int num;
} Agenda;

void IniciarAgenda (Agenda *ag){
    (*ag).num = 0;
}

void AniadirContacto (Agenda *ag, char nom, char apell){
    (*ag).contactos[(*ag).num].nombre = nom;
    (*ag).contactos[(*ag).num].apellido = apell;
    (*ag).num++;
}

void MostrarAgenda (Agenda ag){
    int i;

    printf("Hay %d contactos en la agenda:\n", ag.num);
    for (i=0; i<ag.num; i++){
        printf("Contacto %d: %c %c\n", i+1, ag.contactos[i].nombre, ag.contactos[i].apellido);
    }
}

int main (){
    Agenda agenda;
    char nombre, apellido;
    int i, num;

    IniciarAgenda(&agenda);

    do{    
        printf("¿Cuantos contactos quieres guardar en la agenda? ");
        scanf("%d", &num);

        if (num < 1 || num > 100){
            printf("ERROR: el valor debe estar entre 1 y 100\n");
        }
    } while (num < 1 || num > 100);

    for (i=0; i<num; i++){
        printf("Introduce el nombre del contacto %d: ", i+1);
        scanf("\n%c", &nombre);
        printf("Introduce el apellido del contacto %d: ", i+1);
        scanf("\n%c", &apellido);

        AniadirContacto(&agenda, nombre, apellido);
    }

    MostrarAgenda(agenda);

    return 0;
}