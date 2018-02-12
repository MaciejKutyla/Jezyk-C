#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double liczenie_pierwiastkow(double a, double b, double c)
{
    double delta=b*b-4*a*c;
    if (delta==0)
    {
        double x1=(-b)/(2*a);
        printf("Mamy jeden pierwiastek rzeczywisty: \nx=%lf", x1);
    }
    else if (delta>0)
    {
        double x1=((-b)-(sqrt(delta)))/(2*a);
        double x2=((-b)+(sqrt(delta)))/(2*a);
        printf("Mamy dwa pierwiastki rzeczywiste:\nx1=%lf\nx2=%lf", x1, x2);
    }
    else
        printf("Rownanie nie ma pierwiastkow rzeczywistych");
}

int main(void)
{
    printf("Podaj wspolczynniki rownania kwadratowego: \na=");
    double a,b,c;
    scanf("%lf", &a);
    if (a==0)
    {
        printf("Nie jest to rownanie kwadratowe!\n");
        exit(0);
    }
    printf("b=");
    scanf("%lf", &b);
    printf("c=");
    scanf("%lf", &c);
    liczenie_pierwiastkow(a, b, c);

    return 0;
}
