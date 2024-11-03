#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "io.h"
void metodo01 ( void )
{
 // identificar
   printf ( "\n%s\n", "Metodo 1->");
 int x = 0;
// ler do teclado
 x = IO_readint ( "Entrar com um valor inteiro: " );
// testar valor
 if ( x == 0 )
 {
 IO_printf ( "%s (%d)\n", "Valor igual a zero", x );
 }
 if ( x != 0 )
 {
 IO_printf ( "%s (%d)\n", "Valor diferente de zero ", x );
 }
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
}
void metodo02 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo 2->" );
    
// definir dado
 int x = 0;
// ler do teclado
 x = IO_readint ( "Entrar com um valor inteiro: " );
// testar valor
 if ( x == 0 )
 {
 IO_printf ( "%s (%d)\n", "Valor igual a zero", x );
 }
 else
 {
 IO_printf ( "%s (%d)\n", "Valor diferente de zero ", x );
 } 
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
}
/**
a.) 0
b.) 5
c.) -5
a)
Entrar com um valor inteiro: 0
Valor igual a zero (0)
b)
Entrar com um valor inteiro: 5
Valor diferente de zero  (5)
c)
Entrar com um valor inteiro: -5
Valor diferente de zero  (-5)
 */
void metodo03 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo 3->" );
    
// definir dado
 int x = 0;
// ler do teclado
 x = IO_readint ( "Entrar com um valor inteiro: " );
// testar valor
 if ( x == 0 )
 {
 IO_printf ( "%s (%d)\n", "Valor igual a zero", x );
 }
 else
 {
 IO_printf ( "%s (%d)\n", "Valor diferente de zero ", x );
 if ( x > 0 )
 {
 IO_printf ( "%s (%d)\n", "Valor maior que zero", x );
 }
 else
 {
 IO_printf ( "%s (%d)\n", "Valor menor que zero", x );
 }
 }
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
}
/**
a.) 0
b.) 5
c.) -5
a)
Entrar com um valor inteiro: 0
Valor igual a zero (0)
b)
Entrar com um valor inteiro: 5
Valor diferente de zero  (5)
Valor maior que zero (5)
c)
Entrar com um valor inteiro: -5
Valor diferente de zero  (-5)
Valor menor que zero (-5)
 */
void metodo04 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo 4->" );
    // definir dado
 double x = 0.0;
// ler do teclado
 x = IO_readdouble ( "Entrar com um valor real: " );
// testar valor
 if ( 1.0 <= x && x <= 10.0 )
 {
 IO_printf ( "%s (%lf)\n", "Valor dentro do intervalo [1:10] ", x );
 }
 else
 {
 IO_printf ( "%s (%lf)\n", "Valor fora do intervalo [1:10] ", x );
 if ( x < 1.0 )
 {
 IO_printf ( "%s (%lf)\n", "Valor abaixo do intervalo [1:10] ", x );
 }
 else
 {
 IO_printf ( "%s (%lf)\n", "Valor acima do intervalo [1:10]", x );
 }
 }
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
}
/**
a.) 0
b.) 1
c.) 10
d.) -1
e.) 100
a)
Entrar com um valor real: 0
Valor fora do intervalo [1:10]  (0.000000)
Valor abaixo do intervalo [1:10]  (0.000000)
b)
Entrar com um valor real: 1
Valor dentro do intervalo [1:10]  (1.000000)
c)
Entrar com um valor real: 10
Valor dentro do intervalo [1:10]  (10.000000)
d)
Entrar com um valor real: -1
Valor fora do intervalo [1:10]  (-1.000000)
Valor abaixo do intervalo [1:10]  (-1.000000)
e)
Entrar com um valor real: 100
Valor fora do intervalo [1:10]  (100.000000)
Valor acima do intervalo [1:10] (100.000000)
 */
void metodo05 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo 5 ->" );
    {
// definir dado
 char x = '_';
// ler do teclado
 x = IO_readchar ( "Entrar com um caractere: " );
// testar valor
 if ( ('a' <= x) && (x <= 'z') )
 {
 IO_printf ( "%s (%c)\n", "Letra minuscula", x );
 }
 else
 {
 IO_printf ( "%s (%c)\n", "Valor diferente de minuscula", x );
 if ( ('A' <= x) && (x <= 'Z') )
 {
 IO_printf ( "%s (%c)\n", "Letra maiuscula", x );
 }
 else
 {
 if ( ('0' <= x) && (x <= '9') )
 {
 IO_printf ( "%s (%c)\n", "Algarismo", x );
 }
 else
 {
 IO_printf ( "%s (%c)\n", "Valor diferente de algarismo", x );
 }
 }
 } 
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} 
}
 /**
a.) a
b.) A
c.) 0
d.) #
a)
Entrar com um caractere: a
Letra minuscula (a)
b)
Entrar com um caractere: A
Valor diferente de minuscula (A)
Letra maiuscula (A)
c)
Entrar com um caractere: 0
Valor diferente de minuscula (0)
Algarismo (0)
d)
Entrar com um caractere: #
Valor diferente de minuscula (#)
Valor diferente de algarismo (#)
*/
void metodo06 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo 6->" );
{
// definir dado
 char x = '_';
// ler do teclado
 x = IO_readchar ( "Entrar com um caractere: " );
// testar valor
 if ( ( 'a' <= x && x <= 'z' ) ||
 ( 'A' <= x && x <= 'Z' ) ) 
 {
 IO_printf ( "%s (%c)\n", "Letra", x );
 }
 else
 {
 IO_printf ( "%s (%c)\n", "Valor diferente de letra", x );
 }
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
}
}
/**
a.) 0
b.) 1
c.) 10
d.) -1
e.) 100
f.) A
a)
Entrar com um caractere: 0
Valor diferente de letra (0)
b)
Entrar com um caractere: 1
Valor diferente de letra (1)
c)
Entrar com um caractere: 10
Valor diferente de letra (1)
d)
Entrar com um caractere: -1
Valor diferente de letra (-)
e)
Entrar com um caractere: 100
Valor diferente de letra (1)
f)
Entrar com um caractere: A
Letra (A)
*/
void metodo07 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo 7->" );
 // definir dado
 char x = '_';
// ler do teclado
 x = IO_readchar ( "Entrar com um caractere: " );
// testar valor
 if ( ! ( ( 'a' <= x && x <= 'z' ) || 
 ( 'A' <= x && x <= 'Z' ) ) ) 
 {
 IO_printf ( "%s (%c)\n", "Valor diferente de letra", x );
 }
 else
 {
 IO_printf ( "%s (%c)\n", "Letra", x );
 } // end if
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
}
/**
a.) 0
b.) 1
c.) 10
d.) -1
e.) 100
f.) A
g.) a
h.) _
a)
Entrar com um caractere: 0
Valor diferente de letra (0)
b)
Entrar com um caractere: 1
Valor diferente de letra (1)
c)
Entrar com um caractere: 10
Valor diferente de letra (1)
d)
Entrar com um caractere: -1
Valor diferente de letra (-)
e)
Entrar com um caractere: 100
Valor diferente de letra (1)
f)
Entrar com um caractere: A
Letra (A)
g)
Entrar com um caractere: a
Letra (a)
h)
Entrar com um caractere: _
Valor diferente de letra (_)
 */
void metodo08 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo 7->" );
    {
// definir dado
 char x = '_';
// ler do teclado
 x = IO_readchar ( "Entrar com um caractere ['0','A','a']: " );
// testar valor
 switch ( x )
 {
 case '0':
 IO_printf ( "%s (%c=%d)\n", "Valor igual do simbolo zero", x, x );
 break;
 case 'A':
 IO_printf ( "%s (%c=%d)\n", "Valor igual 'a letra A", x, x );
 break;
 case 'a':
 IO_printf ( "%s (%c=%d)\n", "Valor igual 'a letra a", x, x );
 break;
 default:
 IO_printf ( "%s (%c=%d)\n", "Valor diferente das opcoes ['0','A','a']", x, x );
 } 
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
}
/**
a.) 0
b.) A
c.) a
d.) 1
a)
Entrar com um caractere ['0','A','a']: 0
Valor igual do simbolo zero (0=48)
b)
Entrar com um caractere ['0','A','a']: A
Valor igual 'a letra A (A=65)
c)
Entrar com um caractere ['0','A','a']: a
Valor igual 'a letra a (a=97)
d)
Entrar com um caractere ['0','A','a']: 1
Valor diferente das opcoes ['0','A','a'] (1=49)
 */
}
void metodo09 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo 9->" );
// definir dado
 int x = 0;
// ler do teclado
 x = IO_readint ( "Entrar com um inteiro [0,1,2,3]: " );
// testar valor
 switch ( x )
 {
 case 0:
 IO_printf ( "%s (%d)\n", "Valor igual a zero", x );
 break;
 case 1:
 IO_printf ( "%s (%d)\n", "Valor igual a um ", x );
 break;
 case 2:
 IO_printf ( "%s (%d)\n", "Valor igual a dois", x );
 break;
 case 3:
 IO_printf ( "%s (%d)\n", "Valor igual a tres", x );
 break;
 default:
 IO_printf ( "%s (%d)\n", "Valor diferente das opcoes [0,1,2,3]", x );
 } // end switch
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} 
/**
a.) 0
b.) 1
c.) 2
d.) 3
e.) 4
f.) -1
a)
Entrar com um inteiro [0,1,2,3]: 0
Valor igual a zero (0)
b)
Entrar com um inteiro [0,1,2,3]: 1
Valor igual a um  (1)
c)
Entrar com um inteiro [0,1,2,3]: 2
Valor igual a dois (2)
d)
Entrar com um inteiro [0,1,2,3]: 3
Valor igual a tres (3)
e)
Entrar com um inteiro [0,1,2,3]: 4
Valor diferente das opcoes [0,1,2,3] (4)
f)
Entrar com um inteiro [0,1,2,3]: -1
Valor diferente das opcoes [0,1,2,3] (-1)
 */
void metodo10 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo 10->" );
// definir dado
 int x = 0;
// ler do teclado
 x = IO_readint ( "Entrar com um inteiro [0,1,2,3]: " );
// testar valor
 switch ( x )
 {
 case 0:
 IO_println ( IO_concat ( "Valor igual a zero (",
 IO_concat ( IO_toString_d ( x ), ")\n" ) ) );
 break;
 case 1:
 IO_println ( IO_concat ( "Valor igual a um (",
 IO_concat ( IO_toString_d ( x ), ")\n" ) ) );
 break;
 case 2:
 IO_println ( IO_concat ( "Valor igual a dois (",
 IO_concat ( IO_toString_d ( x ), ")\n" ) ) );
 break;
 case 3:
 IO_println ( IO_concat ( "Valor igual a três (",
 IO_concat ( IO_toString_d ( x ), ")\n" ) ) );
 break;
 default:
 IO_println ( IO_concat ( "Valor diferente das opcoes [0,1,2,3] (",
 IO_concat ( IO_toString_d ( x ), ")" ) ) );
 }
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
}
/**
a.) 0
b.) 1
c.) 2
d.) 3
e.) 4
f.) -1
a)
Entrar com um inteiro [0,1,2,3]: 0
Valor igual a zero (0)
b)
Entrar com um inteiro [0,1,2,3]: 1
Valor igual a um (1)
c)
Entrar com um inteiro [0,1,2,3]: 2
Valor igual a dois (2)
d)
Entrar com um inteiro [0,1,2,3]: 3
Valor igual a tres (3)
e)
Entrar com um inteiro [0,1,2,3]: 4
Valor diferente das opcoes [0,1,2,3] (4)
f)
Entrar com um inteiro [0,1,2,3]: -1
Valor diferente das opcoes [0,1,2,3] (-1)
 */
int main ( void )
{
    int opcao = 0;
    do
    {
     // identificar
        printf ( "\n" );     
        printf ( "%s\n", "ed02 - 20/08/2024"       );
        printf ( "%s\n", "Matricula: 867160 Nome: Miguel Pessoa Lima Ferreira" );

     // mostrar opcoes
        printf ( "%s\n", "Opcoes:"         );
        printf ( "%s\n", " 0 - parar"      );
        printf ( "%s\n", " 1 - metodo 01   2 - metodo 02" );
        printf ( "%s\n", " 3 - metodo 03   4 - metodo 04" );
        printf ( "%s\n", " 5 - metodo 05   6 - metodo 06" );
        printf ( "%s\n", " 7 - metodo 07   8 - metodo 08" );
        printf ( "%s\n", " 9 - metodo 09  10 - metodo 10" );
        printf ( "%s\n", "" );    

     // ler opcao
        printf ( "%s", "Qual a sua opcao? " );
        scanf  ( "%d", &opcao ); getchar ( );
        printf ( "%d",  opcao );

     // escolher acao
        switch ( opcao )
        {
           case  0:               break;
           case  1: metodo01 ( ); break;
           case  2: metodo02 ( ); break;
           case  3: metodo03 ( ); break;
           case  4: metodo04 ( ); break;
           case  5: metodo05 ( ); break;
           case  6: metodo06 ( ); break;
           case  7: metodo07 ( ); break;
           case  8: metodo08 ( ); break;
           case  9: metodo09 ( ); break;
           case 10: metodo10 ( ); break;
           default:
                    printf ( "\n%s\n\n", "ERRO: Opcao invalida." );
                    break;
        }
    }
    while ( opcao != 0 );

 // encerrar
    printf ( "\n%s\n\n", "Apertar ENTER para terminar." );
    getchar( );
}
