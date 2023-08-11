#include <stdio.h>

int main (){
    int x1, x2, x3, x4, x5, x6, total=0;

    for (x1=1; x1<=6; x1++){
        for (x2=1; x2<=6; x2++){
            for (x3=1; x3<=6; x3++){
                for (x4=1; x4<=6; x4++){
                    for (x5=1; x5<=6; x5++){
                        for (x6=1; x6<=6; x5++){
                            total ++;
                        }
                    }
                }
            }
        }
    }

    printf("%d", total);
    return 0;
}