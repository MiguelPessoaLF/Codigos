#include <iostream>
#include <limits>
#include <string>
#include <math.h>
#include <cstdlib>
#include <fstream>
#include "erro.hpp"
#include "contato.hpp"
using namespace std;
void metodo00 ( )
{
}
void metodo01 ( )
{
// identificar
 cout << endl << "Metodo1" << endl;
// definir dados
 Contato pessoa1;
 ref_Contato pessoa2 = nullptr;
 ref_Contato pessoa3 = new Contato ( );
// encerrar
 pause ( "Apertar ENTER para continuar" );
} 
void metodo02 ( )
{
// identificar
 cout << endl << "Metodo2" << endl;
// definir dados
 Contato pessoa1;
 ref_Contato pessoa2 = nullptr;
 ref_Contato pessoa3 = new Contato ( );
// testar atribuicoes
 pessoa1.setNome ( "Pessoa_01" );
 pessoa1.setFone ( "111" );
 pessoa3->setNome ( "Pessoa_03" );
 pessoa3->setFone ( "333" );
 cout << "pessoa1 - { " << pessoa1.getNome ( ) << ", " << pessoa1.getFone ( ) << " }" << endl;
 cout << "pessoa3 - { " << pessoa3->getNome ( ) << ", " << pessoa3->getFone ( ) << " }" << endl;
// encerrar
 pause ( "Apertar ENTER para continuar" );
}
void metodo03 ( )
{
// identificar
 cout << endl << "Metodo3" << endl;
// definir dados
 Contato pessoa1;
 ref_Contato pessoa2 = nullptr;
 ref_Contato pessoa3 = new Contato ( );
// testar atribuicoes
 pessoa1.setNome ( "Pessoa_01" );
 pessoa1.setFone ( "111" );
 pessoa3->setNome ( "Pessoa_03" );
 pessoa3->setFone ( "333" );
 cout << "pessoa1 - " << pessoa1.toString ( ) << endl;
 cout << "pessoa3 - " << pessoa3->toString ( ) << endl;
 // encerrar
 pause ( "Apertar ENTER para continuar" );
}
void metodo04 ( )
{
// identificar
 cout << endl << "Metodo4" << endl;
 
// definir dados
 Contato pessoa1 ( "Pessoa_01", "111" );
 ref_Contato pessoa2 = nullptr;
 ref_Contato pessoa3 = new Contato ( "Pessoa_03", "333" );
// testar atribuicoes
 cout << "pessoa1 - " << pessoa1.toString ( ) << endl;
 cout << "pessoa3 - " << pessoa3->toString ( ) << endl;
// encerrar
 pause ( "Apertar ENTER para continuar" );
}
void metodo05 ( )
{
// identificar
 cout << endl << "Metodo5" << endl;
// definir dados
 Contato pessoa1 ( "Pessoa_01", "111" );
 ref_Contato pessoa2 = nullptr;
 ref_Contato pessoa3 = new Contato ( "", "333" );
// testar atribuicoes
 cout << "pessoa1 - " << pessoa1.toString ( ) << " (" << pessoa1.getErro( ) << ")" << endl;
 cout << "pessoa3 - " << pessoa3->toString ( ) << " (" << pessoa3->getErro( ) << ")" << endl;
// encerrar
 pause ( "Apertar ENTER para continuar" );
}
void metodo06 ( )
{
// identificar
 cout << endl << "Metodo6" << endl;
{
// definir dados
 Contato pessoa1 ( "Pessoa_01", "111" );
 ref_Contato pessoa2 = nullptr;
 ref_Contato pessoa3 = new Contato ( "", "333" );
// testar atribuicoes
 if ( ! pessoa1.hasErro( ) )
 cout << "pessoa1 - " << pessoa1.toString( ) << endl;
 else
 cout << "pessoa1 tem erro (" << pessoa1.getErro( ) << ")" << endl;
 if ( ! pessoa3->hasErro( ) )
 cout << "pessoa3 - " << pessoa3->toString( ) << endl;
 else
 cout << "pessoa3 tem erro (" << pessoa3->getErro( ) << ")" << endl;
// encerrar
 pause ( "Apertar ENTER para continuar" );
}
}
void metodo07 ( )
{
// identificar
 cout << endl << "Metodo7" << endl;
{
// definir dados
 Contato pessoa1 ( "Pessoa_01", "111" );
 ref_Contato pessoa2 = nullptr;
 ref_Contato pessoa3 = new Contato ( "", "333" );
 pessoa2 = &pessoa1;
 if ( ! pessoa2->hasErro( ) )
 cout << "pessoa1 - " << pessoa2->toString( ) << endl;
 else
 cout << "pessoa1 tem erro (" << pessoa2->getErro( ) << ")" << endl;
 pessoa2 = pessoa3;
 if ( ! pessoa2->hasErro( ) )
 cout << "pessoa3 - " << pessoa2->toString( ) << endl;
 else
 cout << "pessoa3 tem erro (" << pessoa2->getErro( ) << ")" << endl;
// encerrar
 pause ( "Apertar ENTER para continuar" );
}
}
void metodo08 ( )
{
// identificar
 cout << endl << "Metodo8" << endl;
// definir dados
 Contato pessoa1 ( "Pessoa_01", "111" );
 ref_Contato pessoa2 = nullptr;
 ref_Contato pessoa3 = new Contato ( "", "333" );
 ref_Contato pessoa4 = nullptr;
// testar atribuicoes
 pessoa2 = new Contato ( pessoa1 );
 if ( pessoa2 )
 cout << "pessoa2 - " << pessoa2->toString( ) << endl;
 else
 cout << "pessoa2 tem erro (" << pessoa2->getErro( ) << ")" << endl;
 if ( pessoa3 )
 {
 pessoa2 = new Contato ( *pessoa3 );
 if ( pessoa2 )
 cout << "pessoa2 - " << pessoa2->toString( ) << endl;
 else
 cout << "pessoa2 tem erro (" << pessoa3->getErro( ) << ")" << endl;
 }
 if ( pessoa4 )
 {
 pessoa2 = new Contato ( *pessoa4 );
 if ( pessoa2 )
 cout << "pessoa2 - " << pessoa2->toString( ) << endl;
 else
 cout << "pessoa2 tem erro (" << pessoa4->getErro( ) << ")" << endl;
 }
// encerrar
 pause ( "Apertar ENTER para continuar" );
}
void metodo09 ( )
{
// identificar
 cout << endl << "Metodo9" << endl;
// definir dados
 Contato pessoa [ 3 ];
 int x = 0;
// testar atribuicoes
 pessoa [ 0 ].setNome ( "Pessoa_1" );
 pessoa [ 0 ].setFone ( "111" );
 pessoa [ 1 ].setNome ( "Pessoa_2" );
 pessoa [ 1 ].setFone ( "222" );
 pessoa [ 2 ].setNome ( "Pessoa_3" );
 pessoa [ 2 ].setFone ( "333" );
 for ( x=0; x < 3; x=x+1 )
 {
 cout << x << " : " << pessoa[ x ].toString( ) << endl;
 }
// encerrar
 pause ( "Apertar ENTER para continuar" );

}
void metodo10 ( )
{
// identificar
 cout << endl << "Metodo10" << endl;
// definir dados
 Contato *pessoa [ 3 ];
 int x = 0;
// testar atribuicoes
 pessoa [ 0 ] = new Contato ( "Pessoa_1", "111" );
 pessoa [ 1 ] = new Contato ( "Pessoa_2", "222" );
 pessoa [ 2 ] = new Contato ( "Pessoa_3", "333" );
 for ( x=0; x < 3; x=x+1 )
 {
 cout << x << " : " << pessoa[ x ]->toString( ) << endl;
 }
// encerrar
 pause ( "Apertar ENTER para continuar" );
}
int main ( int argc, char** argv )
{
// definir dado
 int x = 0;
 do
 {
 // identificar
 cout <<  "21/11/2024"   << endl; 
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