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
typedef
struct s_int_Array
{
 int length;
 ints data ;
 int ix ;
}
int_Array;
typedef int_Array* ref_int_Array;
ref_int_Array new_int_Array ( int n )
{
// reserva de espaco
 ref_int_Array tmpArray = (ref_int_Array) malloc (sizeof(int_Array));
// estabelecer valores padroes
 if ( tmpArray == NULL )
 {
 IO_printf ( "\nERRO: Falta espaco.\n" );
 }
 else
 {
 tmpArray->length = 0;
 tmpArray->data = NULL;
 tmpArray->ix = -1;
 if ( n>0 )
 {
 // guardar a quantidade de dados
 tmpArray->length = n;
 // reservar espaco para os dados
 tmpArray->data = (ints) malloc (n * sizeof(int));
 // definir indicador do primeiro elemento
 tmpArray->ix = 0;
 }
 }
 return ( tmpArray );
}
void free_int_Array ( ref_int_Array tmpArray )
{
// testar se ha' dados, antes de reciclar o espaco
 if ( tmpArray != NULL )
 {
 if ( tmpArray->data != NULL )
 { 
 free ( tmpArray->data );
 }
 free ( tmpArray );
 }
}
void printIntArray ( int_Array array )
{
// mostrar valores no arranjo
 if ( array.data )
 {
 for ( array.ix=0; array.ix<array.length; array.ix=array.ix+1 )
 {
 // mostrar valor
 printf ( "%2d: %d\n", array.ix, array.data [ array.ix ] );
 }
 }
}
void metodo01 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo01" );
// definir dado
 int_Array array;
 array. length = 5;
 array. data = (ints) malloc (array.length * sizeof(int));
// testar a existência de dados
 if ( array.data )
 {
 array. data [ 0 ] = 1;
 array. data [ 1 ] = 2;
 array. data [ 2 ] = 3;
 array. data [ 3 ] = 4;
 array. data [ 4 ] = 5;
 }
// executar o metodo auxiliar
 printIntArray ( array );
// reciclar o espaco
 if ( array.data )
 {
 free ( array.data );
 } // fim se
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
}
int_Array IO_readintArray ( )
{
// definir dados locais
 chars text = IO_new_chars ( STR_SIZE );
 static int_Array array;
// ler a quantidade de dados
 do
 {
 array.length = IO_readint ( "\nlength = " );
 }
 while ( array.length <= 0 );
// reservar espaco para armazenar
 array.data = IO_new_ints ( array.length );
// testar se ha' espaco
 if ( array.data == NULL )
 {
 array.length = 0; // nao ha' espaco
 }
 else
 {
 // ler e guardar valores em arranjo
 for ( array.ix=0; array.ix<array.length; array.ix=array.ix+1 )
 {
 // ler valor
 strcpy ( text, STR_EMPTY );
 array.data [ array.ix ]
 = IO_readint ( IO_concat (
 IO_concat ( text, IO_toString_d ( array.ix ) ), " : " ) );
 }
 }
// retornar arranjo
 return ( array );
}
void metodo02 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo02" );
// definir dados
 int_Array array;
// ler dados
 array = IO_readintArray ( );
// testar a existência de dados
 if ( array.data )
 {
 // mostrar dados
 IO_printf ( "\n" );
 printIntArray ( array );
 // reciclar o espaco
 free ( array.data );
 } // end if
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
}
void fprintIntArray ( chars fileName, int_Array array )
{
// definir dados locais
 FILE* arquivo = fopen ( fileName, "wt" );
// gravar quantidade de dados
 fprintf ( arquivo, "%d\n", array.length );
// gravar valores no arquivo, se existirem
 if ( array.data )
 {
 for ( array.ix=0; array.ix<array.length; array.ix=array.ix+1 )
 {
 // gravar valor
 fprintf ( arquivo, "%d\n", array.data [ array.ix ] );
 } // end for
 } // end if
 
// fechar arquivo
 fclose ( arquivo );
}
void metodo03 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo03" );
// definir dados
 int_Array array;
// ler dados
 array = IO_readintArray ( );
// testar a existência de dados
 if ( array.data )
 {
 // mostrar e gravar dados
 IO_printf ( "\n" );
 printIntArray ( array );
 fprintIntArray ( "ARRAY1.TXT", array );
 // reciclar o espaco
 free ( array.data );
 }
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
}
int freadArraySize ( chars fileName )
{
// definir dados locais
 int n = 0;
 FILE* arquivo = fopen ( fileName, "rt" );
// testar a existencia
 if ( arquivo )
 {
 // ler a quantidade de dados
 fscanf ( arquivo, "%d", &n );
 if ( n <= 0 )
 {
 IO_printf ( "\nERRO: Valor invalido.\n" );
 n = 0;
 }
 fclose ( arquivo );
 }
// retornar dados lidos
 return ( n );
}
int_Array fIO_readintArray ( chars fileName )
{
// definir dados locais
 int x = 0;
 int y = 0;
 FILE* arquivo = fopen ( fileName, "rt" );
 static int_Array array;
// testar a existencia
 if ( arquivo )
 {
 // ler a quantidade de dados
 fscanf ( arquivo, "%d", &array.length );
 // testar se ha' dados
 if ( array.length <= 0 )
 {
 IO_printf ( "\nERRO: Valor invalido.\n" );
 array.length = 0;
 }
 else
 {
 // reservar espaco
 array.data = IO_new_ints ( array.length );
 // testar a existência
 if ( array.data )
 {
 array.ix = 0;
 while ( ! feof ( arquivo ) && 
 array.ix < array.length )
 {
 // ler valor
 fscanf ( arquivo, "%d", &(array.data [ array.ix ]) );
 // passar ao proximo
 array.ix = array.ix + 1;
 }
 }
 }
 }
// retornar dados lidos
 return ( array );
}
void metodo04 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo04" );
// definir dados
 int_Array array; // arranjo sem tamanho definido
// ler dados
 array = fIO_readintArray ( "ARRAY1.TXT" );
// testar a existência de dados
 if ( array.data )
 {
 // mostrar dados
 IO_printf ( "\n" );
 printIntArray ( array );
 // reciclar o espaco
 free ( array.data );
 }
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
}
ref_int_Array copyIntArray ( int_Array array )
{
// definir dados locais
 int x = 0;
 int y = 0;
 ref_int_Array copy;
 if ( array.length <= 0 )
 {
 IO_printf ( "\nERRO: Valor invalido.\n" );
 array.length = 0;
 }
 else
 {
 // reservar area
 copy = new_int_Array ( array.length );
 // testar se ha' descritor
 if ( copy )
 {
 copy->length = array.length;
 copy->data = IO_new_ints ( copy->length );
 // testar se ha' espaco e dados
 if ( copy->data == NULL || array.data == NULL )
 {
 printf ( "\nERRO: Falta espaco ou dados." );
 }
 else
 {
 // ler e copiar valores
 for ( array.ix=0; array.ix<array.length; array.ix=array.ix+1 )
 {
 // copiar valor
 copy->data [ array.ix ] = array.data [ array.ix ];
 }
 }
 }
 }
// retornar dados lidos
 return ( copy );
}
typedef int_Matrix* ref_int_Matrix;
void metodo05 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo05" );
// definir dados
 int_Array array; // arranjo sem tamanho definido
 ref_int_Array other;
// ler dados
 array = fIO_readintArray ( "ARRAY1.TXT" );
// copiar dados
 other = copyIntArray ( array );
// testar a existência de dados
 if ( array.data )
 {
 // mostrar dados
 IO_printf ( "\nOriginal\n" );
 printIntArray ( array );
 // mostrar dados
 IO_printf ( "\nCopia\n" );
 printIntArray ( *other );
 // reciclar os espacos
 free ( array.data );
 free ( other->data );
 free ( other );
 }
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
}
typedef
struct s_int_Matrix
{
 int rows ;
 int columns;
 ints* data ;
 int ix, iy ;
}
int_Matrix;
ref_int_Matrix new_int_Matrix ( int rows, int columns )
{
// reserva de espaco
 ref_int_Matrix tmpMatrix = (ref_int_Matrix) malloc (sizeof(int_Matrix));
// estabelecer valores padroes
 if ( tmpMatrix != NULL )
 {
 tmpMatrix->rows = 0;
 tmpMatrix->columns = 0;
 tmpMatrix->data = NULL;
 // reservar espaco
 if ( rows>0 && columns>0 )
 {
 tmpMatrix->rows = rows;
 tmpMatrix->columns = columns;
 tmpMatrix->data = malloc (rows * sizeof(ints));
 if ( tmpMatrix->data )
 {
 for ( tmpMatrix->ix=0;
 tmpMatrix->ix<tmpMatrix->rows;
 tmpMatrix->ix=tmpMatrix->ix+1 )
 {
 tmpMatrix->data [ tmpMatrix->ix ] = (ints) malloc (columns * sizeof(int));
 } // end for
 } // end if
 } // end if
 tmpMatrix->ix = 0;
 tmpMatrix->iy = 0;
 } // end if
 return ( tmpMatrix );
}
void metodo06 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo06" );
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );

}
void metodo07 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo07" );
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );

}
void metodo08 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo08" );
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );

}
void metodo09 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo09" );
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
        printf ( "%s\n", " - 04/11/2024"       );
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
