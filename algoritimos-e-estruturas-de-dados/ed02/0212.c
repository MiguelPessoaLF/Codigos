#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "io.h"
#include <math.h>
int main (void)
{
    {
   printf ( "\n%s\n", "0212->");
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
    {
 if ( x < 15 )
 {
    IO_printf ("%s %d\n", "valor menor que 15:", x);
 }
 else
 {
    IO_printf ("%s %d\n", "valor maior que 15:", x);
 }
 if ( x == 0 )
 {
   IO_printf ("%s %d\n", "valor igual a zero:", x);
 }
   IO_pause ("Aperte ENTER para continuar");
    }
    }
}
/**
0212->
a)
Entrar com um valor inteiro: 1
Valor impar: (1)

Apertar ENTER para continuar

valor menor que 15: 1

Aperte ENTER para continuar
b)
Entrar com um valor inteiro: 0
Valor par: (0)

Apertar ENTER para continuar

valor menor que 15: 0
valor igual a zero: 0
Aperte ENTER para continuar
 */

