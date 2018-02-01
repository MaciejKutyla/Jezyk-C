#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

enum ArgumentType {CHAR, CHARS, INT, DOUBLE};

int printArgumentInTheMiddle(void* argument, enum ArgumentType type, unsigned width)
{
    if(argument==NULL)
    {
        printf("\n");
        return 0;
    }
    if(type == CHAR)
    {
        char znak = *(char*)argument;
        if(isprint(znak) == 0)
        {
            printf("\n");
        }
        for( int i =0; i<(width/2); i++)
        {
            printf(" ");
        }
        printf("%c", *(char*)argument);
        for (int i=0; i<((width/2)-1); i++)
        {
            printf(" ");
        }
printf("\n");
    }
    else if(type == CHARS)
    {
        char* napis = *(char**)argument;
        int dl_napisu = strlen(napis);
        if(width<dl_napisu)
        {
            printf("%s\n", napis);
        }
        else if((width-dl_napisu)%2 == 1)
        {
            printf("%*c%s\n", ((width-dl_napisu-1)/2),' ',napis);
        }
        else
        {
            printf("%*c%s\n", ((width-dl_napisu)/2),' ', napis);
        }
    }
    else if(type == DOUBLE)
    {
        double liczba = *(double*)argument;
        char tablica_liczba[128];
        snprintf(tablica_liczba,128,"%f",liczba);
        int dl_liczba = strlen(tablica_liczba);
        int przecinki = 2;
        for(int i = 1; i<=dl_liczba; ++i)
            {
                if(tablica_liczba[i]=='.')
                    {
                        dl_liczba=i+3;
                        if(tablica_liczba[i+1]=='0')
                        {
                            if(tablica_liczba[i+2]=='0')
                            {
                                przecinki = 0;
                                dl_liczba=i+1;
                            }
                        }
                        else if(tablica_liczba[i+2]=='0')
                        {
                            przecinki = 1;
                            dl_liczba=i+2;
                        }
                    break;
                    }
            }
        if(dl_liczba>=width)
        {
            printf(" %.*f\n",przecinki,liczba);
        }
        else if((width-dl_liczba)%2 == 1)
        {
            printf(" %*c%.*f\n",(width-dl_liczba-1)/2,' ',przecinki,liczba);
        }
        else
        {
            printf(" %*c%.*f\n",((width-dl_liczba)/2),' ',przecinki,liczba);
        }
    }
    else if(type == INT)
    {
    	int liczba = *(int*)argument;
        int dl_liczba = (int)log10(liczba);
        if(width<dl_liczba)
        {
            printf("%d\n", liczba);
        }
        else if((width-dl_liczba)%2 == 1)
        {
            printf("%*c%d\n", ((width-dl_liczba-1)/2), ' ', liczba);
        }
        else
        {
            printf("%*c%d\n", ((width-dl_liczba)/2), ' ', liczba);
        }
    }

}

int main(void)
{
    char* a = "Kocham Jezyk C";
    char b = 'A';
    int c = 123456;
    double d = 1110.004;
    unsigned width;
    printf("Podaj dlugosc linijki: ");
    scanf("%x", &width);

    printArgumentInTheMiddle(&a,CHARS,width);
    printArgumentInTheMiddle(&b,CHAR,width);
    printArgumentInTheMiddle(&c,INT,width);
    printArgumentInTheMiddle(&d,DOUBLE,width);

    return 0;
}
