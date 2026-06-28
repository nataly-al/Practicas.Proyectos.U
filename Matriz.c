#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int i;
    int j;
    int materias;
    int Estudiantes;
    printf("Ingrese el numero de materias: \n");
    scanf("%d", &materias);
    if (materias <= 0) {
        printf("Error: Debe ser mayor que 0.\n");
        return 1;
    }
    printf("Ingrese el numero de estudiantes: \n");
    scanf("%d", &Estudiantes);
    if (Estudiantes <= 0) {
        printf("Error: Debe ser mayor que 0.\n");
        return 1;
    }
    int calificaciones[Estudiantes][materias];
    for (int i=0; i<Estudiantes; i++){
        for (int j=0; j<materias; j++){
            printf("Ingrese la calificacion del estudiante %d en la materia %d: \n", i+1, j+1);
            scanf("%d", &calificaciones[i][j]);
        }
    }
    return 0;
}