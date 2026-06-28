#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define RESET   "\033[0m"
#define ROJO    "\033[31m"
#define VERDE   "\033[32m"
#define AZUL    "\033[34m"

float lados_variables[28];
float resultados[20];
int menus[10];
const double PI = 3.141592653589793;

int isValid(float n){
    return (n > 0 && n < 10);
}

int isMoreThanZero(float n){
    return (n == 0 || n < 0);
}

int calcTrapecio();
int calcParalel();
int main()
{
    int opcion_principal = 0;

    do {
        printf("7. TRAPECIO\n");
        printf("8. PARALELOGRAMO\n");
        printf("9. SALIR\n");
        printf("Elija una opcion: ");
        scanf(" %d", &opcion_principal);

        switch(opcion_principal) {
            case 7:
                calcTrapecio(); 
                break;
            case 8:
                calcParalel(); 
                break;
            case 9:
                printf(AZUL "Saliendo del programa de prueba...\n" RESET);
                break;
            default:
                printf("Opción no válida en esta prueba.\n");
                break;
        }
    } while(opcion_principal != 9);

    return 0;
}

//funciones y las formulas 

float trapecioAreaBaseAltura(float b_mayor, float b_menor, float altura){
    return ((b_mayor + b_menor) * altura) / 2.0;
}

float trapecioAreaCuatroLados(float b1, float l1, float b2, float l2){
    float subcalculo = ((b1 + l1 + b2 + l2) / 2.0);
    return (((b1 + b2) / (fabs(b1 - b2))) * sqrt((subcalculo - b1) * (subcalculo - b2) * (subcalculo - b1 - l1) * (subcalculo - b1 - l2)));
}

float paralelogramoAreaBaseAltura(float base, float altura){
    return base * altura;
}

float paralelogramoAreaLadosAngulo(float l1, float l2, float angulo){
    float radianes = angulo * (PI / 180.0);
    return (l1 * l2 * sin(radianes));
}

float paralelogramoAreaDiagonalesAngulo(float d1, float d2, float angulo){
    float radianes = angulo * (PI / 180.0);
    return ((d1 * d2 * sin(radianes)) / 2.0);
}

//funciones del menu 

int calcTrapecio(){
    printf("\nQue datos tienes para obtener el calculo del Trapecio?\n");
    printf("....................................................................\n");
    printf("1. Base mayor, base menor y altura\n");
    printf("2. Los 4 lados\n");
    printf("....................................................................\n");
    scanf(" %d", &menus[7]);

    switch(menus[7]){
        case 1: {
            printf("Ingrese la base mayor: \n");
            scanf(" %f", &lados_variables[0]);
            
            printf("Ingrese la base menor: \n");
            scanf(" %f", &lados_variables[1]);
            
            printf("Ingrese la altura: \n");
            scanf(" %f", &lados_variables[2]);
            
            float resultado = trapecioAreaBaseAltura(lados_variables[0], lados_variables[1], lados_variables[2]);
            printf("El" ROJO " área" RESET " es de : " ROJO "%.2f\n" RESET, resultado);
            break;
        }

        case 2: {
            printf("Ingrese la base 1: \n");
            scanf(" %f", &lados_variables[0]);
            
            printf("Ingrese el lado 1: \n");
            scanf(" %f", &lados_variables[1]);
            
            printf("Ingrese la base 2: \n");
            scanf(" %f", &lados_variables[2]);
            
            printf("Ingrese el lado 2: \n");
            scanf(" %f", &lados_variables[3]);

            if (lados_variables[0] == lados_variables[2]){
                printf("Error: Las bases no pueden ser iguales.\n");
            } else {
                float resultado = trapecioAreaCuatroLados(lados_variables[0], lados_variables[1], lados_variables[2], lados_variables[3]);
                printf("El" ROJO " área" RESET " es de : " ROJO "%.2f\n" RESET, resultado);
            }
            break;
        }
        default:
            printf("Ingrese opciones validas\n");
            break;
    }
    return 0;
}

int calcParalel(){
    printf("\nQue datos tienes para obtener el calculo del Paralelogramo?\n");
    printf("....................................................................\n");
    printf("1. Base y altura\n");
    printf("2. 2 lados y un ángulo\n");
    printf("3. 2 diagonales y su ángulo\n");
    printf("....................................................................\n");
    scanf(" %d", &menus[8]);

    switch(menus[8]){
        case 1: {
            printf("\nIngrese la base: \n");
            scanf(" %f", &lados_variables[4]);
            
            printf("Ingrese la altura: \n");
            scanf(" %f", &lados_variables[5]);
            
            float resultado = paralelogramoAreaBaseAltura(lados_variables[4], lados_variables[5]);
            printf("El" ROJO " rea" RESET " es de : " ROJO "%.2f\n" RESET, resultado);
            break;
        }

        case 2: {
            printf("Ingrese el lado 1: \n");
            scanf(" %f", &lados_variables[4]);
            
            printf("Ingrese el lado 2: \n");
            scanf(" %f", &lados_variables[5]);
            
            printf("Ingrese el angulo interno: \n");
            scanf(" %f", &lados_variables[6]);
            
            float resultado = paralelogramoAreaLadosAngulo(lados_variables[4], lados_variables[5], lados_variables[6]);
            printf("El" ROJO " área" RESET " es de : " ROJO "%.2f\n" RESET, resultado);
            break;
        }

        case 3: {
            printf("Ingrese la diagonal 1: \n");
            scanf(" %f", &lados_variables[4]);
            
            printf("Ingrese la diagonal 2: \n");
            scanf(" %f", &lados_variables[5]);
            
            printf("Ingrese el angulo entre estas diagonales: \n");
            scanf(" %f", &lados_variables[6]);
            
            float resultado = paralelogramoAreaDiagonalesAngulo(lados_variables[4], lados_variables[5], lados_variables[6]);
            printf("El" ROJO " área" RESET " es de : " ROJO "%.2f\n" RESET, resultado);
            break;
        }
        default:
            printf("Ingrese opciones validas\n");
            break;
    }
    return 0;
}