#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define cantidad 10

int main()
{
    int i, j=1, num;
    char **lista, *buff;
    buff = (char *)malloc(50*sizeof(char));

    printf("Cuantos nombres completos quiere ingresar?: ");
    scanf("%d", &num);
    lista = malloc(num*2*sizeof(char));
    fflush(stdin);

    for(i=0; i<cantidad; i+=2)
    {
        printf("Ingrese el apellido de la persona %d\n", j);
        gets(buff);
        lista[i] = (char *)malloc(strlen(buff)*sizeof(char));
        strcpy(lista[i], buff);
        printf("Ingrese el nombre de la persona %d\n", j);
        gets(buff);
        lista[i+1] = (char *)malloc((strlen(buff)+1)*sizeof(char));
        strcpy(lista[i+1], buff);
        j++;
        printf("\n\n");
    }

    free(buff);
    
    j=1;
    for(i=0; i<cantidad; i+=2)
    {
        printf("*****Persona %d*****\n", j);
        printf("%s, %s\n\n", lista[i], lista[i+1]);
        free(lista[i]);
        free(lista[i+1]);
        j++;
    }

    return 0;
}