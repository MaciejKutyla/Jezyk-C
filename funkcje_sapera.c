#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

enum kolory{NIEBIESKI = 34, CZERWONY = 31};

enum wartosci_tablicy{MINA = -1, POLE = 0};

enum wyswietlanie_chars{POLE_C = ' ', MINA_C = 241, FLAGA_C = '?'};

typedef struct Komorka{
   int wartosc;
   bool czy_gracz_byl, ograniczenie, flaga;
}pole;


void czysc_bufor(void)
{
   while(getchar()!='\n');
}

void resetuj_kolory()
{
  printf("%c[%dm", 0x1B, 0);
}

int pobierz_inta_od_gracza(const char tekst[])
{
    int ok = 0;
    int wartosc = 0;
    do
    {
        printf("%s", tekst);
        if(scanf("%d", &wartosc) == 1)
        {
            ok = 1;
        }
        czysc_bufor();
    }while(ok !=1);
    return wartosc;
}

int pobierz_liczbe_wieksza_od_zera(const char tekst[])
{
   int wartosc;
   do
   {
      wartosc = pobierz_inta_od_gracza(tekst);
   }while (wartosc <= 0);
   return wartosc;
}

int pobierz_liczbe_mniejsza_Lub_rowna_zadanej_i_wieksza_lub_rowna_zadanej(const char tekst[], int liczba_dolna, int liczba)
{
	int wartosc = 0;
	do
	{
		wartosc = pobierz_liczbe_wieksza_od_zera(tekst);
	}while(wartosc > liczba || wartosc < liczba_dolna);
	
	return wartosc;
}

bool pobierz_bool_od_gracza(const char tekst[])
{
   bool czy_prawda;
   do
   {
      czy_prawda = pobierz_inta_od_gracza(tekst);
   }while(czy_prawda != 0 && czy_prawda !=1);
   return czy_prawda;
}

void losuj_miny(int wysokosc, int szerokosc, pole tablica[wysokosc][szerokosc], int ilosc_min)
{
   for (int i = 0; i < ilosc_min; i++)
   {
      while(1)
      {
         int a = (rand() % (wysokosc - 4)) + 2;
         int b = (rand() % (wysokosc - 4)) + 2;
         if(tablica[a][b].wartosc != MINA)
         {
            tablica[a][b].wartosc = MINA;
            break;
         }
      }
   }
}

int licz_w_otoczeniu(int wysokosc, int szerokosc, pole tablica[wysokosc][szerokosc], int wys, int szer, int wartosc)
{
   int suma = 0;
   
   for (int i = -1; i < 2; i += 2)
   {
      if(tablica[wys][szer+i].wartosc == wartosc)
      {
         suma++;
      }
      if(tablica[wys+i][szer].wartosc == wartosc)
      {
         suma++;
      }
      if(tablica[wys+i][szer+i].wartosc == wartosc)
      {
         suma++;
      }
      if(tablica[wys+i][szer-i].wartosc == wartosc)
      {
         suma++;
      }
   }
   return suma;
}

void oblicz_wartosci_tabeli(int wysokosc, int szerokosc, pole tablica[wysokosc][szerokosc])
{
   for (int i = 1; i < wysokosc -1; i++)
   {
      for (int j = 1; j < szerokosc -1; j++)
      {
         if(tablica[i][j].wartosc == 0)
         {
            tablica[i][j].wartosc = licz_w_otoczeniu(wysokosc, szerokosc, tablica, i, j, MINA);
         }
      }
   }
}

void czysc_tablice(int wysokosc, int szerokosc, pole tablica[wysokosc][szerokosc])
{
   for (int i = 0; i < wysokosc; i++)
   {
      for ( int j = 0; j < szerokosc; j++)
      {
         tablica[i][j].wartosc = 0;
         tablica[i][j].czy_gracz_byl = 0;
         tablica[i][j].ograniczenie = 0;
         tablica[i][j].flaga = 0;
      }
   }
   for (int i = 0; i < szerokosc; i++)
   {
      tablica[0][i].ograniczenie = 1;
      tablica[wysokosc - 1][i].ograniczenie = 1;
   }
   for (int i = 0; i < wysokosc; i++)
   {
      tablica[i][0].ograniczenie = 1;
      tablica[i][szerokosc -1].ograniczenie = 1;
   }
}

void rysuj_tablice(int wysokosc, int szerokosc, pole tablica[wysokosc][szerokosc])
{
   printf("     ");
   for (int i = 1; i < szerokosc - 1; i++)
   {
      printf("  %4d ", i);
   }
   printf("\n");
   for(int i = 1; i < wysokosc - 1; i++)
   {
      printf("%3d  ", i);
      for (int j = 1; j < szerokosc - 1; j++)
      {
         if(tablica[i][j].czy_gracz_byl)
         {
            switch(tablica[i][j].wartosc)
            {
               case MINA:
                  printf("%c[%dm", 0x1B, 7);
                  printf("|  %c  |", MINA_C);
                  resetuj_kolory();
                  break;                 
               default:
                  printf("%c[%dm", 0x1B, CZERWONY);
                  printf("|  %d  |", tablica[i][j].wartosc);
                  resetuj_kolory();
            }
         }
         else
         {
            if(tablica[i][j].flaga == 1)
            {
               printf("%c[%dm", 0x1B, NIEBIESKI);
               printf("|  %c  |", FLAGA_C);
               resetuj_kolory();
            }
            else
            {
               printf("|  %c  |", POLE_C);
            }
         }
      }
      printf("\n");
   }
}

void odkrywanie_do_okola(int wysokosc, int szerokosc, pole tablica[wysokosc][szerokosc], int wys, int szer);

int odkryj_pola(int wysokosc, int szerokosc, pole tablica[wysokosc][szerokosc], int wys, int szer)
{
               if(tablica[wys][szer].ograniczenie == 1)
               {
                  return 0; 
               }
               if(tablica[wys][szer].flaga == 1)
               {
                  return 0;
               }
               if (tablica[wys][szer].czy_gracz_byl==1)
               {
                   return 0;  
               }
               if(tablica[wys][szer].wartosc != MINA)
               {
                  tablica[wys][szer].czy_gracz_byl=1;
               }
               if (tablica[wys][szer].wartosc>0)
               {
                   return 0; 
               }
               
               
               odkrywanie_do_okola(wysokosc, szerokosc, tablica, wys, szer);
   
   return 0;
}

void odkrywanie_do_okola(int wysokosc, int szerokosc, pole tablica[wysokosc][szerokosc], int wys, int szer)
{
   for (int i = -1; i<2; i+=2)
   {
      odkryj_pola(wysokosc, szerokosc, tablica, wys, szer+i);
      odkryj_pola(wysokosc, szerokosc, tablica, wys+i, szer);
      odkryj_pola(wysokosc, szerokosc, tablica, wys+i, szer+i);
      odkryj_pola(wysokosc, szerokosc, tablica, wys+i, szer-i);
   }
}
   
int czy_koniec(int wysokosc, int szerokosc, pole tablica[wysokosc][szerokosc], int suma_min)
{
   int suma_flag = 0;
   int suma_flag_na_minach = 0;
   
   for (int i = 1; i < wysokosc -1; i++)
   {
      for (int j = 1; j < szerokosc -1; j++)
      {
         if(tablica[i][j].flaga == 1 && tablica[i][j].wartosc == MINA)
         {
            suma_flag_na_minach++;
         }
         if(tablica[i][j].flaga == 1)
         {
            suma_flag++;
         }
      }
   }
   if(suma_min + suma_flag == suma_flag_na_minach * 2)
   {
      return 1;
   }
   else
   {
      return 0;
   }
}

int sprawdz_ruch_gracza(int wysokosc, int szerokosc, pole tablica[wysokosc][szerokosc], int wys, int szer, int czy_flaga, int ilosc_min)
{
   if(czy_flaga == 1)
   {
      tablica[wys][szer].flaga = 1;
   }
   else if(tablica[wys][szer].wartosc == MINA)
   {
      if(tablica[wys][szer].flaga != 1)
      {
         tablica[wys][szer].czy_gracz_byl=1;
         printf("                         KONIEC GRY!\n");
         system("echo \"Przegrana gra\" >> game_log.txt");
         rysuj_tablice(wysokosc, szerokosc, tablica);
         exit(1);
      }
   }
   else
   {
      odkryj_pola(wysokosc, szerokosc, tablica, wys, szer);
   }
   
   return(czy_koniec(wysokosc, szerokosc, tablica, ilosc_min));
}
