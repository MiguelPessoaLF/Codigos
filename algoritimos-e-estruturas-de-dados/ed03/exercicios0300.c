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
bool maiuscula (char c )
{
   return (c >= 'A' && c <= 'Z');
}
bool minuscula (char c )
{
   return (c >= 'a' && c <= 'z');
}
bool numero (char c)
{
   return (c >= '0' && c <= '9');
}
void metodo01 ( void )
{
//identificar
printf ( "\n%s\n", "Metodo01" );
//definir variavel
int valor = 0;
int quantidade = 0;
int posicao = 0;
int maiusculas = 0;
char palavra [80];
//ler dados
printf ( "%s", "escreva uma palavra:" );
scanf  ( "%s", palavra          ); getchar ( );
//ler quantidade de digitos 
quantidade = strlen ( palavra );
while ( quantidade > posicao )
{
valor = palavra [posicao];
//filtrar
   if ( 'A' <= valor && valor <= 'Z' )
   {
    IO_printf ( "%d: [%c]\n", posicao, palavra  [posicao] ); 
   }
//passar para a proxima letra
posicao = posicao + 1;
}//end while
// encerrar
    IO_pause ("Aperte ENTER para terminar");
}
void metodo02 ( void )
{
//identificar
printf ( "\n%s\n", "Metodo02" );
//definir variavel
int valor = 0;
int quantidade = 0;
int posicao = 0;
int minusculas = 0;
char palavra [80];
//ler dados
printf ( "%s", "escreva uma palavra:" );
scanf  ( "%s", palavra          ); getchar ( );
//ler quantidade de digitos 
quantidade = strlen ( palavra );
while ( quantidade > posicao )
{
valor = palavra [posicao];
//filtrar
   if ( 'a' <= valor && valor <= 'z' )
   {
    IO_printf ( "%d: [%c]\n", posicao, palavra  [posicao] ); 
    minusculas = minusculas + 1;
   }
//passar para a proxima letra
posicao = posicao + 1;
}//end while
printf ( "%s%d", "letras minusculas: ", minusculas );
// encerrar
    IO_pause ("Aperte ENTER para terminar");
}
void metodo03 ( void )
{
   //identificar
printf ( "\n%s\n", "Metodo03" );
//definir variavel
int valor = 0;
int quantidade = 0;
int posicao = 0;
int minusculas = 0;
char palavra [80];
//ler dados
printf ( "%s", "escreva uma palavra:" );
scanf  ( "%s", palavra          ); getchar ( );
//ler quantidade de digitos 
quantidade = strlen ( palavra );
posicao = quantidade;
while ( posicao >= 0)
{
valor = palavra [posicao];
//filtrar
   if ( 'a' <= valor && valor <= 'z' )
   {
    IO_printf ( "%d: [%c]\n", posicao, palavra  [posicao] ); 
    minusculas = minusculas + 1;
   }
//passar para a proxima letra
posicao = posicao - 1;
}//end while
printf ( "%s%d", "letras minusculas: ", minusculas );
// encerrar
    IO_pause ("Aperte ENTER para terminar");
}
void metodo04 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo04" );
//definir variavel
int valor = 0;
int quantidade = 0;
int posicao = 0;
int minusculas = 0;
int maiusculas = 0;
int simbolos = 0;
char palavra [80];
//ler dados
printf ( "%s", "escreva uma palavra:" );
scanf  ( "%s", palavra          ); getchar ( );
//ler quantidade de digitos 
quantidade = strlen ( palavra );
while ( quantidade > posicao)
{
valor = palavra [posicao];
//filtrar
   if ( 'a' <= valor && valor <= 'z' )
   {
    IO_printf ( "%d: [%c]\n", posicao, palavra  [posicao] ); 
    minusculas = minusculas + 1;
   }
   else 
   {
      if ('A' <= valor && valor <= 'Z' )
   {
    IO_printf ( "%d: [%c]\n", posicao, palavra  [posicao] ); 

    maiusculas = maiusculas + 1;
   }
   else
   {
      IO_printf ( "%d: [%c]\n", posicao, palavra  [posicao]);
      simbolos = simbolos + 1;
   }
   }
//passar para a proxima letra
posicao = posicao + 1;
}//end while
   printf ( "%s%d\n", "letras minusculas: ", minusculas );
   printf ( "%s%d\n", "letras maiusculas: ", maiusculas );
   printf ( "%s%d\n", "simbolos: ", simbolos );
// encerrar
    IO_pause ("Aperte ENTER para terminar");
}
void metodo05 ( void )
{
//identificar
printf ( "\n%s\n", "Metodo03" );
    //definir dados / resultados
    int letras = 0;
    int posicao = 0;
    int maiusculas = 0;
    int minusculas = 0;
    int contador = 0;
    int digitos = 0;
    char simbolos = '!';
    char cadeia [80];
    //acoes
        //ler dado
        printf ("%s", "Entrar com uma palavra: ");
        scanf ("%s", cadeia); getchar ();
        //mapear e mostrar cada caractere
        for (posicao = 0;
             posicao < strlen(cadeia);
             posicao = posicao + 1)
        {
         printf ( "%d %c", posicao, cadeia[posicao]);
         if (maiuscula (cadeia[posicao]))
         {
            printf ("%s\n", " maiuscula");
            maiusculas = maiusculas + 1;
         }
         else
         {
            if (minuscula (cadeia[posicao]))
            {
            printf ("%s\n", " minusculas");
            minusculas = minusculas + 1;
            }
            else
             {
               if (!isalpha (simbolos))
               {
               printf ("%c\n", "simbolo", simbolos);
               contador++;
               }
             }
         }
         }   
   //mostrar a quantidade de letras maiusculas
   printf ("%s%d\n", "minusculas = ", minusculas);
   printf ("%s%d\n", "maiusculas = ", maiusculas);
   printf ("%s%d\n", "simbolos = ", contador);
   //contar as letras
   letras = maiusculas + minusculas;
   digitos = maiusculas + minusculas + contador;
   //mostrar a quantidade de letras 
   printf ("%s%d\n", "letras = ", letras);
   printf ("%s%d\n", "digitos = ", digitos);
    // encerrar
   IO_pause ("aperte ENTER para continuar");
}//end metodo
void metodo06 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo06" );
    //definir dados / resultados
    int posicao = 0;
    int contador = 0;
    int digitos = 0;
    char simbolos = '!';
    char cadeia [80];
    //acoes
        //ler dado
        printf ("%s", "Entrar com uma palavra: ");
        scanf ("%s", cadeia); getchar ();
        //mapear e mostrar cada caractere
        for (posicao = 0;
             posicao < strlen(cadeia);
             posicao = posicao + 1)
        {
         printf ( "%d %c", posicao, cadeia[posicao]);
         if (maiuscula (cadeia[posicao]))
         {
            printf ("");
         }
         else
         {
            if (minuscula (cadeia[posicao]))
            {
               printf ("");
            }
            else
            {
               if (numero (cadeia[posicao]))
               {
                  printf ("");
               }
                else (!isalpha (simbolos));
                {
                printf ("%c\n", "simbolo", simbolos);
                contador++;
                }
            }
         }
        }
   //mostrar a quantidade de letras maiusculas
   printf ("%s%d\n", "simbolos = ", contador);
   //nao consegui :(
// encerrar
    IO_pause ("Aperte ENTER para terminar");
}
void metodo07 ( void )
{
   // identificar
    printf ( "\n%s\n", "Metodo07" );
    int inferior = 0; 
    int superior = 0; 
    int passo = 0; 
    int x = 0; 
    inferior = IO_readint ( "Limite inferior do intervalo : " ); 
    do 
    { 
        superior = IO_readint ( "Limite superior do intervalo: " ); 
    } 
    while ( inferior >= superior ); 
    do 
    { 
        passo = IO_readint ( "Variacao no intervalo (passo): " ); 
    } 
    while ( passo <= 0 ); 
    for ( x  = inferior; x <= superior; x = x + passo) 
    {
      if (x % 5 == 0)
      { 
        IO_printf ( "%d\n", x ); 
      }
    }
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" );
}
void metodo08 ( void )
{
// identificar
    printf ( "\n%s\n", "Metodo08" );
    int inferior = 0; 
    int superior = 0; 
    int passo = 0; 
    int x = 0; 
    inferior = IO_readint ( "Limite inferior do intervalo : " ); 
    do 
    { 
        superior = IO_readint ( "Limite superior do intervalo: " ); 
    } 
    while ( inferior >= superior ); 
    do 
    { 
        passo = IO_readint ( "Variacao no intervalo (passo): " ); 
    } 
    while ( passo <= 0 ); 
    for ( x  = inferior; x <= superior; x = x + passo) 
    {
      if (x % 5 == 0)
      {
         printf ("");
      }
      else if (x % 3 == 0)
      {
         IO_printf ( "%d\n", x ); 
      }
    }   
    // encerrar
    IO_pause ("Apertar ENTER para continuar");
}
void metodo09 ( void )
{
// identificar
    printf ( "\n%s\n", "Metodo08" );
    double inferior = 0.0; 
    double superior = 0.0; 
    double passo = 0.0; 
    int x = 0; 
    inferior = IO_readdouble ( "Limite inferior do intervalo : " ); 
    do 
    { 
        superior = IO_readdouble ( "Limite superior do intervalo: " ); 
    } 
    while ( inferior >= superior ); 
    do 
    { 
        passo = IO_readdouble ( "Variacao no intervalo (passo): " ); 
    } 
    while ( passo <= 0 ); 
    for ( passo  = inferior; passo <= superior; passo = passo + passo) 
    {
      if (x % 2 != 0)
      {
         IO_printf ( "%d\n", x ); 
      }
    }   
    // encerrar
    IO_pause ("Apertar ENTER para continuar");
}
void metodo10 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo10" );
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
//tentei algumas vezes e não consegui
}

int main ( void )
{
    int opcao = 0;
    do
    {
        printf ( "\n" );        
        printf ( "%s\n", " - 27/08/2024"       );
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
