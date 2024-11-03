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
void method_01a ( int x ) 
{ 
    if ( x > 0 ) 
    { 
     // mostrar valor 
        IO_printf ( "%s%d\n", "Valor = ", x ); 
     // passar ao proximo 
        method_01a ( x - 1 ); // motor da recursividade 
    }
}
void metodo01 ( void )
{
 // definir dado 
    int quantidade = 0; 
    int valor      = 0; 
    int controle   = 0; 
 // identificar 
    IO_id ( "Metodo01" ); 
    method_01a ( 5 );
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" );
}
void method_02a ( int x ) 
{ 
    if ( x > 0 ) 
    { 
     // mostrar valor  
        IO_printf ( "%s%d\n", "Valor = ", x ); 
     // passar ao proximo 
        method_02a ( x - 1 );
     // mostrar valor 
        IO_printf ( "%s%d\n", "Valor = ", x ); 
    }
}
void metodo02 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo02" );
    method_02a ( 5 );
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" );
}
void method_03a ( int x ) 
{  
    if ( x > 1 ) 
    { 
     // passar ao proximo 
        method_03a ( x - 1 );
     // mostrar valor 
        IO_printf ( "%s%d\n", "Valor = ", x ); 
    } 
    else 
    { 
        IO_printf ( "%s\n", "Valor = 1" ); 
    }
}
void metodo03 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo03" );
    method_03a ( 5 );
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" );
}
void method_04a ( int x ) 
{ 
    if ( x > 1 ) 
    { 
     // passar ao proximo 
        method_04a ( x - 1 );
     // mostrar valor 
        IO_printf ( "%s%d\n", "Valor = ", 2*(x-1) ); 
    } 
    else 
    { 
        IO_printf ( "%s\n", "Valor = 1" ); 
    }
}
void metodo04 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo04" );
 // executar o metodo auxiliar 
    method_04a ( 5 );  // motor da recursividade 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" );
}
void method_05a ( int x ) 
{ 
    if ( x > 1 ) 
    { 
           // mostrar valor 
        IO_printf ( "%d: %d/%d\n", x, (2*(x-1)), (2*(x-1)+1) ); 
     // passar ao proximo 
        method_05a ( x - 1 );
     // mostrar valor 
        IO_printf ( "%d: %d/%d\n", x, (2*(x-1)), (2*(x-1)+1) ); 
    } 
    else 
    {
        IO_printf ( "%d; %d\n", x, 1 ); 
    }
}
void metodo05 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo05" ); 
    method_05a ( 5 );
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" );
}
double somarFracoes ( int x ) 
{ 
 // definir dado local 
    double soma = 0.0; 
    if ( x > 1 ) 
    {  
      // mostrar valor 
        IO_printf ( "%d: %lf/%lf\n", x, (2.0*(x-1)), (2.0*(x-1)+1) ); 
        soma = (2.0*(x-1))/(2.0*(x-1)+1) + somarFracoes ( x - 1 ); 
     // mostrar valor 
        IO_printf ( "%d: %lf/%lf\n", x, (2.0*(x-1)), (2.0*(x-1)+1) ); 
    } 
    else 
    { 
        soma = 1.0; 
     // mostrar o ultimo 
        IO_printf ( "%d; %lf\n", x, 1.0 ); 
    } 
    return ( soma ); 
}
void metodo06 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo06" );
 // definir dado 
    double soma = 0.0; 
    soma = somarFracoes ( 5 ); 
 // mostrar resultado 
    IO_printf ( "soma = %lf\n", soma ); 
 // encerrar
    IO_pause ( "Apertar ENTER para continuar" ); 
}
double somarFracoes2b ( int x, double soma, double numerador, double denominador ) 
{ 
    if ( x > 0 ) 
    { 
     // mostrar valores atuais 
        IO_printf ( "%d: %lf/%lf\n", x, numerador, denominador ); 
     // somar o termo atual e passar ao proximo (motor da recursividade) 
        soma = somarFracoes2b ( x - 1,soma + (( 1.0 * numerador) / denominador), numerador + 2.0, denominador + 2.0  );                             
    }
 // retornar resultado 
    return ( soma ); 
}
double somarFracoes2a ( int x ) 
{ 
 // definir dado local 
    double soma = 0.0; 
    if ( x > 0 ) 
    { 
        IO_printf ( "%d: %lf\n", x, 1.0 ); 
        soma = somarFracoes2b ( x-1, 1.0, 2.0, 3.0 ); 
    }
 // retornar resultado 
    return ( soma ); 
}
void metodo07 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo07" );
 // definir dado 
    double soma = 0.0; 
 // chamar a funcao e receber o resultado 
    soma = somarFracoes2a ( 5 ); 
 // mostrar resultado 
    IO_printf ( "soma = %lf\n", soma ); 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" );

}
int contarDigitos ( int x ) 
{ 
 // definir dado 
    int resposta = 1;
    if ( x >= 10 ) 
    {  
        resposta = 1 + contarDigitos ( x/10 ); // motor 1 
    } 
    else 
    { 
        if ( x < 0 ) 
        { 
            resposta = contarDigitos ( -x ); // motor 2 
        } 
    }
    return ( resposta ); 
}
void metodo08 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo08" );
 // mostrar resultado 
    IO_printf ( "digitos (%3d) = %d\n", 123, contarDigitos (123) ); 
    IO_printf ( "digitos (%3d) = %d\n",   1  , contarDigitos (  1  ) ); 
    IO_printf ( "digitos (%3d) = %d\n", -10, contarDigitos ( -10 ) ); 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" );
}
int fibonacci ( int x ) 
{ 
 // definir dado 
    int resposta = 0; 
 // testar se contador valido 
    if ( x == 1 || x == 2 ) 
    { 
        resposta = 1; 
    } 
    else 
    { 
        if ( x > 1 ) 
        { 
         // fazer de novo com valor absoluto 
            resposta = fibonacci ( x-1 ) + fibonacci ( x-2 ); 
        }
    }
    return ( resposta ); 
}
void metodo09 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo09" );
 // calcular numero de Fibonacci 
    IO_printf ( "fibonacci (%d) = %d\n", 1, fibonacci ( 1 ) ); 
    IO_printf ( "fibonacci (%d) = %d\n", 2, fibonacci ( 2 ) ); 
    IO_printf ( "fibonacci (%d) = %d\n", 3, fibonacci ( 3 ) ); 
    IO_printf ( "fibonacci (%d) = %d\n", 4, fibonacci ( 4 ) ); 
    IO_printf ( "fibonacci (%d) = %d\n", 5, fibonacci ( 5 ) ); 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" );
}
int contarMinusculas ( chars cadeia, int x ) 
{ 
 // definir dado 
    int resposta = 0; 
    if ( 0 <= x && x < strlen ( cadeia ) ) 
    { 
     // testar se letra minuscula 
        if ( cadeia [x] >= 'a' && 
             cadeia [x] <= 'z' ) 
        { 
         // fazer de novo com valor absoluto 
            resposta = 1; 
        }
        resposta = resposta + contarMinusculas ( cadeia, x+1 ); 
    } 
    return ( resposta ); 
}
void metodo10 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo10" );
// contar minusculas em cadeias de caracteres 
IO_printf ( "Minusculas (\"abc\",0)  = %d\n", contarMinusculas ( "abc", 0 ) ); 
IO_printf ( "Minusculas (\"aBc\",0)  = %d\n", contarMinusculas ( "aBc", 0 ) ); 
IO_printf ( "Minusculas (\"AbC\",0) = %d\n", contarMinusculas ( "AbC", 0 ) ); 
// encerrar 
IO_pause ( "Apertar ENTER para continuar" );

}

int main ( void )
{
    int opcao = 0;
    do
    {
        printf ( "\n" );        
        printf ( "%s\n", " - 25/09/2024"       );
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
