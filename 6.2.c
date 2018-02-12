#include <stdio.h>
#include <time.h>

int Odczytywanie_miesiaca(void);
int Odczytywanie_roku(void);
void Wypisanie_kalendarza(int numer_miesiaca, int rok);
void Ilosc_dni_aktualnego_miesiaca(void);

int main()
{
    int miesiac = Odczytywanie_miesiaca();
    Ilosc_dni_aktualnego_miesiaca();
    int rok = Odczytywanie_roku();
    Wypisanie_kalendarza(miesiac, rok);
    return 0;
}

int Odczytywanie_miesiaca()
{
    int rok = Odczytywanie_roku();
    time_t wsk_sekund;
    time (&wsk_sekund);
    int w=localtime(&wsk_sekund)->tm_mon;
    int miesiac=w+1;
    printf("Mamy %d miesiac \n",miesiac);
    return miesiac;
}

int Odczytywanie_roku()
{
    time_t wsk_lat;
    time (&wsk_lat);
    int lata=localtime(&wsk_lat)->tm_year;
    int rok = lata +1900;
    return rok;
}

void Wypisanie_kalendarza(int numer_miesiaca, int rok)
{
    if(numer_miesiaca==1||numer_miesiaca==3||numer_miesiaca==5||numer_miesiaca==7||numer_miesiaca==8||numer_miesiaca==10||numer_miesiaca==12)
    {
        for (int i=1; i<32; i++)
        {
            printf("   %d   ", i);
            if(i%7==0)
                printf("\n");
        }
    }
    else if (numer_miesiaca==2 && rok%4!=0)
    {
        for (int i=1; i<29; i++)
        {
            printf("   %d   ", i);
            if(i%7==0)
                printf("\n");
        }
    }
    else if (numer_miesiaca==2 && rok%4==0 && (rok%100!=0 && rok%400==0))
    {
        for (int i=1; i<30; i++)
        {
            printf("   %d   ", i);
            if(i%7==0)
                printf("\n");
        }
    }
    else
    {
        for (int i=1; i<31; i++)
        {
            printf("   %d   ", i);
            if(i%7==0)
                printf("\n");
        }
    }
    printf("\n");
}

void Ilosc_dni_aktualnego_miesiaca()
{
    int rok = Odczytywanie_roku();
    time_t wsk_sekund;
    time (&wsk_sekund);
    int w=localtime(&wsk_sekund)->tm_mon;
    int numer_miesiaca=w+1;
    if(numer_miesiaca==1||numer_miesiaca==3||numer_miesiaca==5||numer_miesiaca==7||numer_miesiaca==8||numer_miesiaca==10||numer_miesiaca==12)
        {
            printf("Miesiac ma 31 dni\n");
        }
    else if (numer_miesiaca==2 && rok%4!=0)
        {
            printf("Miesiac ma 28 dni\n");
        }
     else if (numer_miesiaca==2 && rok%4==0 && (rok%100!=0 && rok%400==0))
        {
            printf("Miesiac ma 29 dni\n");
        }
    else
        {
            printf("Miesiac ma 30 dni\n");
        }
}
