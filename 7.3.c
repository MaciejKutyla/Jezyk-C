#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void nowa_tablicaA(int rozmiar, int tablicaA[rozmiar]);
void nowa_tablicaB(int rozmiar, int tablicaA[rozmiar], int *tablicaB[rozmiar]);
void sortowanie(int rozmiar, int *tablicaB[rozmiar]);

int main(void)
{
    srand(time(NULL));

    printf("Podaj rozmiar tablicy:  ");
    int rozmiar;
    scanf("%d", &rozmiar);
    while (rozmiar<1)
    {
        printf("Podales za maly rozmiar, zrob to jeszcze raz!\n");
        scanf("%d", &rozmiar);
    }
    int tablicaA[rozmiar];
    int *tablicaB[rozmiar];

    nowa_tablicaA(rozmiar, tablicaA);
    nowa_tablicaB(rozmiar, tablicaA, tablicaB);
    sortowanie(rozmiar, tablicaB);

    printf("Nieposorotwana tablica A: \n");
	for (int i = 0; i<rozmiar; i++)
	{
		printf(" %d ", tablicaA[i]);
	}

	printf("\nPosortowana tablica A:\n");
	for (int i = 0; i<rozmiar; i++)
	{
		printf(" %d ", *tablicaB[i]);
	}

    return 0;
}

void nowa_tablicaA(int rozmiar, int tablicaA[rozmiar])
{
    for( int i=0; i<rozmiar; i++)
    {
        tablicaA[i] = rand()%10;
    }
}

void nowa_tablicaB(int rozmiar, int tablicaA[rozmiar], int *tablicaB[rozmiar])
{
    for (int i=0; i<rozmiar; i++)
    {
        tablicaB[i]=&tablicaA[i];
    }
}

void sortowanie(int rozmiar, int *tablicaB[rozmiar])
{
    for (int i=0; i<rozmiar; i++)
    {
        for (int j=0; j<(rozmiar-1); j++)
        {
            if(*tablicaB[j]>*tablicaB[j+1])
            {
                int *zmiana = tablicaB[j];
                tablicaB[j] = tablicaB[j+1];
                tablicaB[j+1] = zmiana;
            }
        }
    }
}
