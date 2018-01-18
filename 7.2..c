#include <stdio.h>
#include <stdarg.h>
#include <string.h>

void    printf_ze_scanfem (char* tekst, ...)

{
	int dl_txt = strlen(tekst);
    int *argument;
	va_list argumenty;
	va_start(argumenty, tekst);


	for (int i=0; i< dl_txt; i++)
	{
		if (tekst[i] == '%' && tekst[i+1] == 'd')
		{
			i++;
			argument = va_arg(argumenty, int*);
			scanf("%d", &argument);
		}
		else
		{
			printf("%c", tekst[i]);
		}
	}

	va_end(argumenty);
}

int main (void)
{
    int arg1,arg2,arg3,arg4;
    printf("Podaj swoje 4 ulubione liczby i zobacz co sie stanie!\n");
	printf_ze_scanfem("Pierwsza: %dDruga: %dTrzecia: %dCzwarta: %d", &arg1, &arg2, &arg3, &arg4);
	printf("Nic sie nie stalo :)");
	return 0;
}
