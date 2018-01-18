#include <stdio.h>

double liczenie_sredniej(int *poczatek, int *koniec);

int main(void)

{
    double srednia_wazona;
    int tablica[5] = {5,2,4,1,2};
    int *poczatek = &tablica;
    int *koniec = &tablica[5];

    srednia_wazona = liczenie_sredniej(poczatek, koniec);
    printf("srednia wazona: %g\n",srednia_wazona);
    return 0;
}

double liczenie_sredniej(int *poczatek, int *koniec)

{
    double srednia = 0.0;
    double suma_liczb = 0.0;
    double suma_wag = 0.0;
    int i = 0;
    while (poczatek+i != koniec)
    {
        suma_liczb += *(poczatek+i)*(i+1);
        suma_wag +=(i+1);
        i++;
    }
    srednia = suma_liczb/suma_wag;
    return srednia;
}
