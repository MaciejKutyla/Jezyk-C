//Kutyla Maciej AGH Grupa 5 Czwartek 8:00 nr indeksu 297242
// Zajecia 4 zad 3
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void rozwiazanie_zagadki(int kula[9])
{
    if(kula[0]+kula[1]+kula[2]==4)
    {
        if(kula[0]==2)
            printf("Kulka nr 1 jest najciezsza \n");
        else if (kula[1]==2)
            printf("Kulka nr 2 jest najciezsza \n");
        else
            printf("Kulka nr 3 jest najciezsza \n");
    }
    else if(kula[3]+kula[4]+kula[5]==4)
    {
        if(kula[3]==2)
            printf("Kulka nr 4 jest najciezsza \n");
        else if (kula[4]==2)
            printf("Kulka nr 5 jest najciezsza \n");
        else
            printf("Kulka nr 6 jest najciezsza \n");
    }
    else
    {
        if(kula[6]==2)
            printf("Kulka nr 7 jest najciezsza \n");
        else if (kula[7]==2)
            printf("Kulka nr 8 jest najciezsza \n");
        else
            printf("Kulka nr 9 jest najciezsza \n");
    }
}

int main(void)
{
    srand(time(NULL));
    int kula[] = {1,1,1,1,1,1,1,1,1};
    int CiezszaKula=rand()%sizeof(kula);
    kula[CiezszaKula]=2;
    rozwiazanie_zagadki(kula);

    return 0;
}
