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
int rn (int inferior, int superior)
{
   int random = rand() % (superior - inferior + 1) + inferior;
   return (random);
}
void metodo01 ( void )
{
   FILE* arquivo = fopen ("metodo01.txt", "w");
   int inferior = 0;
   int superior = 0;
   int n = 0;
 // identificar
    printf ( "\n%s\n", "Metodo01" );
    printf ("me de uma quantidade de valores a ser lida:");
    scanf("%d",&n);
    printf ("entre com o limite inferior de um intervalo");
    scanf("%d", &inferior);
    printf ("entre com o limite superior de um intervalo");
    scanf("%d", &superior);
    for (int i = 0; i < n; i = i + 1 )
    {
    int random = rn(inferior, superior);
    fprintf (arquivo, "%d\n", random);
    }
    fclose (arquivo);
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
}
#define MAX 5
bool sa (int valor, char* filename)
{
   FILE* arquivo = fopen ("metodo01.txt", "r");
   char cadeia[MAX];
   int valora = 0;
   while (fgets(cadeia, sizeof(cadeia), arquivo))
   {
   if (sscanf (cadeia, "%d", &valora) == 1)
   {
      if (valora == valor)
      {
      return (true);
      }
   }
   }
   fclose (arquivo);
   return (false);
}
void metodo02 ( void )
{
   int valor = 0;
 // identificar
    printf ( "\n%s\n", "Metodo02" );
    printf ("me de um valor: ");
    scanf ("%d", &valor);
    if (sa(valor,"metodo01.txt"))
    {
      printf ("o valor foi encontrado");
      getchar();
    }
    else 
    {
      printf ("o valor nao foi encontrado");
      getchar();
    }
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
}
struct st
{
   int lenght[80];
   int data;
   int px;
};
void metodo03 ( void )
{
   FILE* arquivo1 = fopen ("metodo03a.txt", "w");
      FILE* arquivo2 = fopen ("metodo03b.txt", "w");
   struct st value1;
   struct st value2;
 // identificar
    int cont1 = 0;
    int cont2 = 0;
    printf ( "\n%s\n", "Metodo03" );
    printf ("me de a quantidade de valores do primeiro arquivo: ");
    scanf ("%d", &value1.lenght[0]);
    int valor1 = value1.lenght[0];
    printf ("%d\n", valor1);
    printf ("me de a quantidade de valores do segundo arquivo: ");
    scanf ("%d", &value2.lenght[1]);
    int valor2 = value2.lenght[1];
    printf ("%d\n", valor2);
    for (int i = valor1; i > 0; i = i - 1)
    {
      fprintf (arquivo1, "%d", cont1);
      cont1 = cont1 + 1;
    }
      for (int o = valor2; o > 0; o = o - 1)
      {
         cont2 = cont2 + 1;
         fprintf (arquivo2, "%d", cont2);
      }
   if (value1.lenght[0] == 0 ||  0 == value2.lenght[1])
   {
      printf ("um dos, ou ambos os tamanhos sao nulos");
      getchar( );
   }
   else if (value1.lenght[0] == value2.lenght[1])
   {
      printf ("os arquivos tem o mesmo tamanho");
      getchar ( );
   }
   else
   {
      printf ("os arquivos nao tem o mesmo tamanho");
      getchar ( );
   }
    fclose (arquivo1);
      fclose (arquivo2);
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
}
struct arrays
{
   int array[20];
};
int la (char* filename1, char* filename2, int n)
{
   FILE* arquivo1 = fopen (filename1, "r");
      FILE* arquivo2 = fopen (filename2, "r");
         FILE* arquivo3 = fopen ("metodo04c.txt", "w");
   struct arrays cadeia1;
      struct arrays cadeia2;
   for (int i = 0; i < MAX; i = i + 1)
   {
      fscanf (arquivo1, "%d", &cadeia1.array[i]);
   }
      for (int o = 0; o < MAX; o = o + 1)
      {
         printf ("%d | ", cadeia1.array[o]);
         fscanf (arquivo2, "%d", &cadeia2.array[o]);
      }
   printf ("\n");
   for (int j = 0; j < MAX; j = j + 1)
   {
      printf ("%d | ", cadeia2.array[j] * 2);
      fprintf (arquivo3, "%d | ", cadeia1.array[j]);
   }
      for (int s = 0; s < MAX; s = s + 1)
      {
         fprintf (arquivo3, "%d | ", cadeia2.array[s] * n);
      }
   fclose (arquivo1);
      fclose (arquivo2);
         fclose (arquivo3);
}
int conc (struct arrays a, struct arrays b)
{
   FILE* arquivo1 = fopen ("metodo04a.txt", "w");
      FILE* arquivo2 = fopen ("metodo04b.txt", "w");
   for (int i = 0; i < MAX; i = i + 1)
   {
      fprintf (arquivo1, "%d\n", a.array[i]);
   }
      for (int o = 0; o < MAX; o = o + 1)
      {
         fprintf (arquivo2, "%d\n", b.array[o]);
      }
   fclose (arquivo1);
      fclose (arquivo2);
}
void metodo04 ( void )
{
   struct arrays array1;
   struct arrays array2;
   int n = 0;
 // identificar
    printf ( "\n%s\n", "Metodo04" );
    printf ("entre com um array de inteiros: \n");
    for (int i = 0; i < MAX; i = i + 1)
    {
    scanf ("%d", &array1.array[i]);
    }
      printf ("entre com outro array de inteiros: \n");
      for (int o = 0; o < MAX; o = o + 1)
      {
      scanf ("%d", &array2.array[o]);
      }
    printf ("entre com um valor para multiplicar o segundo array: ");
    scanf ("%d", &n);
    conc (array1, array2);
    la ("metodo04a.txt", "metodo04b.txt", n);
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
}
int write (struct arrays a)
{
   FILE* arquivo = fopen ("metodo05.txt", "w");
   for (int i = 0; i < MAX; i = i + 1)
   {
      fprintf (arquivo, "%d\n", a.array[i]);
   }
   fclose (arquivo);
}
bool ord ( char* filename)
{  
   struct arrays array5;
   FILE* arquivo = fopen ("metodo05.txt", "r");
    for (int o = 0; o < MAX; o = o + 1) 
    {
      fscanf(arquivo, "%d", &array5.array[o]);
    }
    for (int i = 0; i < MAX - 1; i = i + 1) 
    {
      if (array5.array[i] > array5.array[i + 1])
      {
         return (false);
         fclose (arquivo);
      }
    }
      fclose(arquivo);
   return (true);
}
void metodo05 ( void )
{
   struct arrays array;
   int n = 0;
 // identificar
    printf ( "\n%s\n", "Metodo05" );
    printf ("entre com um array de inteiros: \n");
    for (int i = 0; i < MAX; i = i + 1)
    {
    scanf ("%d", &array.array[i]);
    }
    write (array);
    if (ord("metodo05.txt"))
    {
      printf ("esta ordenado");
    }
    else 
    {
      printf ("nao esta ordenado");
    }
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
}
void lmt ( int linhas, int colunas, int matrix[ ][colunas] )
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
         matrix [cont2][cont1] = valor; 
      } 
    }
}
void mma ( const char* filename, int linhas, int colunas, int matrix[ ][colunas] )
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
    if (linhas <= 0 || colunas <= 0){printf ("valor nulo ou negativo");}
    else 
    {
    int matriz [linhas] [colunas];
    lmt (linhas, colunas, matriz );
    mma ("metodo06.txt", linhas, colunas, matriz );
    }
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
}
void lm ( int linhas, int colunas, int matrix[ ][colunas] )
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
bool mmaif0 ( const char* filename, int linhas, int colunas, int matrix[ ][colunas] )
{ 
    FILE* arquivo = fopen (filename, "r");
    int cont1 = 0; 
    int cont2 = 0; 
    for ( cont1 = 0; cont1 < linhas; cont1 = cont1 + 1 ) 
    { 
      for ( cont2 = 0; cont2 < colunas; cont2 = cont2 + 1 ) 
      { 
         if (fscanf ( arquivo, "%3d\t", matrix [ cont1 ][ cont2 ] ) != 0)
            {
               return (false);
               fclose (arquivo);
            }
      }
    }
    fclose (arquivo);
    return (true);
} 
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
    if (linhas <= 0 || colunas <= 0){printf ("valor nulo ou negativo");}
    else 
    {
    int matriz [linhas] [colunas];
    lm (linhas, colunas, matriz );
    mma ("metodo07.txt", linhas, colunas, matriz);
    if (mmaif0("metodo07a.txt", linhas, colunas, matriz ))
    {
      printf ("todos os valores sao nulos");
    }
    else
    {
      printf ("nem todos os valores sao nulos");
    }
    }
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
}
int tm ( const char* filename, int linhas, int colunas, int matrix[ ][colunas] )
{ 
    FILE* arquivo = fopen (filename, "r");
    int cont1 = 0; 
    int cont2 = 0; 
    int tamanho = 0;
    for ( cont1 = 0; cont1 < linhas; cont1 = cont1 + 1 ) 
    { 
      for ( cont2 = 0; cont2 < colunas; cont2 = cont2 + 1 ) 
      { 
         tamanho = tamanho + 1;
      }
    }
    fclose (arquivo);
    return (tamanho);
} 
void metodo08 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo08" );
    int colunas1 = 0;
    int linhas1 = 0;
    int colunas2 = 0;
    int linhas2 = 0;
    printf ("entrar com o numero de colunas de uma matriz: ");
    scanf ("%d", &colunas1);
    printf ("entrar com o numero de linhas de uma matriz: ");
    scanf ("%d", &linhas1);
    if (linhas1 <= 0 || colunas1 <= 0){printf ("valor nulo ou negativo");}
    else 
    {
    int matriz1 [linhas1] [colunas1];
    lm (linhas1, colunas1, matriz1 );
    mma ("metodo08a.txt", linhas1, colunas1, matriz1);
    int tm1 = tm("metodo08a.txt", linhas1, colunas1, matriz1 );

    printf ("entrar com o numero de colunas de outra matriz: ");
    scanf ("%d", &colunas2);
    printf ("entrar com o numero de linhas de outra matriz: ");
    scanf ("%d", &linhas2);
    if (linhas2 <= 0 || colunas2 <= 0){printf ("valor nulo ou negativo");}
    else 
    {
    int matriz2 [linhas2] [colunas2];
    lm (linhas2, colunas2, matriz2 );
    mma ("metodo08b.txt", linhas2, colunas2, matriz2);
    int tm2 = tm("metodo08b.txt", linhas2, colunas2, matriz2 );

    if (tm1 == tm2)
    {
      printf ("os tamanhos sao iguais");
    }
    else
    {
      printf ("os tamanhos nao sao iguais");
    }
    }
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
   }
}
 void lmm ( int linhas1, int colunas1, int matrix1[ ][colunas1], int n)
{ 
    int cont1 = 0; 
    int cont2 = 0; 
    int valor = 0; 
    
    chars cadeiaconcat = IO_new_chars ( STR_SIZE ); 
    for ( cont1 = 0; cont1 < linhas1; cont1 = cont1 + 1 ) 
    { 
      for ( cont2 = 0; cont2 < colunas1; cont2 = cont2 + 1 ) 
      {
         strcpy ( cadeiaconcat, STR_EMPTY ); 
         printf ("linha: "); 
         valor = IO_readint 
         ( IO_concat (IO_concat (IO_concat (cadeiaconcat, IO_toString_d(cont1)), ", coluna: "), 
         IO_concat (IO_concat (cadeiaconcat, IO_toString_d(cont2)), " : " ))); 
         matrix1 [cont1][cont2] = valor * n; 
      } 
    }
}
void mms ( const char* filename,int linhas1, int colunas1, int matriz1[ ][colunas1],
 int linhas2, int colunas2, int matriz2[ ][colunas2])
{ 
    FILE* arquivo = fopen (filename, "w");
    int cont1 = 0; 
    int cont2 = 0; 
    int matriz3[linhas1][colunas1];
    for ( cont1 = 0; cont1 < linhas1; cont1 = cont1 + 1 ) 
    { 
      for ( cont2 = 0; cont2 < colunas1; cont2 = cont2 + 1 ) 
      { 
         matriz3 [cont1][cont2] = matriz1 [cont1][cont2] + matriz2 [cont1][cont2];
         fprintf ( arquivo, "%3d\t", matriz3 [ cont1 ][ cont2 ] ); 
      }
    fprintf ( arquivo, "\n" ); 
    }
    fclose (arquivo);
} 
void metodo09 ( void )
{
    printf ( "\n%s\n", "Metodo09" );
    int colunas1 = 0;
    int linhas1 = 0;
    int colunas2 = 0;
    int linhas2 = 0;
    int n = 0;
    printf ("entrar com o numero de colunas de uma matriz: ");
    scanf ("%d", &colunas1);
    printf ("entrar com o numero de linhas de uma matriz: ");
    scanf ("%d", &linhas1);
    if (linhas1 <= 0 || colunas1 <= 0){printf ("valor nulo ou negativo");}
    else 
    {
    int matriz1 [linhas1] [colunas1];
    lm (linhas1, colunas1, matriz1 );
    mma ("metodo09a.txt", linhas1, colunas1, matriz1);
    printf ("entrar com o numero de colunas de outra matriz: ");
    scanf ("%d", &colunas2);
    printf ("entrar com o numero de linhas de outra matriz: ");
    scanf ("%d", &linhas2);
    if (linhas1 != linhas2 || colunas1 != colunas2){printf("tamanho incompativel");}
    else {
    printf ("entrar com um numero para multiplicar a segunda matriz: ");
    scanf ("%d", &n);
    if (linhas2 <= 0 || colunas2 <= 0){printf ("valor nulo ou negativo");}
    else 
    {
    int matriz2 [linhas2] [colunas2];
    lmm (linhas2, colunas2, matriz2, n );
    mma ("metodo09b.txt", linhas2, colunas2, matriz2);
    mms ("metodo09c.txt", linhas2, colunas2, matriz2, linhas1, colunas1, matriz1 );
    }
    }
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
}
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
        printf ( "%s\n", " - 09/11/2024"       );
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
