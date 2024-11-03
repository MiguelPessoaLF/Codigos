#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "io.h"
#define PI 3.1415
#include "my_def.h"
#include "my_lib.h"
void method_01 ( void ){

int main ( ){
printf ( "EXEMPLO101 - PRIMEIRO EXEMPLO EM C" );
printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
getchar ( );

return ( 0 );

} 

void method_02 ( void ){

    system ( "cls" );
printf ( "EXEMPLO102 - PRIMEIRO EXEMPLO EM C\n" );
system ( "pause" ); 
return ( EXIT_SUCCESS );
}
}

void method_03 ( void ){

    clrscr ( );
printf ( "EXEMPLO103 - PRIMEIRO EXEMPLO EM C" );
printf ( "\n" );
printf ( "MATRICULA: ______ ALUNO : __________________" );
printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
getchar( );
return ( EXIT_SUCCESS );
}

void method_04 ( void ){

   printf ( "EXEMPLO104 - PRIMEIRO EXEMPLO EM C" );
printf ( "\n" );
printf ( "MATRICULA: ______ ALUNO : __________________" );
printf ( "\n" );
printf ( "PRESSIONAR <Enter> PARA TERMINAR. " );
getchar( );
return ( EXIT_SUCCESS );
} 

void method_05 ( void ){

    printf ( "EXEMPLO105 - PRIMEIRO EXEMPLO EM C" );
printf ( "\nMATRICULA: ______ ALUNO : __________________" );
printf ( "\nEXEMPLOS DE VALORES : " );
printf ( "\nCARACTERE : %c",'A' );
printf ( "\nINTEIRO: %d",
10 );
printf ( "\nREAL: %f", 3.1415 );
printf ( "\nPRESSIONAR <Enter> PARA TERMINAR. " );
getchar( );
return ( EXIT_SUCCESS );
} 

void method_06 ( void ){

    printf ( "EXEMPLO106 - PRIMEIRO EXEMPLO EM C " );
printf ( "\nMATRICULA: ______ ALUNO : __________________" );
printf ( "\nEXEMPLOS DE VALORES : " );
printf ( "\nCARACTERE : %c", 'A' ); 
printf ( "\nINTEIRO: %d", 10 ); 
printf ( "\nREAL: %f", PI ); 
printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
getchar( );
return ( EXIT_SUCCESS );
} 

void method_07 ( void ){
const float PI = 3.14;
printf ( "EXEMPLO107 - PRIMEIRO EXEMPLO EM C" );
printf ( "\nMATRICULA: ______ ALUNO : __________________" );
printf ( "\nEXEMPLOS DE VALORES : " );
printf ( "\nCARACTERE : %c", 'A' ); 
printf ( "\nINTEIRO: %d", 10 ); 
printf ( "\nREAL: %f" , PI ); 
printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
getchar( );

return ( EXIT_SUCCESS );
} 

void method_08 ( void ){
const float PI = 3.14; 
float X = 10.01;

printf ( "EXEMPLO108 - PRIMEIRO EXEMPLO EM C" );
printf ( "\nMATRICULA: ______ ALUNO : __________________" );
printf ( "\nEXEMPLOS DE VALORES : " );
printf ( "\nCARACTERE : %c", 'A' ); 
printf ( "\nINTEIRO: %d", 10 ); 
printf ( "\nREAL: %f", PI ); 
printf ( "\nREAL: %f", X ); 
printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
getchar( );

return ( EXIT_SUCCESS );
} 

void method_09 ( void ){

const float PI = 3.14; 
float X = 10.01;
int I = 10;
printf ( "EXEMPLO109 - PRIMEIRO EXEMPLO EM C" );
printf ( "\nMATRICULA: ______ ALUNO : __________________" );
printf ( "\nEXEMPLOS DE VALORES : " );
printf ( "\nINTEIRO : %i" , I );
printf ( "\nREAL: %f" , X );
printf ( "\nREAL: %f" , PI );
printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
getchar( );
return ( EXIT_SUCCESS );
} 
void method_10 ( void ){

const double PI = 3.14;
float X = 10.01;
int I = 10;
char N = '\n';
printf ( "EXEMPLO110 - PRIMEIRO EXEMPLO EM C" );
printf ( "\nMATRICULA: ______ ALUNO : __________________" );
printf ( "%c%s",
N, "EXEMPLOS DE VALORES : " );
printf ( "%c%s%i" , N, "INTEIRO : " , I );
printf ( "%c%s%f" , N, "REAL: " , X );
printf ( "%c%s%lf", N, "REAL: " , PI );
printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
getchar( );
return ( EXIT_SUCCESS );
} 

void method_11 ( void ){
int X = 0;
printf ( "EXEMPLO201 - LER E IMPRIMIR UM VALOR INTEIRO" );
printf ( "\nFORNECER UM VALOR INTEIRO QUALQUER: " );
scanf ( "%d", &X );
getchar( );
printf ( "\nO VALOR DIGITADO FOI: %d", X );
printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
getchar( );
return ( EXIT_SUCCESS );
}

void method_12 ( void ){
double X = 0.0;
printf ( "EXEMPLO202 - LER E IMPRIMIR UM VALOR REAL" );
printf ( "\nFORNECER UM VALOR REAL QUALQUER: " );
scanf ( "%lf", &X );
getchar( );
printf ( "\nO VALOR DIGITADO FOI: %lf", X );
printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
getchar( );
return ( EXIT_SUCCESS );
}

void method_13 ( void ){
char X = '0';
printf ( "EXEMPLO203 - LER E IMPRIMIR UM CARACTERE" );
printf ( "\nFORNECER UM CARACTERE QUALQUER: " );
scanf ( "%c", &X );
getchar( );
printf ( "\nO VALOR DIGITADO FOI: %c", X );
printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
getchar( );
return ( EXIT_SUCCESS );
}

void method_14 ( void ){
char X [10];
printf ( "EXEMPLO204 - LER E IMPRIMIR, NO MAXIMO, 09 CARACTERES" );
printf ( "\nDIGITE, NO MAXIMO, 09 CARACTERES QUAISQUER: " );
scanf ( "%s", X );
getchar( );
printf ( "\nFOI DIGITADO: %s", X );
printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
getchar( );
return ( EXIT_SUCCESS );
}

void method_15 ( void ){
int X=0, Y=0, Z=0;
printf ( "EXEMPLO205 - LER E SOMAR DOIS VALORES INTEIROS" );
printf ( "\nFORNECER UM VALOR INTEIRO QUALQUER: " );
scanf ( "%d", &X );
getchar( );
printf ( "\nFORNECER OUTRO VALOR INTEIRO QUALQUER: " );
scanf ( "%d", &Y );
getchar( );
Z = X + Y;
printf ( "\nA SOMA DOS DOIS = %d", Z );
printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
getchar( );
return ( EXIT_SUCCESS );
}

void method_16 ( void ){
float X=0.0, Y=0.0, Z=0.0;
printf ( "EXEMPLO206 - LER E SUBTRAIR DOIS VALORES REAIS" );
printf ( "\nFORNECER UM VALOR REAL QUALQUER: " );
scanf ( "%f", &X );
getchar( );
printf ( "\nFORNECER OUTRO VALOR REAL QUALQUER: " );
scanf ( "%f", &Y );
getchar( );
Z = X - Y;
printf ( "\nA DIFERENCA ENTRE OS DOIS = %f", Z );
printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
getchar ( );
return ( EXIT_SUCCESS );
}

void method_17 ( void ){
bool X=false, Y=false, Z=false;
printf ( "EXEMPLO207 - OPERAR VALORES LOGICOS" );
X = true;
Y = false;
Z = X || Y;
printf ( "\nA DISJUNCAO ENTRE VERDADEIRO E FALSO = %d", Z );
Z = X && Y;
printf ( "\nA CONJUNCAO ENTRE VERDADEIRO E FALSO = %d", Z );
printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
getchar ( );
return ( EXIT_SUCCESS );
}

void method_18 ( void ){
double D = 0.0,
T = 0.0,
V = 0.0;
printf ( "EXEMPLO208 - CALCULAR A VELOCIDADE DE UM VEICULO" );
printf ( "\nFORNECER UMA DISTANCIA QUALQUER EM METROS: " );
scanf ( "%lf", &D );
getchar( );
printf ( "\nFORNECER O TEMPO PARA PERCORRE-LA EM SEGUNDOS: " );
scanf ( "%lf", &T );
getchar( );
V = D / T;
printf ( "\nV = D / T = %lf%s", V, " m/s " );
printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
getchar( );
return ( EXIT_SUCCESS );
}

void method_19 ( void ){
const char SENHA[5] = "XXXX";
char S [10];
printf ( "EXEMPLO209 - COMPARAR CARACTERES COM UMA SENHA" );
printf ( "\nFORNECER UMA CADEIA DE CARACTERES QUALQUER: " );
scanf ( "%s", S );
getchar( );
printf ( "\nA COMPARACAO COM A SENHA = %d", (strcmp(S,SENHA)==0)?1:0 );
strcmp(S1,S2) compara S1 com S2
igual a 0: S1 = S2 => 1 ( verdadeiro )
diferente: S1 <> S2 => 0 ( falso )
printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
getchar( );
return ( ( EXIT_SUCCESS ) );
}

void method_20 ( void ){
const double PI = 3.14;
double ARCO = 0.0,
COSSENO = 0.0,
SENO = 0.0,
TANGENTE = 0.0;
printf ( "EXEMPLO210 - CALCULAR O ARCO TRIGONOMETRICO DE UM SENO" );
printf ( "\nFORNECER O VALOR DO SENO: " );
scanf ( "%lf", &SENO );
getchar( );
COSSENO = sqrt( 1.0 - pow(SENO,2) );
TANGENTE = SENO / COSSENO;
ARCO
= atan( TANGENTE );
printf ( "\nO ARCO TRIGONOMETRICO EM GRAUS = %lf", (ARCO*180.0/PI) );
printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
getchar( );
return ( EXIT_SUCCESS );
}

void method_21 ( void ){
int X = 0;
printf ( "EXEMPLO301 - LER E TESTAR UM VALOR INTEIRO" );
printf ( "\nFORNECER UM VALOR INTEIRO QUALQUER: " );
scanf ( "%d", &X );
getchar( );
if ( X == 0 )
printf ( "\nO VALOR DIGITADO FOI ZERO" );
else
printf ( "\nO VALOR DIGITADO NAO FOI ZERO" );
printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
getchar( );
return ( EXIT_SUCCESS );
}

void method_22 ( void ){
float X = 0.0;
printf ( "EXEMPLO302 - LER E TESTAR UM VALOR REAL" );
printf ( "\nFORNECER UM VALOR REAL DIFERENTE DE ZERO: " );
scanf ( "%f", &X );
getchar( );
if( X != 0.0 )
printf ( "\nO VALOR DIGITADO FOI DIFERENTE DE ZERO" );
printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
getchar( );
return ( EXIT_SUCCESS );
}

void method_23 ( void ){
char X = '0';
printf ( "EXEMPLO303 - LER E TESTAR UM CARACTERE" );
printf ( "\nFORNECER UM ALGARISMO QUALQUER: " );
scanf ( "%c", &X );
getchar( );
if( X >= '0' && X <= '9' ){
printf ( "\nO VALOR DIGITADO FOI UM ALGARISMO" );
printf ( "\nO ALGARISMO DIGITADO FOI: %c", X );
}
printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
getchar( );
return ( EXIT_SUCCESS );
}

void method_24 ( void ){
char X = '0';
printf ( "EXEMPLO304 - LER E TESTAR CARACTERE" );
printf ( "\nFORNECER UM CARACTERE QUALQUER: " );
scanf ( "%c", &X );
getchar( );
if( !( X >= '0' && X <= '9') ){
printf ( "\nNAO FOI DIGITADO UM ALGARISMO" );
printf ( "\nFOI DIGITADO O CARACTERE: %c", X );
} 
printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
getchar( );
return ( EXIT_SUCCESS );
}

void method_25 ( void ){
int X=0, Y=0;
printf ( "EXEMPLO305 - LER E TESTAR DOIS VALORES INTEIROS" );
printf ( "\nFORNECER UM VALOR INTEIRO QUALQUER: " );
scanf ( "%d", &X );
getchar( );
printf ( "\nFORNECER OUTRO VALOR INTEIRO QUALQUER: " );
scanf ( "%d", &Y );
getchar( );
if( X == Y )
printf ( "\nDOIS VALORES IGUAIS" );
else{
printf ( "\n%d", X );
printf ( " DIFERENTE DE " );
printf ( "%d", Y );
}
printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
getchar( );
return ( EXIT_SUCCESS );
}

void method_26 ( void ){
double X=0.0, Y=0.0;
printf ( "EXEMPLO306 - LER E TESTAR DOIS VALORES REAIS" );
printf ( "\nFORNECER UM VALOR REAL QUALQUER: " );
scanf ( "%lf", &X );
getchar( );
printf ( "\nFORNECER OUTRO VALOR REAL QUALQUER: " );
scanf ( "%lf", &Y );
getchar( );
if( ! (X == Y) ){
printf ( "\n%lf", X );
printf ( " DIFERENTE DE " );
printf ( "%lf", Y );
}
else{
printf ( "VALORES IGUAIS" );
} 
printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
getchar( );
return ( EXIT_SUCCESS );
}

void method_26 ( void ){
int X=0, Y=0;
bool Z=false;
printf ( "EXEMPLO307 - TRATAR VALORES LOGICOS" );
printf ( "\nFORNECER UM VALOR INTEIRO QUALQUER: " );
scanf ( "%d", &X );
getchar( );
printf ( "\nFORNECER OUTRO VALOR INTEIRO QUALQUER: " );
scanf ( "%d", &Y );
getchar( );
Z = (X == Y);
if( Z )
printf ( "VALORES IGUAIS" );
else
printf ( "VALORES DIFERENTES" );
printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
getchar( );
return ( EXIT_SUCCESS );
}

void method_28 ( void ){
char X = '0';
printf ( "EXEMPLO308 - LER E TESTAR UMA LETRA" );
printf ( "\nFORNECER UMA LETRA QUALQUER: " );
scanf ( "%c", &X );
getchar( );
if( X >= 'A' && X <= 'Z' )
printf ( "FOI DIGITADA UMA LETRA MAIUSCULA" );
else
if( X >= 'a' && X <= 'z' )
printf ( "FOI DIGITADA UMA LETRA MINUSCULA" );
else
printf ( "NAO FOI DIGITADA UMA LETRA" );
printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
getchar( );
return ( EXIT_SUCCESS );
}

void method_29 ( void ){
char X = '0';
printf ( "EXEMPLO309 - COMPARAR CARACTERES < , = , >" );
printf ( "\nFORNECER UM DOS CARACTERES CITADOS: " );
scanf ( "%c", &X );
getchar( );
switch( X )
{
case '>': printf ( "FOI DIGITADO O SINAL DE MAIOR" );
break;
case '=': printf ( "FOI DIGITADO O SINAL DE IGUAL" );
break;
case '<': printf ( "FOI DIGITADO O SINAL DE MENOR" );
break;
default : printf ( "FOI DIGITADO UM OUTRO CARACTERE QUALQUER" );
}
printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
getchar ( );
return ( EXIT_SUCCESS );
}

void method_30 ( void ){
char X = '0';
printf ( "EXEMPLO310 - IDENTIFICAR CARACTERES" );
printf ( "\nFORNECER UM CARACTERE QUALQUER: " );
scanf ( "%c", &X );
getchar( );
switch ( X )
{
case 'A':
case 'E':
case 'I':
case 'O':
case 'U': printf ( "FOI DIGITADO UMA VOGAL" );
break;
case '0':
case '1':
case '2':
case '3':
case '4':
case '5':
case '6':
case '7':
case '8':
case '9': printf ( "FOI DIGITADO UM ALGARISMO" );
printf ( "\nO NUMERO CORRESPONDENTE = %d", (X-48) );
break;
default: printf ( "FOI DIGITADO UM OUTRO CARACTERE QUALQUER" );
}
printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
getchar ( );
return ( EXIT_SUCCESS );
}

void method_31 ( void ){
int X = 0,
CONTADOR = 0;
printf ( "EXEMPLO401 - LER E IMPRIMIR 03 VALORES INTEIROS" );
printf ( "\n" );
CONTADOR = 1;
while ( CONTADOR <= 3 )
{
printf ( "\n" );
printf ( "%d. FORNECER UM VALOR INTEIRO : ", CONTADOR );
scanf( "%d", &X );
getchar( );
printf ( "\nO VALOR DIGITADO FOI : %d\n", X );
CONTADOR = CONTADOR + 1;
}
printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
getchar ( );
return ( EXIT_SUCCESS );
}

void method_32 ( void ){
int X = 0, N = 0, CONTADOR = 0;
printf ( "EXEMPLO402 - LER E IMPRIMIR (N) VALORES INTEIROS\n" );
printf ( "\nFORNECER O NUMERO DE VEZES (N) : " );
scanf ( "%d", &N );
getchar( );
CONTADOR = 1;
while ( CONTADOR <= N )
{
printf ( "\n%d", CONTADOR );
printf ( " FORNECER UM VALOR INTEIRO QUALQUER : " );
scanf ( "%d", &X );
getchar( );
printf ( "\nO VALOR DIGITADO FOI : %d\n", X );
CONTADOR = CONTADOR + 1;
}
printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
getchar ( );
return ( EXIT_SUCCESS );
}

void method_33 ( void ){
int X = 0, N = 0;
printf ( "EXEMPLO403 - LER E IMPRIMIR (N) VALORES INTEIROS\n" );
printf ( "\nFORNECER O NUMERO DE VEZES (N) : " );
scanf ( "%d", &N );
getchar( );
while ( N > 0 )
{
printf ( "\n%d", N );
printf ( " FORNECER UM VALOR INTEIRO QUALQUER : " );
scanf ( "%d", &X );
getchar( );
printf ( "\nO VALOR DIGITADO FOI : %d\n", X );
N = N - 1;
}
printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
getchar ( );
return ( EXIT_SUCCESS );
}

void method_34 ( void ){
int X
= 0,
CONTADOR = 0;
printf ( "EXEMPLO404 - LER E IMPRIMIR 03 VALORES INTEIROS\n" );
for ( CONTADOR = 1; CONTADOR <= 3; CONTADOR = CONTADOR+1)
{
printf ( "\n%d. FORNECER UM VALOR INTEIRO : ", CONTADOR );
scanf ( "%d", &X );
getchar( );
printf ( "\nO VALOR DIGITADO FOI : %d\n", X );
}
printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
getchar ( );
return ( EXIT_SUCCESS );
}

void method_35 ( void ){
int X
= 0,
N
= 0,
CONTADOR = 0;
printf ( "EXEMPLO405 - LER E IMPRIMIR (N) VALORES INTEIROS\n" );
printf ( "\nFORNECER O NUMERO DE VEZES (N) : " );
scanf ( "%d", &N );
getchar( );
for ( CONTADOR = 1; CONTADOR <= N; CONTADOR++ )
{
printf ( "\n%d. FORNECER UM VALOR INTEIRO : ", CONTADOR );
scanf ( "%d", &X );
getchar( );
printf ( "\nO VALOR DIGITADO FOI : %d", X );
}
printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
getchar ( );

return ( EXIT_SUCCESS );
}

void method_36 ( void ){
int X
= 0,
CONTADOR = 0;
printf ( "EXEMPLO406 - LER E IMPRIMIR 03 VALORES INTEIROS\n" );
CONTADOR = 1;
do

{
printf ( "\n%d. FORNECER UM VALOR INTEIRO : ", CONTADOR );
scanf ( "%d", &X );
getchar( );
printf ( "\nO VALOR DIGITADO FOI : %d\n", X );
CONTADOR = CONTADOR + 1;
}
while ( CONTADOR <= 3 );
printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
getchar ( );
return ( EXIT_SUCCESS );
}

void method_37 ( void ){
int X
= 0,
CONTADOR = 0;
printf ( "EXEMPLO407 - LER E IMPRIMIR (N) VALORES INTEIROS\n" );
printf ( "\nFORNECER O NUMERO DE VEZES (N) : " );
scanf ( "%d", &CONTADOR );
getchar( );

do{
printf ( "\n%d. FORNECER UM VALOR INTEIRO : ", CONTADOR );
scanf ( "%d", &X );
getchar( );

printf ( "\nO VALOR DIGITADO FOI : %d\n", X );
CONTADOR = CONTADOR - 1;
}
while ( CONTADOR > 0 );
printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
getchar ( );
return ( EXIT_SUCCESS );
}

void method_38 ( void ){
int X = 0;
printf ( "EXEMPLO408 - LER E IMPRIMIR INTEIROS NAO NULOS\n" );
printf ( "\nFORNECER UM VALOR INTEIRO (0 = PARAR) : " );
scanf ( "%d", &X );
getchar( );
while ( X != 0 )
{
printf ( "\nO VALOR DIGITADO FOI : %d\n", X );
printf ( "\nDIGITE UM VALOR INTEIRO QUALQUER : " );
scanf ( "%d", &X );
getchar( );

}
printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
getchar ( );
return ( EXIT_SUCCESS );
}

void method_39 ( void ){
int X = 0;
printf ( "EXEMPLO409 - PARA LER UM INTEIRO NAO NULO\n" );
printf ( "\nFORNECER UM VALOR DIFERENTE DE ZERO : " );
scanf ( "%d", &X );
getchar( );
while ( X == 0 ){
printf ( "\nFORNECER UM VALOR DIFERENTE DE ZERO : " );
scanf ( "%d", &X );
getchar( );
}
printf ( "\nDIGITADO UM NUMERO DIFERENTE DE ZERO\n" );
printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
getchar ( );
return ( EXIT_SUCCESS );
}

void method_40 ( void ){
int X = 0;
printf ( "EXEMPLO410 - LER UM INTEIRO NAO NULO\n" );
do
{
printf ( "\nFORNECER UM VALOR DIFERENTE DE ZERO : " );
scanf ( "%d", &X );
getchar( );
}
while ( X == 0 );
printf ( "\nDIGITADO UM NUMERO DIFERENTE DE ZERO\n" );
printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
getchar ( );
return ( EXIT_SUCCESS );
}

void method_41 ( void ){
printf ( "\n" );
printf ( "\nCHAMADO O PROCEDIMENTO P1 SEM PARAMETROS" );
printf ( "\n" );
}
int main ( void )
{
printf ( "EXEMPLO0501 - CHAMADA A UM PROCEDIMENTO" );
P1 ( );
printf ( "\n" );
printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
getchar ( );
return ( EXIT_SUCCESS );
}

void method_42 ( void ){
printf ( "\n" );
printf ( "\nCHAMADO O PROCEDIMENTO P1 %d VEZ(ES)", X );
printf ( "\n" );
}
int main ( void )
{
printf ( "EXEMPLO0502 - CHAMADA COM VARIAVEL GLOBAL\n" );
for ( X = 1; X <= 5; X = X + 1 )
P1 ( );
printf ( "\n" );
printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
getchar ( );
return ( EXIT_SUCCESS );
}

void method_43 ( void ){
printf ( "\nCHAMADO O PROCEDIMENTO P1 %d VEZ(ES)", X );
printf ( "\n" );
if ( X < 5 )
P1 ( );
printf ( "\nRETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA %d", X );
X = X - 1;
getchar ( );
} 
int main ( void )
{
printf ( "EXEMPLO0503 - CHAMADA/RETORNO COM VARIAVEL GLOBAL\n" );
X = 0;
P1 ( );
printf ( "\n" );
printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
getchar ( );
return ( EXIT_SUCCESS );
}

void method_44 ( void ){
printf ( "\nCHAMADO O PROCEDIMENTO P1 %d VEZ(ES)\n", X );
if ( X < 5 )
P1( X + 1 );
printf ( "\nRETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA %d", X );
getchar ( );
}
int main ( void )
{
printf ( "EXEMPLO0504 - CHAMADA/RETORNO COM PARAMETRO\n" );
P1 ( 1 );
printf ( "\n" );
printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
getchar ( );
return ( EXIT_SUCCESS );
}

void method_45 ( void ){
printf ( "\nCHAMADO O PROCEDIMENTO P1 %d VEZ(ES)\n", X );
if ( X > 1 )
P1 ( X - 1 );
printf ( "\nRETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA %d", X );
getchar ( );
}
int main ( void )
{
printf ( "EXEMPLO0505 - CHAMADA/RETORNO COM PARAMETRO\n" );
P1 ( 5 );
printf ( "\n" );
printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
getchar ( );
return ( EXIT_SUCCESS );
}

void method_46 ( void ){
printf ( "CHAMADO O PROCEDIMENTO P1 COM X = %d\n", X );
if ( X < 5 )
P2 ( X );
printf ( "RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA COM X = %d\n", X );
getchar ( );
}
void P2 (int X)
{
printf ( "CHAMADO O PROCEDIMENTO P2 COM X = %d\n", X );
X = X+1;
printf ( "RETORNANDO AO PROCEDIMENTO P2 PARA A CHAMADA COM X = %d\n", X );
getchar ( );
P1 ( X );
}
int main ( void )
{

printf ( "EXEMPLO0506 - CHAMADA/RETORNO COM PARAMETRO\n\n" );
P1 ( 1 ); 
printf ( "\n" );
printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
getchar ( );
return ( EXIT_SUCCESS );
}

void method_47 ( void ){
*X = *X + 1;
printf ( "\nCHAMADO O PROCEDIMENTO P1 %d VEZ(ES)\n", *X );
if ( *X < 5 )
P1 ( X );
printf ( "\nRETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA %d", *X );
*X = *X - 1;
getchar ( );
} 
int main ( void ){
int X;
printf ( "EXEMPLO0507 - CHAMADA/RETORNO COM REFERENCIA\n" );
X = 0;
P1 ( &X );
printf ( "\n" );
printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
getchar ( );
return ( EXIT_SUCCESS );
}

void method_48 ( void ){
X = X + 1;
printf ( "CHAMADO O PROCEDIMENTO P1 COM X = %d\n", X );
if ( X < 4 )
{
P1 ( X );
P2 ( X );
}
printf ( "\nRETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA COM X = %d\n", X );
getchar ( ) ;
} 
void P2 ( int X )
{
printf ( "CHAMADO O PROCEDIMENTO P2 COM X = %d\n", X );
if ( X > 1 )
P2 ( X - 1 );
printf ( "RETORNANDO AO PROCEDIMENTO P2 PARA A CHAMADA COM X = %d", X );
getchar ( );
} 
int main ( void )
{
printf ( "EXEMPLO0508 - MULTIPLAS CHAMADAS/RETORNOS\n\n" );
P1 ( 1 );
printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
getchar ( );
return ( EXIT_SUCCESS );
}

void method_49 ( void ){
println ( "EXEMPLO0509 - USO DE MODULOS" );
pause ( "PRESSIONAR <Enter> PARA TERMINAR." );
return ( EXIT_SUCCESS );
}

void method_50 ( void ){

} 

int main ( int argc, char* argv [ ] ){

int opcao = 0;

printf ( "%s\n", "Exemplo00M0" );
printf ( "%s\n", "Autor: Miguel Pessoa Lima" );
printf ( "\n" );

do{
    printf ( "\n%s\n", "Opcoes:");
    printf ( "\n%s" , "0 - Terminar" );
    printf ( "\n%s" , "1 - Method_01" );
    printf ( "\n%s" , "2 - Method_02" );
    printf ( "\n%s" , "3 - Method_03" );
    printf ( "\n%s" , "4 - Method_04" );
    printf ( "\n%s" , "5 - Method_05" );
    printf ( "\n%s" , "6 - Method_06" );
    printf ( "\n%s" , "7 - Method_07" );
    printf ( "\n%s" , "8 - Method_08" );
    printf ( "\n%s" , "9 - Method_09" );
    printf ( "\n%s" , "10 - Method_10" );
    printf ( "\n%s" , "10 - Method_11" );
    printf ( "\n%s" , "10 - Method_12" );
    printf ( "\n%s" , "10 - Method_13" );
    printf ( "\n%s" , "10 - Method_14" );
    printf ( "\n%s" , "10 - Method_15" );
    printf ( "\n%s" , "10 - Method_16" );
    printf ( "\n%s" , "10 - Method_17" );
    printf ( "\n%s" , "10 - Method_18" );
    printf ( "\n%s" , "10 - Method_19" );
    printf ( "\n%s" , "10 - Method_20" );
    printf ( "\n%s" , "10 - Method_21" );
    printf ( "\n%s" , "10 - Method_22" );                
    printf ( "\n%s" , "10 - Method_23" );
    printf ( "\n%s" , "10 - Method_24" );
    printf ( "\n%s" , "10 - Method_25" );
    printf ( "\n%s" , "10 - Method_26" );
    printf ( "\n%s" , "10 - Method_27" );
    printf ( "\n%s" , "10 - Method_28" );
    printf ( "\n%s" , "10 - Method_29" );
    printf ( "\n%s" , "10 - Method_30" );
    printf ( "\n%s" , "10 - Method_31" );
    printf ( "\n%s" , "10 - Method_32" );
    printf ( "\n%s" , "10 - Method_33" );
    printf ( "\n%s" , "10 - Method_34" );
    printf ( "\n%s" , "10 - Method_35" );
    printf ( "\n%s" , "10 - Method_36" );
    printf ( "\n%s" , "10 - Method_37" );
    printf ( "\n%s" , "10 - Method_38" );
    printf ( "\n%s" , "10 - Method_39" );
    printf ( "\n%s" , "10 - Method_40" );
    printf ( "\n%s" , "10 - Method_41" );
    printf ( "\n%s" , "10 - Method_42" );
    printf ( "\n%s" , "10 - Method_43" );
    printf ( "\n%s" , "10 - Method_44" );
    printf ( "\n%s" , "10 - Method_45" );
    printf ( "\n%s" , "10 - Method_46" );
    printf ( "\n%s" , "10 - Method_47" );
    printf ( "\n%s" , "10 - Method_48" );
    printf ( "\n%s" , "10 - Method_49" );
    printf ( "\n%s" , "10 - Method_50" );

    printf ( "\n" );
    printf ( "\n%s", "Opcao = " );
    scanf ( "%d", &opcao );
    getchar( );
    printf ( "\n%s%d", "Opcao = ", opcao );

        switch ( opcao ){
            case 0: break;
            case 1: method_01 ( ); break;
            case 2: method_02 ( ); break;
            case 3: method_03 ( ); break;
            case 4: method_04 ( ); break;
            case 5: method_05 ( ); break;
            case 6: method_06 ( ); break;
            case 7: method_07 (); break;
            case 8: method_08 (); break;
            case 9: method_09 (); break;
            case 10: method_10 (); break;
            case 11: method_11 (); break;
            case 12: method_12 (); break;
            case 13: method_13 (); break;
            case 14: method_14 (); break;
            case 15: method_15 (); break;
            case 16: method_16 (); break;
            case 17: method_17 (); break;
            case 18: method_18 (); break;
            case 19: method_19 (); break;
            case 20: method_20 (); break;
            case 21: method_21 (); break;
            case 22: method_22 (); break;
            case 23: method_23 (); break;
            case 24: method_24 (); break;
            case 25: method_25 (); break;
            case 26: method_26 (); break;
            case 27: method_27 (); break;
            case 28: method_28 (); break;
            case 29: method_29 (); break;
            case 30: method_30 (); break;
            case 31: method_31 (); break;
            case 32: method_32 (); break;
            case 33: method_33 (); break;
            case 34: method_34 (); break;
            case 35: method_35 (); break;
            case 36: method_36 (); break;
            case 37: method_37 (); break;
            case 38: method_38 (); break;
            case 39: method_39 (); break;
            case 40: method_40 (); break;
            case 41: method_41 (); break;
            case 42: method_42 (); break;
            case 43: method_43 (); break;
            case 44: method_44 (); break;
            case 45: method_45 (); break;
            case 46: method_46 (); break; 
            case 47: method_47 (); break;
            case 48: method_48 (); break;
            case 49: method_49 (); break;
            case 50: method_50 (); break;
                                                    

            default: printf ( "\nERRO: Opcao invalida.\n" );break;
        } 
}

while ( opcao != 0 );
printf ( "\n\nApertar ENTER para terminar." );
getchar( );
return ( 0 );

} 

/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
---------------------------------------------- historico
Versao      Teste
0.1          01. ( OK )
0.2          01. ( OK )

Data
__/__
Modificacao
esboco
---------------------------------------------- testes
Versao
0.0
Teste  00. ( ___ )
identificacao de programa
*/