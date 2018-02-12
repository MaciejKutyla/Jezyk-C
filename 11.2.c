#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>
#include <stdlib.h>

#define BUFSIZE 1024

void wyswietlanie_tablicy(int rozmiar, int tablica[rozmiar]);
void sortowanie_tablicy(int rozmiar, int tablica[rozmiar]);

void wyswietlanie_tablicy(int rozmiar, int tablica[rozmiar])
{
    for(int i=0; i<rozmiar; i++)
    {
        printf("%d", tablica[i]);
    }
}

void sortowanie_tablicy(int rozmiar, int tablica[rozmiar])
{
    for (int i=0; i<rozmiar; i++)
    {
        for (int j=0; j<(rozmiar-1); j++)
        {
            if(tablica[j]>tablica[j+1])
            {
                int zmiana = tablica[j];
                tablica[j] = tablica[j+1];
                tablica[j+1] = zmiana;
            }
        }
    }
}

int main (int argc, char **argv)
{
    const char* plik = argv[1];
    FILE *f1 = fopen (plik, "r+w");
    if(f1 == NULL)
    {
        int blad = errno;
        printf("Cos poszlo nie tak \n");
        if(blad == EACCES)
        {
            printf("Nie masz dostepu");
            return 1;
        }
    }
    if(argc != 2)
    {
        printf("Nie podano argumentow");
        return 1;
    }
    else
    {
        printf("Swietnie! Podales 2 argumenty \n");
    }

    char bufor[BUFSIZE];
    int tablica[BUFSIZE];
    int rozmiar = 0;
    while(fscanf( f1 , "%s", &bufor) != EOF)
    {
        tablica[rozmiar] = strtol(bufor, NULL, 10);
        rozmiar++;
    }

    sortowanie_tablicy(rozmiar, tablica);
    wyswietlanie_tablicy(rozmiar, tablica);

    fclose(f1);

    return 0;
}
