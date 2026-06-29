#include <stdio.h>
#include <stdlib.h>
// funcion de calcular el cuadrado de un numero
// funcion de calcular el salario de un trabajador
int Cuadrado(int num)
{
    return num * num;
}
float Salario(float salario, int dias)
{
    return salario * dias;
}

int main()
{
    int opcion;

    do
    {
        printf("Bienvenido al programa de calculos \n");
        printf("Seleccione una opcion: \n");
        printf("1. Calcular el cuadrado de un numero \n");
        printf("2. Calcular el salario de un trabajador \n");
        printf("3. Salir del programa \n");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            int num;
            printf("Ingrese un numero: \n");
            scanf("%d", &num);
            printf("El cuadrado de %d es %d\n", num, Cuadrado(num));
            break;
        case 2:
            float salario;
            int dias;
            printf("Ingrese el salario diario: \n");
            scanf("%f", &salario);
            printf("Ingrese el número de días trabajados: \n");
            scanf("%d", &dias);
            printf("El salario es: %.2f\n", Salario(salario, dias));
            break;
        case 3:
            printf("Saliendo del programa...\n");
            return 0;
        default:
            printf("Opción no válida, intenta de nuevo.\n");
        }
    } while (opcion != 3);
    return 0;
}
