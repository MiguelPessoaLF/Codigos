#include <iostream> // std::cin, std::cout, std:endl
#include <limits> // std::numeric_limits
#include <string> // para cadeias de caracteres
// ----------------------------------------------- definicoes globais
void pause ( std::string text )
{
 std::string dummy;
 std::cin.clear ( );
 std::cout << std::endl << text;
 std::cin.ignore( );
 std::getline(std::cin, dummy);
 std::cout << std::endl << std::endl;
} // end pause ( )
// ----------------------------------------------- classes / pacotes
#include "myarray.hpp"
using namespace std;
void metodo00 ( )
{
}
void metodo01 ( )
{
// identificar
 cout << endl << "Metodo1" << endl;
// definir dados
 Array <int> int_array ( 5, 0 );
 int_array.set ( 0, 1 );
 int_array.set ( 1, 2 );
 int_array.set ( 2, 3 );
 int_array.set ( 3, 4 );
 int_array.set ( 4, 5 );
// mostrar dados
 int_array.print ( );
// reciclar espaco
 int_array.free ( );
// encerrar
 pause ( "Apertar ENTER para continuar" );
} 
void metodo02 ( )
{
// identificar
 cout << endl << "Metodo2" << endl;
// definir dados
 Array <int> int_array ( 5, 0 );
// ler dados
 int_array.read ( );
// mostrar dados
 int_array.print ( );
// reciclar espaco
 int_array.free ( ); 
// encerrar
 pause ( "Apertar ENTER para continuar" );
}
void metodo03 ( )
{
// identificar
 cout << endl << "Metodo3" << endl;
// definir dados
 Array <int> int_array ( 5, 0 );
// ler dados
 int_array.read ( );
// mostrar dados
 int_array.fprint ( "INT_ARRAY1.TXT" );
// reciclar espaco
 int_array.free ( ); 
// encerrar
 pause ( "Apertar ENTER para continuar" );

}
void metodo04 ( )
{
// identificar
 cout << endl << "Metodo4" << endl;
// definir dados
 Array <int> int_array ( 5, 0 );
// ler dados
 int_array.fread ( "INT_ARRAY1.TXT" );
// mostrar dados
 int_array.print ( );
// reciclar espaco
 int_array.free ( ); 
// encerrar
 pause ( "Apertar ENTER para continuar" );
}
void metodo05 ( )
{
// identificar
 cout << endl << "Metodo5" << endl;

// definir dados
 int other [ ] = { 1, 2, 3, 4, 5 };
 Array <int> int_array ( 5, other );
// mostrar dados
 cout << "\nCopia\n" << endl;
 int_array.print ( );
// reciclar espaco
 int_array.free ( ); 
// encerrar
 pause ( "Apertar ENTER para continuar" );
}
void metodo06 ( )
{
// identificar
 cout << endl << "Metodo6" << endl;
// definir dados
 Array <int> int_array1 ( 1, 0 );
// ler dados
 int_array1.fread ( "INT_ARRAY1.TXT" );
// mostrar dados
 cout << "\nOriginal\n" << endl;
 int_array1.print ( );
// criar copia
 Array <int> int_array2 ( int_array1 );
// mostrar dados
 cout << "\nCopia\n" << endl;
 int_array2.print ( );
// reciclar espaco
 int_array1.free ( ); 
 int_array2.free ( );
// encerrar
 pause ( "Apertar ENTER para continuar" );

}
void metodo07 ( )
{
// identificar
 cout << endl << "Metodo7" << endl;
// definir dados
 Array <int> int_array1 ( 1, 0 );
 Array <int> int_array2 ( 1, 0 );
// ler dados
 int_array1.fread ( "INT_ARRAY1.TXT" );
// mostrar dados
 cout << "\nOriginal\n" << endl;
 int_array1.print ( );
// copiar dados
 int_array2 = int_array1;
// mostrar dados
 cout << "\nCopia\n" << endl;
 int_array2.print ( );
// reciclar espaco
 int_array1.free ( ); 
 int_array2.free ( ); 
// encerrar
 pause ( "Apertar ENTER para continuar" );
}
void metodo08 ( )
{
// identificar
 cout << endl << "Metodo8" << endl;

// definir dados
 int other [ ] = { 1, 2, 3 };
 Array <int> int_array1 ( 3, other );
 Array <int> int_array2 ( 3, other );
 int x;
// mostrar dados
 cout << endl;
 cout << "Array_1";
 int_array1.print ( );
// mostrar dados
 cout << "Array_2";
 int_array2.print ( );
// mostrar comparacao
 cout << "Igualdade = " << (int_array1==int_array2) << endl;
// alterar dado
 int_array2.set ( 0, (-1) );
// mostrar dados
 cout << endl;
 cout << "Array_1" << endl;
 int_array1.print ( );
 
 cout << "Array_2" << endl;
 int_array2.print ( );
// mostrar comparacao
 cout << "Igualdade = " << (int_array1==int_array2) << endl;
// reciclar espaco
 int_array1.free ( ); 
 int_array2.free ( ); 
// encerrar
 pause ( "Apertar ENTER para continuar" );
}
void metodo09 ( )
{
// identificar
 cout << endl << "Metodo9" << endl;
// definir dados
 Array <int> int_array1 ( 1, 0 );
 Array <int> int_array2 ( 1, 0 );
 Array <int> int_array3 ( 1, 0 );
// ler dados
 int_array1.fread ( "INT_ARRAY1.TXT" );
// copiar dados
 int_array2 = int_array1;
// somar dados
 int_array3 = int_array2 + int_array1;
// mostrar dados
 cout << endl;
 cout << "Original" << endl;
 int_array1.print ( );
// mostrar dados
 cout << "Copia" << endl;
 int_array2.print ( );
// mostrar dados
 cout << "Soma" << endl;
 int_array3.print ( );
// reciclar espaco
 int_array1.free ( ); 
 int_array2.free ( ); 
 int_array3.free ( ); 
// encerrar
 pause ( "Apertar ENTER para continuar" );
}
void metodo10 ( )
{
// identificar
 cout << endl << "Metodo10" << endl;
// definir dados
 int other [ ] = { 1, 2, 3, 4, 5 };
 Array <int> int_array ( 5, other );
 int x;
// mostrar dados
 cout << "\nAcesso externo" << endl;
 for ( x=0; x<int_array.getLength( ); x=x+1 )
 {
 cout << endl << setw( 3 ) << x << " : " << int_array [ x ];
 } // fim repetir
 cout << endl << "\nFora dos limites:";
 cout << endl << "[-1]: " << int_array.get(-1) << endl;
 cout << endl << "[" << int_array.getLength( ) << "]: " 
 << int_array [ int_array.getLength( ) ] << endl;
// reciclar espaco
 int_array.free ( ); 
// encerrar
 pause ( "Apertar ENTER para continuar" );
}
// ----------------------------------------------- acao principal
int main ( int argc, char** argv )
{
// definir dado
 int x = 0; // definir variavel com valor inicial
// repetir até desejar parar
 do
 {
 // identificar
 cout <<  "11/11/2024"   << endl; 
 cout << "Miguel Pessoa - Matricula 867160" << endl;
 // mostrar opcoes
 cout << "Opcoes " << endl;
 cout << " 0 - parar " << endl;
 cout << " 1 - metodo01" << endl;
 cout << " 2 - metodo02" << endl;
 cout << " 3 - metodo03" << endl;
 cout << " 4 - metodo04" << endl;
 cout << " 5 - metodo05" << endl;
 cout << " 6 - metodo06" << endl;
 cout << " 7 - metodo07" << endl;
 cout << " 8 - metod008" << endl;
 cout << " 9 - metodo09" << endl;
 cout << "10 - metodo10" << endl;
 // ler do teclado
 cout << endl << "Entrar com uma opcao: ";
 cin >> x;
 // escolher acao
 switch ( x )
 {
 case 0: metodo00 ( ); break;
 case 1: metodo01 ( ); break;
 case 2: metodo02 ( ); break;
 case 3: metodo03 ( ); break;
 case 4: metodo04 ( ); break;
 case 5: metodo05 ( ); break;
 case 6: metodo06 ( ); break;
 case 7: metodo07 ( ); break;
 case 8: metodo08 ( ); break;
 case 9: metodo09 ( ); break;
 case 10: metodo10 ( ); break;
 default:
 cout << endl << "ERRO: Valor invalido." << endl;
 } // end switch
 }
 while ( x != 0 );
// encerrar
 pause ( "Apertar ENTER para terminar" );
 return ( 0 );
}