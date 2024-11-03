#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "io.h"
void metodo01 ( void )
{
// definir dado
 int x = 0;
// identificar
   printf ( "\n%s\n", "Metodo01->" );
// mostrar valor inicial
 printf ( "\n%s%d\n", "x = ", x );
 printf ( "&%s%p\n" , "x = ", &x );
// ler do teclado
 printf ( "Entrar com um valor inteiro: " );
 scanf ( "%d", &x );
 getchar ( );
// mostrar valor lido
 printf ( "%s%i\n", "x = ", x );
// encerrar
 printf ( "\n\nApertar ENTER para continuar." );
 getchar( );
}
/*
a.) 5
b.) -5
c.) 123456789
a.) 
x = 0

&x = 000000DC271FFD0C
Entrar com um valor inteiro: 5
x = 5
b.)
x = 0
&x = 000000DC271FFD0C
Entrar com um valor inteiro: -5
x = -5
c)
x = 0
&x = 000000DC271FFD0C
Entrar com um valor inteiro: 12345678
x = 12345678
  */
 void metodo02 ( void )
{
// definir dado
 double x = 0.0;
// identificar
 printf ( "\n%s\n", "Metodo2->" );
// mostrar valor inicial
 printf ( "\n%s%lf\n", "x = ", x );
// ler do teclado
 printf ( "Entrar com um valor real: " );
 scanf ( "%lf", &x );
 getchar ( );
// mostrar valor lido
 printf ( "%s%lf\n", "x = ", x );
// encerrar
 printf ( "\n\nApertar ENTER para continuar.\n" );
 getchar( );
}
/**
a.) 0.5
b.) -0.5
c.) 1.23456789
a)
x = 0.000000
Entrar com um valor real: 0.5
x = 0.500000
b)
x = 0.000000
Entrar com um valor real: -0.5
x = -0.500000
c)
x = 0.000000
Entrar com um valor real: 1.23456789
x = 1.234568
*/
void metodo03 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo03" );
// definir dado
 char x = 'A'; // definir variavel com valor inicial
// OBS.: Indispensavel usar apostrofos
// mostrar valor inicial
 printf ( "\n%s%c\n", "x = ", x );
// ler do teclado
 printf ( "Entrar com um caractere: " );
 scanf ( "%c", &x );
 getchar ( );
// mostrar valor lido
 printf ( "%s%c\n", "x = ", x );
// encerrar
 printf ( "\n\nApertar ENTER para continuar.\n" );
 getchar( );
}
/**
a.) a
b.) B
c.) alfabeto
d.) 12
a)
x = A
Entrar com um caractere: a
x = a
b)
x = A
Entrar com um caractere: B
x = B
c)
ele reseta e pede um novo caracter
d)
o mesmo ocorre
 */
void metodo04 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo04->" );
    // definir dado
 bool x = false; // definir variavel com valor inicial
 int y = 0; // definir variavel auxiliar
// mostrar valor inicial
 printf ( "\n%s%d\n", "x = ", x );
// ler do teclado
 printf ( "Entrar com um valor logico: " );
 scanf ( "%d", &y );
 getchar ( );
// garantir valor logico no intervalo [0:1]
 x = (y!=0);
// mostrar valor lido
 printf ( "%s%d\n", "x = ", x );
// encerrar
 printf ( "\n\nApertar ENTER para continuar.\n" );
 getchar( );
}
/**
a.) 1
b.) 0
c.) true
a)
x = 0
Entrar com um valor logico: 1
x = 1
b)
x = 0
Entrar com um valor logico: 0
x = 0
c)
x = 0
Entrar com um valor logico: true
x = 0
// pelo que eu entendi se eu coloco qualquer valor alem de 0 ele devolve 1, mas se eu colocar 0, ou um ou mais
// de um caracter ele devolve 0.
 */
void metodo05 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo05->" );
// definir dado
 char x [80] = "abc"; // definir variavel com tamanho e valor inicial
 char *px = &x[0]; // definir alternativa para acesso via endereco
// mostrar valor inicial
 printf ( "\n%s%s\n", "x = ", x );
// ler do teclado
 printf ( "Entrar com uma cadeia de caracteres: " );
 scanf ( "%s", x );
// OBS.: Nao devera' ser usado o endereco dessa vez !
// O tamanho do valor NAO devera' ultrapassar 80 símbolos.
 getchar ( );
// mostrar valor lido
 printf ( "%s%s\n", "x = ", x );
// ler do teclado (forma alternativa para acesso via endereco)
 printf ( "Entrar com outra cadeia de caracteres: " );
 scanf ( "%s", px );
 printf ( "%s%s\n", "x = ", x );
 getchar ( ); 
// mostrar valor lido (forma alternativa para acesso via endereco)
// encerrar
 printf ( "\n\nApertar ENTER para continuar.\n" );
 getchar( );
}
/**
a.) def
b.) d e f
c.) d_e_f
a e b)
x = abc
Entrar com uma cadeia de caracteres: def
x = def
Entrar com outra cadeia de caracteres: d e f
x = d
//no fim ele nao aceita e pede um novo conjunto de caracteres
c)
x = abc
Entrar com uma cadeia de caracteres: d_e_f
x = d_e_f
 */
void metodo06 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo06->" );
    // definir dados
 int x = 0; // definir variavel com valor inicial
 int y = 0; // definir variavel com valor inicial
 int z = 0; // definir variavel com valor inicial
 int *py = &y; // definir acesso a y via endereco
// mostrar valores iniciais
 printf ( "%s%d\n", "x = ", x );
 printf ( "%s%i\n" , "y = ", y );
// ler do teclado
 printf ( "Entrar com um valor inteiro: " );
 scanf ( "%d", &x );
 getchar ( ); 
 printf ( "Entrar com outro valor inteiro: " );
 scanf ( "%i", py );
// OBS.: Não e' necessario indicar o endereco -> &
 getchar ( );
// operar valores
 z = x * y; // guardar em z o produto de x por y
// mostrar valor resultante
 printf ( "%s(%i)*(%i) = (%d)\n", "z = ", x, y, z );
// encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
}
/**
a.) 3 e 5
b.) -3 e 5
c.) -3 e -5
a)
x = 0
y = 0
Entrar com um valor inteiro: 3
Entrar com outro valor inteiro: 5
z = (3)*(5) = (15)
b)
x = 0
y = 0
Entrar com um valor inteiro: -3
Entrar com outro valor inteiro: 5
z = (-3)*(5) = (-15)
c)
x = 0
y = 0
Entrar com um valor inteiro: -3
Entrar com outro valor inteiro: -5
z = (-3)*(-5) = (15)
*/
void metodo07 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo07->" );
        // definir dados
 char x [80] = "abc"; // definir variavel com tamanho e valor inicial
 char y [80] = "def"; // definir variavel com tamanho e valor inicial
 char z [80]; // definir variavel com tamanho inicial
 strcpy ( z, "" ); // e copiar para (z) a representacao de vazio
// mostrar valores iniciais e comprimentos das cadeias
 printf ( "%s%s (%d)\n", "x = ", x, strlen( x) );
 printf ( "%s%s (%d)\n", "y = ", y, strlen( y) );
// ler do teclado
 printf ( "Entrar com caracteres: " );
 scanf ( "%s", x );
 getchar ( );
 printf ( "Entrar com outros caracteres: " );
 scanf ( "%s", y );
 getchar ( );
// operar valores
 strcpy ( z, x ); // copiar (x) para (z)
 strcat ( z, y ); // concatenar (juntar) (y) a (z)
// mostrar valor resultante
 printf ( "%s[%s]*[%s] = [%s]\n", "z = ", x, y, z );
// operar valores (forma alternativa)
 strcpy ( z, strcat ( strdup(x), y ) );
// copiar para (z)
// o resultado de concatenar
// a copia de (x) com (y)
// OBS.: Se nao duplicar, o valor (x) sera' alterado.
// mostrar valor resultante
 printf ( "%s[%s]*[%s] = [%s]\n", "z = ", x, y, z );
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
}
/**
a.) 12 e 24
b.) ab e cd
c.) a e bc
d.) ab e c
a)
x = abc (3)
y = def (3)
Entrar com caracteres: 12
Entrar com outros caracteres: 24
z = [12]*[24] = [1224]
z = [12]*[24] = [1224]
b)
x = abc (3)
y = def (3)
Entrar com caracteres: ab
Entrar com outros caracteres: cd
z = [ab]*[cd] = [abcd]
z = [ab]*[cd] = [abcd]
c)
x = abc (3)
y = def (3)
Entrar com caracteres: a
Entrar com outros caracteres: bc
z = [a]*[bc] = [abc]
z = [a]*[bc] = [abc]
d)
x = abc (3)
y = def (3)
Entrar com caracteres: ab
Entrar com outros caracteres: c
z = [ab]*[c] = [abc]
z = [ab]*[c] = [abc]
*/
void metodo08 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo08->" );
// usar gcc -o exemplo0108 exemplo0108.c -lm se necessario
// definir dados
 double x = 0.0; // definir variavel com valor inicial
 double y = 0.0; // definir variavel com valor inicial
 double z = 0.0; // definir variavel com valor inicial
// mostrar valores iniciais
 printf ( "%s%lf\n", "x = ", x );
 printf ( "%s%lf\n", "y = ", y );
// ler do teclado
 printf ( "Entrar com um valor real: " );
 scanf ( "%lf", &x );
 getchar ( );
 printf ( "Entrar com outro valor real: " );
 scanf ( "%lf", &y );
 getchar ( );
// operar valores
 z = pow( x, y ); // elevar a base (x) 'a potencia (y)
// mostrar valor resultante
 printf ( "%s(%lf) elevado a (%lf) = (%lf)\n", "z = ", x, y, z );
// operar valores
 x = pow( z, 1.0/y ); // elevar a base (x) 'a potencia inversa de (y) (raiz)
// mostrar valor resultante
 printf ( "%s(%lf) elevado a (1/%lf) = (%lf)\n", "z = ", z, y, x );
// operar valores
 z = sqrt( x ); // raiz quadrada do argumento
// mostrar valor resultante
 printf ( "%sraiz(%lf) = (%lf)\n", "z = ", x, z );
// encerrar
 printf ( "\n\nApertar ENTER para continuar.\n" );
 getchar( ); // aguardar por ENTER
}
/**
a.) 2.0 e 3.0
b.) 3.0 e 2.0
c.) -3.0 e 2.0
d.) -2.0 e -3.0
a)
a.) 2.0 e 3.0
b.) 3.0 e 2.0
c.) -3.0 e 2.0
d.) -2.0 e -3.0
b)
x = 0.000000
y = 0.000000
Entrar com um valor real: 3
Entrar com outro valor real: 2
z = (3.000000) elevado a (2.000000) = (9.000000)
z = (9.000000) elevado a (1/2.000000) = (3.000000)
z = raiz(3.000000) = (1.732051)
c)
x = 0.000000
y = 0.000000
Entrar com um valor real: -3
Entrar com outro valor real: 2
z = (-3.000000) elevado a (2.000000) = (9.000000)
z = (9.000000) elevado a (1/2.000000) = (3.000000)
z = raiz(3.000000) = (1.732051)
d)
x = 0.000000
y = 0.000000
Entrar com um valor real: -2
Entrar com outro valor real: -3
z = (-2.000000) elevado a (-3.000000) = (-0.125000)
z = (-0.125000) elevado a (1/-3.000000) = (-nan(ind))
z = raiz(-nan(ind)) = (-nan(ind))
// nao entendi o pq do erro na ultima...
 */
void metodo09 ( void )
{
// definir dados singulares
 int x = 0 ; // definir variavel com valor inicial para guardar inteiro
 double y = 3.5; // definir variavel com valor inicial para guardar real
 char z = 'A'; // definir variavel com valor inicial para guardar caractere (simbolo)
 bool w = false; // definir variavel com valor inicial para guardar falso ou verdadeiro
// definir dados com mais de um valor
 char s [80] = ""; // definir espaco de armazenamento para ate' 80 caracteres (simbolos)
// mostrar valores iniciais
 printf ( "01. %s%d\n" , "x = ", x );
 printf ( "02. %s%lf\n" , "y = ", y );
 printf ( "03. %s%c\n" , "z = ", z );
// converter entre tipos de dados (type casting)
 x = (int) z; // codigo inteiro equivalente ao caractere
 printf ( "04. %s%d -> %c\n" , "x = ", x, z );
 x = (int) y; // parte inteira de real
 printf ( "05. %s%d -> %lf\n", "x = ", x, y );
 x = 97;
 z = (char) x; // símbolo equivalente ao codigo inteiro
 printf ( "06. %s%c -> %d\n" , "z = ", z, x );
 x = (int) '0'; // codigo inteiro equivalente ao caractere
 z = (char) x; // caractere equivalente ao codigo inteiro
 printf ( "07. %s%c -> %d\n" , "z = ", z, x );
 x = w; // codigo inteiro equivalente ao logico
 printf ( "08. %s%d -> %d\n" , "x = ", x, w );
 w = true;
 x = w; // codigo inteiro equivalente ao logico
 printf ( "09. %s%d -> %d\n" , "x = ", x, w );
 x = (w==false); // equivalente 'a comparacao de igualdade (true igual a false)
 printf ( "10. %s%d -> %d\n" , "x = ", x, w );
 x = ! (w==false); // equivalente ao contrario da comparacao de valores (true igual a false)
 printf ( "11. %s%d -> %d\n" , "x = ", x, w );
 x = (w!=false); // equivalente 'a comparacao de diferenca (true diferente de false)
 printf ( "12. %s%d -> %d\n" , "x = ", x, w );
 w = (x == 0); // equivalente 'a comparacao de igualdade entre (x) e zero
 printf ( "13. %s%d == %d = %d\n" , "w = ", x, 0, w );
 w = (x != 0); // equivalente 'a comparacao de diferenca entre (x) e zero
 printf ( "14. %s%d != %d = %d\n" , "w = ", x, 0, w );
 w = (x < y); // equivalente 'a comparacao entre (x) e (y)
 printf ( "15. %s%d < %lf = %d\n" , "w = ", x, y, w );
 w = (x <= y); // equivalente 'a comparacao entre (x) e (y)
 printf ( "16. %s%d <= %lf = %d\n" , "w = ", x, y, w );
 w = (y > x); // equivalente 'a comparacao entre (x) e (y)
 printf ( "17. %s%lf > %d = %d\n" , "w = ", y, x, w );
 w = (y >= x); // equivalente 'a comparacao entre (x) e (y)
 printf ( "18. %s%lf >= %d = %d\n" , "w = ", y, x, w );
 x = 4;
 w = (x % 2 == 0); // equivalente a testar se é par ou
 // resto inteiro (%) da divisao por 2 igual a zero
 printf ( "19. %s (%d%%2) ? %d\n" , "e' par ", x, w );
 x = 4;
 w = (x % 2 != 0); // equivalente a testar se é ímpar ou
 // resto inteiro (%) da divisao por 2 diferente de zero
 printf ( "20. %s (%d%%2) ? %d\n" , "e' impar ", x, w );
 z = '5';
 w = ('0'<=z && z<='9'); // equivalente a testar se e' algarismo/digito
// pertence a [‘0’:’9’] (é igual ou esta’ entre ‘0’ e ‘9’)
 printf ( "21. %s (%c) ? %d\n" , "e' digito", z, w );
 z = 'x';
 w = ('a'<=z && z<='z'); // equivalente a testar se e' letra minuscula,
// pertence a [‘a’:’z’] (é igual ou esta’ entre ‘a’ e ‘z’)
 printf ( "22. %s (%c) ? %d\n" , "e' minuscula ", z, w );
 z = 'X';
 w = ( ! ('a'<=z && z<='z' ) ); // equivalente a testar se NAO (!) e' letra minuscula
 printf ( "23. %s (%c) ? %d\n" , "nao e' minuscula ", z, w );
 z = 'x';
 w = ('A'<=z && z<='Z'); // equivalente a testar se e' letra maiuscula
 printf ( "24. %s (%c) ? %d\n" , "e' maiuscula ", z, w );
 z = 'X';
 w = ( (z < 'A') || ('Z' < z) ); // equivalente a testar se NAO e' letra maiuscula,
// esta’ fora do intervalo [’a’:’z’], ou e’ menor que ‘a’ ou e’ maior que ‘z’
 printf ( "25. %s (%c) ? %d\n" , "nao e' maiuscula ", z, w );
 z = '0';
 w = ('0'==z || '1'==z); // equivalente a testar se e' igual a '0' ou a '1'
 printf ( "26. %s (%c) ? %d\n" , "e' 0 ou 1 ", z, w );
 strcpy ( s, "zero" ); // copiar para (s) <- "zero" (NAO usar '=' com caracteres);
 printf ( "27. palavra = %s\n", s );
 w = (strcmp ( "zero", s ) == 0);// comparar se caracteres iguais (NAO usar '==' com caracteres);
// Nota: O resultado da comparação sempre devera' ser avaliado
// em relacao a zero, e sera' igual caso coincida.
 printf ( "28. palavra == %s ? %d\n", s, w );
 strcpy ( s, "um e dois" ); // copiar para (s) <- "outras palavras" (NAO usar '=' com caracteres);
 printf ( "29. palavras = %s\n", s );
 w = (strcmp ( "zero", s ) != 0); // comparar se caracteres diferentes (NAO usar '!=' com caracteres);
// Nota: O resultado da comparação sempre devera' ser avaliado
// em relacao a zero, e sera' diferente caso NAO coincidir.
 printf ( "30. palavra == %s ? %d\n", s, w );
// encerrar
 printf ( "\n\nApertar ENTER para continuar." );
 getchar( );
}
void metodo10 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo10" );
    // definir dados
 int x = 5 ; // definir variavel com valor inicial
 double y = 3.5; // definir variavel com valor inicial
 char z = 'A'; // definir variavel com valor inicial
 bool w = TRUE; // definir variavel com valor inicial
 chars a = IO_new_chars(STR_SIZE); // definir variavel com tamanho inicial
 chars b = IO_new_chars(STR_SIZE); // definir variavel com tamanho inicial
 chars c = IO_new_chars(STR_SIZE); // definir variavel com tamanho inicial
// concatenar (juntar) cadeias de caracteres
 strcpy ( a, "abc" ); // atribuir a variavel (a) o valor constante ("abc")
 strcpy ( b, "def" ); // OBS.: a atribuicao de cadeia de caracteres NAO usa (=)
 IO_printf ( "\na = %s b = %s\n", a, b );
 c = IO_concat ( a, b ); // alternativa melhor para a funcao nativa strcat (a,b)
 IO_printf ( "\nc = [%s]+[%s] = [%s]\n", a, b, c );
 strcpy ( a, "c = " );
 strcpy ( c, STR_EMPTY ); // limpar a cadeia de caracteres
 IO_printf ( "%s\n", IO_concat ( a, IO_toString_c ( z ) ) );
 IO_println ( IO_concat ( "x = ", IO_toString_d ( x ) ) );
 IO_println ( IO_concat ( "w = ", IO_toString_b ( w ) ) );
 strcpy ( b, STR_EMPTY );
 IO_print ( "y = " );
 IO_print ( IO_concat ( b, IO_toString_f ( y ) ) );
 IO_print ( "\n" );
 z = IO_readchar ( "char = " );
 IO_println ( IO_concat ( a, IO_toString_c ( z ) ) );
 y = IO_readdouble ( "double = " );
 IO_println ( IO_concat ( a, IO_toString_f ( y ) ) );
 x = IO_readint ( "int = " );
 IO_println ( IO_concat ( a, IO_toString_d ( x ) ) );
 w = IO_readbool ( "bool = " );
 IO_println ( IO_concat ( a, IO_toString_b ( w ) ) );
 b = IO_readstring ( "chars = " );
 IO_println ( IO_concat ( a, b ) );
 b = IO_readln ( "line = " );
 IO_println ( IO_concat ( a, b ) );
// encerrar
 IO_pause ( "Apertar ENTER para terminar" );
}
/**
a.) a
b.) 4.2
c.) 10
d.) 1
e.) abc def
f .) abc de
respostas:
a = abc b = def

c = [abc]+[def] = [abcdef]
c = A
x = 5
w = 1
y = 3.500000
char = a
c = a
double = 4.2
c = 4.200000
int = 10
c = 10
bool = 1
c = 1
chars = abc def
c = abc
line = abc de
c = abc de
*/
int main ( void )
{
 // definir dados
    int opcao = 0;
    do
    {
     // identificar
        printf ( "\n" );             
        printf ( "%s\n", "ed01 14/08/2024"       );
        printf ( "%s\n", "Matricula: 861160 Nome: Miguel Pessoa Lima Ferreira" );

     // mostrar opcoes
        printf ( "%s\n", "Opcoes:"         );
        printf ( "%s\n", " 0 - parar"      );
        printf ( "%s\n", " 1 - metodo 01   2 - metodo 02" );
        printf ( "%s\n", " 3 - metodo 03   4 - metodo 04" );
        printf ( "%s\n", " 5 - metodo 05   6 - metodo 06" );
        printf ( "%s\n", " 7 - metodo 07   8 - metodo 08" );
        printf ( "%s\n", " 9 - metodo 09  10 - metodo 10" );
        printf ( "%s\n", "" );     

     // ler opcao
        printf ( "%s", "Qual a sua opcao? " );
        scanf  ( "%d", &opcao ); getchar ( );
        printf ( "%d",  opcao );

     // escolher acao
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

 // encerrar execucao
    printf ( "\n%s\n\n", "Apertar ENTER para terminar." );
    getchar( );
}