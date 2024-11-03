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
void writeInts ( chars fileName, int x ) 
{ 
 // definir dados 
    FILE* arquivo = fopen ( fileName, "wt" ); 
    int y = 0; 
    for ( y = 1; y <= x; y = y + 1 ) 
    { 
      fprintf ( arquivo, "%d\n", y ); 
    } 
    fclose ( arquivo ); 
}
void metodo01 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo01" );
    writeInts ( "DADOS1.TXT", 12 ); 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" );
}
void readInts ( chars fileName ) 
{ 
 // definir dados 
    FILE* arquivo = fopen ( fileName, "rt" ); 
    int x = 0; 
    fscanf ( arquivo, "%d", &x ); 
    while ( ! feof ( arquivo ) ) 
    { 
     // mostrar valor 
        printf ( "%d\n", x ); 
        fscanf ( arquivo, "%d", &x ); 
    }
    fclose ( arquivo ); 
}
void metodo02 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo02" );
    readInts ( "DADOS1.TXT" ); 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" );
}
void writeDoubles ( chars fileName, int x ) 
{ 
 // definir dados 
    FILE* arquivo = fopen ( fileName, "wt" ); 
    int y = 0; 
    IO_fprintf ( arquivo, "%d\n", x ); 
    for ( y = 1; y <= x; y = y + 1 ) 
    { 
        IO_fprintf ( arquivo, "%lf\n", (0.1*y) ); 
    }
    fclose ( arquivo ); 
}
void metodo03 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo03" );
    writeDoubles ( "DADOS2.TXT", 10 ); 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
}
void readDoubles ( chars fileName ) 
{ 
 // definir dados 
    FILE* arquivo = fopen ( fileName, "rt" ); 
    int        x =   0 ; 
    int        y =   1 ; 
    double z = 0.0; 
    fscanf ( arquivo, "%d", &x ); 
    while ( ! feof ( arquivo ) && y <= x ) 
    { 
        fscanf ( arquivo, "%lf", &z ); 
        printf ( "%2d: %lf\n", y, z ); 
        y = y + 1; 
    }
    fclose ( arquivo ); 
}
void metodo04 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo04" );
     // executar o metodo auxiliar 
    readDoubles ( "DADOS2.TXT" ); 
 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} 

void writeText ( chars fileName ) 
{ 
 // definir dados 
    FILE* arquivo = fopen ( fileName, "wt" ); 
    chars linha     = IO_new_chars ( STR_SIZE ); 
 
 // repetir ate' desejar parar 
    IO_println ( "Gravar linhas (para terminar, entrar com \"PARAR\"):\n" ); 
    do 
    { 
     // ler do teclado 
        strcpy ( linha, IO_readln ( "" ) ); 
     // gravar valor 
        IO_fprintf ( arquivo, "%s\n", linha ); 
    } 
    while ( strcmp ( "PARAR", linha ) != 0 ); 
    fclose ( arquivo ); 
}
void metodo05 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo05" );
    writeText ( "DADOS3.TXT" ); 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" );

}
void readText ( chars fileName ) 
{ 
 // definir dados 
    FILE* arquivo = fopen ( fileName, "rt" ); 
    chars linha     = IO_new_chars ( STR_SIZE ); 
    strcpy ( linha, IO_freadln ( arquivo ) ); 
    while ( ! feof (arquivo) && 
                  strcmp ( "PARAR", linha ) != 0 ) 
    { 
     // mostrar valor 
        printf ( "%s\n", linha ); 
        strcpy ( linha, IO_freadln ( arquivo ) ); 
    } 
    fclose ( arquivo ); 
}
void metodo06 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo06" );
    readText ( "DADOS3.TXT" ); 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 

}
void copyText ( chars fileOut, chars fileIn ) 
{ 
 // definir dados 
    FILE* saida      = fopen ( fileOut, "wt" ); 
    FILE* entrada  = fopen ( fileIn , "rt" ); 
    chars linha      = IO_new_chars ( STR_SIZE ); 
    int   contador  = 0; 
    strcpy ( linha, IO_freadln ( entrada ) ); 
    while ( ! feof ( entrada ) ) 
    { 
        contador = contador + 1; 
        if ( strcmp ( "PARAR", linha ) != 0 ) 
        { 
           IO_fprintln ( saida, linha ); 
        }
        strcpy ( linha, IO_freadln ( entrada ) ); 
    } 
    IO_printf ( "Lines read = %d\n", contador ); 
    fclose (   saida   ); 
    fclose ( entrada ); 
} 
void metodo07 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo07" );
    copyText ( "DADOS4.TXT", "DADOS3.TXT" ); 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" );
}
void appendText ( chars fileName ) 
{ 
 // definir dados 
    FILE* arquivo = fopen ( fileName, "at" ); 
    chars linha     = IO_new_chars ( STR_SIZE ); 
    IO_println ( "Gravar linhas (para terminar, entrar com \"PARAR\"):\n" ); 
    do 
    { 
        strcpy ( linha, IO_readln ( "" ) ); 
        IO_fprintln ( arquivo, linha ); 
    } 
    while ( strcmp ( "PARAR", linha ) != 0 ); 
    fclose ( arquivo ); 
}
void metodo08 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo08" );
    appendText ( "DADOS4.TXT" ); 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" );
}
void readWords ( chars fileName ) 
{ 
 // definir dados 
    FILE* arquivo = fopen ( fileName, "rt" ); 
    chars linha     = IO_new_chars ( STR_SIZE ); 
    strcpy ( linha, IO_fread ( arquivo ) ); 
    while ( ! feof (arquivo) && 
                  strcmp ( "PARAR", linha ) != 0 ) 
    { 
        printf ( "%s\n", linha );  
        strcpy ( linha, IO_fread ( arquivo ) ); 
    }
    fclose ( arquivo ); 
}
void metodo09 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo09" );
    readWords ( "DADOS4.TXT" ); 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
}
bool searchWord ( chars fileName, chars word ) 
{ 
 // definir dados 
    FILE* arquivo = fopen ( fileName, "rt" ); 
    chars linha     = IO_new_chars ( STR_SIZE ); 
    strcpy ( linha, IO_fread ( arquivo ) ); 
    while ( ! feof (arquivo) && 
                  strcmp ( word, linha ) != 0 ) 
    { 
        strcpy ( linha, IO_fread ( arquivo ) ); 
    }
    fclose ( arquivo ); 
 // retornar resultado 
    return ( strcmp ( word, linha ) == 0 ); 
}
void metodo10 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo10" );
    IO_printf ( "Procurar (\"%s\") = %d\n", "pqr", searchWord ( "DADOS4.TXT", "pqr" ) ); 
    IO_printf ( "Procurar (\"%s\") = %d\n", "pqs", searchWord ( "DADOS4.TXT", "pqs" ) ); 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" );
}

int main ( void )
{
    int opcao = 0;
    do
    {
        printf ( "\n" );        
        printf ( "%s\n", " - 06/09/2024"       );
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
