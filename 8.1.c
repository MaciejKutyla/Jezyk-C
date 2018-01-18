#include <stdio.h>
#include <stdlib.h>

void sprawdzenie_ilosci(int ilosc, double *wsk);
int suma(int *tablica, int ilosc);
double srednia(int *tablica, int ilosc);
void sortowanie(int *tablica, int ilosc);
double mediana(int *tablica, int ilosc);
int dominanta(int *tablica, int ilosc);

void sprawdzenie_ilosci(int ilosc, double *wsk)
{
    if (ilosc<1)
    {
        printf("Podano liczbe ujemna!");
        exit(0);
    }
    else if (wsk == NULL)
    {
        printf("Przydzial pamieci nie powiodl sie! \n");
        exit(0);
    }
}

int suma(int *tablica, int ilosc)
{
    int suma = 0;
    for (int i=0; i<ilosc; i++)
    {
       suma+=tablica[i];
    }
    return suma;
}

double srednia(int *tablica, int ilosc)
{
    double suma_calosci=(suma(tablica, ilosc));
    double srednia = suma_calosci/ilosc;
    return srednia;
}

void sortowanie(int *tablica, int ilosc)
{
    for (int i=0; i<ilosc; i++)
    {
        for (int j=0; j<(ilosc -1); j++)
        {
            if(tablica[j]>tablica[j+1])
            {
                int *zmiana = tablica[j];
                tablica[j] = tablica[j+1];
                tablica[j+1] = zmiana;
            }
        }
    }
}

double mediana(int *tablica, int ilosc)
{
        sortowanie(tablica, ilosc);
        if (ilosc%2==0)
        {
            double mediana = ((double)tablica[(ilosc/2)-1]+(double)tablica[ilosc/2])/2;
            return mediana;
        }
        else
        {
            double mediana = tablica[(ilosc+1)/2-1];
            return mediana;
        }
}

int dominanta(int *tablica, int ilosc)
{
	int dominanta=0;
	for(int i =0; i<ilosc; i++)
	{
		int licznik = 0;
		for(int k =0; k<ilosc; k++)
		{
			if(tablica[i] == tablica[k])
			{
				licznik+=1;
			}
		}
		if(licznik > dominanta)
		{
			dominanta = i;
		}
	}
	return tablica[dominanta];
}

int main(void)
{
    int ilosc;
    int liczba;
    double *wsk;

    printf("Podaj ile liczb chcesz wpisac:  ");
    scanf("%d", &ilosc);
    wsk = (double *) malloc(ilosc * sizeof(double));
    sprawdzenie_ilosci(ilosc, wsk);
    int tablica[ilosc];
    printf("Podaj swoje liczby: \n");
    for(int i = 0;i<ilosc;++i)
    {
        if(scanf("%d", &tablica[i])==EOF)
        {
            if(i==0)
            {
                exit(0);
            }
            ilosc = i;
            break;
        }
    }
    int suma1=(suma(tablica, ilosc));
    double srednia1=srednia(tablica,ilosc);
    double mediana1= mediana(tablica, ilosc);
    int dominanta1=dominanta(tablica, ilosc);
    printf("Suma twoich liczb to: %d lub osemkowo %o lub szesnatkowo %x\n", suma1,suma1,suma1);
    printf("Srednia twoich liczb to: %lf \n", srednia1);
    printf("Mediana twoich liczb to: %lf\n", mediana1);
    printf("Dominanta twoich liczb to: %d lub osemkowo %o lub szesnastkowo %x\n", dominanta1,dominanta1,dominanta1);
    return 0;
}
