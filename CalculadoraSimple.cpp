// Calculadora 1.0

#include <conio.h>
#include <stdio.h>
#include <math.h>

//Funciones de las operaciones
double suma(double acumulado, double numero) {
    return acumulado + numero;
}
double resta(double acumulado, double numero) {
    return acumulado - numero;
}
double multiplicacion(double acumulado, double numero) {
    return acumulado * numero;
}
double division(double acumulado, double numero) {
    return acumulado / numero;
}

int main() {
	
/*FUNCIONAMIENTO DE CADA VARIABLE:
	n= es para guardar la cantidad de numeros con los que va a trabajar el usuario
	operacion= es para escoger la operacion con la que va a trabajar el usuario
	numero= guarda los numeros con los que los usuarios van a trabajar las operaciones
	acumulado= va avanzando uno por uno en el programa, sin este el programa solo mostraria el ultimo numero ingresado
	*/
    int n, operacion;
    double numero, acumulado;

    do { //usa un do while para que se repita el proceso de la calculadora las veces que el usuario desee
    
        printf("\n=========== CALCULADORA ===========\n");
        printf("�Bienvenid@! Seleccione la operacion:\n");
        printf("1. Suma\n2. Resta\n3. Multiplicacion\n4. Division\n5. Salir\n");
        scanf("%d", &operacion);

        if (operacion >= 1 && operacion <= 4) { //Uso este if para que se cumpla con las opciones elegidas del menu y no vaya a ser que a un usuario le de el chiste de elegir la opcion 6 que no existe
            printf("\nIngrese la cantidad de numeros: "); //aqui se escoje la cantidad de numeros con los que desea trabajar el usuario
            scanf("%d", &n);

            for (int i = 1; i <= n; i++) { //con este for pido los numeros la cantidad de veces que se pidio anteriormente 
                printf("%d. Ingrese numero: ", i);
                scanf("%lf", &numero);

                if (operacion == 1) { // suma
                    if (i == 1) acumulado = 0;
                    acumulado = suma(acumulado, numero);

                } else if (operacion == 2) { // resta
                    if (i == 1) acumulado = numero;
                    else acumulado = resta(acumulado, numero);

                } else if (operacion == 3) { // multiplicacion
                    if (i == 1) acumulado = 1;
                    acumulado = multiplicacion(acumulado, numero);

                } else if (operacion == 4) { // division
                    if (i == 1) acumulado = numero;
                    else {
                        if (numero != 0)
                            acumulado = division(acumulado, numero);
                        else {
                            printf("Error: Como va a dividir entre cero, no sea bruto\n");//no falta el chistoso que divida entre cero
                            acumulado = 0;
                            break;
                        }
                    }
                }
            }

            // Resultado
            if (operacion == 1) printf("\nLa suma es: %.2lf\n", acumulado);
            if (operacion == 2) printf("\nLa resta es: %.2lf\n", acumulado);
            if (operacion == 3) printf("\nLa multiplicacion es: %.2lf\n", acumulado);
            if (operacion == 4) printf("\nLa division es: %.2lf\n", acumulado);

        } else if (operacion == 5) {
            printf("\nSaliendo de la calculadora...\n Nos vemos despues, chiquita ;)\n");
        } else {
            printf("\nOpcion incorrecta. Intenta de nuevo.\n");
        }

    } while (operacion != 5);/*Todas las operaciones se resuelven mientras que se cumpla que el usuario
	no escoja la opcion 5 que como sabemos es para salir de la calculadora*/

    getch();
    return 0;
}

