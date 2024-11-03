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
bool minuscula (char c )
{
   return (c >= 'a' && c <= 'z');
}
bool maiuscula (char c )
{
   return (c >= 'A' && c <= 'Z');
}
bool m (char c )
{
   return (c >= 'a' && c <= 'm');
}
bool M (char c )
{
   return (c >= 'A' && c <= 'M');
}
bool par (int x)
{
   return (x % 2 == 0);
}
bool impar (int x)
{
   return (x % 2 == 1);
}
bool letra (char c)
{
   return (isalpha(c));
}
int DI(const char *str) {
    int contagem = 0;
    while (*str) 
    {
        if (isdigit(*str)) 
        {
            int digito = *str - '0'; 
            if (digito % 2 != 0) 
            { 
                contagem++;
            }
        }
        str++; 
    }
    return contagem;
}
void metodo01 ( void )
{
int quantidade = 0;
double superior = 0.0;
double inferior = 0.0;
int controle = 0;
double valor = 0.0;
// identificar
printf ( "\n%s\n", "Metodo01" );
//ler quantidade
quantidade = IO_readint ("qual a quantidade?\n");
//ler superior
inferior = IO_readdouble ("qual o limite inferior?\n");
//ler inferior
superior = IO_readdouble ("qual o limite superior?\n");
//descobrir o valor
controle = 1;
while (controle <= quantidade)
{
   valor = IO_readdouble ( IO_concat ( IO_concat ( "", IO_toString_d ( controle ) ),": "  ) );
   if ( valor >= inferior && valor <= superior )
   {
      printf ("%s%f\n", "valor dentro do intervalo: ", valor );
   }
      else
      {
      printf ("%s%f\n", "valor fora do intervalo: ", valor );
      }
   controle = controle + 1;
}
//finalizar
IO_pause ("Aperte Enter para continuar");
}
void metodo02 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo02" );
char cadeia[80];
int posicao = 0;
int quantidade = 0;
int valor = 0;
//ler cadeia de caracteres
printf ("%s", "Entrar com uma cadeia de caracteres: ");
        scanf ("%s", cadeia); getchar ();
//lidar com valores
for (posicao = 0;
     posicao < strlen(cadeia);
     posicao = posicao + 1)
{
   valor = cadeia [posicao];
   if (maiuscula (cadeia[posicao]))
   {
      printf (""); 
   }
   else
   { 
      if (valor >= 'a' && valor <= 'm')
      {
      IO_printf ( "%d: [%c] Letra menos que m \n", posicao, cadeia [posicao] ); 
      }
   }
}
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
}
void metodo03 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo03" );
char cadeia[80];
int posicao = 0;
int quantidade = 0;
int valor = 0;
//ler cadeia de caracteres
printf ("%s", "Entrar com uma cadeia de caracteres: ");
        scanf ("%s", cadeia); getchar ();
//lidar com valores
for (posicao = 0;
     posicao < strlen(cadeia);
     posicao = posicao + 1)
{
   valor = cadeia [posicao];
   if (maiuscula (cadeia[posicao]))
   {
      printf (""); 
   }
   else
   { 
      if (m(cadeia[posicao]))
      {
      IO_printf ( "%d: [%c]\n", posicao, cadeia [posicao] ); 
      quantidade = quantidade + 1;
      }
   }
}
 //mostrar quantidade
 printf ("\n%s%d", "Quantidades de letras minusculas menores que m: ", quantidade);
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
}
void metodo04 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo04" );
char cadeia[80];
int posicao = 0;
int quantidade = 0;
int valor = 0;
//ler cadeia de caracteres
printf ("%s", "Entrar com uma cadeia de caracteres: ");
        scanf ("%s", cadeia); getchar ();
//lidar com valores
for (posicao = 0;
     posicao < strlen(cadeia);
     posicao = posicao + 1)
{
   valor = cadeia [posicao];
   if (maiuscula (cadeia[posicao]))
   {
      printf (""); 
   }
   else
   { 
      if (m(cadeia[posicao]))
      {
      IO_printf ( "[%c],", cadeia [posicao] ); 
      quantidade = quantidade + 1;
      }
   }
}
 //mostrar quantidade
 printf ("\n%s%d", "Quantidades de letras minusculas menores que m: ", quantidade);
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
}
void metodo05 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo05" );
char cadeia[80];
int posicao = 0;
int quantidade = 0;
int valor = 0;
//ler cadeia de caracteres
printf ("%s", "Entrar com uma cadeia de caracteres: ");
        scanf ("%s", cadeia); getchar ();
//lidar com valores
for (posicao = 0;
     posicao < strlen(cadeia);
     posicao = posicao + 1)
{
      if (m(cadeia[posicao]))
      {
      quantidade = quantidade + 1;
      }
      else
      {
         if (M(cadeia[posicao]))
         {
         quantidade = quantidade + 1;
         }
      }
}
 //mostrar quantidade
 printf ("\n%s%d", "Quantidades de letras minusculas menores que m: ", quantidade);
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
}
void metodo06 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo06" );
char cadeia[80];
int posicao = 0;
int quantidade = 0;
int valor = 0;
//ler cadeia de caracteres
printf ("%s", "Entrar com uma cadeia de caracteres: ");
        scanf ("%s", cadeia); getchar ();
//lidar com valores
for (posicao = 0;
     posicao < strlen(cadeia);
     posicao = posicao + 1)
{
      if (m(cadeia[posicao]))
      {
      IO_printf ( "%d: [%c]\n", posicao, cadeia [posicao] ); 
      quantidade = quantidade + 1;
      }
      else
      {
         if (M(cadeia[posicao]))
         {
         IO_printf ( "%d: [%c]\n", posicao, cadeia [posicao] ); 
         quantidade = quantidade + 1;
         }
      }
}
 //mostrar quantidade
 printf ("\n%s%d", "Quantidades de letras minusculas menores que m: ", quantidade);
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
}
void metodo07 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo07" );
char cadeiad [80];
int posicao = 0;
int quantidade = 0;
int valor = 0;
int x = 0;
//ler cadeia de caracteres
printf ("%s", "Entrar com uma cadeia de caracteres: ");
        scanf ("%s", &cadeiad); getchar ();
//lidar com valores
quantidade = DI (cadeiad);
//mostrar dados
printf ("%s%d", "digitos impares = ", quantidade);
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
}
void metodo08 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo08" );
char cadeia[80];
int posicao = 0;
int quantidade = 0;
int valor = 0;
//ler cadeia de caracteres
printf ("%s", "Entrar com uma cadeia de caracteres: ");
        scanf ("%s", cadeia); getchar ();
//lidar com valores
for (posicao = 0;
     posicao < strlen(cadeia);
     posicao = posicao + 1)
    {
      if (isdigit(cadeia[posicao]))
      {
         printf("");
      }
      else
      {
         if (letra(cadeia[posicao]))
         {
            printf("");
         }
         else
         {
            IO_printf ( "%d: [%c]\n", posicao, cadeia [posicao] ); 
         }
      }
    }
//encerrar
printf ( "\n%s\n", "Apertar ENTER para continuar." );
getchar( );
}
void metodo09 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo09" );
char cadeia[80];
int posicao = 0;
int quantidade = 0;
int valor = 0;
//ler cadeia de caracteres
printf ("%s", "Entrar com uma cadeia de caracteres: ");
        scanf ("%s", cadeia); getchar ();
//lidar com valores
for (posicao = 0;
     posicao < strlen(cadeia);
     posicao = posicao + 1)
    {
      if (isdigit(cadeia[posicao]))
      {
            IO_printf ( "%d: [%c]\n", posicao, cadeia [posicao] ); 
      }
      else
      {
         if (letra(cadeia[posicao]))
         {
            IO_printf ( "%d: [%c]\n", posicao, cadeia [posicao] ); 
         }
      }
    }
//encerrar
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
