//Kutyla Maciej AGH Grupa 5 Czwartek 8:00 nr indeksu 297242
// Zajecia 5 zad 2
#include <stdio.h>
#include <stdlib.h>

int liczeniewyznacznika(int macierz[3][3]);
void LosowanieMacierzy(int macierz [3][3]);
void WyswietlanieMacierzy(int macierz[3][3]);

int main(void)
{
    srand(time(NULL));
    int macierz[3][3];
    LosowanieMacierzy(macierz);
    WyswietlanieMacierzy(macierz);
    liczeniewyznacznika(macierz);

    return 0;
}

void LosowanieMacierzy(int macierz [3][3])
{
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            int x=rand()%2+1;
            macierz[i][j]=x;
        }
    }
}
void WyswietlanieMacierzy(int macierz[3][3])
{
    printf("Losowa macierz to: \n");
    for (int k=0; k<3; k++)
    {
        for (int l=0;l<3; l++)
        {
            printf(" %d ", macierz[k][l]);
        }
        printf("\n");
    }
}

int liczeniewyznacznika(int macierz[3][3])
{
    int wyznacznik = macierz[0][0]*macierz[1][1]*macierz[2][2]+macierz[1][0]*macierz[2][1]*macierz[0][2]+macierz[0][1]*macierz[1][2]*macierz[2][0]-macierz[0][2]*macierz[1][1]*macierz[2][0]-macierz[2][1]*macierz[1][2]*macierz[0][0]-macierz[1][0]*macierz[0][1]*macierz[2][2];
    printf("Wyzncznik macierzy to: %d", wyznacznik);
    return wyznacznik;
}

