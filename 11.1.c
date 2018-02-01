#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define PLIK "plik.txt"

int generowanie_liczb(int liczby[], int n);
void wypisanie_liczb(int liczby[],int n);

int main(void)
{
    FILE *wsk;
    printf("Podaj ile liczb chcesz wygenerowac:");
    int ilosc;
    scanf("%d", &ilosc);
    int liczby[ilosc];
    srand(time(NULL));
    generowanie_liczb(liczby, ilosc);
    wypisanie_liczb(liczby, ilosc);
    wsk = fopen(PLIK, "w");
    for (int i=0; i<ilosc;i++)
        fprintf(wsk, "%d", liczby[i]);
    fclose(wsk);
    getch();
    return 0;
}

int generowanie_liczb(int liczby[], int n)
{
    for (int i=0; i<n; i++)
    {
        int x=rand()%10;
        liczby[i]=x;
    }
    return liczby[10];
}

void wypisanie_liczb(int liczby[],int n)
{
    printf("Oto twoje liczby: \n");
    for (int i=0; i<n; i++)
    {
        printf("%d  ", liczby[i]);
    }
}
