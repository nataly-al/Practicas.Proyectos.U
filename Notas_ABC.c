#include <stdio.h>
//Registrar 40 notas , mostrar cuantos sacaron A,B,C,D y F 
//mostrar el porcentaje de los q sacaron A,B o C 
//Notas del 0 al 100
// A= 91-100 , B=81-90 , C=71-80 , D= 61-70, F= menos de 61
int main()
{
    float notas[5];
    int i, A=0, B=0, C=0, D=0, F=0;
    for (i = 0; i < 5; i++) //repetir una cantidad conocida
    {
     printf("Ingrese su nota %d:",i+1);
     scanf("%f", &notas[i]);
     if (notas[i]<0 || notas[i]>100)
     {
        printf("Ingrese una nota valida\n");
        i--; //decrementar el contador para repetir la iteracion
     }
    }
    for (i = 0; i < 5; i++)
    {
    if(notas[i]>=91 && notas[i]<=100)
    {
        A++;
    }
    else if(notas[i]>=81 && notas[i]<=90)
    {
        B++;
    }
    else if(notas[i]>=71 && notas[i]<=80)
    {
        C++;
    }
    else if(notas[i]>=61 && notas[i]<=70)
    {
    D++;
    }
    else if(notas[i]<61)
    {
    F++;
    }
    printf("Cantidad de A: %d\n", A);
    printf("Cantidad de B: %d\n", B);
    printf("Cantidad de C: %d\n", C);
    printf("Cantidad de D: %d\n", D);
    printf("Cantidad de F: %d\n", F);

    return 0;
}
}