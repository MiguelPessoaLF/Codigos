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
 if ( x >= 10 && x <= 25 )
    { 
    IO_printf ( "%s %d\n", "valor dentro do intervalo (10,25):", x);
    }
    else
    {
    IO_printf ( "%s %d\n", "valor fora do intervalo (10,25):", x);
    }
 if ( x >= 15 && x <= 50 )
    {
    IO_printf ( "%s %d\n", "valor dentro do intervalo (15,50):", x);
    }
    else
    {
    IO_printf ( "%s %d\n", "valor fora do intervalo (15,50):", x);
    }
if ( x >= 15 && x <= 25 )
    {
    IO_printf ( "%s %d", "valor dentro de ambos intervalos:", x);
    }
    {
    IO_pause ("aperte ENTER para continuar");
    }
    }
}
/**
a)
0214->
Entrar com um valor inteiro:
15
valor dentro do intervalo (10,25): 15
valor dentro do intervalo (15,50): 15
valor dentro de ambos intervalos: 15
aperte ENTER para continuar
b)
Entrar com um valor inteiro:
12
valor dentro do intervalo (10,25): 12
valor fora do intervalo (15,50): 12
aperte ENTER para continuar
c)
Entrar com um valor inteiro:
45
valor fora do intervalo (10,25): 45
valor dentro do intervalo (15,50): 45
aperte ENTER para continuar
 */