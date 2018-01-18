//Kutyla Maciej AGH Grupa 5 Czwartek 8:00 nr indeksu 297242
// Zajecia 4 zad 1
#include <stdio.h>
#include <math.h>

double liczenie_pierwiastkow(double a, double b, double c)
{
    double delta, x1, x2;
    delta=b*b-4*a*c;
    if (delta==0)
    {
        x1=(-b)/(2*a);
        printf("Mamy jeden pierwiastek rzeczywisty: \nx=%lf", x1);
    }
    else if (delta>0)
    {
        x1=((-b)-(sqrt(delta)))/(2*a);
        x2=((-b)+(sqrt(delta)))/(2*a);
        printf("Mamy dwa pierwiastki rzeczywiste:\nx1=%lf\nx2=%lf", x1, x2);
    }
    else
        printf("Rownanie nie ma pierwiastkow rzeczywistych");
}



int main(void)
{
    double a,b,c;
    printf("Podaj wspolczynniki rownania kwadratowego: \na=");
    scanf("%lf", &a);
    printf("b=");
    scanf("%lf", &b);
    printf("c=");
    scanf("%lf", &c);
    liczenie_pierwiastkow(a, b, c);

    return 0;
}
