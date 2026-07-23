#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
//el usuario debe intentar adivinar un numero aleatorio generado por el programa
//contar el numero de intentos que le tomo al usuario adivinar el numero
bool NumeroValido(int n) {
    if (n >= 1 && n <= 100) {
        return true;  // Es válido
    } else {
        printf("¡Error! Debes ingresar un número entre 1 y 100.\n");
        return false; // No es válido
    }
} 
int main() {
int numero_aleatorio;
int intentos = 0;
int n = 0;


//generar un numero aleatorio entre 1 y 100
srand(time(NULL));
numero_aleatorio = rand() % 100 + 1;

printf("Bienvenido al juego de adivinar el numero!\n");
printf("Estoy pensando en un numero entre 1 y 100.\n");
printf("Intenta adivinar el numero:\n");


do {
    printf("Ingresa un numero: ");
    scanf("%d", &n);   
    if (NumeroValido(n))
    {
    intentos++;
    if (n < numero_aleatorio) {
        printf("Demasiado bajo! Intenta de nuevo.\n");
    } else if (n > numero_aleatorio) {
        printf("Demasiado alto! Intenta de nuevo.\n");
    } else {
        printf("Felicidades! Adivinaste el numero en %d intentos.\n", intentos);
    }
    }
   }while (n != numero_aleatorio);

   printf("Quieres volver a jugar? (s/n): ");
   printf("Ingresa 's' para si o 'n' para no: ");
   char respuesta;
   scanf(" %c", &respuesta);
   if (respuesta == 's' || respuesta == 'S') {
       main(); // Llamada recursiva para reiniciar el juego
   } else {
       printf("Gracias por jugar! Hasta luego.\n");
   }
   return 0;
}