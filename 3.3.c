//Kuty³a Maciej AGH Grupa 5 Czwartek 8:00 nr indeksu 297242
// Zajecia 3 zad 2
#include <stdio.h>
void CelsjuszenaFahrenheity(void);
void FahrenheitynaCaelsjusze(void);
int main(void)
{
    printf("***Menu***\n");
    printf("[1]Celsjusze-->Fahrenheity\n");
    printf("[2]Fahrenheity-->Celsjusze\n");
    int x;
    scanf("%d", &x);

    switch(x)
    {
        case 1:
            CelsjuszenaFahrenheity();
            break;
        case 2:
            FahrenheitynaCaelsjusze();
            break;
        default:
            printf("Nie ma takiego numeru");
    }
return 0;
}
void CelsjuszenaFahrenheity(void)
{
    printf("Podaj temperature w Celsjuszach:\n");
    double celsjusze,fahrenheity;
    scanf("%lf", &celsjusze);
    fahrenheity=32+((9.0/5)*celsjusze);
    printf("To %lf stopni Farhenheita", fahrenheity);
}
void FahrenheitynaCaelsjusze(void)
{
    printf("Podaj temperature w Fahrenheitach:\n");
    double celsjusze,fahrenheity;
    scanf("%lf", &fahrenheity);
    celsjusze=(fahrenheity-32)*(5.0/9.0);
    printf(" To %lf stopni Celsjusza", celsjusze);
}

