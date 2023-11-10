/*
integrantes del grupo: 
Facundo Solari
Nicolas Garcia
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> // incluye booleanos en c
#include <windows.h> // incluye Sleep

// inicializo clase clientes
struct clientes
{
    int nroCuenta;
    int contra;
    char nombre[60];
    float saldo;
    int estado;
};

// inicializo funciones
void inicializoEstructura(struct clientes clientes[]);
void escribirLineas();
int checkNroCliente(int *nro, struct clientes clientes[]);
void checkContra(int *nro, struct clientes clientes[], int identificadorCliente, int *intentos, bool *chequeoIngreso);
int checkMonto(float *nro, struct clientes clientes[], int identificadorCliente);
void funcionCajero(int identificadorClienete, struct clientes clientes[]);

void main()
{
    
    struct clientes clientes[10];
    inicializoEstructura(clientes);
    int nroClienteIngresado, nroContraIngresado, identificadorCliente;
    int repetir = 1;
    bool validacion = false, chequeoIngreso;

    do
    {
        int intentos = 3;

        // sirve para limpiar la pantalla
        system("cls"); 

        printf("**************** BIENVENIDO ****************\n");
        escribirLineas();
        printf("Ingrese su numero de cuenta: ");
        scanf("%i", &nroClienteIngresado);
        identificadorCliente = checkNroCliente(&nroClienteIngresado, clientes);
        
        escribirLineas();
        printf("Numero de cuenta: %i\n\n", clientes[identificadorCliente].nroCuenta);
        printf("Ingrese su contraseña: ");
        scanf("%i", &nroContraIngresado);
        checkContra(&nroContraIngresado, clientes, identificadorCliente, &intentos, &chequeoIngreso);

        funcionCajero(identificadorCliente, clientes);
    }
    while (repetir = 1);
}

int checkNroCliente(int *nro, struct clientes clientes[])
{
    system("cls");

    int identificador, i = 0;
    bool encontrado;
    encontrado = false;

    while (*nro < 100 || *nro > 999)
    {
        system("cls");
        escribirLineas();
        printf("Numero de cuenta invalido. Ingrese nuevamente:");
        scanf("%i", nro);
    }

    while (i < 9 && !encontrado)
    {
        if (clientes[i].nroCuenta == *nro)
        {
            encontrado = true;
            identificador = i;
        }
        else 
        {
            i++;
        }
    }

    if (!encontrado)
    {
        system("cls");
        escribirLineas();
        printf("Numero de cuenta no encontrado. Intente nuevamente: ");
        scanf("%i", nro);
        identificador = checkNroCliente(nro, clientes);
    }
    else 
    {
        return identificador;
    }
}


void checkContra(int *nro, struct clientes clientes[], int identificadorCliente, int *intentos, bool *chequeoIngreso)
{
    *chequeoIngreso = false;

    while (*nro < 1000 || *nro > 9999)
    {
        system("cls");
        escribirLineas();
        printf("Numero de cuenta: %i\n\n", clientes[identificadorCliente].nroCuenta);
        printf("Contraseña invalida. Intente nuevamente: ");
        scanf("%i", nro);
    }

    if (clientes[identificadorCliente].contra == *nro && *intentos >= 0)
    {
        *chequeoIngreso = true;
    }
    else if (clientes[identificadorCliente].contra != *nro && *intentos > 1)
    {
        system("cls");
        (*intentos)--;
        escribirLineas();
        printf("Numero de cuenta: %i\n\n", clientes[identificadorCliente].nroCuenta);
        printf("Contraseña incorrecta. Intentos restantes: %i\n", *intentos);
        printf("Ingrese nuevamente la contraseña: ");
        scanf("%i", nro);
        checkContra(nro, clientes, identificadorCliente, intentos, chequeoIngreso);
    }
    else 
    {
        clientes[identificadorCliente].estado = 0;
        system("cls");
        escribirLineas();
        printf("Su cuenta está bloqueada, comuníquese con la entidad bancaria.\n\n");
        system("pause");
    }
}


int checkMonto(float *nro, struct clientes clientes[], int identificadorCliente)
{
    while (*nro < 0)
    {
        printf("Ingrese un monto valido: $");
        scanf("%f", nro);
    }

    while (*nro > clientes[identificadorCliente].saldo)
    {
        printf("Saldo insuficiente.");
        printf("Ingrese un monto valido: $");
        scanf("%f", nro);
    }
}


void funcionCajero(int identificadorCliente, struct clientes clientes[])
{
    int opc, operaciones = 0;
    float montoDeposito, montoRetiro;
    int nroCuentaMovimiento, movimientoDinero;
    int identificadorTransferencia;

    do
    {
        bool encontrado = false;
        int j = 0;

        system("cls");
        escribirLineas();
        printf("1. Realizar un Deposito.\n");
        printf("2. Realizar una Extraccion.\n");
        printf("3. Consultar el Saldo de la Cuenta.\n");
        printf("4. Realizar una Transferencia entre Cuentas.\n");
        printf("5. Mostrar cantidad de Operaciones Realizadas y Saldo Actual.\n");
        printf("6. Salir de la Sesion.\n");
        escribirLineas();
        printf("Seleccione una opcion: ");
        scanf("%i", &opc);

        while(opc < 1 || opc > 6)
        {
            printf("\nERROR. Ingrese una opcion valida: ");
            scanf("%i", &opc);
        }

        system("cls");

        switch (opc)
        {
        case 1:
            if (operaciones == 10)
            {
                escribirLineas();
                printf("Ha alcanzado el limite de operaciones. Gracias.");
                Sleep(2250); // espera 2.25 segundos y sale (2250 ms)
            }
            else
            {      
                operaciones++;
                escribirLineas();
                printf("Ingrese monto del Depósito: $");
                scanf("%f", &montoDeposito);
                clientes[identificadorCliente].saldo += montoDeposito;

                system("cls");
                escribirLineas();
                printf("Saldo actual: $%.2f\n\n", clientes[identificadorCliente].saldo);
                Sleep(2250);
            }

            break;

        case 2:
            if (operaciones == 10)
            {
                escribirLineas();
                printf("Ha alcanzado el limite de operaciones. Gracias.");
                Sleep(2250);
            }
            else
            {
                operaciones++;
                escribirLineas();
                printf("Ingrese monto del Retiro: $");
                scanf("%f", &montoRetiro);
                clientes[identificadorCliente].saldo = clientes[identificadorCliente].saldo - montoRetiro;

                system("cls");
                escribirLineas();
                printf("Saldo actual: $%.2f", clientes[identificadorCliente].saldo);
                Sleep(2250);
            }

            break;

        case 3:
            if (operaciones == 10)
            {
                escribirLineas();
                printf("Ha alcanzado el limite de operaciones. Gracias.");
                Sleep(2250);
            }
            else
            {
                operaciones++;
                escribirLineas();
                printf("Su saldo es: $%.2f\n\n", clientes[identificadorCliente].saldo);
                system("pause");
            }

            break;

        case 4:
            if (operaciones == 10)
            {
                escribirLineas();
                printf("Ha alcanzado el limite de operaciones. Gracias.");
                Sleep(2250);
            }
            else
            {
                operaciones++;
                escribirLineas();
                printf("Saldo disponible: %d\n", clientes[identificadorCliente].saldo);
                escribirLineas();
                printf("Numero de cuenta a transferir: ");
                scanf("%d", &nroCuentaMovimiento);
                identificadorTransferencia = checkNroCliente(&nroCuentaMovimiento, clientes);

                printf("\nIngrese el monto a transferir: $");
                scanf("%f", &movimientoDinero);
                checkMonto(&movimientoDinero, clientes, identificadorCliente);

                clientes[identificadorCliente].saldo = clientes[identificadorCliente].saldo - movimientoDinero;
                clientes[identificadorTransferencia].saldo = clientes[identificadorTransferencia].saldo + movimientoDinero;


            }

            break;

        case 5:
            if (operaciones == 10)
            {
                escribirLineas();
                printf("Ha alcanzado el limite de operaciones. Gracias.");
                Sleep(2250);
            }
            else
            {
                operaciones++;
                escribirLineas();
                printf("Cantidad de operaciones realizadas: %d\n\n", operaciones);
                system("pause");
            }

            break;

        case 6:
            escribirLineas();
            printf("Gracias por elegirnos. Hasta la proxima.");
            Sleep(2250);

            break;

        }
    } while (opc != 6);
}


void escribirLineas()
{
    printf("---------------------------------------------\n");
}


void inicializoEstructura(struct clientes clientes[]) // funcion para cargar los datos fuera del main
{
    clientes[0].nroCuenta = 100;
    clientes[0].contra = 1234;
    strcpy(clientes[0].nombre, "Ariel Ortega");
    clientes[0].saldo = 50000;
    clientes[0].estado = 1;

    clientes[1].nroCuenta = 200;
    clientes[1].contra = 2345;
    strcpy(clientes[1].nombre, "Luis Miguel Rodriguez");
    clientes[1].saldo = 0;
    clientes[1].estado = 1;

    clientes[2].nroCuenta = 300;
    clientes[2].contra = 3456;
    strcpy(clientes[2].nombre, "Julio Grondona");
    clientes[2].saldo = 5000000;
    clientes[2].estado = 0;

    clientes[3].nroCuenta = 400;
    clientes[3].contra = 4567;
    strcpy(clientes[3].nombre, "Gonzalo Montiel");
    clientes[3].saldo = 400000;
    clientes[3].estado = 1;

    clientes[4].nroCuenta = 500;
    clientes[4].contra = 5678;
    strcpy(clientes[4].nombre, "Matias Coccaro");
    clientes[4].saldo = 500;
    clientes[4].estado = 1;

    clientes[5].nroCuenta = 600;
    clientes[5].contra = 6789;
    strcpy(clientes[5].nombre, "Juan Roman Riquelme");
    clientes[5].saldo = 700000;
    clientes[5].estado = 1;

    clientes[6].nroCuenta = 700;
    clientes[6].contra = 7890;
    strcpy(clientes[6].nombre, "Lisandro Martinez");
    clientes[6].saldo = 181222;
    clientes[6].estado = 1;

    clientes[7].nroCuenta = 800;
    clientes[7].contra = 8901;
    strcpy(clientes[7].nombre, "Ramon Abila");
    clientes[7].saldo = 10;
    clientes[7].estado = 1;

    clientes[8].nroCuenta = 900;
    clientes[8].contra = 9012;
    strcpy(clientes[8].nombre, "Sebastian Villa");
    clientes[8].saldo = 450000;
    clientes[8].estado = 0;

    clientes[9].nroCuenta = 111;
    clientes[9].contra = 2222;
    strcpy(clientes[9].nombre, "Mauro Lombardo");
    clientes[9].saldo = 50000000;
    clientes[9].estado = 1;
}