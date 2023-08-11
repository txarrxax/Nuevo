#include <stdio.h>

int main (){
    int d1, m1, a1, d2, m2, a2;

    printf("Por favor, introduce la primera fecha: ");
    scanf("%d %d %d", &d1, &m1, &a1);
    printf("Por favor, introduce la segunda fecha: ");
    scanf("%d %d %d", &d2, &m2, &a2);

    if (a1 == a2){
        if (m1 == m2){
            if (d1 == d2){
                printf("La fecha %d/%d/%d conincide con %d/%d/%d", d1, m1, a1, d2, m2, a2);
            }
            else if (d1 < d2){
                printf("La fecha %d/%d/%d es anterior a %d/%d/%d", d1, m1, a1, d2, m2, a2);
            }
            else{
                printf("La fecha %d/%d/%d es anterior a %d/%d/%d", d2, m2, a2, d1, m1, a1);
            }
        }
        else if (m1 < m2){
            printf("La fecha %d/%d/%d es anterior a %d/%d/%d", d1, m1, a1, d2, m2, a2);
        }
        else{
            printf("La fecha %d/%d/%d es anterior a %d/%d/%d", d2, m2, a2, d1, m1, a1);
        }
    }
    else if (a1 < a2){
        printf("La fecha %d/%d/%d es anterior a %d/%d/%d", d1, m1, a1, d2, m2, a2);
    }
    else{
        printf("La fecha %d/%d/%d es anterior a %d/%d/%d", d2, m2, a2, d1, m1, a1);
    }
    return 0;
}