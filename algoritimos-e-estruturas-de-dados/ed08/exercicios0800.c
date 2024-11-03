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
void metodo01 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo01" );
   char cadeia[80];
   int posicao = 0;
   printf ( "\n%s\n", "Digite uma cadeia de caracteres: " );
   scanf ("%s", cadeia);
   if (strlen(cadeia) <= 0)
   {
      printf ("cadeia invalida");
   }
   else
   {
      for (
            posicao = 0;
            posicao < strlen(cadeia);
            posicao = posicao + 1
          )
   {
      if (isdigit(cadeia[posicao]) && (cadeia[posicao]) >= 0 && (cadeia[posicao]) % 2 != 0)
      {
      printf ("%c\n", (cadeia[posicao]));
      getchar ();
      }
   }
   }
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
}
void metodo02 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo02" );
   char cadeia;
   FILE* arquivo = fopen ("metodo02.txt", "r");
      while ((cadeia = fgetc(arquivo)) != EOF)
      {
      if (isdigit(cadeia) && cadeia >= 0 && cadeia % 2 != 0)
         printf ("%c\n", cadeia);
      }
   fclose (arquivo);
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
}
int lr (const char* filename, int valor, int inferior, int superior, int contador)
{
   FILE* arquivo = fopen (filename, "w");
    for (
      contador = 0;
      contador < valor;
      contador = contador + 1
        )
        {
         int random = rand() % (superior - inferior + 1) + inferior;
         fprintf (arquivo, "%d\n",  random);
        }
        fclose(arquivo);
}
void metodo03 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo03" );
    int inferior = 0;
    int superior = 0;
    int valor = 0;
    int contador = 0;
    FILE* arquivo = fopen ("metodo03.txt", "w");
    printf ("entrar com um numero de dados: ");
    scanf ("%d", &valor);
    printf ("entrar com o valor inferior de um intervalo: ");
    scanf ("%d", &inferior);
    printf ("entrar com o valor superior de um intervalo: ");
    scanf ("%d", &superior);
    lr ("metodo03.txt", valor, inferior, superior, contador);
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
}
int i (const char* filename)
{
   int impar = 0;
   char cadeia;
   FILE* arquivo = fopen (filename, "r");
         while ((cadeia = fgetc(arquivo)) != EOF)
      {
      if (isdigit(cadeia) && cadeia % 2 != 0 && cadeia > impar)
      {  
         impar = cadeia;
      }
      }
   fclose (arquivo);
   return (impar);
}
void metodo04 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo04" );
    char resposta = i ("metodo04.txt");
   printf ("%c", resposta);
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
}
int im (const char* filename)
{
   int impar = 0;
   char cadeia;
   FILE* arquivo = fopen (filename, "r");
         while ((cadeia = fgetc(arquivo)) != EOF)
      {
      if (isdigit(cadeia) && cadeia % 2 == 0 && cadeia % 3 == 0 && cadeia > impar)
      {  
         impar = cadeia;
      }
      }
   fclose (arquivo);
   return (impar);
}
void metodo05 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo05" );
    char resposta =im ("metodo05.txt");
    printf ("%c", resposta);
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
}
int med (const char* filename)
{
   int soma = 0;
   int contador = 0;
   int media = 0;
   char cadeia;
   FILE* arquivo = fopen (filename, "r");
   while ((cadeia = fgetc(arquivo)) != EOF)
   {
      if (isdigit(cadeia))
      {
         contador = contador + 1;
         soma = soma + cadeia;
         media = soma / contador;
      }
   }
   fclose(arquivo);
   return(media);
}
int m (const char* filename)
{
   int impar = 0;
   char cadeia;
   int contador = 0;
   int soma = 0;
   FILE* arquivo1 = fopen (filename, "r");
   FILE* arquivo2 = fopen ("metodo06b.txt", "w");
   FILE* arquivo3 = fopen ("metodo06c.txt", "w");
   int media = med ("metodo06a.txt");
      while ((cadeia = fgetc(arquivo1)) != EOF)
      {
      if (isdigit(cadeia) && cadeia < media)
      {  
         fprintf (arquivo2, "%c", cadeia);
      }
      else if (isdigit(cadeia) && cadeia > media)
      {
         fprintf (arquivo3, "%c", cadeia);
      }
      }
   fclose (arquivo1);
      fclose (arquivo2);
         fclose (arquivo3);
}
void metodo06 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo06" );
    m ("metodo06a.txt");
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
}
//codigo mais lindo que ja fiz na vida
bool ordem (const char* filename)
{
   char cadeia;
   int tamanho = 0;
   FILE* arquivo = fopen (filename, "r");
         while ((cadeia = fgetc(arquivo)) != EOF)
      {
         tamanho = tamanho + 1;
      }
      fseek(arquivo, tamanho, SEEK_SET);
      while ((cadeia = fgetc(arquivo)) != EOF)
      {
      if (isdigit(cadeia) && cadeia - 1 < cadeia)
      {
         return (true);
      }
      }
   fclose (arquivo);
   return (false);
}
void metodo07 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo07" );
    if (ordem("metodo07.txt"))
    {
      printf ("esta ordenado.\n");
    }
    else
    {
      printf ("nao esta ordenado.\n");
    }
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
}
bool search (const char* filename, char valor, int posicao)
{
   char cadeia;
   FILE* arquivo = fopen (filename, "r");
   fseek(arquivo, posicao, SEEK_SET);
      while ((cadeia = fgetc(arquivo)) != EOF)
      {
      if (cadeia == valor)
      {  
         return (true);
      }
      }
   fclose (arquivo);
   return (false);
}
void metodo08 ( void )
{
   char valor = 0;
   int posicao = 0;
 // identificar
    printf ( "\n%s\n", "Metodo08" );
    printf ("Entrar com um valor a ser procurado: ");
    scanf("%c", &valor);
    printf ("Entrar com a posicao inicial: ");
    scanf("%d", &posicao);
    if (search ("metodo08.txt", valor, posicao - 1))
    {
      printf ("O valor foi encontrado.\n");
    }
    else
    {
      printf ("O valor nao foi encontrado.\n");
    }
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
}
int searchl (const char* filename, char valor, int posicao)
{
   char cadeia;
   int contador = 0;
   FILE* arquivo = fopen (filename, "r");
   fseek(arquivo, posicao, SEEK_SET);
      while ((cadeia = fgetc(arquivo)) != EOF)
      {
      contador = contador + 1;
      if (cadeia == valor)
      {  
         printf ("%d: %c\n", contador, cadeia);
      }
      else
      {
         printf ("%d: x\n", contador);
      }
      }
   fclose (arquivo);
}
void metodo09 ( void )
{
   char valor = 0;
   int posicao = 0;
 // identificar
    printf ( "\n%s\n", "Metodo09" );
    printf ("Entrar com um valor a ser procurado: ");
    scanf("%c", &valor);
    printf ("Entrar com a posicao inicial: ");
    scanf("%d", &posicao);
    searchl ("metodo09.txt", valor, posicao - 1);
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
}
int searchlv (const char* filename, char valor, int posicao)
{
   char cadeia;
   int contador = 0;
   int vezes = 0;
   FILE* arquivo = fopen (filename, "r");
   fseek(arquivo, posicao, SEEK_SET);
      while ((cadeia = fgetc(arquivo)) != EOF)
      {
      contador = contador + 1;
      if (cadeia == valor)
      {  
         vezes = vezes + 1;
         printf ("%d: %c | vezes: %d\n", contador, cadeia, vezes);
      }
      else
      {
         printf ("%d: x\n", contador);
      }
      }
   fclose (arquivo);
}
void metodo10 ( void )
{
   char valor = 0;
   int posicao = 0;
 // identificar
    printf ( "\n%s\n", "Metodo10" );
    printf ("Entrar com um valor a ser procurado: ");
    scanf("%c", &valor);
    printf ("Entrar com a posicao inicial: ");
    scanf("%d", &posicao);
    searchlv ("metodo10.txt", valor, posicao - 1);
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
        printf ( "%s\n", " - 16/10/2024"       );
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
