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
int somar_1 (int n )
{
	int soma = 0;
	if (n > 0 )
	{
		printf ( ">n=%d soma=%d somar_1(%d-1)\n", n, soma, n ); getchar();
		soma = n + somar_1 ( n-1);
		printf ( ">n=%d soma=%d somar_1(%d-1)\n", n, soma, n ); getchar();
	}
	return (soma);
}
int quatro1 ( int n )
{
    int x    = 0;
    int y    = 0;
    for (
          x = 4;
          x <= n * 4;
          x = x + 4
        )
    {
         y = y + 1;
        //definir soma
        printf ("%d: %d\n", y, x);
    }
    return ( x );
}
int quatro2 ( int n )
{
    int contador = 0;
    int x    = 0;
    int y    = 0;
    int z    = 0;
    for (
          x = 1;
          x <= n*3;
          x = x+1
        )
    {
      y = x * 4;
      contador = contador + 1;
      if ( y % 3 == 0 && y % 4 == 0)
      {
        //definir soma
        printf ("%d: %d\n", contador,y);
      }
    }
    return ( z );
}
int quatro3 ( int n )
{
    int x    = 0;
    int y    = 0;
    int z    = 0;
    int a    = 0;
    for (
          x = 4;
          x <= n * 4;
          x = x + 4
        )
    {
         y = y + 1;
        //definir soma
        printf ("%d: %d\n", y, x);
        getchar ();
    }
    for (
          z = 3;
          z <= n * 3;
          z = z + 3
        )
    {
         a = a + 1;
        //definir soma
        printf ("%d: %d\n", a, z);
        getchar ();
    }
    return ( x );
}
int potenciaT ( int n )
{
    int contador = 0;
    int y    = 1;
    int z    = 0;
    n = n + 1;
    contador = n;
for (
     z = n - 1;
     z > 0;
     z = z - 1
    )
    {
    contador = contador - 1;
    printf ("%d: %.0f\n", contador, pow(3,z));
    getchar ( );
    }
    return ( z );
}
int denominador1 ( int n )
{
    int contador = 0;
    int y    = 4;
    int z    = 0;
    n = n + 1;
 for ( 
       n >= 0;
       n = n - 1;
       y = y + 4
     )
 {
 contador = contador + 1;
 printf ("%d: %s%d\n", contador, "1/", y);
 getchar ( );
 }
}
double denominador2 (int n)
{
    double soma = 1.0;
    double numerador = 0.0;
    double denominador = 0.0;
    int contador = 1;
    int y = 1;
    for ( contador = pow (contador, 2); contador <= pow(n, 2); contador = contador + 1 )
    {
    numerador = 1.0;
    denominador = 2.0 * contador;
    printf ( "\n%d: %7.4lf/%7.4lf = %lf\n", contador, numerador, denominador, (numerador/denominador) );
    getchar();
    soma = soma + (1.0) / (2.0 * y);
}
}
int m4n5 (int n)
{
    int contador = 0;
    int soma = 0;
    int x    = 0;
    int y    = 4;
    int z    = 0;
    for (
          x = 1;
          x <= n;
          x = x+1
        )
    {
      y = y + 4;
      contador = contador + 1;
      if ( y % 4 == 0 && y % 5 != 0 )
      {
        soma = soma + y;
        //definir soma
        printf ("%d: %d | soma = %d\n", contador, y, soma);
        getchar();
      }
    }
    return ( z );
}
double denominador3 (int n)
{
    int contador = 0;
    double soma = 1.0;
    double numerador = 0.0;
    double denominador = 0.0;
    int y = 0;
    int z = 0;
    for 
        ( 
          y = 0;
          y <= (n - 1) * 3;
          y = y + 3 
        )
        {
        contador = contador + 1;
        numerador = 1.0;
        denominador = 3.0 + y;
        z = denominador;
        if (z % 5 == 0 )
        {
            printf("");
        }
            else
            {
            soma = soma + numerador / denominador;
            printf ( "\n%d: %7.4lf/%7.4lf = %lf | %7.4lf\n", contador, numerador, denominador, (numerador/denominador), soma );
            getchar();
            }
        }
return ( soma );
}
int somanaturais (int n)
{
    int soma = 0;
    int contador = 0;
    int x    = 0;
    int y    = 3;
    for (
          x = 0;
          x <= n - 1;
          x = x + 1
        )
    {
        contador = contador + 1;
        y = y + 1;
        //definir soma
        soma = soma + y;
        printf ("%d: %d | soma = %d\n", contador, y, soma);
        getchar ();
    }
    return ( soma );
}
int somaquadrados (int n)
{
     int soma = 0;
    int contador = 0;
    int x    = 4;
    int y    = 4;
    for (
          x = 4;
          contador < n;
          x = x + 1
        )
    {
        contador = contador + 1;
        y = pow (x, 2);
        //definir soma
        soma = soma + y;
        printf ("%d: %d | soma = %d\n", contador, y, soma);
        getchar ();
    }
    return ( soma );
}
int denominador4 (int n)
{
    int contador = 0;
    double numerador = 0.0;
    double denominador = 0.0;
    int y = 0;
    int z = 0;
    denominador = n * 4;
    for 
        ( 
          y = 0;
          denominador >= 8;
          y = y - 4
        )
        {
        contador = contador + 1;
        numerador = 1.0;
        denominador = denominador - 4;
            printf ( "\n%d: %7.4lf/%7.4lf = %lf\n", contador, numerador, denominador, (numerador/denominador));
            getchar();
        }
return ( y );
}
void metodo00 ( void )
{
    int valor = 0;
    // identificar
    printf("%s\n", "\nMetodo00\n");
    //ler valor
    printf ( "%s%d", "entrar com um valor inteiro", valor);
    scanf("%d", &valor);
	 printf ( "soma_1 = %d\n", somar_1 (valor) );
    // encerrar
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar( );
}
void metodo01 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo01" );
    //ler valor inteiro
    int valor = 0;
    printf ("Entrar com um valor inteiro:", valor);
    scanf ("%d", &valor);
    //rodar
	 printf ( "%d\n", quatro1 ( valor ) );
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
}
void metodo02 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo02" );
   //ler valor inteiro
    int valor = 0;
    printf ("Entrar com um valor inteiro:", valor);
    scanf ("%d", &valor);
    //rodar
	 printf ( "%d\n", quatro2 ( valor ) );
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
}
void metodo03 (void)
{
    int valor = 0;
    // identificar
    printf("%s\n", "\nMetodo03\n");
    // acoes
    printf ("Entrar com um valor inteiro:", valor);
    scanf ("%d", &valor);
    printf ( "%d\n", potenciaT (valor) );

    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar( );
}
void metodo04 (void)
{
    int valor = 0;
    // identificar
    printf("%s\n", "\nMetodo04\n");
    // acoes
    printf ("Entrar com um valor inteiro:", valor);
    scanf ("%d", &valor);
    printf ( "%d\n", denominador1 (valor) );
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar( );
}
void metodo05 (void)
{
    int valor = 0;
    // identificar
    printf("%s\n", "\nMetodo05\n");
    // acoes
    printf ("Entrar com um valor inteiro:", valor);
    scanf ("%d", &valor);
    printf ( "%d\n", denominador2 (valor) );
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar( );
}
void metodo06 (void)
{
    // definir dados e resultados
    int n         = 0; // quantidade de termos
    int valor = 0;
    // identificar
    printf("%s\n", "\nMetodo06\n");
    // acoes
    printf ("Entrar com um valor inteiro:", valor);
    scanf ("%d", &valor);
    printf ( "%d\n", m4n5 (valor) );

    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar( );
}
void metodo07 (void)
{
    // definir dados e resultados
    int n         = 0; // quantidade de termos
    int valor = 0;
    // identificar
    printf("%s\n", "\nMetodo07\n");
    // acoes
    printf ("Entrar com um valor inteiro:", valor);
    scanf ("%d", &valor);
    printf ( "%d\n", denominador3 (valor) );
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar( );
}
void metodo08 (void)
{
    // definir dados e resultados
    int n         = 0; // quantidade de termos
    int valor = 0;
    // identificar
    printf("%s\n", "\nMetodo08\n");
    // acoes
    printf ("Entrar com um valor inteiro:", valor);
    scanf ("%d", &valor);
    printf ( "%d\n", somanaturais (valor) );

    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar( );
}
void metodo09 (void)
{
    // definir dados e resultados
    int n         = 0; // quantidade de termos
    int valor = 0;
    // identificar
    printf("%s\n", "\nMetodo09\n");
    // acoes
    printf ("Entrar com um valor inteiro:", valor);
    scanf ("%d", &valor);
    printf ( "%d\n", somaquadrados (valor) );

    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar( );
}
void metodo10 (void)
{
    // definir dados e resultados
    int n         = 0; // quantidade de termos
    int valor = 0;
    // identificar
    printf("%s\n", "\nMetodo10\n");
    // acoes
    printf ("Entrar com um valor inteiro:", valor);
    scanf ("%d", &valor);
    printf ( "%d\n", denominador4 (valor) );

    printf("%s\n", "\nApertar ENTER para continuar\n");
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
        printf ( "%s\n", " 11 - metodo 00" );
        printf ( "%s\n", "" );
        printf ( "%s", "Qual a sua opcao? " );
        scanf  ( "%d", &opcao ); getchar ( );
        printf ( "%d",  opcao );
        switch ( opcao )
        {
           case  0:               break;
           case  11: metodo00 ( ); break;
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
