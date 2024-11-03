#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "io.h"
#include <math.h>
int main (void)
{
    {
   printf ( "\n%s\n", "0214->");
 int x = 0;
 x = IO_readint ( "Entrar com um valor inteiro:\n" );
 if ( x > 20 && x < 60 )
    { 
    IO_printf ( "%s %d\n", "valor dentro do intervalo [20,60]:", x);
    }
    else
    {
    IO_printf ( "%s %d\n", "valor fora do intervalo [20,60]:", x);
    }
    {
    IO_pause ("aperte ENTER para continuar");
    }
    }
}
/**
0214->
a)
Entrar com um valor inteiro:
20
valor fora do intervalo [20,60]: 20
aperte ENTER para continuar
b)
Entrar com um valor inteiro:
21
valor dentro do intervalo [20,60]: 21
aperte ENTER para continuar
 */