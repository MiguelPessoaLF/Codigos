#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "io.h"
#include <stdio.h>
#include <string.h>
int main ( void )
{
 // identificar
    printf ( "\n%s\n", "Questao 1:" );
 // definir dados
 int x = 0;
 int y = 2; 
 int z= 0;
 int p = 0;
 int *py = &z;
// mostrar valores iniciais
 printf ( "%s%d\n", "x = ", x );
// ler do teclado
 printf ( "Entrar com o lado de um quadrado: " );
 scanf ( "%d", &x );
 getchar ( ); 
// operar valores
    z = x * y; 
    printf ( "%s(%i)*(%i) = (%d)\n", "z = ", x, y, z );
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
    p = z * z;
    printf ( "%s%i\n", "Area do novo quadrado =" ,p  );
    //encerrar
    printf ( "\n%s\n" , "Aperte ENTER para finalizar");
    getchar ( );
}
/**
Questao 1:
x = 0
Entrar com o lado de um quadrado: 5
z = (5)*(2) = (10)

Apertar ENTER para continuar.

Area do novo quadrado =100
 */