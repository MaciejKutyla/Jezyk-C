#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void TworzenieMacierzy(int wiersze, int kolumny, int macierz[wiersze][kolumny]);
void WypisanieMacierzy (int wiersze, int kolumny, int macierz[wiersze][kolumny]);
int ZamianaNaMacierz222 (int wiersze, int kolumny, int trzeci_wymiar, int macierz[wiersze][kolumny][trzeci_wymiar], int macierz1[wiersze][kolumny], int macierz2[wiersze][kolumny]);
void WypisanieMacierzy222 (int wiersze, int kolumny, int trzeci_wymiar, int macierz [wiersze][kolumny][trzeci_wymiar]);
int Macierz222NaDwie22 (int wiersze, int kolumny, int trzeci_wymiar, int macierz [wiersze][kolumny][kolumny], int macierz1[wiersze][kolumny], int macierz2[wiersze][kolumny]);
void MnozenieDwochMacierzy (int wiersze, int kolumny, int trzeci_wymiar, int macierz[wiersze][kolumny][trzeci_wymiar]);

int main (void)
{
    int wiersze = 2;
    int kolumny = 2;
    int trzeci_wymiar = 2;
    int macierz1[2][2], macierz2[2][2], macierz[2][2][2], macierzPomnozona[2][2];
    srand(time(NULL));
    TworzenieMacierzy (wiersze, kolumny, macierz1);
    TworzenieMacierzy (wiersze, kolumny, macierz2);
    ZamianaNaMacierz222(wiersze, kolumny, trzeci_wymiar, macierz, macierz1, macierz2);
    WypisanieMacierzy222(wiersze, kolumny, trzeci_wymiar, macierz);
    MnozenieDwochMacierzy(wiersze, kolumny, trzeci_wymiar, macierz);

    return 0;
}

void TworzenieMacierzy(int wiersze, int kolumny, int macierz[wiersze][kolumny])
{
    for (int i=0; i<wiersze; i++)
    {
        for (int j=0;j<kolumny; j++)
        {
            macierz[i][j]=rand()%200 -100;
        }
    }
}

void WypisanieMacierzy (int wiersze, int kolumny, int macierz[wiersze][kolumny])
{
    for (int k=0; k<wiersze; k++)
    {
        for (int l=0;l<kolumny; l++)
        {
            printf(" %d ", macierz[k][l]);
        }
        printf("\n");
    }
}

int ZamianaNaMacierz222 (int wiersze, int kolumny, int trzeci_wymiar, int macierz[wiersze][kolumny][trzeci_wymiar], int macierz1[wiersze][kolumny], int macierz2[wiersze][kolumny])
{
    for (int j=0; j<wiersze; j++)
    {
        for (int k=0; k<kolumny; k++)
        {
            macierz[0][j][k]=macierz1[j][k];
        }
    }

    for (int j=0; j<wiersze; j++)
    {
        for (int k=0; k<kolumny; k++)
        {
            macierz[1][j][k]=macierz2[j][k];
        }
    }
    return macierz [wiersze][kolumny][trzeci_wymiar];
}

void WypisanieMacierzy222 (int wiersze, int kolumny, int trzeci_wymiar, int macierz [wiersze][kolumny][trzeci_wymiar])
{
    for (int i=0; i<wiersze;i++)
    {
        for(int j=0; j<kolumny; j++)
        {
            for (int k=0; k<trzeci_wymiar; k++)
            {
                printf (" %d ", macierz[i][j][k]);
            }
            printf("\n");
        }
        printf ("\n");
    }
}

int Macierz222NaDwie22 (int wiersze, int kolumny, int trzeci_wymiar, int macierz [wiersze][kolumny][kolumny], int macierz1[wiersze][kolumny], int macierz2[wiersze][kolumny])
{
    for (int j=0; j<wiersze; j++)
    {
        for (int k=0; k<kolumny; k++)
        {
            macierz1[j][k]=macierz[0][j][k];
        }
    }
    for (int j=0; j<wiersze; j++)
    {
        for (int k=0; k<kolumny; k++)
        {
            macierz2[j][k]=macierz[1][j][k];
        }
    }
}

void MnozenieDwochMacierzy (int wiersze, int kolumny, int trzeci_wymiar, int macierz[wiersze][kolumny][trzeci_wymiar])
{
    int macierz1[wiersze][kolumny], macierz2[wiersze][kolumny], macierzPomnozona[wiersze][kolumny];
    Macierz222NaDwie22(wiersze, kolumny, trzeci_wymiar, macierz, macierz1, macierz2);
    macierzPomnozona[0][0]=macierz1[0][0]*macierz2[0][0]+macierz1[0][1]*macierz2[1][0];
    macierzPomnozona[0][1]=macierz1[0][0]*macierz2[0][1]+macierz1[0][1]*macierz2[1][1];
    macierzPomnozona[1][0]=macierz1[1][0]*macierz2[0][0]+macierz1[1][1]*macierz2[1][0];
    macierzPomnozona[1][1]=macierz1[1][0]*macierz2[0][1]+macierz1[1][1]*macierz2[1][1];
    WypisanieMacierzy(wiersze, kolumny, macierzPomnozona);
}

