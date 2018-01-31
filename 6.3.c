#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROZMIAR 10
int Losowanie_Tablicy(int rozmiar, int tablica[ROZMIAR]);
void Wypisanie_Tablicy (int tablica[ROZMIAR], int rozmiar);
double Liczenie_Sredniej(int tablica[ROZMIAR], int rozmiar);
int Sortowanie_Tablicy(int tablica[ROZMIAR], int rozmiar);
double Liczenie_Mediany(int tablica[ROZMIAR], int rozmiar);
int Max_Min_element_Tablicy(int tablica[ROZMIAR], int rozmiar);

int main(void)
{
    int tablica[ROZMIAR];
    int rozmiar= sizeof(tablica)/4;

    srand(time(NULL));

    printf("***MENU***\n");
    printf("[1]Losowanie tablicy \n");
    printf("[2]Wyswietlenie tablicy \n");
    printf("[3]Liczenie sredniej liczb z tablicy \n");
    printf("[4]Liczenie mediany tablicy \n");
    printf("[5]Max/Min element tablicy \n");
    printf("[6]Wyjdz z programu \n");

    while (1>0)
    {
        int przypadek;
        scanf("%d", &przypadek);

        switch (przypadek)
        {
            case 1:
                Losowanie_Tablicy(rozmiar, tablica);
                printf("Wylosowales tablice. Co chcesz zrobic dalej? \n");
                break;
            case 2:
                Wypisanie_Tablicy(tablica, rozmiar);
                printf("Co chcesz zrobic dalej? \n");
                break;
            case 3:
                Liczenie_Sredniej(tablica, rozmiar);
                printf("Co chcesz zrobic dalej? \n");
                break;
            case 4:
                Liczenie_Mediany(tablica, rozmiar);
                printf("Co chcesz zrobic dalej? \n");
                break;
            case 5:
                Max_Min_element_Tablicy(tablica, rozmiar);
                printf("Co chcesz zrobic dalej? \n");
                break;
            case 6:
                exit(0);
            default:
                printf("Wybrano zly numer!!!\nPodaj go jeszcze raz. \n");
        }
    }

    return 0;
}

int Losowanie_Tablicy(int rozmiar, int tablica[ROZMIAR])
{
    for (int i=0; i<rozmiar; i++)
    {
        tablica[i]=rand()%ROZMIAR;
    }
    return tablica[ROZMIAR];
}

void Wypisanie_Tablicy(int tablica[ROZMIAR], int rozmiar)

{
    Sortowanie_Tablicy(tablica, rozmiar);
    printf("Twoja tablica to: \n");
    for(int i=0; i<rozmiar; i++)
    {
        printf("%d \n", tablica[i]);
    }
}

double Liczenie_Sredniej(int tablica[ROZMIAR], int rozmiar)
{
    double suma=0;
    for(int i=0; i<rozmiar; i++)
    {
        suma+=tablica[i];
    }
    double srednia=suma/rozmiar;
    printf("Srednia liczb to: %lf \n", srednia);
    return srednia;
}

int Sortowanie_Tablicy(int tablica[ROZMIAR], int rozmiar)
{
    for (int i=0; i<(rozmiar +1); i++)
    {
       for (int k=0; k<(rozmiar +1); k++)
       {
           if ( tablica[i]<tablica[k])
           {
				int zamiana=tablica[i];
				tablica[i]=tablica[k];
				tablica[k]=zamiana;
           }
       }
    }
    return tablica[ROZMIAR];
}

double Liczenie_Mediany(int tablica[ROZMIAR], int rozmiar)
{
    Sortowanie_Tablicy(tablica, rozmiar);
    double mediana=(tablica[4]+tablica[5])/2;
    printf("Mediana to: %lf \n", mediana);
    return mediana;
}

int Max_Min_element_Tablicy(int tablica[ROZMIAR], int rozmiar)
{
    Sortowanie_Tablicy(tablica, rozmiar);
    int min=tablica[0];
    int max=tablica[9];
    printf("Wartosc min to: %d, a wartosc max to: %d\n", min, max);
}

