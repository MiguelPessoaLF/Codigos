#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "io.h"
#include <math.h>
int main (void)
{
    {
   printf ( "\n%s\n", "0211->");
 int x = 0;
 x = IO_readint ( "Entrar com um valor inteiro: " );
 if ( x % 2 == 0 )
 {
 IO_printf ( "%s (%d)\n", "Valor par:", x );
 }
else
 {
 IO_printf ( "%s (%d)\n", "Valor impar:", x );
 }
 IO_pause ( "Apertar ENTER para continuar" );
}
}
/**
a)
Entrar com um valor inteiro: 4
Valor par: (4)
b)
Entrar com um valor inteiro: 3
Valor impar: (3)
Apertar ENTER para continuar
 */