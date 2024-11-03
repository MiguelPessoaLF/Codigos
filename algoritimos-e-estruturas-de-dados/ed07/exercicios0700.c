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
void fm3 (chars fileName, int valor)
{
   FILE* arquivo = fopen ( fileName, "wt");
   int y = 0;
   int z = 3;
   for (y = 0;
        y <= valor - 1;
        y = y + 1
       )
       {
         if (z % 2 != 0)
         {
            fprintf (arquivo, "%d\n", z);
         }
         else
         {
            y = y - 1;
         }
         z = z + 3;
       }
       fclose (arquivo);
}
void metodo01 ( void )
{
   int valor = 0;
 // identificar
    printf ( "\n%s\n", "Metodo01" );
   printf ("entrar com um valor:");
   scanf("%d",&valor);
   fm3 ("fm3.txt", valor);
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
}
void fm6 (chars fileName, int valor)
{
   FILE* arquivo = fopen ( fileName, "wt");
   int y = 0;
   int z = valor * 6 + 30;
   for (
        y = 0;
        y <= valor;
        y = y + 1
       )
       {
         if (z % 2 == 0)
         {
            fprintf (arquivo, "%d\n", z);
         }
         else
         {
            y = y - 1;
         }
         z = z - 6;
       }
       fclose (arquivo);
}
void metodo02 ( void )
{
   int valor = 0;
 // identificar
   printf ( "\n%s\n", "Metodo02" );
   printf ("entrar com um valor:");
   scanf("%d", &valor);
   fm6 ("fm6.txt", valor);
 // encerrar
   printf ( "\n%s\n", "Apertar ENTER para continuar." );
   getchar( );
}
void fm4 (chars fileName, int valor)
{
   FILE* arquivo = fopen ( fileName, "wt");
   int y = 0;
   int z = 1;
   for (
        y = 0;
        y <= valor - 1;
        y = y + 1
       )
       {
         fprintf (arquivo, "%d\n", z);
         z = z * 4;
       }
       fclose (arquivo);
}
void metodo03 ( void )
{
   int valor = 0;
 // identificar
   printf ( "\n%s\n", "Metodo03" );
   printf ("entrar com um valor:");
   scanf("%d", &valor);
   fm4 ("fm4.txt", valor);
 // encerrar
   printf ( "\n%s\n", "Apertar ENTER para continuar." );
   getchar( );
}
void fm4d (chars fileName, int valor)
{
   FILE* arquivo = fopen ( fileName, "wt");
   int y = 0;
   double z = pow(4,valor - 1);
   for (
        y = 0;
        y <= valor - 1;
        y = y + 1
       )
       {
            fprintf (arquivo, "%lf\n", 1/z);
            z = z / 4;
       }
       fclose (arquivo);
}
void metodo04 ( void )
{
   int valor = 0;
 // identificar
   printf ( "\n%s\n", "Metodo04" );
   printf ("entrar com um valor:");
   scanf("%d", &valor);
   fm4d ("fm4d.txt", valor);
 // encerrar
   printf ( "\n%s\n", "Apertar ENTER para continuar." );
   getchar( );
}
void fm2 (chars fileName, int valor, int x)
{
   FILE* arquivo = fopen ( fileName, "wt");
   int y = 0;
   double z = 0;
   double o = 1;
   for (
        y = 0;
        y <= valor - 1;
        y = y + 1
       )
       {
            fprintf (arquivo, "%lf\n", 1/o);
            z = z + 2;
            o = pow( x , z );
       }
       fclose (arquivo);
}
void metodo05 ( void )
{
   int valor = 0;
   int x = 0;
 // identificar
   printf ( "\n%s\n", "Metodo05" );
   printf ("entrar com um valor:");
   scanf("%d", &valor);
   printf ("entrar com outro valor:");
   scanf("%d", &x);
   fm2 ("fm2.txt", valor, x);
 // encerrar
   printf ( "\n%s\n", "Apertar ENTER para continuar." );
   getchar( );
}
void fm2b (chars fileName, int valor, int x, int soma)
{
   FILE* arquivo = fopen ( fileName, "wt");
   int y = 0;
   double z = 0;
   double o = 1;
   for (
        y = 0;
        y <= valor - 1;
        y = y + 1
       )
       {
            fprintf (arquivo, "%lf\n", 1/o + soma);
            z = z + 2;
            o = pow( x , z );
       }
       fclose (arquivo);
}
void metodo06 ( void )
{
   int valor = 0;
   int x = 0;
   int soma = 0;
 // identificar
   printf ( "\n%s\n", "Metodo06" );
   printf ("entrar com um valor:");
   scanf("%d", &valor);
   printf ("entrar com outro valor:");
   scanf("%d", &x);
   printf ("entrar com outro valor para somar:");
   scanf("%d", &soma);
   fm2b ("fm2b.txt", valor, x, soma);
 // encerrar
   printf ( "\n%s\n", "Apertar ENTER para continuar." );
   getchar( );
}
void metodo07 ( void )
{
  int valor = 0;
 // identificar
   printf ( "\n%s\n", "Metodo07" );
   printf ("entrar com um valor:");
   scanf("%d", &valor);
   fm4d ("fm4d2.txt", valor);
 // encerrar
   printf ( "\n%s\n", "Apertar ENTER para continuar." );
   getchar( );

}
void fmf (chars fileName, int valor)
{
   FILE* arquivo = fopen ( fileName, "wt");
   int y = 0;
   int z = 0;
   int o = 1;
   int x = 0;
      for (
        y = 0;
        y <= valor - 1;
        y = y + 1
       )
       {
            x = o + z;
            fprintf (arquivo, "%d\n", x);
            o = z;
            z = x;
       }
       fclose (arquivo);
}
void metodo08 ( void )
{
   int valor = 0;
   int x = 0;
 // identificar
   printf ( "\n%s\n", "Metodo08" );
   printf ("entrar com um valor:");
   scanf("%d", &valor);
   fmf ("fmf.txt", valor);
 // encerrar
   printf ( "\n%s\n", "Apertar ENTER para continuar." );
   getchar( );
}
void cm (chars fileName, char * cadeia)
{
   FILE* arquivo = fopen ( fileName, "wt");
   int posicao = 0;
   for (
      posicao = 0;
      posicao < strlen(cadeia);
      posicao = posicao + 1
   )
   {
      if (isalpha(cadeia[posicao]))
      {
         if (cadeia[posicao] >= 'a' && cadeia[posicao] <= 'z')
         {
            fprintf ( arquivo, "%c\n", (cadeia[posicao]));
         }
      }
   }
   fclose ( arquivo );
}
void metodo09 ( void )
{
 // identificar
   printf ( "\n%s\n", "Metodo09" );
   char cadeia[80];
   printf ("entrar com uma cadeia:");
   scanf("%s", cadeia);
   cm ("cm.txt", cadeia);
 // encerrar
   printf ( "\n%s\n", "Apertar ENTER para continuar." );
   getchar( );
}
void c4 (chars fileName, char * cadeia)
{
   FILE* arquivo = fopen ( fileName, "wt");
   int posicao = 0;
   for (
      posicao = 0;
      posicao < strlen(cadeia);
      posicao = posicao + 1
   )
   {
      if (isdigit(cadeia[posicao]))
      {
         if ((cadeia[posicao]) <= '4' )
         {
            fprintf ( arquivo, "%c\n", (cadeia[posicao]));
         }
      }
   }
   fclose ( arquivo );
}
void metodo10 ( void )
{
 // identificar
   printf ( "\n%s\n", "Metodo10" );
   char cadeia[80];
   printf ("entrar com uma cadeia:");
   scanf("%s", cadeia);
   c4 ("c4.txt", cadeia);
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
        printf ( "%s\n", " - 09/09/2024"       );
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