#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Losowanie_Tablicy(int rozmiar_tablicy, int tablica[rozmiar_tablicy]);
void Wypisanie_Tablicy (int rozmiar_tablicy, int tablica[rozmiar_tablicy]);
double Liczenie_Sredniej(int rozmiar_tablicy, int tablica[rozmiar_tablicy]);
int Sortowanie_Tablicy(int rozmiar_tablicy, int tablica[rozmiar_tablicy]);
double Liczenie_Mediany(int rozmiar_tablicy, int tablica[rozmiar_tablicy]);
int Max_Min_element_Tablicy(int rozmiar_tablicy, int tablica[rozmiar_tablicy]);

int main(void)
{
    int rozmiar_tablicy;
    printf("Podaj na ilu elementowej tablicy chcesz operowac:\n");
    scanf("%d", &rozmiar_tablicy);
    while (rozmiar_tablicy<1)
    {
        printf("Podano zly rozmiar tablicy. Podaj go jeszcze raz: \n");
        scanf("%d", &rozmiar_tablicy);
    }
    int tablica[rozmiar_tablicy];

    srand(time(NULL));

    printf("***MENU***\n");
    printf("[1]Losowanie tablicy \n");
    printf("[2]Wyswietlenie tablicy \n");
    printf("[3]Liczenie sredniej liczb z tablicy \n");
    printf("[4]Liczenie mediany tablicy \n");
    printf("[5]Max/Min element tablicy \n");
    printf("[6]Wyjdz z programu \n");

    while (1)
    {
        int przypadek;
        scanf("%d", &przypadek);

        switch (przypadek)
        {
            case 1:
                Losowanie_Tablicy(rozmiar_tablicy, tablica);
                printf("Wylosowales tablice. Co chcesz zrobic dalej? \n");
                break;
            case 2:
                Wypisanie_Tablicy(rozmiar_tablicy, tablica);
                printf("Co chcesz zrobic dalej? \n");
                break;
            case 3:
                Liczenie_Sredniej(rozmiar_tablicy, tablica);
                printf("Co chcesz zrobic dalej? \n");
                break;
            case 4:
                Liczenie_Mediany(rozmiar_tablicy, tablica);
                printf("Co chcesz zrobic dalej? \n");
                break;
            case 5:
                Max_Min_element_Tablicy(rozmiar_tablicy, tablica);
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

int Losowanie_Tablicy(int rozmiar_tablicy, int tablica[rozmiar_tablicy])
{
    for (int i=0; i<rozmiar_tablicy; i++)
    {
        tablica[i]=rand()%rozmiar_tablicy;
    }
    return tablica[rozmiar_tablicy];
}

void Wypisanie_Tablicy(int rozmiar_tablicy, int tablica[rozmiar_tablicy])
{
    Sortowanie_Tablicy(rozmiar_tablicy, tablica);
    printf("Twoja tablica to: \n");
    for(int i=0; i<rozmiar_tablicy; i++)
    {
        printf("%d \n", tablica[i]);
    }
}

double Liczenie_Sredniej(int rozmiar_tablicy, int tablica[rozmiar_tablicy])
{
    double suma=0;
    for(int i=0; i<rozmiar_tablicy; i++)
    {
        suma+=tablica[i];
    }
    double srednia=suma/rozmiar_tablicy;
    printf("Srednia liczb to: %lf \n", srednia);
    return srednia;
}

int Sortowanie_Tablicy(int rozmiar_tablicy, int tablica[rozmiar_tablicy])
{
    for (int i=0; i<(rozmiar_tablicy +1); i++)
    {
       for (int k=0; k<(rozmiar_tablicy +1); k++)
       {
           if ( tablica[i]<tablica[k])
           {
				int zamiana=tablica[i];
				tablica[i]=tablica[k];
				tablica[k]=zamiana;
           }
       }
    }
    return tablica[rozmiar_tablicy];
}

double Liczenie_Mediany(int rozmiar_tablicy, int tablica[rozmiar_tablicy])
{
    Sortowanie_Tablicy(rozmiar_tablicy, tablica);
    double mediana;
    if (rozmiar_tablicy%2==0)
    {
        mediana = (tablica[rozmiar_tablicy/2]+tablica[rozmiar_tablicy/2-1]);
        mediana = mediana/2;
    }
    else
    {
        mediana = (tablica[(rozmiar_tablicy-1)/2]);
    }
    printf("Mediana to: %lf \n", mediana);
    return mediana;
}

int Max_Min_element_Tablicy(int rozmiar_tablicy, int tablica[rozmiar_tablicy])
{
    Sortowanie_Tablicy(rozmiar_tablicy, tablica);
    int min=tablica[0];
    int max=tablica[(rozmiar_tablicy-1)];
    printf("Wartosc min to: %d, a wartosc max to: %d\n", min, max);
}

