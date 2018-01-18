//Kutyla Maciej AGH Grupa 5 Czwartek 8:00 nr indeksu 297242
// Zajecia 5 zad 3
#include <stdlib.h>
#include <time.h>

void TworzenieMacierzy(int macierz[2][2]);
void WypisanieMacierzy (int macierz[2][2]);
int ZamianaNaMacierz222 (int macierz[2][2][2], int macierz1[2][2], int macierz2[2][2]);
void WypisanieMacierzy222 (int macierz [2][2][2]);
int Macierz222NaDwie22 (int macierz [2][2][2], int macierz1[2][2], int macierz2[2][2]);

int main (void)
{
    int macierz1[2][2], macierz2[2][2], macierz[2][2][2], macierzPomnozona[2][2];
    srand(time(NULL));
    TworzenieMacierzy (macierz1);
    TworzenieMacierzy (macierz2);
    ZamianaNaMacierz222(macierz, macierz1, macierz2);
    WypisanieMacierzy222(macierz);
    MnozenieDwochMacierzy(macierz);
    return 0;
}

void TworzenieMacierzy(int macierz[2][2])
{
    for (int i=0; i<2; i++)
    {
        for (int j=0;j<2; j++)
        {
            macierz[i][j]=rand()%200 -100;
        }
    }
}

void WypisanieMacierzy (int macierz[2][2])
{
    for (int k=0; k<2; k++)
    {
        for (int l=0;l<2; l++)
        {
            printf(" %d ", macierz[k][l]);
        }
        printf("\n");
    }
}

int ZamianaNaMacierz222 (int macierz[2][2][2], int macierz1[2][2], int macierz2[2][2])
{
    for (int j=0; j<2; j++)
    {
        for (int k=0; k<2; k++)
        {
            macierz[0][j][k]=macierz1[j][k];
        }
    }

    for (int j=0; j<2; j++)
    {
        for (int k=0; k<2; k++)
        {
            macierz[1][j][k]=macierz2[j][k];
        }
    }
    return macierz [2][2][2];
}

void WypisanieMacierzy222 (int macierz [2][2][2])
{
    for (int i=0; i<2;i++)
    {
        for(int j=0; j<2; j++)
        {
            for (int k=0; k<2; k++)
            {
                printf (" %d ", macierz[i][j][k]);
            }
            printf("\n");
        }
        printf ("\n");
    }
}

int Macierz222NaDwie22 (int macierz [2][2][2], int macierz1[2][2], int macierz2[2][2])
{
    for (int j=0; j<2; j++)
    {
        for (int k=0; k<2; k++)
        {
            macierz1[j][k]=macierz[0][j][k];
        }
    }
    for (int j=0; j<2; j++)
    {
        for (int k=0; k<2; k++)
        {
            macierz2[j][k]=macierz[1][j][k];
        }
    }
}

void MnozenieDwochMacierzy (int macierz[2][2][2])
{
    int macierz1[2][2], macierz2[2][2], macierzPomnozona[2][2];
    Macierz222NaDwie22(macierz, macierz1, macierz2);
    macierzPomnozona[0][0]=macierz1[0][0]*macierz2[0][0]+macierz1[0][1]*macierz2[1][0];
    macierzPomnozona[0][1]=macierz1[0][0]*macierz2[0][1]+macierz1[0][1]*macierz2[1][1];
    macierzPomnozona[1][0]=macierz1[1][0]*macierz2[0][0]+macierz1[1][1]*macierz2[1][0];
    macierzPomnozona[1][1]=macierz1[1][0]*macierz2[0][1]+macierz1[1][1]*macierz2[1][1];
    WypisanieMacierzy(macierzPomnozona);
}

