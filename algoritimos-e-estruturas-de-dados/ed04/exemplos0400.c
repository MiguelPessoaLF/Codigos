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
bool positive ( int x ) 
{ 
 // definir dado local 
    bool result = false; 
 // testar a condicao 
    if ( x > 0 ) 
    { 
       result = true; 
    } // end if 
    return ( result ); 
} // end positive ( )
bool belongsTo ( int x, int inferior, int superior ) 
{ 
 // definir dado local 
    bool result = false; 
 // testar a condicao 
    if ( inferior < x && x < superior ) 
    { 
       result = true; 
    } // end if 
   return ( result ); 
} // end belongsTo ( )
bool even ( int x ) 
{ 
 // definir dado local 
    bool result = false; 
 // testar a condicao ( resto inteiro (%) da divisao por 2 igual a zero ) 
    if ( x % 2 == 0 ) 
    { 
       result = true; 
    } // end if 
   return ( result ); 
} // end even ( )
bool isLowerCase ( char x ) 
{ 
 // definir dado local 
    bool result = false; 
 // testar a condicao 
    if ( 'a' <= x && x <= 'z' ) 
    { 
       result = true; 
    } // end if 
   return ( result ); 
} // end isLowerCase ( )
bool isDigit ( char x ) 
{ 
 // definir dado local 
    bool result = false; 
 // testar a condicao 
    if ( '0' <= x && x <= '9' ) 
    { 
       result = true; 
    } // end if 
   return ( result ); 
} // end isDigit ( )
bool isADigit ( char x ) 
{ 
   return ( '0' <= x && x <= '9' ); 
} // end isADigit ( ) 
chars concatADigit ( chars string, char digit ) 
{ 
   return ( IO_concat ( string, IO_toString_c ( digit ) ) ); 
} // end concatADigit ( )
void metodo01 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo01" );
 // definir dado 
    int quantidade = 0; 
    int valor            = 0; 
    int controle      = 0; 
 // ler do teclado 
    quantidade = IO_readint ( "Entrar com uma quantidade: " ); 
 
 // repetir para a quantidade de vezes informada 
    controle = 1; 
    while ( controle <= quantidade ) 
    { 
     // ler valor do teclado 
        valor = IO_readint ( IO_concat ( IO_concat ( "", IO_toString_d ( controle ) ),": "  ) ); 
     // mostrar valor lido 
        printf ( "\n%s%d", "valor = ", valor ); 
     // passar ao proximo valor 
        controle = controle + 1; 
    } // end while 
 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" );
}
void metodo02 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo02" );
 // definir dado 
    int quantidade = 0; 
    int valor            = 0; 
    int controle      = 0; 
    int contador     = 0; 
 // ler do teclado 
    quantidade = IO_readint ( "Entrar com uma quantidade: " ); 
 
 // repetir para a quantidade de vezes informada 
    controle = 1; 
    while ( controle <= quantidade ) 
    { 
     // ler valor do teclado 
        valor = IO_readint ( IO_concat ( 
                                          IO_concat ( "", IO_toString_d ( controle ) ), 
                                          ": "  ) ); 
     // testar e contar se valor for positivo 
        if ( positive ( valor ) ) 
        { 
           contador = contador + 1; 
        } // end if 
 
     // passar ao proximo valor 
        controle = controle + 1; 
    } // end while 
 // mostrar a quantidade de valores positivos 
    IO_printf ( "%s%d\n", "Positivos = ", contador ); 
 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" );
}
void metodo03 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo03" );
 // definir dado 
    int quantidade = 0; 
    int valor            = 0; 
    int controle      = 0; 
    int contador     = 0; 
 // ler do teclado 
    quantidade = IO_readint ( "Entrar com uma quantidade: " ); 
 
 // repetir para a quantidade de vezes informada 
    controle = 1; 
    while ( controle <= quantidade ) 
    { 
     // ler valor do teclado 
        valor = IO_readint ( IO_concat ( 
                                          IO_concat ( "", IO_toString_d ( controle ) ), 
                                          ": "  ) ); 
     // testar e contar se valor for positivo 
        if ( belongsTo ( valor, 0, 100 ) ) 
        { 
           contador = contador + 1; 
        } // end if 
     // passar ao proximo valor 
        controle = controle + 1;
}
}
void metodo04 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo04" );
 // definir dado 
    int quantidade = 0; 
    int valor            = 0; 
    int controle      = 0; 
    int contador     = 0; 
 // ler do teclado 
    quantidade = IO_readint ( "Entrar com uma quantidade: " ); 
 
 
 
 // repetir para a quantidade de vezes informada 
    controle = 1; 
    while ( controle <= quantidade ) 
    { 
     // ler valor do teclado 
        valor = IO_readint ( IO_concat ( 
                                          IO_concat ( "", IO_toString_d ( controle ) ), 
                                          ": "  ) ); 
     // testar e contar se valor for positivo menor que 100 e par 
        if ( belongsTo ( valor, 0, 100 ) && even ( valor ) ) 
        { 
           contador = contador + 1; 
        } // end if 
 
     // passar ao proximo valor 
        controle = controle + 1; 
    } // end while 
 // mostrar a quantidade de valores positivos 
    IO_printf ( "%s%d\n", "Positivos menores que 100 e pares = ", contador ); 
 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
}
void metodo05 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo05" );
// definir dado 
    int  quantidade = 0; 
    int  valor            = 0; 
    int  controle       = 0; 
    int  contador      = 0; 
    bool ok               = false; 
 // ler do teclado 
    quantidade = IO_readint ( "Entrar com uma quantidade: " ); 
 
 // repetir para a quantidade de vezes informada 
    controle = 1; 
    while ( controle <= quantidade ) 
    { 
     // ler valor do teclado 
        valor = IO_readint ( IO_concat ( 
                                          IO_concat ( "", IO_toString_d ( controle ) ), 
                                          ": "  ) ); 
     // testar e contar se valor for positivo menor que 100 e par 
        ok = belongsTo ( valor, 0, 100 ); 
        ok = ok && even ( valor ); 
        if ( ok ) 
        { 
           contador = contador + 1; 
        } // end if 
 
     // passar ao proximo valor 
        controle = controle + 1; 
    } // end while 
 
 // mostrar a quantidade de valores positivos 
    IO_printf ( "%s%d\n", "Positivos menores que 100 e pares = ", contador ); 
 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" );
}
void metodo06 ( void )
{
   printf ("\n%s\n", "Metodo06");
 // definir dado 
    chars palavra    = IO_new_chars ( STR_SIZE ); 
    int      tamanho  =  0; 
    int      posicao   =  0; 
    char  simbolo    = '_'; 
    int     contador  =  0; 
 // ler do teclado 
    palavra = IO_readstring ( "Entrar com uma palavra: " ); 
 
 // determinar a quantidade de simbolos na palavra 
    tamanho = strlen ( palavra ); 
 
 // repetir para a quantidade de vezes informada 
    for ( posicao = 0; posicao < tamanho; posicao = posicao + 1 ) 
    { 
     // isolar um simbolo por vez 
        simbolo = palavra [ posicao ]; 
     // testar e contar se caractere e' letra minuscula  
       if ( isLowerCase ( simbolo ) ) 
        { 
           contador = contador + 1; 
        } // end if 
    } // end for 
 // mostrar a quantidade de minusculas 
    IO_printf ( "%s%d\n", "Minusculas = ", contador ); 
 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
}
void metodo07 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo07" );
 // definir dado 
    chars palavra   = IO_new_chars ( STR_SIZE ); 
    int      tamanho =  0; 
    int      posicao  =  0; 
    char  simbolo   = '_'; 
    int     contador  =  0; 
 // ler do teclado 
    palavra = IO_readstring ( "Entrar com uma palavra: " ); 
 
 // determinar a quantidade de simbolos na palavra 
    tamanho = strlen ( palavra ); 
 // repetir para a quantidade de vezes informada 
    for ( posicao = 0; posicao < tamanho; posicao = posicao + 1 ) 
    { 
     // isolar um simbolo por vez 
        simbolo = palavra [ posicao ]; 
     // testar e contar se caractere e' letra minuscula 
        if ( isLowerCase ( simbolo ) ) 
        { 
         // mostrar 
            IO_printf ( "%c ", simbolo ); 
         // contar 
           contador = contador + 1; 
        } // end if 
    } // end for 
 
 // mostrar a quantidade de minusculas 
    IO_printf ( "\n%s%d\n", "Minusculas = ", contador ); 
 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" );
}
void metodo08 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo08" );
 // definir dado 
    chars palavra        = IO_new_chars ( STR_SIZE ); 
    int      tamanho      =  0; 
    int      posicao       =  0; 
    char   simbolo       = '_'; 
    int      contador      =  0; 
    chars minusculas = IO_new_chars ( STR_SIZE ); 
 
    strcpy ( minusculas, STR_EMPTY );  // vazio 
 // ler do teclado 
    palavra = IO_readstring ( "Entrar com uma palavra: " ); 
 
 // determinar a quantidade de simbolos na palavra 
    tamanho = strlen ( palavra ); 
 
 // repetir para a quantidade de vezes informada 
    for ( posicao = 0; posicao < tamanho; posicao = posicao + 1 ) 
    { 
     // isolar um simbolo por vez 
        simbolo = palavra [ posicao ]; 
     // testar e contar as letras minusculas de uma palavra 
        if ( isLowerCase ( simbolo ) ) 
        { 
         // concatenar simbolo encontrado 
            minusculas = IO_concat ( minusculas, IO_toString_c ( simbolo ) ); 
         // contar 
           contador = contador + 1; 
        } // end if 
    } // end for 
 
 // mostrar a quantidade de minusculas 
    IO_printf ( "\n%s%d [%s]\n", "Minusculas = ", contador, minusculas ); 
 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" );
}
void metodo09 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo09" );
 // definir dado 
    chars palavra    = IO_new_chars ( STR_SIZE ); 
    int      tamanho  =  0; 
    int      posicao   =  0; 
    char   simbolo   = '_'; 
    int      contador  =  0; 
 // ler do teclado 
    palavra = IO_readstring ( "Entrar com caracteres: " ); 
 
 // determinar a quantidade de simbolos 
    tamanho = strlen ( palavra ); 
 
 // repetir para a quantidade de vezes informada 
    for ( posicao = 0; posicao < tamanho; posicao = posicao + 1 ) 
    { 
     // isolar um simbolo por vez 
        simbolo = palavra [ posicao ]; 
     // testar e contar os algarismos em uma cadeia de caracteres 
        if ( isDigit ( simbolo ) ) 
        { 
         // mostrar 
            IO_printf ( "%c ", simbolo ); 
         // contar 
           contador = contador + 1; 
        } // end if 
    } // end for 
 
 // mostrar a quantidade de digitos 
    IO_printf ( "\n%s%d\n", "Algarismos = ", contador ); 
 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
}
void metodo10 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo10" );
 // definir dado 
    chars palavra    = IO_new_chars ( STR_SIZE ); 
    int      tamanho  =  0; 
    int      posicao   =  0; 
    char   simbolo   = '_'; 
    chars digitos     = IO_new_chars ( STR_SIZE ); 
 
    strcpy ( digitos, STR_EMPTY );  // vazio 
 // ler do teclado 
    palavra = IO_readstring ( "Entrar com uma palavra: " ); 
 
 // determinar a quantidade de simbolos na palavra 
    tamanho = strlen ( palavra ); 
 
 // repetir para a quantidade de vezes informada 
    for ( posicao = 0; posicao < tamanho; posicao = posicao + 1 ) 
    { 
     // isolar um simbolo por vez 
        simbolo = palavra [ posicao ]; 
     // testar e contar os algarismos em uma cadeia de caracteres 
        if ( isADigit ( simbolo ) ) 
        { 
         // concatenar simbolo encontrado 
            digitos = concatADigit ( digitos, simbolo ); 
        } // end if 
    } // end for 
 
 // mostrar a quantidade de digitos 
    IO_printf ( "\n%s%d [%s]\n", "Algarismos = ", strlen( digitos ), digitos ); 
 
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
