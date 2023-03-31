#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define anio 5
#define mes 12

//void cargarMatriz(int matriz[anio][mes]);

int main()
{
    int matriz[anio][mes], i, j;

    for(i=0; i<anio; i++)
    {
        for(j=0; j<mes; j++)
        {
            matriz[i][j] = 10000 + rand() % 50000;
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}

/*void cargarMatriz(int matriz[anio][mes])
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
}*/