#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "funkcje_sapera.c"

int main(void)
{
   system("echo \"$USER\" > game_log.txt");
   printf("\n");
   for (int i = 0; i<15;i++)
   {
	   printf(" ");
   }
   printf("WITAJ W GRZE SAPER!\n\n");
   printf("Instrukcje:\n Na samym poczatku wybierz wielkossc planszy jaka cie interesuje! \n Mozesz strzelac w pole wybierajac 0.\n Mozesz rowniez flagowac miejsce w ktorym wystepuje mina za pomoca 1.\n Wygrasz jesli oflagujesz wszystkie miny!\n\n                     POWODZENIA!!!\n\n");
   srand(time(NULL));
   int szerokosc_tablicy = pobierz_wymiar_tablicy("Podaj szerokosc tablicy:\n") + 2;
   int wysokosc_tablicy = pobierz_wymiar_tablicy("Podaj wysokosc tablicy:\n") + 2;
   
   int ilosc_min = szerokosc_tablicy + wysokosc_tablicy;
   pole tablica[wysokosc_tablicy][szerokosc_tablicy];

   czysc_tablice(wysokosc_tablicy, szerokosc_tablicy, tablica);
   
   losuj_miny(wysokosc_tablicy, szerokosc_tablicy, tablica, ilosc_min);
   
   oblicz_wartosci_tabeli(wysokosc_tablicy, szerokosc_tablicy, tablica);
   
   int done = 0;
   while(!done)
   {
      rysuj_tablice(wysokosc_tablicy, szerokosc_tablicy, tablica);
         
      int czy_flaga = pobierz_bool_od_gracza("Czy chcesz oflagowac miejsce?\n0-NIE, \"you only live once\"\n1-TAK, boje sie tego sprawdzac\n");
      int wys = pobierz_wymiar_tablicy("Prosze podac wspolrzedna wysokosci:\n");
      int szer = pobierz_wymiar_tablicy("Prosze podac wspolrzedna szerokosci:\n");
      
      
      done = sprawdz_ruch_gracza(wysokosc_tablicy, szerokosc_tablicy, tablica, wys, szer, czy_flaga, ilosc_min);
   }
   printf("GRATULACJE!");
   system("echo \"Wygrana gra\" >> game_log.txt");
   return 0;
}
