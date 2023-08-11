#include <stdio.h>

int main(){
    int n1, n2, n3;

    printf("Introduce el primer numero: ");
    scanf("%d", &n1);
    printf("Introduce el segundo numero: ");
    scanf("%d", &n2);
    printf("Introduce el tercer numero: ");
    scanf("%d", &n3);

    if (n1<=n2 && n1<=n3){
        printf("El numero %d es el menor", n1);
    }
    else if (n2<=n1 && n2<=n3){
        printf("El numero %d es el menor", n2);
    }
    else{
        printf("el numero %d es el menor", n3);
    }

    return 0;
}