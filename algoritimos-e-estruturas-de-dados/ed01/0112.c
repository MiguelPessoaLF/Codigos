#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "io.h"
#include <stdio.h>
#include <string.h>
int main ( void )
{
 // identificar
    printf ( "\n%s\n", "Questao 2:" );
 // definir dados
 int x = 0;
 int z= 0;
 int p = 0;
 int r = 0;
 int q = 4;
// mostrar valores iniciais
 printf ( "%s%d\n", "x = ", x );
// ler do teclado
 printf ( "Entrar com o lado de um quadrado: " );
 scanf ( "%d", &x );
 getchar ( ); 
// operar valores
    z = x /3;
    printf ( "%s(%i)/3 = (%d)\n", "z = ", x, z );
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
    p = z * z;
    printf ( "%s%i\n", "Area do novo quadrado =" ,p  );
    r = q * z;
    printf ( "%s%i\n", "Perimetro do novo quadrado =" ,r );
    //encerrar
    printf ( "\n%s\n" , "Aperte ENTER para finalizar");
    getchar ( );
}
/**
x = 0
Entrar com o lado de um quadrado: 5
z = (5)/3 = (1)

Apertar ENTER para continuar.

Area do novo quadrado =1
Perimetro do novo quadrado =4
 */