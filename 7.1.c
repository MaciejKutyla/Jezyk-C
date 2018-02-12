#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double liczenie_sredniej(int *poczatek, int *koniec);
int losowanie_tablicy(int rozmiar, int tablica[rozmiar]);
void wypisanie_tablicy(int rozmiar, int tablica[rozmiar]);

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
    int tablica[rozmiar];

    losowanie_tablicy(rozmiar, tablica);
    wypisanie_tablicy(rozmiar, tablica);

    int *poczatek = &tablica;
    int *koniec = &tablica[rozmiar];
    double srednia_wazona = liczenie_sredniej(poczatek, koniec);
    printf("Srednia wazona: %g\n", srednia_wazona);

    return 0;
}

double liczenie_sredniej(int *poczatek, int *koniec)
{
    double srednia = 0.0;
    double suma_liczb = 0.0;
    double suma_wag = 0.0;
    int i = 0;
    while (poczatek+i != koniec)
    {
        suma_liczb += *(poczatek+i)*(i+1);
        suma_wag +=(i+1);
        i++;
    }
    srednia = suma_liczb/suma_wag;
    return srednia;
}

int losowanie_tablicy(int rozmiar, int tablica[rozmiar])
{
    for (int i=0; i<rozmiar; i++)
    {
        tablica[i]=rand()%10;
    }
    return tablica[rozmiar];
}

void wypisanie_tablicy(int rozmiar, int tablica[rozmiar])
{
    printf("Twoja tablica to: \n");
    for(int i=0; i<rozmiar; i++)
    {
        printf("%d  ", tablica[i]);
    }
    printf("\n");
}
