#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void  generowanie_liczb(int ilosc, FILE* plik);

int main (int argc, char **argv)
{
    srand(time(NULL));

    if(argc != 3)
    {
        printf("Brak argumentow");
        return 1;
    }
    const int ilosc = *argv[1];
    if (ilosc<1)
    {
        printf("Podano zly rozmiar tablicy");
        return -1;
    }
    const char plik = *argv[2];
    if (plik == NULL)
    {
        printf("Zgubiles plik!");
        return -1;
    }
    FILE *wsk = fopen (plik, "w");
    generowanie_liczb(ilosc, plik);
    fclose(wsk);

    return(0);
}

void generowanie_liczb(int ilosc, FILE* plik)
{
    for (int i=0; i < ilosc; i++)
    {
        fprintf(plik, " %d ", rand()%20);
    }
}

