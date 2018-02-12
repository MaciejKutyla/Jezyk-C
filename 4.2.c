#include <stdio.h>

int main(void)
{
    int zakresOd = 0;
    int zakresDo = 10;
    int PodanaLiczba;
    printf("Podaj liczbe z zakresu [1, 10]\n");
    scanf("%d", &PodanaLiczba);
    if (PodanaLiczba>10 || PodanaLiczba<1)
    {
        printf("Podales liczbe spoza zakresu. Naprawilismy to! \n");
    }
    PodanaLiczba = zakres (PodanaLiczba, zakresOd, zakresDo);
    zgadywanie_liczby (PodanaLiczba);

    return 0;
}

int zakres (int PodanaLiczba, int zakresOd, int zakresDo)
{
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

void zgadywanie_liczby (int PodanaLiczba)
{
    if (PodanaLiczba>=6)
    {
        if (PodanaLiczba>=8)
        {
            if (PodanaLiczba>=9)
            {
                if (PodanaLiczba==9)
                {
                    printf("Podana liczba to 9\n");
                }
                else printf("Podana liczba to 10\n");
            }
            else printf("Podana liczba to 8\n");
        }
        else if (PodanaLiczba==6)
        {
            printf("Podana liczba to 6\n");
        }
        else printf("Podana liczba to 7\n");
    }
    else if (PodanaLiczba>=3)
    {
        if (PodanaLiczba>=4)
        {
            if (PodanaLiczba==4)
            {
                printf("Podana liczba to 4\n");
            }
            else printf("Podana liczba to 5\n");
        }
        else printf("Podana liczba to 3\n");
    }
    else if (PodanaLiczba==1)
    {
        printf("Podana liczba to 1\n");
    }
    else printf("Podana liczba to 2\n");
}
