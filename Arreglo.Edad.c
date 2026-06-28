#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i ;
    int edad[6];
    for (i=0; i<6; i++){
        printf("Ingrese la edad del elemento %d: \n", i);
        scanf("%d", &edad[i]);
    }
    for (i=0; i<6; i++){
        printf("La edad del elemento %d es: %d\n", i, edad[i]);
    }
    for (i=0; i<6; i++){
        edad[i]= edad[i]*2;
    }
    printf("Las edades multiplicadas por 2 son: \n");
    for (i=0; i<6; i++){
        printf("La edad del elemento %d es: %d\n", i, edad[i]);
    }
    
return 0;
}