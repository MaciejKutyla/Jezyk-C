#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void nowa_tablicaA(int  tablicaA[10]);
void nowa_tablicaB(int tablicaA[10], int *tablicaB[10]);
void sortowanie(int *tablicaB[10]);

void nowa_tablicaA(int tablicaA[10])
{
    for( int i=0; i<10; i++)
    {
        tablicaA[i] = rand()%10;
    }
}

void nowa_tablicaB(int tablicaA[10], int *tablicaB[10])
{
    for (int i=0; i<10; i++)
    {
        tablicaB[i]=&tablicaA[i];
    }
}

void sortowanie(int *tablicaB[10])
{
    for (int i=0; i<10; i++)
    {
        for (int j=0; j<9; j++)
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

int main(void)
{
    int tablicaA[10];
    int *tablicaB[10];
    srand(time(NULL));
    nowa_tablicaA(tablicaA);
    nowa_tablicaB(tablicaA, tablicaB);
    sortowanie(tablicaB);

    printf("Nieposorotwana tablica A: \n");
	for (int i = 0; i<10; i++)
	{
		printf(" %d ", tablicaA[i]);
	}

	printf("\n Posortowana tablica A:\n");

	for (int i = 0; i<10; i++)
	{
		printf(" %d ", *tablicaB[i]);
	}

    return 0;

}
