#include <iostream>
#include <limits>
#include <string>
#include <math.h>
#include <cstdlib>
#include <fstream>
void pause ( std::string text )
{
 std::string dummy;
 std::cin.clear ( );
 std::cout << std::endl << text;
 std::cin.ignore( );
 std::getline(std::cin, dummy);
 std::cout << std::endl << std::endl;
}
#include "mymatrix.hpp"
#include <iostream>
using std::cin ; // para entrada
using std::cout; // para saida
using std::endl; // para mudar de linha
#include <iomanip>
using std::setw; // para definir espacamento
#include <string>
using std::string; // para cadeia de caracteres
#include <fstream>
using std::ofstream; // para gravar arquivo
using std::ifstream; // para ler arquivo

using namespace std;
void metodo00 ( )
{
}
void metodo01 ( )
{
// identificar
 cout << endl << "Metodo1" << endl;
// definir dados
 Matrix <int> int_matrix ( 2, 2, 0 );
 int_matrix.set ( 0, 0, 1 ); int_matrix.set ( 0, 1, 2 );
 int_matrix.set ( 1, 0, 3 ); int_matrix.set ( 1, 1, 4 );
// mostrar dados
 int_matrix.print ( );
// encerrar
 pause ( "Apertar ENTER para continuar" );
} 
void metodo02 ( )
{
// identificar
 cout << endl << "Metodo2" << endl;
// definir dados
 Matrix <int> matrix ( 2, 2, 0 );
// ler dados
 matrix.read ( );
// mostrar dados
 matrix.print ( );
// encerrar
 pause ( "Apertar ENTER para continuar" );
}
void metodo03 ( )
{
// identificar
 cout << endl << "Metodo3" << endl;
 Matrix <int> matrix ( 2, 2, 0 );
// ler dados
 matrix.read ( );
// mostrar dados
 matrix.print ( );
// gravar dados
 matrix.fprint( "MATRIX1.TXT" );
// encerrar
 pause ( "Apertar ENTER para continuar" );
}
void metodo04 ( )
{
// identificar
 cout << endl << "Metodo4" << endl;

// definir dados
 Matrix <int> matrix ( 1, 1, 0 );
// ler dados
 matrix.fread ( "MATRIX1.TXT" );
// mostrar dados
 matrix.print ( );
// encerrar
 pause ( "Apertar ENTER para continuar" );
}
void metodo05 ( )
{
// identificar
 cout << endl << "Metodo5" << endl;
{
// definir dados
 Matrix <int> int_matrix1 ( 1, 1, 0 );
 Matrix <int> int_matrix2 ( 1, 1, 0 );
// ler dados
 int_matrix1.fread ( "MATRIX1.TXT" );
// mostrar dados
 cout << "\nOriginal\n" << endl;
 int_matrix1.print ( );
// copiar dados
 int_matrix2 = int_matrix1;
// mostrar dados
 cout << "\nCopia\n" << endl;
 int_matrix2.print ( );
// encerrar
 pause ( "Apertar ENTER para continuar" );
}
}
void metodo06 ( )
{
// identificar
 cout << endl << "Metodo6" << endl;
// definir dados
 Matrix <int> int_matrix ( 2, 2, 0 );
 int_matrix.set ( 0, 0, 0 ); int_matrix.set ( 0, 1, 0 );
 int_matrix.set ( 1, 0, 0 ); int_matrix.set ( 1, 1, 0 );
// mostrar dados
 int_matrix.print ( );
// testar condicao
 cout << "Zeros = " << int_matrix.isZeros ( ) << endl;
// ler dados
 int_matrix.fread ( "MATRIX1.TXT" );
// mostrar dados
 int_matrix.print ( );
// testar condicao
 cout << "Zeros = " << int_matrix.isZeros ( ) << endl;
// encerrar
 pause ( "Apertar ENTER para continuar" );

}
void metodo07 ( )
{
// identificar
 cout << endl << "Metodo7" << endl;
// definir dados
 Matrix <int> int_matrix1 ( 1, 1, 0 );
 Matrix <int> int_matrix2 ( 1, 1, 0 );
// ler dados
 int_matrix1.fread ( "MATRIX1.TXT" );
// mostrar dados
 cout << "\nMatrix_1\n";
 int_matrix1.print ( );
// copiar dados
 int_matrix2 = int_matrix1;
// mostrar dados
 cout << "\nMatrix_2\n";
 int_matrix2.print ( );
// testar condicao
 cout << "Diferentes = " << (int_matrix1!=int_matrix2) << endl;
// alterar dados
 int_matrix2.set ( 0, 0, (-1) );
// mostrar dados
 cout << "\nMatrix_1\n";
 int_matrix1.print ( );
// mostrar dados
 cout << "\nMatrix_2\n";
 int_matrix2.print ( );
// testar condicao
 cout << "Diferentes = " << (int_matrix1!=int_matrix2) << endl;
// encerrar
 pause ( "Apertar ENTER para continuar" );

}
void metodo08 ( )
{
// identificar
 cout << endl << "Metodo8" << endl;

// definir dados
 Matrix <int> int_matrix1 ( 1, 1, 0 );
 Matrix <int> int_matrix2 ( 1, 1, 0 );
 Matrix <int> int_matrix3 ( 1, 1, 0 );
// ler dados
 int_matrix1.fread ( "MATRIX1.TXT" );
// mostrar dados
 cout << "\nMatrix_1\n";
 int_matrix1.print ( );
// copiar dados
 int_matrix2 = int_matrix1;
// mostrar dados
 cout << "\nMatrix_2\n";
 int_matrix2.print ( );
// operar dados
 int_matrix3 = int_matrix1 - int_matrix2;
// mostrar dados
 cout << "\nMatrix_3\n";
 int_matrix3.print ( );
// encerrar
 pause ( "Apertar ENTER para continuar" );
}
void metodo09 ( )
{
// identificar
 cout << endl << "Metodo9" << endl;
{
// definir dados
 Matrix <int> int_matrix1 ( 2, 2, 0 );
 int_matrix1.set ( 0, 0, 1 );
 int_matrix1.set ( 0, 1, 0 );
 int_matrix1.set ( 1, 0, 0 );
 int_matrix1.set ( 1, 1, 1 );
 Matrix <int> int_matrix2 ( 1, 1, 0 );
 Matrix <int> int_matrix3 ( 1, 1, 0 );
// ler dados
 int_matrix2.fread ( "MATRIX1.TXT" );
// mostrar dados
 cout << "\nMatrix_1\n";
 int_matrix1.print ( );
// mostrar dados
 cout << "\nMatrix_2\n";
 int_matrix2.print ( );
// operar dados
 int_matrix3 = int_matrix1 * int_matrix2;
// mostrar dados
 cout << "\nMatrix_3\n";
 int_matrix3.print ( );
// encerrar
 pause ( "Apertar ENTER para continuar" );

}
}
void metodo10 ( )
{
// identificar
 cout << endl << "Metodo10" << endl;
 
// definir dados
 Matrix <int> int_matrix ( 3, 3, 0 );
 int x = 0;
 int y = 0;
// ler dados
 int_matrix.fread ( "MATRIX1.TXT" );
// mostrar dados
 cout << "\nMatrix\n";
 int_matrix.print ( );
// operar dados
 for ( int x = 0; x < int_matrix.getRows ( ); x=x+1 )
 {
 for ( int y = 0; y < int_matrix.getColumns ( ); y=y+1 )
 {
 int_matrix.set ( x, y, int_matrix.get ( x, y ) * (-1) );
 } // end for
 } // end for
// mostrar dados
 cout << "\nMatrix\n";
 int_matrix.print ( );
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