#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "io.h"
#include <stddef.h>
#include <stdarg.h>
#include <ctype.h>
#include <time.h>
#include <wchar.h>
#include <iso646.h>
int somarValores ( int x ) 
{ 
 // definir dados locais 
    int soma = 1; 
    int y    = 0;  // controle 
 
 // repetir enquanto controle menor que a quantidade desejada 
    for ( y = 1; y <= (x-1); y = y+1 ) 
    { 
     // mostrar valor 
        IO_printf ( "%d: %d\n", y, (2*y) ); 
     // somar valor 
        soma = soma + (2*y); 
    } // end for 
 // retornar resultado 
    return ( soma ); 
}
double somarFracao1 ( int x ) 
{ 
 // definir dados locais 
    double soma              = 1.0; 
    double numerador     = 0.0; 
    double denominador = 0.0; 
    int y                             =  0  ;  // controle 
 // repetir enquanto controle menor que a quantidade desejada 
    for ( y = 1; y <= (x-1); y = y+1 ) 
    { 
     // calcular numerador 
        numerador     = 1.0; 
     // calcular denominador 
        denominador = 2.0*y; 
     // mostrar valor 
        IO_printf ( "%d: %7.4lf/%7.4lf = %lf\n", 
                          y, numerador, denominador, (numerador/denominador) ); 
     // somar valor 
        soma = soma + (1.0)/(2.0*y); 
    } // end for 
 // retornar resultado 
    return ( soma ); 
} 
double somarFracao2 ( int x ) 
{ 
 // definir dados locais 
    double soma              = 1.0; 
    double numerador     = 0.0; 
    double denominador = 0.0; 
    int y                             =  0  ;  // controle 
 
 // mostrar primeiro valor 
    IO_printf ( "%d: %7.4lf/%7.4lf\n", 1, 1.0, soma ); 
 
 // repetir enquanto controle menor que a quantidade desejada 
    for ( y = 1; y <= (x-1); y = y+1 ) 
    { 
     // calcular numerador 
        numerador     = 2.0*y-1; 
     // calcular denominador 
        denominador = 2.0*y; 
     // mostrar valor 
        IO_printf ( "%d: %7.4lf/%7.4lf = %lf\n", 
                            y+1, numerador, denominador, (numerador/denominador) ); 
     // somar valor 
        soma = soma + numerador / denominador; 
    } // end for 
 // retornar resultado 
    return ( soma ); 
}
double somarFracao3 ( int x ) 
{ 
 // definir dados locais 
    double soma = 1.0; 
    int y                =  0  ;  // controle 
 
 // mostrar primeiro valor 
    IO_printf ( "%d: %7.4lf/%7.4lf\n", 1, 1.0, soma ); 
 
 // repetir enquanto controle menor que a quantidade desejada 
    for ( y = 1; y < x; y = y+1 ) 
    { 
     // mostrar valor 
        IO_printf ( "%d: %7.4lf/%7.4lf = %7.4lf\n", 
                            y+1, (2.0*y), (2.0*y+1), ((2.0*y)/(2.0*y+1)) ); 
     // somar valor 
        soma = soma + (2.0*y)/(2.0*y+1); 
    } // end for 
 // retornar resultado 
    return ( soma ); 
}
int multiplicarValores ( int x ) 
{ 
 // definir dados locais 
    int produto = 1; 
    int y             = 0;  // controle 
 
 // repetir enquanto controle menor que a quantidade desejada 
    for ( y = 1; y <= x; y = y+1 ) 
    { 
     // mostrar valor 
        IO_printf ( "%d: %d\n", y, (2*y-1) ); 
     // calcular o produto 
        produto = produto * (2*y-1); 
    } // end for 
 // retornar resultado 
    return ( produto ); 
} 
void metodo01a ( int x )
{
 // identificar
    printf ( "\n%s\n", "Metodo01a" );
 // definir dado local 
    int y = 1;  // controle 
 
 // repetir enquanto controle menor que a quantidade desejada 
    while ( y <= x ) 
    { 
     // mostrar valor 
        IO_printf ( "%s%d\n", "Valor = ", y ); 
     // passar ao proximo 
        y = y + 1; 
    } // end if 
}
void metodo01 (void)
{
 // identificar 
    IO_id ( " Metodo01" ); 
 
 // executar o metodo auxiliar 
    metodo01a ( 5 ); 
 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" );
}
void metodo02a ( int x ) 
{ 
 // definir dado local 
    int y = 1;  // controle 
    int z = 2; 
 
 // repetir enquanto controle menor que a quantidade desejada 
    while ( y <= x ) 
    { 
     // mostrar valor 
        IO_printf ( "%d: %d\n", y, z ); 
     // passar ao proximo par 
        z = z + 2; 
     // passar ao proximo valor controlado 
        y = y + 1; 
    } // end while 
}
void metodo02 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo02" );
 // executar o metodo auxiliar 
    metodo02a ( 5 ); 
 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" );
}
void metodo03a ( int x ) 
{ 
 // definir dado local 
    int y = 1;  // controle 
    int z = 0; 
 
 // repetir enquanto controle menor que a quantidade desejada 
    while ( y <= x ) 
    { 
     // vincular o valor a ser mostrado ao controle 
        z = 2 * y; 
     // mostrar valor 
        IO_printf ( "%d: %d\n", y, z ); 
     // passar ao proximo valor controlado 
        y = y + 1; 
    } // end while 
}
void metodo03 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo03" );
 // executar o metodo auxiliar 
    metodo03a ( 5 ); 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" );
}
void metodo04a ( int x ) 
{ 
 // definir dado local 
    int y = x;  // controle 
    int z = 0; 
 
 // repetir enquanto controle menor que a quantidade desejada 
    while ( y > 0 ) 
    { 
     // vincular o valor a ser mostrado ao controle 
        z = 2 * y; 
     // mostrar valor 
        IO_printf ( "%d: %d\n", y, z ); 
     // passar ao proximo valor controlado 
        y = y - 1; 
    } // end while 
}
void metodo04 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo04" );
 // executar o metodo auxiliar 
    metodo04a ( 5 ); 
 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
}
void metodo05a ( int x ) 
{ 
 // definir dado local 
    int y = 0;  // controle 
 
 // repetir enquanto controle menor que a quantidade desejada 
    for ( y = x; y > 0; y = y-1 ) 
    { 
     // mostrar valor 
        IO_printf ( "%d: %d\n", y, (2*y) ); 
    } // end for 
}
void metodo05 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo05" );
 // executar o metodo auxiliar 
    metodo05a ( 5 ); 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" );
}
void metodo06 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo06" );
 // definir dado 
    int soma = 0; 
 // chamar e receber resultado da funcao 
    soma = somarValores ( 5 ); 
 // mostrar resultado 
    IO_printf ( "soma de pares = %d\n", soma ); 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
}
void metodo07 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo07" );
 // definir dado 
    double soma = 0.0; 
 // chamar e receber resultado da funcao 
    soma = somarFracao1 ( 5 ); 
 // mostrar resultado 
    IO_printf ( "soma de fracoes = %lf\n", soma ); 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" );
}
void metodo08 ( void )
{
    // identificar
    printf ( "\n%s\n", "Metodo08" );
 // definir dado 
    double soma = 0.0; 
 // chamar e receber resultado da funcao 
    soma = somarFracao2 ( 5 ); 
 
 // mostrar resultado 
    IO_printf ( "soma de fracoes = %lf\n", soma ); 
 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" );
}
void metodo09 ( void )
{
 // definir dado 
    double soma = 0.0; 
 
 // identificar 
    IO_id ( "Metodo09" ); 
 
 // chamar e receber resultado da funcao 
    soma = somarFracao3 ( 5 ); 
 
 // mostrar resultado 
    IO_printf ( "soma de fracoes = %lf\n", soma ); 
 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
}
void metodo10 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo10" );
// mostrar produto de valores 
IO_printf ( "%s%d\n", "produto = ", multiplicarValores ( 5 )  ); 
// encerrar 
IO_pause ( "Apertar ENTER para continuar" );
}

int main ( void )
{
    int opcao = 0;
    do
    {
        printf ( "\n" );        
        printf ( "%s\n", " - 15/09/2024"       );
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
