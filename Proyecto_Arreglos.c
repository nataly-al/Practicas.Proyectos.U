#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#define RESET   "\033[0m"
#define VERDE   "\033[32m"
#define AZUL    "\033[34m"
#define ROJO    "\033[31m"

// ==========================================
// 1. PROTOTIPO DE LA FUNCIÓN
// ==========================================
int menu();

int main()
{
    //Definir variables
    setlocale(LC_ALL, "");
    const double PI=3.14159265358979323846;
    
    int menu_formas=0;
    char rect_1='a';
    int opcion=0;
    
    // Nuestro arreglo multiusos de 4 espacios que se encarga de TODO
    float datos[4] = {0, 0, 0, 0}; 
    
    // Variables de control de los sub-menús
    int seleccion_tringl=0;
    int seleccion_circ=0;
    int seleccion_romb=0;
    int seleccion_trap=0;
    int seleccion_paral=0;
    
    float subcalculo=0;
    float degree_1=0;
    float degree_2=0;
    float c=0;

    //iniciamos el ciclo de todo el programa
    do{
        // ==========================================
        // 2. LLAMADA A LA FUNCIÓN MENÚ
        // ==========================================
        menu_formas = menu();

        switch(menu_formas){
            case 1:
                printf("Eliga la opción que se integre al problema y información adquirida.\n");
                printf("....................................................................\n");
                printf("1. Tengo la base y altura\n");
                printf("2. Tengo los tres lados conocidos\n");
                printf("3. Tengo dos lados y el ángulo comprendido\n");
                printf("4. Tengo dos ángulos y un lado\n");
                printf("5. Ninguna de las anteriores\n");
                printf("6. Volver al menú\n");
                printf("....................................................................\n");
                scanf(" %d", &seleccion_tringl);

                switch(seleccion_tringl){
                    case 1:
                        do{
                            printf ("Ingrese la base: \n");
                            scanf (" %f", &datos[0]);
                        }while(datos[0]==0 || datos[0]<0);
                        
                        do{
                            printf ("Ingrese la altura : \n");
                            scanf (" %f", &datos[1]);
                        }while(datos[1]==0 || datos[1]<0);
                        
                        datos[2] = ((datos[0]*datos[1])/2.0);
                        printf ("El" ROJO" rea"RESET " es de : " ROJO"%.2f\n"RESET, datos[2]);
                        opcion = 0;
                        break;

                    case 2:
                        do{
                            printf("Ingrese el primer lado: \n");
                            scanf(" %f", &datos[0]); 
                        }while(datos[0]==0 || datos[0]<0);
                        
                        do{
                            printf("Ingrese el segundo lado: \n");
                            scanf(" %f", &datos[1]); 
                        }while(datos[1]==0 || datos[1]<0);
                        
                        do{
                            printf("Ingrese el tercero lado: \n");
                            scanf(" %f", &datos[2]); 
                        }while(datos[2]==0 || datos[2]<0);
                        
                        if ((datos[0] + datos[1] <= datos[2]) || (datos[0] + datos[2] <= datos[1]) || (datos[1] + datos[2] <= datos[0])){
                            printf("Los valores dan lados imposibles de formar un triangulo!\n");
                            printf("Ingrese valores reales.\n");
                        }else{ 
                            subcalculo = ((datos[0]+datos[1]+datos[2])/2.0);
                            datos[3] = (sqrt(subcalculo*((subcalculo - datos[0])*(subcalculo - datos[1])*(subcalculo - datos[2] ))));
                            printf ("El" ROJO"rea"RESET " es de : " ROJO"%.2f\n"RESET, datos[3]);
                            opcion = 0;
                        }
                        break;

                    case 3:
                        do{
                            printf("Ingrese el primer lado conocido: \n");
                            scanf(" %f", &datos[0]); 
                        }while(datos[0]==0 || datos[0]<0);
                        
                        do{
                            printf("Ingrese el segundo lado conocido: \n");
                            scanf(" %f", &datos[1]); 
                        }while(datos[1]==0 || datos[1]<0);
                        
                        printf("Ingrese el ángulo comprendido: \n");
                        scanf(" %f", &degree_1);
                        double radians_1 = degree_1 * (PI / 180.0);
                        datos[2] = ((datos[0]*datos[1]*sin(radians_1))/2.0);
                        printf ("El" ROJO" área"RESET " es de : " ROJO"%.2f\n"RESET, datos[2]);
                        opcion = 0;
                        break;

                    case 4:
                        do{
                            printf("Ingrese el lado conocido: \n");
                            scanf(" %f", &datos[0]); 
                        }while(datos[0]==0 || datos[0]<0);
                        
                        printf("Ingrese el primer ángulo conocido: \n");
                        scanf(" %f", &degree_1);
                        double radians_1_case4 = degree_1 * (PI / 180.0);
                        printf("Ingrese el segundo ángulo conocido: \n");
                        scanf(" %f", &degree_2);
                        double radians_2 = degree_2 * (PI / 180.0);
                        datos[1] = (((datos[0]*datos[0]) * sin(radians_1_case4)*sin(radians_2))/(2.0*sin(radians_1_case4+radians_2)));
                        printf ("El" ROJO" área"RESET " es de : " ROJO"%.2f\n"RESET, datos[1]);
                        opcion = 0;
                        break;
                        
                    case 5:
                        printf("Adquiera mas informacieon!\n");
                        printf("....................................................................\n");
                        continue;

                    default:
                        opcion = 0;
                        break;
                }
                break;

            case 2:
                do{
                    printf ("\nIngrese la longitud de cualquier lado: \n");
                    scanf (" %f", &datos[0]);
                }while(datos[0]==0 || datos[0]<0);
                datos[1] = (datos[0]*datos[0]);
                printf ("El" ROJO" área"RESET " es de : " ROJO"%.2f\n"RESET, datos[1]);
                break;

            case 3:
                printf("\nQue datos tiene para calcular la altura?\n");
                printf("a. Base y altura\n");
                printf("b. Diagonal y un lado\n");
                printf("c. Perimetro y un lado\n\n");
                scanf(" %c", &rect_1);

                switch(rect_1){
                    case 'a': 
                        do{
                            printf ("\nIngrese la base: \n");
                            scanf (" %f", &datos[0]);
                        }while(datos[0]==0 || datos[0]<0);
                        
                        do{
                            printf ("Ingrese la altura: \n");
                            scanf (" %f", &datos[1]);
                        }while(datos[1]==0 || datos[1]<0);
                        
                        datos[2] = (datos[0]*datos[1]);
                        printf ("El" ROJO" área"RESET " es de : " ROJO"%.2f\n"RESET, datos[2]);
                        break;

                    case 'b':
                        do{
                            printf("Ingrese la diagonal: \n");
                            scanf(" %f", &datos[0]);
                        }while(datos[0]==0 || datos[0]<0);
                        
                        do{
                            printf("Ingrese el lado: \n");
                            scanf(" %f", &datos[1]);
                        }while(datos[1]==0 || datos[1]<0);
                        
                        if(datos[0]<=datos[1]){
                            printf("La diagonal debe ser mayor a el lado. Ingrese valores vlidos\n\n");
                        }else{
                            subcalculo=sqrt(pow(datos[0],2)-pow(datos[1],2));
                            datos[2]=datos[1]*subcalculo;
                            printf ("El" ROJO" rea"RESET " es de : " ROJO"%.2f\n"RESET, datos[2]);
                        }
                        break;

                    case 'c': 
                        printf("\nIngrese el perimetro\n");
                        do{
                            scanf(" %f", &datos[0]);
                        }while(datos[0]==0 || datos[0]<0);
                        
                        do{
                            printf("Ingrese longitud de un lado\n");
                            scanf(" %f", &datos[1]);
                        }while(datos[1]==0 || datos[1]<0);
                        
                        if(datos[0]<=datos[1]){
                            printf("La diagonal debe ser mayor a el lado. Ingrese valores vlidos\n\n");
                        }else{
                            datos[2]=(datos[1]*((datos[0]-(2*datos[1]))/2));
                            printf ("El" ROJO" rea"RESET " es de : " ROJO"%.2f\n"RESET, datos[2]);
                        }
                        break;
                        
                    default:
                        printf("Ingrese un valor valido\n");
                        break;
                }
                break;

            case 4:
                printf("Que datos tienes para obtener el calculo?\n");
                printf("1. Radio\n");
                printf("2. Diametro\n");
                printf("3. Circunferencia/perimetro\n\n");
                scanf(" %d", &seleccion_circ);

                switch (seleccion_circ){
                    case 1: 
                        do{
                            printf ("\nIngrese el radio:\n");
                            scanf (" %f", &datos[0]);
                        }
                        while(datos[0]==0 || datos[0]<0);
                        datos[1]= (PI*(datos[0]*datos[0]));
                        printf ("El" ROJO" rea"RESET " es de : " ROJO"%.2f\n"RESET, datos[1]);
                        break;

                    case 2: 
                        do{
                            printf("\nIngrese el diametro:\n");
                            scanf(" %f", &datos[0]);
                        }
                        while(datos[0]==0 || datos[0]<0);
                        datos[1]=datos[0]/2; 
                        datos[2]=(PI*pow(datos[1],2));
                        printf ("El" ROJO" rea"RESET " es de : " ROJO"%.2f\n"RESET, datos[2]);
                        break;

                    case 3: 
                        do{
                            printf("\nIngrese la circunferencia/perimetro");
                            scanf(" %f", &datos[0]);
                        }
                        while(datos[0]==0 || datos[0]<0);
                        c=datos[0]/(2*PI);
                        datos[1]=(pow(c,2)/(4*PI));
                        printf ("El" ROJO" área"RESET " es de : " ROJO"%.2f\n"RESET, datos[1]);
                        break;

                    default:
                        printf("Ingrese una opción valida\n");
                        break;
                }
                break;

            case 5:
                do{
                    printf ("\nIngrese el semieje mayor: \n");
                    scanf (" %f", &datos[0]);
                }
                while(datos[0]==0 || datos[0]<0);
                
                do{
                    printf ("Ingrese el semieje menor: \n");
                    scanf (" %f", &datos[1]);
                }
                while(datos[1]==0 || datos[1]<0);
                
                datos[2]= (PI*(datos[0]*datos[1]));
                printf ("El" ROJO" rea"RESET " es de : " ROJO"%.2f\n"RESET, datos[2]);
                break;

            case 6:
                printf("Que datos tienes para obtener el calculo?\n");
                printf("1. Dos diagonales\n");
                printf("2. Base y Altura\n");
                printf("3. Lado y un ángulo\n\n");
                scanf(" %d", &seleccion_romb);

                switch(seleccion_romb){
                    case 1: 
                        do{
                            printf ("Ingrese la diagonal mayor: \n");
                            scanf (" %f", &datos[0]);
                        }
                        while(datos[0]==0 || datos[0]<0);
                        
                        do{
                            printf ("Ingrese la diagonal menor: \n");
                            scanf (" %f", &datos[1]);
                        }
                            while(datos[1]==0 || datos[1]<0);
                        
                        datos[2]= ((datos[0]*datos[1])/2);
                        printf ("El" ROJO" rea"RESET " es de : " ROJO"%.2f\n"RESET, datos[2]);
                        break;

                    case 2:
                        do{
                            printf("Ingrese la base: \n");
                            scanf(" %f", &datos[0]);
                        }while(datos[0]==0 || datos[0]<0);
                        
                        do{
                            printf("Ingrese la altura: \n");
                            scanf(" %f", &datos[1]);
                        }while(datos[1]==0 || datos[1]<0);
                        
                        datos[2]=datos[0]*datos[1];
                        printf ("El" ROJO" rea"RESET " es de : " ROJO"%.2f\n"RESET, datos[2]);
                        break;

                    case 3:
                        do{
                            printf("Ingrese el valor de un lado \n");
                            scanf(" %f", &datos[0]);
                        }while(datos[0]==0 || datos[0]<0);
                        
                        printf("Ingrese uno de sus ángulos internos: \n");
                        scanf(" %f", &degree_1);
                        degree_1=degree_1*(PI / 180.0);
                        datos[1]=((pow(datos[0],2))*(sin(degree_1)));
                        printf ("El" ROJO" área"RESET " es de : " ROJO"%.2f\n"RESET, datos[1]);
                        break;

                    default:
                        printf("Ingrese opciones validas\n");
                        break;
                }
                break;

            case 7:
                printf("Que datos tienes para obtener el calculo?\n");
                printf("1. Base mayor, base menor y altura\n");
                printf("2. Los 4 lados\n");
                scanf(" %d", &seleccion_trap);

                switch(seleccion_trap){
                    case 1: 
                        do{
                            printf("Ingrese la base mayor: \n");
                            scanf(" %f", &datos[0]);
                        }while(datos[0]==0 || datos[0]<0);
                        
                        do{
                            printf("Ingrese la base menor: \n");
                            scanf(" %f", &datos[1]);
                        }while(datos[1]==0 || datos[1]<0);
                        
                        do{
                            printf("Ingrese la altura: \n");
                            scanf(" %f", &datos[2]);
                        }while(datos[2]==0 || datos[2]<0);
                        
                        datos[3] =(((datos[0] + datos[1])*datos[2])/2);
                        printf ("El" ROJO" área"RESET " es de : " ROJO"%.2f\n"RESET, datos[3]);
                        break;

                    case 2:
                        do{
                            printf("Ingrese la base 1: \n");
                            scanf(" %f", &datos[0]); 
                        }while(datos[0]==0 || datos[0]<0);
                        
                        do{
                            printf("Ingrese el lado 1: \n");
                            scanf(" %f", &datos[1]); 
                        }while(datos[1]==0 || datos[1]<0);
                        
                        do{
                            printf("Ingrese la base 2: \n");
                            scanf(" %f", &datos[2]); 
                        }while(datos[2]==0 || datos[2]<0);
                        
                        do{
                            printf("Ingrese el lado 2: \n");
                            scanf(" %f", &datos[3]); 
                        }while(datos[3]==0 || datos[3]<0);

                        if (datos[0]==datos[2]){
                            printf ("Error: Las bases no pueden ser iguales.\n");
                        }else{
                            subcalculo=((datos[0]+datos[1]+datos[2]+datos[3])/2);
                            datos[0]=(((datos[0]+datos[2])/(fabs(datos[0]-datos[2])))*sqrt((subcalculo-datos[0])*(subcalculo-datos[2])*(subcalculo-datos[0]-datos[1])*(subcalculo-datos[0]-datos[3])));
                            printf ("El" ROJO" área"RESET " es de : " ROJO"%.2f\n"RESET, datos[0]);
                        }
                        break;

                    default:
                        printf("Ingrese opciones validas\n");
                        break;
                }
                break;

            case 8:
                printf("Que datos tienes para obtener el calculo?\n");
                printf("1. Base y altura\n");
                printf("2. 2 lados y un ángulo\n");
                printf("3. 2 diagonales y su ángulo\n");
                scanf(" %d", &seleccion_paral);

                switch(seleccion_paral){
                    case 1:
                        do{
                            printf ("\nIngrese la base: \n");
                            scanf (" %f", &datos[0]);
                        }while(datos[0]==0 || datos[0]<0);
                        
                        do{
                            printf ("Ingrese la altura: \n");
                            scanf (" %f", &datos[1]);
                        }while(datos[1]==0 || datos[1]<0);
                        
                        datos[2]=(datos[0]*datos[1]);
                        printf ("El" ROJO" rea"RESET " es de : " ROJO"%.2f\n"RESET, datos[2]);
                        break;

                    case 2:
                        do{
                            printf("Ingrese el lado 1: \n");
                            scanf (" %f", &datos[0]); 
                        }while(datos[0]==0 || datos[0]<0);
                        
                        do{
                            printf("Ingrese el lado 2: \n");
                            scanf (" %f", &datos[1]); 
                        }while(datos[1]==0 || datos[1]<0);
                        
                        printf("Ingrese el angulo interno: \n");
                        scanf(" %f", &degree_1);
                        degree_1=degree_1*(PI / 180.0);
                        datos[2] =(datos[0] * datos[1] * sin(degree_1));
                        printf ("El" ROJO" área"RESET " es de : " ROJO"%.2f\n"RESET, datos[2]);
                        break;

                    case 3:
                        do{
                            printf("Ingrese la diagonal 1: \n");
                            scanf (" %f", &datos[0]); 
                        }while(datos[0]==0 || datos[0]<0);
                        
                        do{
                            printf("Ingrese la diagonal 2: \n");
                            scanf (" %f", &datos[1]); 
                        }while(datos[1]==0 || datos[1]<0);
                        
                        printf("Ingrese el angulo entre estas diagonales: \n");
                        scanf(" %f", &degree_1);
                        degree_1=degree_1*(PI / 180.0);
                        datos[2]=((datos[0]*datos[1]*sin(degree_1))/2);
                        printf ("El" ROJO" área"RESET " es de : " ROJO"%.2f\n"RESET, datos[2]);
                        break;

                    default:
                        printf("Ingrese opciones validas\n");
                        break;
                }
                break;

            case 9:
                printf(AZUL"Gracias por usar nuestro programa, tenga buen dia :)\n"RESET);
                break;
                
            default: 
                printf("\nIngrese un numero valido\n\n");
                break;
        }
    }while(menu_formas!=9);

    return 0;
}

// ==========================================
// 3. CUARTEL DE LA FUNCIÓN MENU (Definición)
// ==========================================
int menu()
{
    int opcion_interna = 0;
    
    printf("*****************************\n" );
    printf(VERDE"*PROGRAMA DE CALCULO DE AREA*\n"RESET);
    printf("* INGRESE SU OPCION:     *\n");
    printf("* 1. TRIáNGULO              *\n");
    printf("* 2. CUADRADO               *\n");
    printf("* 3. RECTANGULO             *\n");
    printf("* 4. CíRCULO                *\n");
    printf("* 5. ELIPSE                 *\n");
    printf("* 6. ROMBO                  *\n");
    printf("* 7. TRAPECIO               *\n");
    printf("* 8. PARALELOGRAMO          *\n");
    printf("* 9. SALIR                  *\n");
    printf("* *\n");
    printf("*****************************\n");

    scanf(" %d", &opcion_interna);
    
    return opcion_interna;
}