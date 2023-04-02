#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define anio 5
#define mes 12

void cargarMatriz(int matriz[anio][mes]);
void mostrarMatriz(int matriz[anio][mes]);
void promedio(int matriz[anio][mes]);
void minimoMaximo(int matriz[anio][mes]);

int main()
{
    int matriz[anio][mes];

    cargarMatriz(matriz);
    mostrarMatriz(matriz);
    promedio(matriz);

    return 0;
}

void cargarMatriz(int matriz[anio][mes])
{
    int i, j;
    srand(time(NULL));

    for(i=0; i<anio; i++)
    {
        for(j=0; j<mes; j++)
        {
            matriz[i][j] = 10000 + rand() % 50000;
        }
    }
}

void mostrarMatriz(int matriz[anio][mes])
{
    int i=0, j;
    
    for(i=0; i<anio; i++)
    {
        for(j=0; j<mes; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void promedio(int matriz[anio][mes])
{
    int i, j, promedio=0;

    printf("\n");
    for (i=0; i<anio; i++)
    {
        for(j=0; j<mes; j++)
        {
            promedio += matriz[i][j];
        }
        promedio /= 12;
        printf("promedio anio %d = %d", i+1, promedio);
        printf("\n");
    }
}

void minimoMaximo(int matriz[anio][mes])
{
    int i, j, mesMinimo, anioMinimo, mesMaximo, anioMaximo;
}