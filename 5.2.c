#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int LiczenieWyznacznika(int wiersze, int kolumny, int macierz[wiersze][kolumny]);
void LosowanieMacierzy(int wiersze, int kolumny, int macierz[wiersze][kolumny]);
void WyswietlanieMacierzy(int wiersze, int kolumny, int macierz[wiersze][kolumny]);

int main(void)
{
    srand(time(NULL));
    int wiersze = 3;
    int kolumny = 3;
    int macierz[wiersze][kolumny];
    LosowanieMacierzy(wiersze, kolumny, macierz);
    WyswietlanieMacierzy(wiersze, kolumny, macierz);
    LiczenieWyznacznika(wiersze, kolumny, macierz);

    return 0;
}

void LosowanieMacierzy(int wiersze, int kolumny, int macierz[wiersze][kolumny])
{
    for (int i=0; i<kolumny; i++)
    {
        for (int j=0; j<wiersze; j++)
        {
            int x=rand()%11;
            macierz[i][j]=x;
        }
    }
}

void WyswietlanieMacierzy(int wiersze, int kolumny, int macierz[wiersze][kolumny])
{
    printf("Losowa macierz to: \n");
    for (int k=0; k<kolumny; k++)
    {
        for (int l=0;l<wiersze; l++)
        {
            printf(" %d ", macierz[k][l]);
        }
        printf("\n");
    }
}

int LiczenieWyznacznika(int wiersze, int kolumny, int macierz[wiersze][kolumny])
{
    int wyznacznik = macierz[0][0]*macierz[1][1]*macierz[2][2]+macierz[1][0]*macierz[2][1]*macierz[0][2]+macierz[0][1]*macierz[1][2]*macierz[2][0]-macierz[0][2]*macierz[1][1]*macierz[2][0]-macierz[2][1]*macierz[1][2]*macierz[0][0]-macierz[1][0]*macierz[0][1]*macierz[2][2];
    printf("Wyzncznik macierzy to: %d", wyznacznik);
    return wyznacznik;
}

