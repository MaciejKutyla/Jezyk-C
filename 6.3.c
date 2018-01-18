#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Losowanie_Tablicy(int tablica[10], int rozmiar);
void Wypisanie_Tablicy (int tablica[10], int rozmiar);
double Liczenie_Sredniej(int tablica[10], int rozmiar);
int Sortowanie_Tablicy(int tablica[10], int rozmiar);
double Liczenie_Mediany(int tablica[10], int rozmiar);
int Max_Min_element_Tablicy(int tablica[10], int rozmiar);

int main(void)
{
    int tablica[10];
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
        int x;
        scanf("%d", &x);

        switch (x)
        {
            case 1:
                Losowanie_Tablicy(tablica, rozmiar);
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

int Losowanie_Tablicy(int tablica[10], int rozmiar)
{
    for (int i=0; i<rozmiar; i++)
    {
        tablica[i]=rand()%10;
    }
    return tablica[10];
}

void Wypisanie_Tablicy(int tablica[10], int rozmiar)

{
    Sortowanie_Tablicy(tablica, rozmiar);
    printf("Twoja tablica to: \n");
    for(int i=0; i<rozmiar; i++)
    {
        printf("%d \n", tablica[i]);
    }
}

double Liczenie_Sredniej(int tablica[10], int rozmiar)
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

int Sortowanie_Tablicy(int tablica[10], int rozmiar)
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
    return tablica[10];
}

double Liczenie_Mediany(int tablica[10], int rozmiar)
{
    Sortowanie_Tablicy(tablica, rozmiar);
    double mediana=(tablica[4]+tablica[5])/2;
    printf("Mediana to: %lf \n", mediana);
    return mediana;
}

int Max_Min_element_Tablicy(int tablica[10], int rozmiar)
{
    Sortowanie_Tablicy(tablica, rozmiar);
    int min=tablica[0];
    int max=tablica[9];
    printf("Wartosc min to: %d, a wartosc max to: %d\n", min, max);
}

