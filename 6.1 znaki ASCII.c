#include <stdio.h>

void Wyswietlenie_znakow_ASCII();

int main(void)
{
    Wyswietlenie_znakow_ASCII();
    return 0;
}

void Wyswietlenie_znakow_ASCII()
{
    for (int i=0; i<256; i++)
    {
        unsigned char znak=i;
        printf("%c   %d \n", znak,i);
    }
}



