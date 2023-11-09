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
int validarUsuario(int nroClienteIngresado, int nroContraIngresado, int valido, int identificadorCliente, struct clientes clientes[10]);
void funcionCajero(int identificadorClienete, struct clientes clientes[10]);

void main()
{
    //system("cls");
    int tam = 10, nroClienteIngresado, nroContraIngresado;
    struct clientes clientes[10];
    //system("cls"); // sirve para limpiar la pantalla
    inicializoEstructura(clientes);
    int ClienteIngresado, ContraIngresado;
    bool validacion = false;
    int identificadorCliente, intentos = 3;
    int valido = -1;

    do
    {

        printf("**********BIENVENIDO**********\n\n");
        printf("Por favor, ingrese su numero de cuenta: ");
        scanf("%i", &nroClienteIngresado);
        checkNroCliente(&nroClienteIngresado);
        printf("Ingrese su contraseña: ");
        scanf("%i", &nroContraIngresado);
        checkContra(&nroContraIngresado);
        valido = validarUsuario(nroClienteIngresado,nroContraIngresado,valido,identificadorCliente,clientes);
        if (valido > -1)
        {
          identificadorCliente = valido;
          funcionCajero(identificadorCliente,clientes);
          intentos = 0;
        }
        if (valido == -1)
        {
            printf ("NO es valido\n");
        }
    } while (intentos > 0);
}

int validarUsuario(int nroClienteIngresado, int nroContraIngresado, int valido, int identificadorCliente, struct clientes clientes[10])
{
    int aux1, aux2;
    for (int i = 0; i < 10; i++)
        {
            aux1 = clientes[i].nroCuenta;
            aux2 = clientes[i].contra;
            
            if (nroClienteIngresado == aux1 && nroContraIngresado == aux2)
            {
                valido = i;
            }
        }
        return valido;
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

void funcionCajero(int identificadorCliente, struct clientes clientes[10])
{
    int opc, operaciones = 0;
    int montoMas,montoMenos;
    int nroCuentaMovimiento, movimientoDinero;
    int aux1, aux2;
    do
    {
        printf("1. Realizar un Deposito.\n");
        printf("2. Realizar una Extraccion.\n");
        printf("3. Consultar el Saldo de la Cuenta.\n");
        printf("4. Realizar una Transferencia entre Cuentas.\n");
        printf("5. Mostrar cantidad de Operaciones Realizadas y Saldo Actual.\n");
        printf("6. Salir de la Sesion.\n");
        do
        {
            scanf("%d", &opc);
        } while (opc > 6 || opc < 1);

        switch (opc)
        {
        case 1:
            operaciones = operaciones + 1;
            printf ("Ingrese monto del Depósito\n");
            scanf ("%d", &montoMas);
            clientes[identificadorCliente].saldo = clientes[identificadorCliente].saldo + montoMas ;
            printf ("El saldo del cliente en valor identificadorCliente es : %d\n",clientes[identificadorCliente].saldo);
            printf ("%d\n");
            break;

        case 2:
            operaciones = operaciones + 1;
            printf ("Ingrese monto del Retiro\n");
            scanf ("%d", &montoMenos);
            clientes[identificadorCliente].saldo = clientes[identificadorCliente].saldo - montoMenos ;
            printf ("El saldo del cliente en valor identificadorCliente es : %d\n",clientes[identificadorCliente].saldo);
            break;
        case 3:
            operaciones = operaciones + 1;
            printf ("Su saldo es %d",clientes[identificadorCliente].saldo);
            break;
        case 4:
        printf ("Saldo del cliente en 1 antes de la transferencia es : %d\n",clientes[1].saldo);
            operaciones = operaciones + 1;
            printf ("Ingrese el numero de cuenta al que quiere transferir dinero\n");
            scanf ("%d", &nroCuentaMovimiento);
            printf ("Ingrese el monto a transferirle a la cuenta %d\n", nroCuentaMovimiento);
            scanf ("%d", &movimientoDinero);
            for (int j = 0; j < 10; j++)
            {
                if (nroCuentaMovimiento == clientes[j].nroCuenta)
                {
                  clientes[identificadorCliente].saldo = clientes[identificadorCliente].saldo - movimientoDinero;
                  clientes[j].saldo = clientes[j].saldo + movimientoDinero;
                 printf ("El saldo nuevo del cliente en valor identificadorCliente es : %d\n",clientes[identificadorCliente].saldo);
                 printf ("El saldo nuevo del cliente al que le transferimos es %d\n",clientes[j].saldo);
                }
            }
           
            printf ("Saldo del cliente en 1 despues de la transferencia es : %d\n",clientes[1].saldo);
            
            break;
        case 5:
            operaciones = operaciones + 1;
            printf ("La cantidad de operaciones realizadas es de %d",operaciones);
            printf ("Su saldo es %d",clientes[identificadorCliente].saldo);

            break;
        case 6:
            operaciones = 10;
            break;
        }
    } while (operaciones < 1);
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