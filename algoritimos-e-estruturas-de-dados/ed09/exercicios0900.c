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
void lm ( int linhas, int colunas, int matrix[ ][colunas] ) //ler os valores da matriz
{ 
    int cont1 = 0; 
    int cont2 = 0; 
    int valor = 0; 
    chars cadeiaconcat = IO_new_chars ( STR_SIZE ); 
    for ( cont1 = 0; cont1 < linhas; cont1 = cont1 + 1 ) 
    { 
      for ( cont2 = 0; cont2 < colunas; cont2 = cont2 + 1 ) 
      {
         strcpy ( cadeiaconcat, STR_EMPTY ); 
         printf ("linha: ");
         valor = IO_readint 
         ( IO_concat (IO_concat (IO_concat (cadeiaconcat, IO_toString_d(cont1)), ", coluna: "), 
         IO_concat (IO_concat (cadeiaconcat, IO_toString_d(cont2)), " : " ))); 
         matrix [cont1][cont2] = valor; 
      } 
    }
}
void mm ( int linhas, int colunas, int matrix[ ][colunas] ) //mostrar matriz definida em lm
{ 
    int cont1 = 0; 
    int cont2 = 0; 
    for ( cont1 = 0; cont1 < linhas; cont1 = cont1 + 1 ) 
    { 
      for ( cont2 = 0; cont2 < colunas; cont2 = cont2 + 1 ) 
      { 
         printf ( "%3d\t", matrix [ cont1 ][ cont2 ] ); 
      }
    printf ( "\n" ); 
    }
}
void mma ( const char* filename, int linhas, int colunas, int matrix[ ][colunas] ) //mostrar matriz definida em lm em um arquivo
{ 
    FILE* arquivo = fopen (filename, "w");
    int cont1 = 0; 
    int cont2 = 0; 
    for ( cont1 = 0; cont1 < linhas; cont1 = cont1 + 1 ) 
    { 
      for ( cont2 = 0; cont2 < colunas; cont2 = cont2 + 1 ) 
      { 
         fprintf ( arquivo, "%3d\t", matrix [ cont1 ][ cont2 ] ); 
      }
    fprintf ( arquivo, "\n" ); 
    }
    fclose (arquivo);
}
void metodo01 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo01" );
    int colunas = 0;
    int linhas = 0;
    printf ("entrar com o numero de colunas de uma matriz: ");
    scanf ("%d", &colunas);
    printf ("entrar com o numero de linhas de uma matriz: ");
    scanf ("%d", &linhas);
    if (linhas <= 0 || colunas <= 0){printf ("valor nulo ou negativo");}
    else 
    {
    int matriz [linhas] [colunas];
    lm (linhas, colunas, matriz );
    mm (linhas, colunas, matriz );
    }
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
}
void metodo02 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo02" );
    int colunas = 0;
    int linhas = 0;
    printf ("entrar com o numero de colunas de uma matriz: ");
    scanf ("%d", &colunas);
    printf ("entrar com o numero de linhas de uma matriz: ");
    scanf ("%d", &linhas);
    if (linhas <= 0 || colunas <= 0){printf ("valor nulo ou negativo");}
    else 
    {
    int matriz [linhas] [colunas];
    lm (linhas, colunas, matriz );
    mma ("matriz2.txt", linhas, colunas, matriz );
    }
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
}
void mmad ( const char* filename, int linhas, int colunas, int matrix[ ][colunas] )
{ 
    FILE* arquivo = fopen (filename, "w");
    int cont1 = 0; 
    int cont2 = 0; 
    for ( cont1 = 0; cont1 < linhas; cont1 = cont1 + 1 ) 
    { 
      for ( cont2 = 0; cont2 < colunas; cont2 = cont2 + 1 ) 
      {
         if (cont2 == cont1) 
         {
         fprintf ( arquivo, "%3d\t", matrix [ cont1 ][ cont2 ] ); 
         }
         else 
         {
            fprintf ( arquivo, "\t" );
         }
      }
    fprintf ( arquivo, "\n" ); 
    }
    fclose (arquivo);
}
void metodo03 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo03" );
    int colunas = 0;
    int linhas = 0;
    printf ("entrar com o numero de colunas de uma matriz: ");
    scanf ("%d", &colunas);
    printf ("entrar com o numero de linhas de uma matriz: ");
    scanf ("%d", &linhas);
    if (linhas <= 0 || colunas <= 0 || linhas != colunas){printf ("valor nulo ou negativo");}
    else 
    {
    int matriz [linhas] [colunas];
    lm (linhas, colunas, matriz );
    mmad ("matriz3.txt", linhas, colunas, matriz );
    }
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
}
//de alguma forma esse foi meu primeiro codigo a dar certo de primeira
void mmadi ( const char* filename, int linhas, int colunas, int matrix[ ][colunas] )
{ 
    FILE* arquivo = fopen (filename, "w");
    int cont1 = 0; 
    int cont2 = 0; 
    int colunascopy = colunas - 1;
    for ( cont1 = 0; cont1 < linhas; cont1 = cont1 + 1 ) 
    { 
      for ( cont2 = 0; cont2 < colunas; cont2 = cont2 + 1 ) 
      {
         if (cont2 == colunascopy) 
         {
         fprintf ( arquivo, "%3d\t", matrix [ cont1 ][ cont2 ] ); 
         colunascopy = colunascopy - 1;
         }
         else 
         {
            fprintf ( arquivo, "\t" );
         }
      }
    fprintf ( arquivo, "\n" ); 
    }
    fclose (arquivo);
}
void metodo04 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo04" );
    int colunas = 0;
    int linhas = 0;
    printf ("entrar com o numero de colunas de uma matriz: ");
    scanf ("%d", &colunas);
    printf ("entrar com o numero de linhas de uma matriz: ");
    scanf ("%d", &linhas);
    if (linhas <= 0 || colunas <= 0 || linhas != colunas){printf ("valor nulo ou negativo");}
    else 
    {
    int matriz [linhas] [colunas];
    lm (linhas, colunas, matriz );
    mmadi ("matriz4.txt", linhas, colunas, matriz );
    }
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
}
void mmadb ( const char* filename, int linhas, int colunas, int matrix[ ][colunas] )
{ 
    FILE* arquivo = fopen (filename, "w");
    int cont1 = 0; 
    int cont2 = 0; 
    int colunascopy = colunas;
    for ( cont1 = 0; cont1 < linhas; cont1 = cont1 + 1 ) 
    { 
      for ( cont2 = 0; cont2 < colunas; cont2 = cont2 + 1 ) 
      {
         if (cont2 <= cont1) 
         {
         fprintf ( arquivo, "%3d\t", matrix [ cont1 ][ cont2 ] ); 
         }
         else 
         {
            fprintf ( arquivo, "\t" );
         }
      }
    fprintf ( arquivo, "\n" ); 
    }
    fclose (arquivo);
}
void metodo05 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo05" );
    int colunas = 0;
    int linhas = 0;
    printf ("entrar com o numero de colunas de uma matriz: ");
    scanf ("%d", &colunas);
    printf ("entrar com o numero de linhas de uma matriz: ");
    scanf ("%d", &linhas);
    if (linhas <= 0 || colunas <= 0 || linhas != colunas){printf ("valor nulo ou negativo");}
    else 
    {
    int matriz [linhas] [colunas];
    lm (linhas, colunas, matriz );
    mmadb ("matriz5.txt", linhas, colunas, matriz );
    }
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
}
void mmada ( const char* filename, int linhas, int colunas, int matrix[ ][colunas] )
{ 
    FILE* arquivo = fopen (filename, "w");
    int cont1 = 0; 
    int cont2 = 0; 
    int colunascopy = colunas;
    for ( cont1 = 0; cont1 < linhas; cont1 = cont1 + 1 ) 
    { 
      for ( cont2 = 0; cont2 < colunas; cont2 = cont2 + 1 ) 
      {
         if (cont2 >= cont1) 
         {
         fprintf ( arquivo, "%3d\t", matrix [ cont1 ][ cont2 ] ); 
         }
         else 
         {
            fprintf ( arquivo, "\t" );
         }
      }
    fprintf ( arquivo, "\n" ); 
    }
    fclose (arquivo);
}
void metodo06 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo06" );
    int colunas = 0;
    int linhas = 0;
    printf ("entrar com o numero de colunas de uma matriz: ");
    scanf ("%d", &colunas);
    printf ("entrar com o numero de linhas de uma matriz: ");
    scanf ("%d", &linhas);
    if (linhas <= 0 || colunas <= 0 || linhas != colunas){printf ("valor nulo ou negativo");}
    else 
    {
    int matriz [linhas] [colunas];
    lm (linhas, colunas, matriz );
    mmada ("matriz6.txt", linhas, colunas, matriz );
    }
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
}
void mmadib ( const char* filename, int linhas, int colunas, int matrix[ ][colunas] )
{ 
    FILE* arquivo = fopen (filename, "w");
    int cont1 = 0; 
    int cont2 = 0; 
    for ( cont1 = 0; cont1 < linhas; cont1 = cont1 + 1 ) 
    { 
      for ( cont2 = 0; cont2 < colunas; cont2 = cont2 + 1 ) 
      {
         if (cont2 <= colunas - cont1 - 1) 
         {
         fprintf ( arquivo, "%3d\t", matrix [ cont1 ][ cont2 ] ); 
         }
         else 
         {
            fprintf ( arquivo, "\t" );
         }
      }
    fprintf ( arquivo, "\n" ); 
    }
    fclose (arquivo);
}
//aquele outro raciocinio da questão 4 não funcionou direito aqui, essa outra soluçao ficou mais consistente,
//mesmo assim vou deixar la como aprendizado
void metodo07 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo07" );
    int colunas = 0;
    int linhas = 0;
    printf ("entrar com o numero de colunas de uma matriz: ");
    scanf ("%d", &colunas);
    printf ("entrar com o numero de linhas de uma matriz: ");
    scanf ("%d", &linhas);
    if (linhas <= 0 || colunas <= 0 || linhas != colunas){printf ("valor nulo ou negativo");}
    else 
    {
    int matriz [linhas] [colunas];
    lm (linhas, colunas, matriz );
    mmadib ("matriz7.txt", linhas, colunas, matriz );
    }
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
}
void mmadia ( const char* filename, int linhas, int colunas, int matrix[ ][colunas] )
{ 
    FILE* arquivo = fopen (filename, "w");
    int cont1 = 0; 
    int cont2 = 0; 
    for ( cont1 = 0; cont1 < linhas; cont1 = cont1 + 1 ) 
    { 
      for ( cont2 = 0; cont2 < colunas; cont2 = cont2 + 1 ) 
      {
         if (cont2 <= colunas - cont1 - 1) 
         {
         fprintf ( arquivo, "%3d\t", matrix [ cont1 ][ cont2 ] ); 
         }
         else 
         {
            fprintf ( arquivo, "\t" );
         }
      }
    fprintf ( arquivo, "\n" ); 
    }
    fclose (arquivo);
}

void metodo08 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo08" );
    int colunas = 0;
    int linhas = 0;
    printf ("entrar com o numero de colunas de uma matriz: ");
    scanf ("%d", &colunas);
    printf ("entrar com o numero de linhas de uma matriz: ");
    scanf ("%d", &linhas);
    if (linhas <= 0 || colunas <= 0 || linhas != colunas){printf ("valor nulo ou negativo");}
    else 
    {
    int matriz [linhas] [colunas];
    lm (linhas, colunas, matriz );
    mmadia ("matriz8.txt", linhas, colunas, matriz );
    }
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
}
bool mmadb0 ( const char* filename, int linhas, int colunas, int matrix[ ][colunas] )
{ 
    FILE* arquivo = fopen (filename, "r");
    int cont1 = 0; 
    int cont2 = 0; 
    for ( cont1 = 0; cont1 < linhas; cont1 = cont1 + 1 ) 
    { 
      for ( cont2 = 0; cont2 < colunas; cont2 = cont2 + 1 ) 
      {
      if (cont2 <= cont1 && cont2 == 0)
      {
         return (true);
      }
      }
    fprintf ( arquivo, "\n" ); 
    }
    fclose (arquivo);
    return (false);
}
void metodo09 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo09" );
    int colunas = 0;
    int linhas = 0;
    printf ("entrar com o numero de colunas de uma matriz: ");
    scanf ("%d", &colunas);
    printf ("entrar com o numero de linhas de uma matriz: ");
    scanf ("%d", &linhas);
    if (linhas <= 0 || colunas <= 0 || linhas != colunas){printf ("valor nulo ou negativo");}
    else 
    {
    int matriz [linhas] [colunas];
    lm (linhas, colunas, matriz );
    if (mmadb0 ("matriz9.txt", linhas, colunas, matriz )){printf("todos os valores sao nulos");}
    else{printf("todos os valores nao sao nulos");}
    }
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
