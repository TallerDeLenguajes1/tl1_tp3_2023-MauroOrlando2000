#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char *TiposProductos[]={"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};

struct Producto {
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
} typedef Producto;

struct Cliente {
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos; //El tamaño de este arreglo depende de la variable
    // “CantidadProductosAPedir”
} typedef Cliente;

void mostrarProductos(Cliente Cliente[], int num);
float costoTotal(float precio, int cantidad);

int main()
{
    Cliente *persona;
    int num, i, j, aux;
    char auxChar[50];
    srand(time(NULL));

    printf("Cuantos clientes hay?: ");
    scanf("%d", &num);
    persona = malloc(num*sizeof(Cliente));
    fflush(stdin);
    
    for(i=0; i<num; i++)
    {
        persona[i].ClienteID = i+1;
        printf("Ingrese el nombre del cliente %d\n", persona[i].ClienteID);
        gets(auxChar);
        persona[i].NombreCliente = (char *)malloc((strlen(auxChar)+1)*sizeof(char));
        strcpy(persona[i].NombreCliente, auxChar);
        persona[i].CantidadProductosAPedir = 1 + rand() % 5;
        persona[i].Productos = malloc(persona[i].CantidadProductosAPedir);
        for(j=0; j<persona[i].CantidadProductosAPedir; j++)
        {
            persona[i].Productos[j].ProductoID = j+1;
            persona[i].Productos[j].Cantidad = 1 + rand() % 10;
            aux = 1 + rand() % 5;
            persona[i].Productos[j].TipoProducto = (char *)malloc((strlen(TiposProductos[aux])+1)*sizeof(char));
            persona[i].Productos[j].TipoProducto = TiposProductos[aux];
            persona[i].Productos[j].PrecioUnitario = 10 + rand() % 90;
        }
    }

    mostrarProductos(persona, num);
    free(persona);

    return 0;
}

void mostrarProductos(Cliente Cliente[], int num)
{
    int i, j;
    float aux1, aux2;
    for(i=0; i<num; i++)
    {
    	aux1 = aux2 = 0;
        printf("\nCliente %d\n", Cliente[i].ClienteID);
        printf("%s\n", Cliente[i].NombreCliente);
        for(j=0; j<Cliente[i].CantidadProductosAPedir; j++)
        {
            printf("Producto %d\n", Cliente[i].Productos[j].ProductoID);
            printf("%d %s - $%f c/u\n", Cliente[i].Productos[j].Cantidad, Cliente[i].Productos[j].TipoProducto, Cliente[i].Productos[j].PrecioUnitario);
            aux2 += aux1 = costoTotal(Cliente[i].Productos[j].PrecioUnitario, Cliente[i].Productos[j].Cantidad);
            printf("Costo total del producto= %f\n\n", aux1);
        }
        printf("Costo total del cliente= %f\n\n\n", aux2);
    }
}

float costoTotal(float precio, int cantidad)
{
    return precio * cantidad;
}
