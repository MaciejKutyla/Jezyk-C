//Kutyla Maciej AGH Grupa 5 Czwartek 8:00 nr indeksu 297242
// Zajecia 4 zad 2
#include <stdio.h>

void zgadywanie_liczby();
int zakres();

int main(void)
{
    int PodanaLiczba, liczba;
    printf("Podaj liczbe z zakresu [1, 10]\n");
    scanf("%d", &PodanaLiczba);
    if (PodanaLiczba>10 || PodanaLiczba<1)
    {
        printf("Podales liczbe spoza zakresu. Naprawilismy to! \n");
    }
    liczba = zakres (PodanaLiczba);
    zgadywanie_liczby (liczba);
    return 0;
}

int zakres (int PodanaLiczba)
{
    int zakresOd = 0;
    int zakresDo = 10;
    if (PodanaLiczba<zakresOd)
    {
        PodanaLiczba=-PodanaLiczba;
    }
    if (PodanaLiczba==zakresOd)
    {
        PodanaLiczba =+ 1;
    }
    if (PodanaLiczba>zakresDo)
    {
        PodanaLiczba=PodanaLiczba % zakresDo+1;
    }

    return PodanaLiczba;
}

void zgadywanie_liczby (int liczba)
{
    if (liczba>=6)
    {
        if (liczba>=8)
        {
            if (liczba>=9)
            {
                if (liczba==9)
                {
                    printf("Podana liczba to 9\n");
                }
                else printf("Podana liczba to 10\n");
            }
            else printf("Podana liczba to 8\n");
        }
        else if (liczba==6)
        {
            printf("Podana liczba to 6\n");
        }
        else printf("Podana liczba to 7\n");
    }
    else if (liczba>=3)
    {
        if (liczba>=4)
        {
            if (liczba==4)
            {
                printf("Podana liczba to 4\n");
            }
            else printf("Podana liczba to 5\n");
        }
        else printf("Podana liczba to 3\n");
    }
    else if (liczba==1)
    {
        printf("Podana liczba to 1\n");
    }
    else printf("Podana liczba to 2\n");
}
