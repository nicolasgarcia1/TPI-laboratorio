#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// inicializo clase clientes
struct clientes
{
    int nroCuenta;
    int contra;
    char nombre[60];
    int saldo;
    int estado;
};

// inicializo funciones
void inicializoEstructura(struct clientes clientes[10]);
void checkNroCliente(int *nro);
void checkContra(int *nro);
void validarUsuario(int num1, int num2, bool validacion, int identificador);
void funcionCajero(int identificadorClienete);

void main()
{
    system("cls");
    int tam = 10, nroClienteIngresado, nroContraIngresado;
    struct clientes clientes[10];
    system("cls"); // sirve para limpiar la pantalla
    inicializoEstructura(clientes);
    int ClienteIngresado, ContraIngresado;
    bool validacion = false;
    int identificadorCliente = -1, intentos = 3;

    do
    {

        printf("**********BIENVENIDO**********\n\n");
        printf("Por favor, ingrese su numero de cuenta: ");
        scanf("%i", &nroClienteIngresado);
        checkNroCliente(&nroClienteIngresado);
        printf("Ingrese su contraseña: ");
        scanf("%i", &nroContraIngresado);
        checkContra(&nroContraIngresado);

        validarUsuario(nroClienteIngresado, nroContraIngresado, &validacion, &identificadorCliente);

        if (validacion = true)
        {
            funcionCajero (identificadorCliente);
        }
        if (validacion = false)
        {
            intentos = intentos - 1;
            clientes[identificadorCliente].estado = 0;
            printf ("No se permiten más intentos. Su cuenta ha sido bloqueada; comuníquese con la entidad bancaria.");
        }

    } while (intentos > 0);
}

void validarUsuario(int num1, int num2, bool validacion, int identificador)
{
    struct clientes clientes[10];
    for (int i = 0; i < 9; i++)
        {
            if ((num1 = clientes[i].nroCuenta) && (num2 = clientes[i].contra))
            {
                validacion = true;
                identificador = i;
            }
            if (i = 9)
            {
                printf("Número de cuenta o contraseña incorrecta.");
                validacion = false;
            }
        }
}

void checkNroCliente(int *nro)
{
    while (*nro < 100 || *nro > 999)
    {
        system("cls");
        printf("Numero de cuenta invalido. Ingrese nuevamente:");
        scanf("%i", nro);
    }
}

void checkContra(int *nro)

{
    while (*nro < 1000 || *nro > 9999)
    {
        system("cls");
        printf("Contraseña invalida. Intente nuevamente: ");
        scanf("%i", nro);
    }
}

void funcionCajero(identificadorCliente)
{
    struct clientes clientes[10];
    int opc, operaciones = 10;
    int montoMas,montoMenos;
    int nroCuentaMovimiento, movimientoDinero;
    do
    {
        printf("1. Realizar un Depósito.");
        printf("2. Realizar una Extracción.");
        printf("3. Consultar el Saldo de la Cuenta.");
        printf("4. Realizar una Transferencia entre Cuentas.");
        printf("5. Mostrar cantidad de Operaciones Realizadas y Saldo Actual.");
        printf("6. Salir de la Sesión.");
        do
        {
            scanf("%d", opc);
        } while (opc > 6 || opc < 1);

        switch (opc)
        {
        case 1:
            operaciones = operaciones + 1;
            printf ("Ingrese monto del Depósito");
            scanf ("%d", &montoMas);
            clientes[identificadorCliente].saldo = clientes[identificadorCliente].saldo + montoMas ;
            
            break;

        case 2:
            operaciones = operaciones + 1;
            printf ("Ingrese monto del Retiro");
            scanf ("%d", &montoMenos);
            clientes[identificadorCliente].saldo = clientes[identificadorCliente].saldo - montoMenos ;
            break;
        case 3:
            operaciones = operaciones + 1;
            printf ("Su saldo es %d",clientes[identificadorCliente].saldo);
            break;
        case 4:
            operaciones = operaciones + 1;
            printf ("Ingrese el numero de cuenta al que quiere transferir dinero");
            scanf ("%d", &nroCuentaMovimiento);
            printf ("Ingrese el monto a transferirle a la cuenta %d", nroCuentaMovimiento);
            scanf ("%d", &movimientoDinero);
            for (int j = 0; j < 10; j++)
            {
                if (nroCuentaMovimiento = clientes[j].nroCuenta)
                {
                  clientes[identificadorCliente].saldo = clientes[identificadorCliente].saldo - movimientoDinero;
                  clientes[j].saldo = clientes[j].saldo + movimientoDinero;
                }
            }
            
            
            break;
        case 5:
            operaciones = operaciones + 1;
            printf ("La cantidad de operaciones realizadas es de %d",operaciones);
            printf ("Su saldo es %d",clientes[identificadorCliente].saldo);

            break;
        default:
            operaciones = 0;
            break;
        }
    } while (operaciones < 10);
}

void inicializoEstructura(struct clientes clientes[10]) // funcion para cargar los datos fuera del main
{
    clientes[0].nroCuenta = 100;
    clientes[0].contra = 1234;
    strcpy(clientes[0].nombre, "Ariel Ortega");
    clientes[0].saldo = 1000000;
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