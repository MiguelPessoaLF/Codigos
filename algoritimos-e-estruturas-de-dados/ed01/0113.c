#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "io.h"
#include <stdio.h>
#include <string.h>
int main ( void )
{
 // identificar
    printf ( "\n%s\n", "Questao 3:" );
 // definir dados
 int x = 0;
 int y = 0; 
 int f = 0;
 int z= 0;
 int p = 3;
 int l = 2;
 int j = 0;
 int o = 0;
 int q = 0;
 int e = 0;
 int *py = &z;
// mostrar valores iniciais
 printf ( "%s%d\n", "x = " ,x );
 printf ( "%s%d\n", "y = " ,y );
// ler do teclado
 printf ( "Entrar com o lado de um retangulo: " );
 scanf ( "%d", &x );
 getchar ( ); 
 printf ( "Entrar com outro lado de um retangulo:");
 scanf ( "%d", &y );
 getchar ( );
// operar valores
    f = x * p; 
    printf ( "%s(%i)*(%i) = (%d)\n", "f = ", x, p, f );
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
    z = y * p;
    printf ( "%s(%i)*(%i) = (%d)\n", "z = ", y, p, z );
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
    j = f * z;
    printf ( "%s(%i)*(%i) = (%d)\n", "j = ", f, z, j );
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
    o = l * f;
    printf ( "%s(%i)*(%i) = (%d)\n", "o = ", l, f, o );
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
    q = l * z;
    printf ( "%s(%i)*(%i) = (%d)\n", "q = ", l, z, q );
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
    e = o + q;
    printf ( "%s%i\n", "Area do novo retangulo =" ,j  );
    printf ( "%s%i\n", "Perimetro do retangulo =" ,e  );
    //encerrar
    printf ( "\n%s\n" , "Aperte ENTER para finalizar");
    getchar ( );
}
/**
Questao 3:
x = 0
y=  0
Entrar com o lado de um retangulo: 3
Entrar com outro lado de um retangulo:5
f = (3)*(3) = (9)

Apertar ENTER para continuar.

z = (5)*(3) = (15)

Apertar ENTER para continuar.

j = (9)*(15) = (135)

Apertar ENTER para continuar.

o = (2)*(9) = (18)

Apertar ENTER para continuar.

q = (2)*(15) = (30)

Apertar ENTER para continuar.

Area do novo retangulo =135
Perimetro do retangulo =48
 */
//li errado a questao e acabei fazendo mais doque precisava kkk