//Kutyla Maciej AGH Grupa 5 Czwartek 8:00 nr indeksu 297242
// Zajecia 5 zad 1
#include <stdio.h>

int PorownanieDwoch (int godzina1[3], int godzina2[3]);
void KontrolaBledow (int godzina [3]);
int TablicaGodzin (int godzina[3]);

int main (void)
{
    int godzina1[3], godzina2[3];
    TablicaGodzin (godzina1);
    TablicaGodzin (godzina2);

    int x = PorownanieDwoch(godzina1, godzina2);
    switch (x)
    {
        case (0):
            printf("Godziny sa rowne \n");
            break;
        case (1):
            printf ("Pierwsza wpisana godzina jest wieksza\n");
            break;
        case (-1):
            printf ("Druga wpiasana godzina jest wieksza\n");
            break;
    }

    return 0;
}

int TablicaGodzin (int godzina[3])
{
    printf("Wpisz godzine, minute i sekunde\n");
    printf ("godziny = ");
    scanf ("%d", &godzina[0]);
    printf ("minuty = ");
    scanf ("%d", &godzina[1]);
    printf ("sekundy = ");
    scanf ("%d", &godzina[2]);

    while (godzina[0]<0||godzina[0]>24)
    {
        printf ("Zla godzina, wartosc musi zawierac sie miedzy 0 i 24, wpisz jeszcze raz \n");
        scanf ("%d", &godzina[0]);
    }
    while (godzina [1]<0||godzina[1]>60)
    {
        printf ("Zla godzina, wartosc musi zawierac sie miedzy 0 i 60, wpisz jeszcze raz \n");
        scanf ("%d", &godzina[1]);
    }
    while (godzina [2]<0||godzina[2]>60)
    {
        printf ("Zla godzina, wartosc musi zawierac sie miedzy 0 i 60, wpisz jeszcze raz \n");
        scanf ("%d", &godzina[2]);
    }
    return godzina[3];
}


int PorownanieDwoch (int godzina1[3], int godzina2[3])
{
    if (godzina1[0]>godzina2[0])
    {
        if (godzina1[1]>godzina2[1])
        {
            if (godzina1[2]>godzina2[2])
                return 1;
        }
    }
    else if (godzina1[0]==godzina2[0])
    {
        if (godzina1[1]==godzina2[1])
        {
            if (godzina1[2]==godzina2[2])
                return 0;
        }
    }
    else
        return -1;
}
