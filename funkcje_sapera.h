#ifndef funkcje
#define funkcje

void czysc_bufor(void);

void resetuj_kolory();

int pobierz_inta_od_gracza(char tekst[]);
int pobierz_liczbe_wieksza_od_zera(char tekst[]);
int pobierz_bool_od_gracza(char tekst[]);
int pobierz_liczbe_mniejsza_Lub_rowna_zadanej_i_wieksza_lub_rowna_zadanej(char tekst[], int liczba_dolna, int liczba);

void losuj_miny(int wysokosc, int szerokosc, pole tablica[wysokosc][szerokosc], int ilosc_min);

int licz_w_otoczeniu(int wysokosc, int szerokosc, pole tablica[wysokosc][szerokosc], int wys, int szer, int co);

void oblicz_wartosci_tabeli(int wysokosc, int szerokosc, pole tablica[wysokosc][szerokosc]);

void czysc_tablice(int wysokosc, int szerokosc, pole tablica[wysokosc][szerokosc]);

void rysuj_tablice(int wysokosc, int szerokosc, pole tablica[wysokosc][szerokosc]);

void odkrywanie_do_okola(int wysokosc, int szerokosc, pole tablica[wysokosc][szerokosc], int wys, int szer);

int odkryj_pola(int wysokosc, int szerokosc, pole tablica[wysokosc][szerokosc], int wys, int szer);

int czy_koniec(int wysokosc, int szerokosc, pole tablica[wysokosc][szerokosc], int suma_min);

int sprawdz_ruch_gracza(int wysokosc, int szerokosc, pole tablica[wysokosc][szerokosc], int wys, int szer, int czy_flaga, int ilosc_min);


#endif
