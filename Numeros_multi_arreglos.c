#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i ;
    int numero[6];
    for (i=0; i<6; i++){
        printf("Ingrese sus numero %d: \n", i);
        scanf("%d", &numero[i]);
    }
    for (i=0; i<6; i++){
        printf("Su numero %d es: %d\n", i, numero[i]);
    }
    for (i=0; i<6; i++){
        numero[i]= numero[i]*2;
    }
    printf("Los numeros multiplicados por 2 son: \n");
    for (i=0; i<6; i++){
        printf("Su numero %d es: %d\n", i, numero[i]);
    }
    return 0;
}
