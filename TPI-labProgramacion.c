#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct clientes
{
    int nroCuenta;
    int contra;
    char nombre[60];
    int saldo;
    int estado;
};


void inicializoEstructura(struct clientes clientes[]);
void checkNroCliente(int *nro);


void main()
{
    system("cls");
    int tam = 10, nroClienteIngresado, nroContraIngresado;
    struct clientes clientes[10];
    inicializoEstructura(clientes);
    
    printf("**********BIENVENIDO**********\n\n");
    printf("Por favor, ingrese su numero de cuenta: ");
    scanf("%i", &nroClienteIngresado);
    checkNroCliente(&nroClienteIngresado);

    printf("Ingrese su contraseña: ");
    scanf("%i", &nroContraIngresado);
    while (nroContraIngresado < 1000 || nroContraIngresado > 9999)
    {
        system("cls");
        printf("Contraseña invalida. Intente nuevamente: ");
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


void checkContra()
{

}


void inicializoEstructura(struct clientes clientes[]) // funcion para cargar los datos fuera del main
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
    
    clientes[8].nroCuenta =900;
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