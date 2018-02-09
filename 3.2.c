//Kuty³a Maciej AGH Grupa 5 Czwartek 8:00 nr indeksu 297242
//Zajecia 3 zad 3
#include <stdio.h>
void radianynastopnie(void);
void stopnienaradiany(void);
int main(void)
{
    printf("***MENU***\n");
    printf("[1]Stopnie-->Radiany\n");
    printf("[2]Radiany-->Stopnie\n");
    int x;
    scanf("%d", &x);

    switch (x)
    {
        case 1:
            stopnienaradiany();
            break;
        case 2:
            radianynastopnie();
            break;
        default:
            printf("Nie ma takiego numeru!");
            break;
    }
    return 0;
}
void radianynastopnie()
{
    double stopnie,radiany;
    printf("Podaj miare kata w radianach: \n");
    scanf("%lf", &radiany);
    stopnie=radiany*180;
    printf("%lf radiany to %lf stopni",radiany,stopnie);
}
void stopnienaradiany()
{
    double stopnie,radiany;
    printf("Podaj miare kata w stopniach \n");
    scanf("%lf", &stopnie);
    radiany=stopnie/180;
    printf("%lf stopni to %lf radianow",stopnie,radiany);
}
