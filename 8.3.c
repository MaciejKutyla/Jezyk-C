#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long copyArgumentAndPrintCharByCharReturningSumOfArguments(const void* data, size_t sizeOfData)
{
    char skopiowane_dane[256];
    memcpy(skopiowane_dane, data ,sizeOfData);
    const unsigned int ilosc_elementow = sizeOfData/sizeof(char);

    long long suma = 0;
    for (int i = 0; i<ilosc_elementow; i++)
    {
        printf("%x\n", (char)skopiowane_dane[i]);
        suma+=1;
    }
    return suma;
}

int main()
{
    const char przyklad1[8] = "JezykC";
    printf("\n%x\n",copyArgumentAndPrintCharByCharReturningSumOfArguments(&przyklad1,sizeof przyklad1));
    const int przyklad2 = 4;
    printf("\n%x\n",copyArgumentAndPrintCharByCharReturningSumOfArguments(&przyklad2,sizeof przyklad2));
    return 0;
}
