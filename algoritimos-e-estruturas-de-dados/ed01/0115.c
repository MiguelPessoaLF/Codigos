#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "io.h"
#include <stdio.h>
#include <string.h>
int main ( void )
{
 // identificar
    printf ( "\n%s\n", "Questao 5:" );
 // definir dados
 int x = 0;
 int y = 0; 
 int z = 0;
 int t = 0;
 int s = 0;
 int p = 2;
 int *py = &z;
// mostrar valores iniciais
printf ( "%s%d\n", "x = " ,x );
printf ( "%s%d\n", "y = " ,y );
// ler do teclado
printf ( "Entrar com a altura de um triangulo:" );
scanf ( "%d", &x );
getchar ( ); 
printf ( "Entrar com a base de um triangulo:");
scanf ( "%d", &y );
getchar ( );
// calcular
z = x / p;
printf ( "%s(%i)/(%i) = (%d)\n", "z =", x, p, z);
printf ( "Aperte Enter para continuar");
getchar ( );
t = z * y;
printf ( "%s(%i)*(%i) = (%d)\n", "t =", z, y, t);
printf ( "\nAperte Enter para continuar");
getchar ( );
s = t / p;
printf ( "%s (%i)/(%i) = (%d)\n", "Area do novo triangulo =", t, p, s);
//encerrar
printf ( "\n%s\n" , "Aperte ENTER para finalizar");
getchar ( );
}
/**
Questao 5:
x = 0
y = 0
Entrar com a altura de um triangulo:3
Entrar com a base de um triangulo:4
z =(3)/(2) = (1)
Aperte Enter para continuar
t =(1)*(4) = (4)

Aperte Enter para continuar
Area do novo triangulo = (4)/(2) = (2)
*/