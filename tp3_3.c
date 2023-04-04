#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define cantidad 10

int main()
{
    int i;
    char *lista[], *buff;

    lista = (char *)malloc(100*sizeof(char));

    for(i=0; i<cantidad; i++)
    {
        printf("Ingrese el nombre de la persona %d\n", i+1);
        gets(nuevo);
        nombre = (char *)malloc((strlen(nuevo)+1)*sizeof(char));
        strcpy(nombre[i], nuevo);
        printf("Ingrese el apellido de la persona %d\n", i+1);
        gets(nuevo);
        apellido[i] = (char *)malloc(strlen(nuevo)*sizeof(char));
        strcpy(apellido[i], nuevo);
        printf("\n\n");
    }

    free(nuevo);
    
    for(i=0; i<TAMA; i++)
    {
        printf("*****Persona %d*****\n", i+1);
        printf("%s, %s\n\n", apellido[i], nombre[i]);
        free(nombre[i]);
        free(apellido[i]);
    }

    return 0;
}