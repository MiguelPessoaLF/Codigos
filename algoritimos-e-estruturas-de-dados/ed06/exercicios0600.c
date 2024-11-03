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
int m4 (int valor )
{
   int contador = 0;
   //definir contador
   contador = valor;
   if ( valor > 1)
   {
      contador = contador - 1;
      m4 ( valor - 1);
      printf ("%d: %d\n", contador, 4*(valor-1));
      getchar ();
   }
}
void metodo01 ( void )
{
   int valor = 0;
 // identificar
   printf ( "\n%s\n", "Metodo01" );
   printf ("%s", "entrar com um valor inteiro: ");
   scanf ("%d", &valor);
   m4 ( valor + 1);
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
}
int m4d (int valor, int contador )
{
   //definir contador
   if ( valor > 0 )
   {
      printf ("%d: %d\n", contador, valor);
      getchar ();
      m4d ( valor - 4, contador - 1);
   }
}
void metodo02 ( void )
{
  int valor = 0;
  int contador = 0;
 // identificar
   printf ( "\n%s\n", "Metodo02" );
   printf ("%s", "entrar com um valor inteiro: ");
   scanf ("%d", &valor);
   contador = valor;
   m4d ( valor * 4, contador);
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
}
int d4 (int valor, int contador )
{ 
   if ( contador >= valor + 1)
   {
      return(0);
   }
   int divisor = contador * 4;
   if (contador == 0)
   {
      printf ("");
   }
   else
   {
      printf ("%d: %.5lf\n", contador, 1.0 / divisor);
      getchar ();
   }
   d4 (valor, contador + 1);
}
void metodo03 ( void )
{
   int valor = 0;
 // identificar
   printf ( "\n%s\n", "Metodo03" );
   printf ("%s", "entrar com um valor inteiro: ");
   scanf ("%d", &valor);
   d4 ( valor, 0);
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
}
int d4i (int valor, int contador )
{ 
   if ( contador <= 0)
   {
      return(0);
   }
   if (contador == 0)
   {
      printf ("");
   }
   else
   {
      printf ("%d: %.5lf\n", contador, 1.0 / valor);
      getchar ();
      d4i (valor - 4, contador - 1);
   }
}
void metodo04 ( void )
{
   int valor = 0;
   int contador = 0;
 // identificar
   printf ( "\n%s\n", "Metodo03" );
   printf ("%s", "entrar com um valor inteiro: ");
   scanf ("%d", &valor);
   contador = valor;
   valor = valor * 4;
   d4i ( valor, contador);
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
}
int m4s (int valor, int contador, int y, int par, int o)
{
   //definir contador
   if ( valor > 0)
   {
      printf ("%d: %d", contador, o);
      o = o - 4;
      y = par + 4;
      o = o + y;
      getchar ();
      m4s (valor - 1, contador + 1, y, par + 2, o);
   }
}
void metodo05 ( void )
{
   int valor = 0;
 // identificar
   printf ( "\n%s\n", "Metodo05" );
   printf ("%s", "entrar com um valor inteiro: ");
   scanf ("%d", &valor);
   getchar ();
   m4s ( valor, 1, 0, 2, 4 );
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
}
double m4ds (int valor, int contador, double y, double par, double o, double z)
{
   //definir contador
   if ( valor > 0)
   {
      printf ("%d: %.5lf", contador, z);
      o = o - 4.0;
      y = par + 4.0;
      o = o + y;
      z = 1.0 / o;
      getchar ();
      m4ds (valor - 1, contador + 1, y, par + 2, o, z);
   }
}
void metodo06 ( void )
{
   int valor = 0;
   double z = 1.0 / 4.0;
 // identificar
   printf ( "\n%s\n", "Metodo06" );
   printf ("%s", "entrar com um valor inteiro: ");
   scanf ("%d", &valor);
   getchar ();
   m4ds ( valor, 1.0, 0.0, 2.0, 4.0, z);
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
}
char ps ( char * cadeia, int valor, int contador, int posicao)
{
   if (valor >= 0)
   {
      printf ("%d: %c\n", contador, (cadeia[posicao]));
      getchar ();
      ps (cadeia, valor - 1, contador + 1, posicao + 1);
   }
}
void metodo07 ( void )
{
   char cadeia[80];
   int posicao = 0;
 // identificar
   printf ( "\n%s\n", "Metodo07" );
   printf ("%s", "entrar com uma palavra: ");
   scanf ("%s", cadeia);
   int valor = strlen (cadeia);
   getchar ();
   ps (cadeia, valor - 1, 1, posicao);
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
}
char ip ( char * cadeia, int valor, int contador, int posicao, int impar)
{
   if (valor >= 0)
   {
      if (isdigit(cadeia[posicao]))
      {
         if ((cadeia[posicao]) % 2 != 0 )
         {
            impar = impar + 1;
            printf ("%d: %c\n", contador, (cadeia[posicao]));
            printf ("%s%d\n", "impares totais: ", impar);
            getchar ();
         }
      }
      ip (cadeia, valor - 1, contador + 1, posicao + 1, impar);
   }
}
void metodo08 ( void )
{
   char cadeia[80];
   int posicao = 0;
   int impar = 0;
 // identificar
   printf ( "\n%s\n", "Metodo08" );
   printf ("%s", "entrar com uma palavra: ");
   scanf ("%s", cadeia);
   int valor = strlen (cadeia);
   getchar ();
   ip (cadeia, valor - 1, 1, posicao, impar);
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
}
char mm ( char * cadeia, int valor, int contador, int posicao, int mai)
{
   if (valor >= 0)
   {
      if (isalpha(cadeia[posicao]))
      {
         if ((cadeia[posicao]) >= 'M' && (cadeia[posicao]) <= 'Z')
         {
            mai = mai + 1;
            printf ("%d: %c\n", contador, (cadeia[posicao]));
            printf ("%s%d\n", "maiusculas maiores que M totais: ", mai);
            getchar ();
         }
      }
      mm (cadeia, valor - 1, contador + 1, posicao + 1, mai);
   }
}
void metodo09 ( void )
{
   char cadeia[80];
   int posicao = 0;
   int mai = 0;
 // identificar
   printf ( "\n%s\n", "Metodo09" );
   printf ("%s", "entrar com uma palavra: ");
   scanf ("%s", cadeia);
   int valor = strlen (cadeia);
   getchar ();
   mm (cadeia, valor - 1, 1, posicao, mai);
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
}
void metodo10 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo10" );
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );

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
