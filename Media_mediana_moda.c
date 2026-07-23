#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int Arreglo[20];
int Elementos = 0;
int ArregloModificado[20];

bool NumeroValido(int n)
{
    if(n < 0 || n > 100){
        printf("Ingrese un numero valido...\n");
        return true;
    }
    else{
        return false;
    }
}

int ComparadorNumerico(const void *x, const void *y)
{
    int valx = *(const int *)x;
    int valy = *(const int *)y;
    return (valx > valy) - (valx < valy);
}

void MenorMayorArreglo()
{
    for (int i = 0; i < Elementos; i++) {
        ArregloModificado[i] = Arreglo[i];
    }
      qsort(ArregloModificado, Elementos, sizeof(int), ComparadorNumerico);
}

void IngresoArreglo()
{
    char Condicion = 'N';
    printf("Cuantos numeros enteros positivos desea ingresar?\n");
    printf("Ingrese un minimo de dos (2) y maximo de veinte (20) numeros...\n");
    do{
        Condicion = 'V';
        printf("Elementos: ");
        if (scanf("%d%c", &Elementos, &Condicion) == 2 && (Condicion == '\n' || Condicion == ' ')){
                if (Elementos < 2 || Elementos > 20){
                    printf("Recuerde ingresar un minimo de dos (2) y maximo de veinte (20) numeros...\n");
                    Condicion = 'I';
                }
                else{
                    Condicion = 'N';
                }
            }
            else{
                printf("Ingrese un elemento valido...\n");
                Condicion = 'I';
                while(getchar() != '\n');
            }
    }
    while(Condicion == 'I');
    for(int i = 0; i < Elementos; i++){
        do{
        Condicion = 'V';
        printf("Numero %d:", i + 1);
        if (scanf("%d%c", &Arreglo[i], &Condicion) == 2 && (Condicion == '\n' || Condicion == ' ')){
            Condicion = 'O';
        }
        else{
            printf("Ingrese un elemento valido...\n");
            Condicion = 'I';
            while(getchar() != '\n');
        }
        }
        while(Condicion == 'I' || (NumeroValido(Arreglo[i])== true && Condicion == 'O'));
    }
    MenorMayorArreglo();
}



// funciones matematicas para calcular la media, mediana y moda

void Moda()
{
    int MayorFrecuencia = 1;
    int CuentaActual = 1;
       
    for (int i = 1; i < Elementos; i++){
        if (ArregloModificado[i] == ArregloModificado[i - 1]){
            CuentaActual++;
        } else {
            if (CuentaActual > MayorFrecuencia){
                MayorFrecuencia = CuentaActual;
            }
            CuentaActual = 1;
        }
    }
    if (CuentaActual > MayorFrecuencia){
        MayorFrecuencia = CuentaActual;
    }
    if (MayorFrecuencia == 1) {
        printf("Moda: No hay moda alguna, todos los elementos aparecen exactamente una sola vez.\n");
        return;
    }
    else {
        printf("\n\033[1;32m-----------------------------------------\033[0m\n");
        printf(">>> Moda(s) detectada(s),  se repite %d veces el numero(s): ", MayorFrecuencia);
    }
    

    CuentaActual = 1;

    for (int i = 1; i < Elementos; i++){
        if (ArregloModificado[i] == ArregloModificado[i - 1]){
            CuentaActual++;
        } else{
            if(CuentaActual == MayorFrecuencia){
                printf("%d ", ArregloModificado[i - 1]);
            }
            CuentaActual = 1;
        }
    }
    if (CuentaActual == MayorFrecuencia){
        printf("%d\n ", ArregloModificado[Elementos - 1]);
    }
    printf("<<<\n");
    printf("\n\033[1;32m-----------------------------------------\033[0m\n");
}

void Mediana()
{
    double CalcMediana = 0;
    if (Elementos % 2 != 0) {
        CalcMediana = (double)(ArregloModificado[Elementos / 2]);
    } 
    else {
        CalcMediana = (double)(ArregloModificado[(Elementos / 2) - 1] + ArregloModificado[Elementos / 2]) / 2.0;
    }
    printf("\n\033[1;32m-----------------------------------------\033[0m\n");
    printf("  -------> La mediana es de: \033[1;33m%.1f\033[0m\n", CalcMediana);
    printf("\n\033[1;32m-----------------------------------------\033[0m\n");
}

void CalcularMedia()
{
    int suma = 0;
    for (int i = 0; i < Elementos; i++) {
        suma += Arreglo[i];
    }
    float promedio = (float)suma / Elementos;

    printf("\n\033[1;32m-----------------------------------------\033[0m\n");
    printf("  -> RESULTADO: La Media es: \033[1;33m%.2f\033[0m\n", promedio);
    printf("\033[1;32m-----------------------------------------\033[0m\n");
}



int mostrarMenu()
{
    int opcion;
    printf("\n\033[1;36m=====================================================\033[0m\n");
    printf("                 MENÚ          \n");
    printf("\n\033[1;36m=====================================================\033[0m\n");
    printf("  [1] Registrar Nuevos Valores\n");
    printf("  [2] Calcular Media (Promedio)\n");
    printf("  [3] Calcular Mediana\n");
    printf("  [4] Calcular Moda\n");
    printf("  [5] Mostrar Resumen Estadistico\n");
    printf("  [6] Salir del Programa\n");
    printf("\n\033[1;36m=====================================================\033[0m\n");
    printf("Seleccione una opcion: ");

    scanf(" %d", &opcion);
    return opcion;
}

int main(){
    int opcion;
    int datos_ingresados = 0;

    do {
        opcion = mostrarMenu();

    switch(opcion){
    case 1:
        printf("\n\033[1;36m=========================================\033[0m\n");
                printf(" >>>        REGISTRO DE VALORES       <<<\n");
                printf("\033[1;36m=========================================\033[0m\n");

                IngresoArreglo();
                datos_ingresados = 1;

                printf("\n\033[1;32m-----------------------------------------\033[0m\n");
                printf("\033[1;32m [OK] ¡Valores guardados con éxito!\033[0m\n");
                printf("\033[1;32m-----------------------------------------\033[0m\n");
                break;

    case 2:
        printf("\n\033[1;36m=========================================\033[0m\n");
        printf(" >>>        CÁLCULO DE LA MEDIA       <<<\n");
        printf("\033[1;36m=========================================\033[0m\n");

        if (datos_ingresados == 0) {
        printf("\033[1;31m [ALERTA] Primero debes ingresar datos en la Opción 1.\033[0m\n");
        } else {
            CalcularMedia(); // Llamada a la función
        }
        break;

    case 3:
        printf("\n\033[1;36m=========================================\033[0m\n");
        printf(" >>>        CÁLCULO DE LA MEDIANA       <<<\n");
        printf("\033[1;36m=========================================\033[0m\n");

        if (datos_ingresados == 0) {
        printf("\033[1;31m [ALERTA] Primero debes ingresar datos en la Opción 1.\033[0m\n");
        } else {
            Mediana(); // Llamada a la función
        }
        break;

    case 4:
        printf("\n\033[1;36m=========================================\033[0m\n");
        printf(" >>>        CÁLCULO DE LA MODA       <<<\n");
        printf("\033[1;36m=========================================\033[0m\n");

        if (datos_ingresados == 0) {
        printf("\033[1;31m [ALERTA] Primero debes ingresar datos en la Opción 1.\033[0m\n");
        } else {
            Moda(); // Llamada a la función
        }
        break;

    case 5:
        printf("\n\033[1;36m=========================================\033[0m\n");
        printf(" >>>        RESUMEN ESTADISTICO       <<<\n");
        printf("\033[1;36m=========================================\033[0m\n");

        if (datos_ingresados == 0) {
        printf("\033[1;31m [ALERTA] Primero debes ingresar datos en la Opción 1.\033[0m\n");
        }
        else{
            CalcularMedia();
            Mediana();
            Moda();
        }break;

    case 6:
        printf("Saliendo del programa...\n");
        break;
    default:
    printf("\n[ERROR] Opcion no valida. Intente de nuevo.\n");break;


    }
    }while(opcion != 6);
    return 0;
}
