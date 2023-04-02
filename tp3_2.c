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
    int matriz[anio][mes], aux1, aux2;

    cargarMatriz(matriz);
    mostrarMatriz(matriz);
    promedio(matriz);
    minimoMaximo(matriz);

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
    int i, j, mesMinimo = 0, anioMinimo = 0, mesMaximo = 0, anioMaximo = 0, aux1, aux2;
    aux1 = aux2 = matriz[0][0];

    for(i=0; i<anio; i++)
    {
        for(j=0; j<mes; j++)
        {
            if(aux1 > matriz[i][j])
            {
                aux1 = matriz[i][j];
                mesMinimo = j;
                anioMinimo = i;
            }
            if(aux2 < matriz[i][j])
            {
                aux2 = matriz[i][j];
                mesMaximo = j;
                anioMaximo = i;
            }
        }
    }

    printf("\nMaximo y minimo\n");
    printf("Valor minimo = %d / Anio: %d, Mes: %d\n", aux1, anioMinimo+1, mesMinimo+1);
    printf("Valor maximo = %d / Anio: %d, Mes: %d", aux2, anioMaximo+1, mesMaximo+1);
}