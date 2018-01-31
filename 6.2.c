#include <stdio.h>
#include <time.h>

int Odczytywanie_miesiaca(void);
int Odczytywanie_roku(void);
void Wypisanie_kalendarza(int k, int rok);

int main()
{
    int miesiac = Odczytywanie_miesiaca();
    ilosc_dni_aktualnego_miesiaca();
    int rok = Odczytywanie_roku();
    Wypisanie_kalendarza(miesiac, rok);
    return 0;
}

int Odczytywanie_miesiaca()
{
    int rok;
    Odczytywanie_roku();
    time_t wsk_sekund;
    time (&wsk_sekund);
    int w=localtime(&wsk_sekund)->tm_mon;
    int miesiac=w+1;
    printf("Mamy %d miesiac \n",miesiac);
    return miesiac;
}

int Odczytywanie_roku(void)
{
    time_t wsk_lat;
    time (&wsk_lat);
    int lata=localtime(&wsk_lat)->tm_year;
    int rok;
    rok = lata +1900;
    return rok;
}

void Wypisanie_kalendarza(int k, int rok)
{
    if(k==1||k==3||k==5||k==7||k==8||k==10||k==12)
    {
        for (int i=1; i<32; i++)
        {
            printf("   %d   ", i);
            if(i%7==0)
                printf("\n");
        }
    }
    else if (k==2 && rok%4!=0)
    {
        for (int i=1; i<29; i++)
        {
            printf("   %d   ", i);
            if(i%7==0)
                printf("\n");
        }
    }
    else if (k==2 && rok%4==0)
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

int ilosc_dni_aktualnego_miesiaca()
{
    int rok;
    Odczytywanie_roku();
    time_t wsk_sekund;
    time (&wsk_sekund);
    int w=localtime(&wsk_sekund)->tm_mon;
    int k=w+1;
    if(k==1||k==3||k==5||k==7||k==8||k==10||k==12)
        {
            printf("Miesiac ma 31 dni\n");
        }
    else if (k==2 && rok%4!=0)
        {
            printf("Miesiac ma 28 dni\n");
        }
     else if (k==2 && rok%4==0)
        {
            printf("Miesiac ma 29 dni\n");
        }
    else
        {
            printf("Miesiac ma 30 dni\n");
        }
}
