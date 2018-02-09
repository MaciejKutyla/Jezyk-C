//Kuty³a Maciej AGH Grupa 5 Czwartek 8:00 nr indeksu 297242
// Zajecia 3 zad 1
#include <stdio.h>

void kwadrat();
void prostokat();
void trojkat ();
void kolo();

int main(void)
{
    printf("***Czego pole chcesz liczyc***\n");
    printf("[1]Kwadrat\n");
    printf("[2]Prostokat\n");
    printf("[3]Trojkat\n");
    printf("[4]Kolo\n");

    int x;
    scanf("%d", &x);

    switch (x)
    {
        case 1:
            kwadrat();
            break;
        case 2:
            prostokat();
            break;
        case 3:
            trojkat();
            break;
        case 4:
            kolo();
            break;
        default:
            printf("Nie ma takiego numeru");
            break;

    }
    return 0;
}

void kwadrat()
{
    printf("Podaj bok kwadratu:\n");
    double a;
    scanf("%lf", &a);
    while (a<0)
        {
            printf("Podano ujemne wartosci boku, podaj wartosc jeszcze raz\n");
            scanf("%lf", &a);
        }
    double obwod,pole;
    pole=a*a;
    obwod=4*a;
    printf("Pole kwadratu to %lf,a jego obwod to %lf", pole,obwod);
}

void prostokat()
{
    printf("Podaj boki prostokata:\n");
    double a,b;
    scanf("%lf \n %lf", &a,&b);
    while (a<0 || b<0)
        {
            printf("Podano ujemne wartosci bokow, podaj wartosc jeszcze raz:\n");
            scanf("%lf \n %lf", &a,&b);
        }
    double obwod,pole;
    pole=a*b;
    obwod=2*a+2*b;
    printf("Pole prostokata to %lf,a jego obwod to %lf", pole,obwod);
}

void trojkat()
{
    printf("Podaj boki trojkata\n");
    double a,b,c;
    scanf("%lf \n %lf \n %lf",&a, &b, &c);
    while (a<0 || b<0 ||c<0)
        {
            printf("Podano ujemna wartosci bokow, podaj wartosc jeszcze raz:\n");
            scanf("%lf \n %lf \n %lf",&a, &b, &c);
        }
    printf("Podaj wysokosc trojkata\n");
    double wysokosc;
    scanf("%lf",&wysokosc);
    while (wysokosc<0)
        {
            printf("Podano ujemne wartosc wysokosci, podaj wartosc jeszcze raz:\n");
            scanf("%lf",&wysokosc);
        }
    double pole,obwod;
    pole=0.5*a*wysokosc;
    obwod=a+b+c;
    printf("Pole tojkata to %lf,a obwod to %lf", pole,obwod);
}

void kolo()
{
    printf("Podaj promien kola:\n");
    double r;
    scanf("%lf", &r);
    while (r<0)
    {
        printf("Podano ujemna wartosc promienia, podaj wartosc jeszcze raz:\n");
        scanf("%lf", &r);
    }

    double pole,obwod;
    double pi=3.14;
    pole=pi*r*r;
    obwod=pi*2*r;
    printf("Pole kola to %lf,a obwod to %lf", pole,obwod);
}
