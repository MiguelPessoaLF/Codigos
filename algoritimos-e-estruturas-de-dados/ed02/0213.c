#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "io.h"
#include <math.h>
int main (void)
{
    {
   printf ( "\n%s\n", "0213->");
 int x = 0;
 x = IO_readint ( "Entrar com um valor inteiro:\n" );
 if ( x >= 25 && x <= 45 )
    { 
    IO_printf ( "%s %d\n", "valor dentro do intervalo (25,45):", x);
    }
    else
    {
    IO_printf ( "%s %d\n", "valor fora do intervalo (25,45):", x);
    }
    {
    IO_pause ("aperte ENTER para continuar");
    }
    }
}
/**
a)
0213->
Entrar com um valor inteiro:
4
valor fora do intervalo (25,45): 4
aperte ENTER para continuar
b)
Entrar com um valor inteiro:
30
valor dentro do intervalo (25,45): 30
aperte ENTER para continuar
*/