#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "io.h"
void metodo01 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo01" );
    int x = 0; 
    x = IO_readint ( "Entrar com uma quantidade: " ); 
 // repetir (x) vezes 
    while ( x > 0 ) 
    { 
     // mostrar valor atual 
        IO_println ( IO_toString_d ( x ) ); 
     // passar ao proximo valor 
        x = x - 1; 
    }
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" );
}
/**
a.)   0 
b.)   1 
c.)   2 
d.)   3 
e.)   4 
f.)  -1 
a)
Metodo01
Entrar com uma quantidade: 0
b)
Metodo01
Entrar com uma quantidade: 1
1
c)
Metodo01
Entrar com uma quantidade: 2
2
1
d)
Metodo01
Entrar com uma quantidade: 3
3
2
1
e)
Metodo01
Entrar com uma quantidade: 4
4
3
2
1
f)
Metodo01
Entrar com uma quantidade: -1
 */
void metodo02 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo02" );
    int x = 0; 
    int y = 0;  
    x = IO_readint ( "Entrar com uma quantidade: " ); 
 // repetir (x) vezes 
    y = x;  // copiar o valor lido
    while ( y > 0 ) 
    { 
     // mostrar valor atual 
        IO_println ( IO_toString_d ( x ) ); 
     // passar ao proximo valor 
        y = y - 1; 
    }
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" );
}
/**
a.)   0 
b.)   1 
c.)   5 
d.)  -5 
a)
Metodo02
Entrar com uma quantidade: 0
b)
Metodo02
Entrar com uma quantidade: 1
1
c)
Metodo02
Entrar com uma quantidade: 5
5
5
5
5
5
d)
Metodo02
Entrar com uma quantidade: -5
 */
void metodo03 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo03" );
    int x = 0; 
    int y = 0; 
    x = IO_readint ( "Entrar com uma quantidade: " ); 
 // repetir (x) vezes 
    y = 1;
    while ( y <= x ) 
    { 
     // mostrar valor atual 
        IO_printf ( "%d\n", y ); 
     // passar ao proximo valor 
        y = y + 1; 
    }
    IO_pause ( "Apertar ENTER para continuar" );
}
/**
a.)   0 
b.)   1 
c.)   3 
d.)   5 
e.)  -5 
a)
Metodo03
Entrar com uma quantidade: 0
b)
Metodo03
Entrar com uma quantidade: 1
1
c)
Metodo03
Entrar com uma quantidade: 3
1
2
3
d)
Metodo03
Entrar com uma quantidade: 5
1
2
3
4
5
e)
Metodo03
Entrar com uma quantidade: -5
 */
void metodo04 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo04" );
    int x = 0; 
    int y = 0; 
    int z = 0; 
    x = IO_readint ( "Entrar com uma quantidade: " ); 
 // repetir (x) vezes 
 //        inicio    teste   variacao 
    for ( y  = 1; y <= x; y = y + 1 ) 
    { 
     // ler valor do teclado 
        z = IO_readint ( "Valor = " ); 
     // mostrar valor atual 
        IO_printf ( "%d. %d\n", y, z ); 
    }
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" );
}
/**
a.)   0 
b.)   1 
c.)   3 
d.)   5 
e.)  -5 
a)
Metodo04
Entrar com uma quantidade: 0
b)
Metodo04
Entrar com uma quantidade: 1
Valor = 1
1. 1
c)
Metodo04
Entrar com uma quantidade: 3
Valor = 3
1. 3
Valor = 3
2. 3
Valor = 3
3. 3
d)
Metodo04
Entrar com uma quantidade: 5
Valor = 5
1. 5
Valor = 5
2. 5
Valor = 5
3. 5
Valor = 5
4. 5
Valor = 5
5. 5
e)
Metodo04
Entrar com uma quantidade: -5
f)
Metodo04
Entrar com uma quantidade: 5
Valor = 1
1. 1
Valor = 2
2. 2
Valor = 4
3. 4
Valor = 7
4. 7
Valor = 2
5. 2
*/
void metodo05 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo05" );
    int x = 0; 
    int y = 0; 
    int z = 0; 
    x = IO_readint ( "Entrar com uma quantidade: " ); 
 // repetir (x) vezes 
 //        inicio    teste   variacao 
    for ( y  = x; y >= 1; y = y - 1 ) 
    { 
     // ler valor do teclado 
        z = IO_readint ( "Valor = " ); 
     // mostrar valor atual 
        IO_printf ( "%d. %d\n", y, z ); 
    }
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" );
}
/**
a.)   0 
b.)   1 
c.)   3 
d.)   5 
e.)  -5 
a)
Metodo05
Entrar com uma quantidade: 0
b)
Metodo05
Entrar com uma quantidade: 1
Valor = 4
1. 4
c)
Entrar com uma quantidade: 3
Valor = 4
3. 4
Valor = 5
2. 5
Valor = 6
1. 6
d)
Entrar com uma quantidade: 5
Valor = 2
5. 2
Valor = 3
4. 3
Valor = 4
3. 4
Valor = 5
2. 5
Valor = 6
1. 6
e)
Metodo05
Entrar com uma quantidade: -5
 */
void metodo06 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo06" );
    int x = 0; 
    int y = 0; 
    chars palavra = IO_new_chars ( STR_SIZE ); 
    int  tamanho   = 0; 
 // identificar 
    IO_id ( "Method_06 - v0.0" ); 
    palavra = IO_readstring ( "Entrar com uma palavra: " ); 
 // repetir para cada letra 
    tamanho = strlen ( palavra ) - 1; 
//  OBS: A cadeia de caracteres iniciam suas posições em zero. 
 //         inicio               teste   variacao 
    for ( y  = tamanho; y >= 0; y = y - 1 ) 
    { 
     // mostrar valor atual 
        IO_printf ( "%d: [%c]\n", y, palavra [y] ); 
    }
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
}
/**
a.)   "a" 
b.)   "abc" 
c.)   "abc def" 
a)
Metodo06
Entrar com uma palavra: a
0: [a]
b)
Metodo06
Entrar com uma palavra: abc
2: [c]
1: [b]
0: [a]
c)
Entrar com uma palavra: abc def
2: [c]
1: [b]
0: [a]
 */
void metodo07 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo07" );
    int x = 0; 
    int y = 0; 
    char palavra [STR_SIZE]; 
    int  tamanho = 0; 
    IO_printf ( "Entrar com uma palavra: " ); 
    scanf  ( "%s", palavra ); getchar( ); 
//  OBS: A cadeia de caracteres dispensa a indicacao de endereco (&) na leitura. 
 // repetir para cada letra 
    tamanho = strlen ( palavra ); 
//  OBS: A cadeia de caracteres iniciam suas posições em zero. 
 
 //         inicio        teste        variacao 
    for ( y  = 0; y < tamanho; y = y + 1 ) 
    { 
     // mostrar valor atual 
        IO_printf ( "%d: [%c]\n", y, palavra [y] ); 
    }
    IO_pause ( "Apertar ENTER para continuar" );
}
/**
a.)   "a" 
b.)   "abc" 
c.)   "abc def"
a)
Metodo07
Entrar com uma palavra: a
0: [a]
b)
Metodo07
Entrar com uma palavra: abc
0: [a]
1: [b]
2: [c]
c)
Metodo07
Entrar com uma palavra: abc def
0: [a]
1: [b]
2: [c]
 */
void metodo08 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo08" );
    int inferior = 0; 
    int superior = 0; 
    int x = 0; 
    inferior   = IO_readint ( "Limite inferior do intervalo: " ); 
    superior = IO_readint ( "Limite superior do intervalo: " ); 
 //                inicio             teste         variacao 
    for ( x  = inferior; x <= superior; x = x + 1 ) 
    { 
     // mostrar valor atual 
        IO_printf ( "%d\n", x ); 
    } 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
}
/**
a.)   0 e 1 
b.)   1 e  5 
c.)   3 e  5 
d.)  -5 e  5 
a)
Metodo08
Limite inferior do intervalo: 0
Limite superior do intervalo: 1
0
1
b)
Metodo08
Limite inferior do intervalo: 1
Limite superior do intervalo: 5
1
2
3
4
5
c)
Metodo08
Limite inferior do intervalo: 3
Limite superior do intervalo: 5
3
4
5
d)
Metodo08
Limite inferior do intervalo: -5
Limite superior do intervalo: 5
-5
-4
-3
-2
-1
0
1
2
3
4
5
 */
void metodo09 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo09" );
    double inferior   = 0; 
    double superior = 0; 
    double passo     = 0; 
    double x             = 0; 
    inferior   = IO_readdouble ( "Limite inferior do intervalo: " ); 
    superior = IO_readdouble ( "Limite superior do intervalo: " ); 
    passo     = IO_readdouble ( "Variacao no intervalo (passo): " ); 
 
 //                inicio               teste            variacao 
    for ( x  = superior; x >= inferior; x = x - passo ) 
    { 
     // mostrar valor atual 
        IO_printf ( "%lf\n", x ); 
    }
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" );
}
/**
a.)   0 e  1, passo  1 
b.)   1 e  5, passo  1 
c.)   1 e  5, passo  2 
d.)   3 e  5, passo  1 
e.)   3 e  5, passo  2 
f. )  -5 e  5, passo  1 
g.)  -5 e  5, passo  2 
h.)  -5 e  5, passo  5 
 i.)  -5 e  5, passo -1 
 a)
 Metodo09
Limite inferior do intervalo: 0
Limite superior do intervalo: 1
Variacao no intervalo (passo): 1
1.000000
0.000000
b)
Metodo09
Limite inferior do intervalo: 1
Limite superior do intervalo: 5
Variacao no intervalo (passo): 1
5.000000
4.000000
3.000000
2.000000
1.000000
c)
Metodo09
Limite inferior do intervalo: 1
Limite superior do intervalo: 5
Variacao no intervalo (passo): 2
5.000000
3.000000
1.000000
d)
Metodo09
Limite inferior do intervalo: 3
Limite superior do intervalo: 5
Variacao no intervalo (passo): 1
5.000000
4.000000
3.000000
e)
Metodo09
Limite inferior do intervalo: 3
Limite superior do intervalo: 5
Variacao no intervalo (passo): 2
5.000000
3.000000
f)
Metodo09
Limite inferior do intervalo: -5
Limite superior do intervalo: 5
Variacao no intervalo (passo): 1
5.000000
4.000000
3.000000
2.000000
1.000000
0.000000
-1.000000
-2.000000
-3.000000
-4.000000
-5.000000
g)
Metodo09
Limite inferior do intervalo: -5
Limite superior do intervalo: 5
Variacao no intervalo (passo): 2
5.000000
3.000000
1.000000
-1.000000
-3.000000
-5.000000
h)
Metodo09
Limite inferior do intervalo: -5
Limite superior do intervalo: 5
Variacao no intervalo (passo): 5
5.000000
0.000000
-5.000000
i)
Metodo09
Limite inferior do intervalo: -5
Limite superior do intervalo: 5
Variacao no intervalo (passo): -1
5.000000
6.000000
7.000000
8.000000
9.000000
10.000000
11.000000
12.000000
13.000000
14.000000
15.000000
16.000000
17.000000
18.000000
19.000000
20.000000...
 */
void metodo10 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo10" );
    double inferior   = 0; 
    double superior = 0; 
    double passo     = 0; 
    double x             = 0; 
    inferior = IO_readdouble ( "Limite inferior do intervalo : " ); 
 // repetir ate' haver confirmacao de validade 
    do 
    { 
        superior = IO_readdouble ( "Limite superior do intervalo: " ); 
    } 
    while ( inferior >= superior ); 
 
 // repetir ate' haver confirmacao de validade 
    do 
    { 
        passo = IO_readdouble ( "Variacao no intervalo (passo): " ); 
    } 
    while ( passo <= 0.0 ); 
 
 //                inicio              teste              variacao 
    for ( x  = inferior; x <= superior; x = x + passo ) 
    { 
        IO_printf ( "%lf\n", x ); 
    }
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" );
}
/**
a.)  [ 0.1 : 0.5 ] e passo =   0.1 
b.)  [ 0.5 : 0.1 ] e passo =  -0.1 
c.)  [ 0.5 : 0.1 ] e passo =   0.1 
d.)  [ 0.1 : 0.5 ] e passo =  -0.1 
a)
Metodo10
Limite inferior do intervalo : 0.1
Limite superior do intervalo: 0.5
Variacao no intervalo (passo): 0.1
0.100000
0.200000
0.300000
0.400000
0.500000
b)
Metodo10
Limite inferior do intervalo : 0.5
Limite superior do intervalo: 0.1
Limite superior do intervalo: 0.6
Variacao no intervalo (passo): -0.1
Variacao no intervalo (passo): 0.1
0.500000
0.600000
c)
Metodo10
Limite inferior do intervalo : 0.5
Limite superior do intervalo: 0.1
Limite superior do intervalo: 0.6
Variacao no intervalo (passo): 0.1
0.500000
0.600000
d)
Metodo10
Limite inferior do intervalo : 0.1
Limite superior do intervalo: 0.5
Variacao no intervalo (passo): -0.1
Variacao no intervalo (passo): 0.1
0.100000
0.200000
0.300000
0.400000
0.500000
 */
int main ( void )
{
    int opcao = 0;
    do
    {
        printf ( "\n" );        
        printf ( "%s\n", "Exemplo0300 - 28/08/2024"       );
        printf ( "%s\n", "Matricula: 867160 Nome: Miguel Pessoa Lima Ferreira" );
        printf ( "%s\n", "Opcoes:"         );
        printf ( "%s\n", " 0 - parar"      );
        printf ( "%s\n", " 1 - metodo 01   2 - metodo 02" );
        printf ( "%s\n", " 3 - metodo 03   4 - metodo 04" );
        printf ( "%s\n", " 5 - metodo 05   6 - metodo 06" );
        printf ( "%s\n", " 7 - metodo 07   8 - metodo 08" );
        printf ( "%s\n", " 9 - metodo 09  10 - metodo 10" );
        printf ( "%s\n", "" );
        printf ( "%s", "Qual a sua opcao? " );
        scanf  ( "%d", &opcao ); getchar ( );
        printf ( "%d",  opcao );
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
    printf ( "\n%s\n\n", "Apertar ENTER para terminar." );
    getchar( );

}
