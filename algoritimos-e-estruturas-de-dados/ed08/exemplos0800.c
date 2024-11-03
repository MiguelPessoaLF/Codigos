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
void printIntArray ( int n, int array [ ] ) 
{ 
 // definir dado local 
    int x = 0; 
    for ( x=0; x<n; x=x+1 ) 
    { 
        IO_printf ( "%2d: %d\n", x, array [ x ] ); 
    }
}
void metodo01 ( void )
{
 // definir dado 
    int array [ ] = { 1, 2, 3, 4, 5 }; 
 // identificar
    printf ( "\n%s\n", "Metodo02" );
    printIntArray ( 5, array ); 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
}
void readIntArray ( int n,  int array [ ] ) 
{ 
    int x = 0; 
    int y = 0; 
    chars text = IO_new_chars ( STR_SIZE ); 
    for ( x=0; x<n; x=x+1 ) 
    { 
        strcpy ( text, STR_EMPTY ); 
        y = IO_readint ( IO_concat ( IO_concat ( text, IO_toString_d ( x ) ), " : " ) );  
        array [ x ] = y; 
    }
}
void metodo02 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo02" );
 // definir dados 
    int n = 5;
    int array [ n ]; 
 // ler dados 
    readIntArray  ( n, array ); 
 // mostrar dados 
    IO_printf       ( "\n" ); 
    printIntArray ( n, array ); 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
}
void fprintIntArray ( chars fileName, int n, int array [ ] ) 
{ 
 // definir dados locais 
    FILE* arquivo = fopen ( fileName, "wt" ); 
    int x = 0; 
    IO_fprintf ( arquivo, "%d\n", n ); 
    for ( x=0; x<n; x=x+1 ) 
    { 
     // gravar valor 
        IO_fprintf ( arquivo, "%d\n", array [ x ] ); 
    } // end for 
     
 // fechar arquivo 
    fclose ( arquivo ); 
} 
void metodo03 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo03" );
 // definir dados 
    int n = 5;
    int array [ n ]; 
 // ler dados 
    readIntArray   ( n, array ); 
 // mostrar dados 
    IO_printf      ( "\n" ); 
    fprintIntArray ( "ARRAY1.TXT", n, array ); 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
}
int freadArraySize ( chars fileName ) 
{ 
 // definir dados locais 
    int n = 0; 
    FILE* arquivo = fopen ( fileName, "rt" ); 
    IO_fscanf ( arquivo, "%d", &n ); 
 
    if ( n <= 0 ) 
    { 
       IO_println ( "ERRO: Valor invalido." ); 
       n = 0; 
    }
 // retornar dado lido 
    return ( n ); 
}
void freadIntArray ( chars fileName, int n, int array [ ] ) 
{ 
 // definir dados locais 
    int x = 0; 
    int y = 0; 
    FILE* arquivo = fopen ( fileName, "rt" ); 
 
 // ler a quantidade de dados 
    IO_fscanf ( arquivo, "%d", &x ); 
 
 
 
 
 
 
    if ( n <= 0 || n > x ) 
    { 
       IO_println ( "ERRO: Valor invalido." ); 
    } 
    else 
    { 
     // ler e guardar valores em arranjo 
        x = 0; 
        while ( ! feof ( arquivo ) && x < n ) 
        { 
         // ler valor 
            IO_fscanf ( arquivo, "%d", &y ); 
         // guardar valor 
            array [ x ] = y; 
         // passar ao proximo 
            x = x+1; 
        } // end while 
    } // end if 
 
}
void metodo04 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo04" );
 // definir dados 
    int n = 0;
 // ler dados 
    n = freadArraySize ( "ARRAY1.TXT"   ); 
 
    if ( n <= 0 ) 
    { 
       IO_printf ( "\nERRO: Valor invalido.\n" ); 
    } 
    else 
    { 
        int array [ n ]; 
        freadIntArray  ( "ARRAY1.TXT", n, array ); 
        IO_printf     ( "\n" ); 
        printIntArray ( n, array ); 
    }
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" );
}
void copyIntArray ( int n, int copy [ ], int array [ ] ) 
{ 
 // definir dados locais 
    int x = 0; 
    int y = 0; 
 
    if ( n <= 0 ) 
    { 
       IO_println ( "ERRO: Valor invalido." ); 
       n = 0; 
    } 
    else 
    { 
        for ( x = 0; x < n; x = x + 1 ) 
        { 
            copy [ x ] = array [ x ]; 
        }
    }
}
void metodo05 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo05" );
 // definir dados 
    int n = 0;
 // identificar 
    IO_id ( "Method_05 - v0.0" ); 
 
 // ler a quantidade de dados 
    n = freadArraySize ( "ARRAY1.TXT"   ); 
    if ( n <= 0 ) 
    { 
       IO_printf ( "\nERRO: Valor invalido.\n" ); 
    } 
    else 
    { 
     // definir armazenador 
        int array [ n ]; 
        int other [ n ]; 
     // ler dados 
        freadIntArray ( "ARRAY1.TXT", n, array ); 
     // copiar dados 
        copyIntArray  ( n, other, array ); 
     // mostrar dados 
        IO_printf     ( "\nOriginal\n" ); 
        printIntArray ( n, array ); 
     // mostrar dados 
        IO_printf     ( "\nCopia\n" ); 
        printIntArray ( n, other ); 
    }
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" );
}
int sumIntArray ( int n, int array [ ] ) 
{ 
 // definir dados locais 
    int soma = 0; 
    int x        = 0; 
    for ( x=0; x<n; x=x+1 ) 
    { 
        soma = soma + array [ x ]; 
    }
    return ( soma ); 
}
void metodo06 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo06" );
 // definir dados 
    int n = 0;
    n = freadArraySize ( "ARRAY1.TXT"   ); 
 
    if ( n <= 0 ) 
    { 
       IO_printf ( "\nERRO: Valor invalido.\n" ); 
    } 
    else 
    { 
        int array [ n ]; 
     // ler dados 
        freadIntArray ( "ARRAY1.TXT", n, array ); 
        IO_printf ( "\nSoma = %d\n", sumIntArray ( n, array ) ); 
    }
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" );
}
bool isAllZeros ( int n, int array [ ] ) 
{ 
 // definir dados locais 
    bool result = true; 
    int x            = 0; 
 
 
 // mostrar valores no arranjo 
    x=0;  
    while ( x<n && result ) 
    { 
     // testar valor 
        result = result && ( array [ x ] == 0 ); 
     // passar ao proximo 
        x = x + 1; 
    } // end while 
 
 // retornar resposta 
    return ( result ); 
}
void metodo07 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo07" );
 // definir dados 
    int n = 5;
    int array1 [ ] = { 0,0,0,0,0 }; 
    int array2 [ ] = { 1,2,3,4,5 }; 
    int array3 [ ] = { 1,2,0,4,5 }; 
 // testar dados 
    IO_println    ( "\nArray1" ); 
    printIntArray ( n, array1  ); 
    IO_printf     ( "isAllZeros (array1) = %d", isAllZeros (n, array1) ); 
    IO_println    ( "\nArray2" ); 
    printIntArray ( n, array2  ); 
    IO_printf     ( "isAllZeros (array2) = %d", isAllZeros (n, array2) ); 
    IO_println    ( "\nArray3" ); 
    printIntArray ( n, array3  ); 
    IO_printf     ( "isAllZeros (array3) = %d", isAllZeros (n, array3) ); 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
}
void addIntArray ( int n, int array3 [ ],  
                                int array1 [ ], int k, int array2 [ ] ) 
{ 
 // definir dados locais 
    int x = 0; 
    for ( x=0; x<n; x=x+1 ) 
    { 
        array3 [ x ]= array1 [ x ] + k * array2 [ x ]; 
    }
}
void metodo08 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo08" );
 // definir dados 
    int n = 0;
    n = freadArraySize ( "ARRAY1.TXT"   ); 
    if ( n <= 0 ) 
    { 
       IO_printf ( "\nERRO: Valor invalido.\n" ); 
    } 
    else 
    { 
        int array [ n ]; 
        int other [ n ]; 
        int sum   [ n ]; 
        freadIntArray ( "ARRAY1.TXT", n, array ); 
        copyIntArray  ( n, other, array ); 
        IO_printf     ( "\nOriginal\n" ); 
        printIntArray ( n, array ); 
        IO_printf     ( "\nCopia\n" ); 
        printIntArray ( n, other ); 
        addIntArray   ( n, sum, array, (-2), other ); 
        IO_printf     ( "\nSoma\n" ); 
        printIntArray ( n, sum ); 
    }
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" );
}
bool isEqual ( int n, int array1 [ ], int array2 [ ] ) 
{ 
 // definir dados locais 
    bool result = true; 
    int x       = 0; 
 
 // mostrar valores no arranjo 
    x = 0; 
    while ( x<n && result ) 
    { 
     // testar valor 
        result = result && ( array1 [ x ] == array2 [ x ] ); 
     // passar ao proximo 
        x = x + 1; 
    } // end while 
 
 // retornar resposta 
    return ( result ); 
}
void metodo09 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo09" );
 // definir dados 
    int n = 0;
    n = freadArraySize ( "ARRAY1.TXT"   ); 
    if ( n <= 0 ) 
    { 
       IO_printf ( "\nERRO: Valor invalido.\n" ); 
    } 
    else 
    { 
        int array [ n ]; 
        int other [ n ]; 
     // ler dados 
        freadIntArray ( "ARRAY1.TXT", n, array ); 
        copyIntArray  ( n, other, array ); 
        IO_printf     ( "\nOriginal\n" ); 
        printIntArray ( n, array ); 
        IO_printf     ( "\nCopia\n" ); 
        printIntArray ( n, other ); 
        IO_printf     ( "\nIguais = %d\n", isEqual ( n, array, other ) ); 
        other [ 0 ] = (-1) * other [ 0 ]; 
        IO_printf     ( "\nCopia alterada\n" ); 
        printIntArray ( n, other ); 
        IO_printf     ( "\nIguais = %d\n", isEqual ( n, array, other ) ); 
    }
 // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
}
bool searchArray ( int value, int n, int array [ ] ) 
{ 
 // definir dados locais 
    bool result = false; 
    int x       = 0; 
    x = 0; 
    while ( x<n && ! result ) 
    { 
        result = ( value == array [ x ] ); 
        x = x + 1; 
    }
 // retornar resposta 
    return ( result ); 
}
void metodo10 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo10" );
 // definir dados 
    int  n        = 0;
    int  value = 0;
 // identificar 
    IO_id ( "Method_10 - v0.0" ); 
    n = freadArraySize ( "ARRAY1.TXT"   ); 
    if ( n <= 0 ) 
    { 
       IO_printf ( "\nERRO: Valor invalido.\n" ); 
    } 
    else 
    { 
     // definir armazenador 
        int array [ n ]; 
     // ler dados 
        freadIntArray ( "ARRAY1.TXT", n, array ); 
        IO_printf     ( "\nOriginal\n" ); 
        printIntArray ( n, array ); 
        value = array [ 0 ]; 
        IO_printf     ( "\nProcurar por (%d) = %d\n",  
        value, searchArray ( value, n, array ) ); 
        value = array [ n / 2 ]; 
        IO_printf     ( "\nProcurar por (%d) = %d\n",  
        value, searchArray ( value, n, array ) ); 
        value = array [ n - 1 ]; 
        IO_printf     ( "\nProcurar por (%d) = %d\n",  
        value, searchArray ( value, n, array ) ); 
        value = (-1); 
        IO_printf     ( "\nProcurar por (%d) = %d\n",  
        value, searchArray ( value, n, array ) ); 
    }
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" );
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
