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
#include "mylib1300.hpp"
#include "myerror.hpp"
using namespace std;
class test_construtor
{
    private:
    int a;
    public:
    //construtor
    test_construtor(int x, string name)
    {
        cout << "construtor de nome " << name << " tem o valor: " << x << endl; 
    }
};
void metodo00 ()
{
}
void metodom1 ( )
{
    int x = 0;
    string name;
     cout << "de um nome ao objeto: " << endl;
    cin >> name;
    cout << "de um valor ao nome: " << endl;
    cin >> x;
    test_construtor teste(x,name);
}

void metodo01 ( )
{
 string name;
// identificar
 cout << endl << "Metodo1" << endl;
 cout << "de um nome ao objeto: " << endl;
 cin >> name;
 mylib obj1(name);
// encerrar
 pause ( "Apertar ENTER para continuar" );
} 
void metodo02 ( )
{
 string ddd;
 string temp;
 string n1,n2;
 string name;
// identificar
 cout << endl << "Metodo2" << endl;
 cout << "de um nome ao objeto: " << endl;
 cin >> name;
 cout << "de um numero de telefone ao objeto, numero por numero: " << endl;
 cout << "ddd: " << endl;
 for (int i = 0; i < 2; i++)
 {
    cin >> temp;
    ddd = ddd + temp;
 }
  cout << "parte 1: " << endl;
  for (int o = 0; o < 4; o++)
 {
    cin >> temp;
    n1 = n1 + temp;
 }
  cout << "parte 2: " << endl;
  for (int j = 0; j < 4; j++)
 {
    cin >> temp;
    n2 = n2 + temp;
 }
 mylib obj2(name,ddd,n1,n2);
// encerrar
 pause ( "Apertar ENTER para continuar" );
}
void metodo03 ( )
{
 string ddd;
 string temp;
 string n1,n2;
 string name;
// identificar
 cout << endl << "Metodo3" << endl;
 cout << "de um nome ao objeto: " << endl;
 cin >> name;
 cout << "de um numero de telefone ao objeto, numero por numero: " << endl;
 cout << "ddd: " << endl;
 for (int i = 0; i < 2; i++)
 {
    cin >> temp;
    ddd = ddd + temp;
 }
  cout << "parte 1: " << endl;
  for (int o = 0; o < 4; o++)
 {
    cin >> temp;
    n1 = n1 + temp;
 }
  cout << "parte 2: " << endl;
  for (int j = 0; j < 4; j++)
 {
    cin >> temp;
    n2 = n2 + temp;
 }
 mylib obj3(name,ddd,n1,n2);
// encerrar
 pause ( "Apertar ENTER para continuar" );
}
//a forma como eu fiz é diferente da que eu imagino que voce queria, mas no fim tambem funciona,
//talvez adicionar um limite de caracteres deixaria mais funcional
void metodo04 ( )
{
 string ddd;
 string temp;
 string n1,n2;
 string name;
// identificar
 cout << endl << "Metodo4" << endl;
 cout << "de um nome ao objeto: " << endl;
 cin >> name;
 cout << "de um numero de telefone ao objeto, numero por numero: " << endl;
 cout << "ddd: " << endl;
 for (int i = 0; i < 2; i++)
 {
    cin >> temp;
    ddd = ddd + temp;
 }
  cout << "parte 1: " << endl;
  for (int o = 0; o < 4; o++)
 {
    cin >> temp;
    n1 = n1 + temp;
 }
  cout << "parte 2: " << endl;
  for (int j = 0; j < 4; j++)
 {
    cin >> temp;
    n2 = n2 + temp;
 }
 //extra: 
 cout << "o contato esta online? 1 = sim 2 = nao" << endl;
 int on = 0;
 cin >> on;
 if (on != 1 && on != 2){cout << "erro, tente novamente";return;}
 else
 {
 if (on == 1){mylib obj4(name,ddd,n1,n2,"on.txt");}
 else if (on == 2){mylib obj4(name,ddd,n1,n2,"off.txt");}
 }
// encerrar
 pause ( "Apertar ENTER para continuar" );
}
void metodo05 ( )
{
 string ddd;
 string temp;
 string n1,n2;
 string name;
// identificar
 cout << endl << "Metodo5" << endl;
 cout << "de um nome ao objeto: " << endl;
 cin >> name;
 cout << "de um numero de telefone ao objeto, numero por numero: " << endl;
 cout << "ddd: " << endl;
 for (int i = 0; i < 2; i++)
 {
    cin >> temp;
    ddd = ddd + temp;
 }
  cout << "parte 1: " << endl;
  for (int o = 0; o < 4; o++)
 {
    cin >> temp;
    n1 = n1 + temp;
 }
  cout << "parte 2: " << endl;
  for (int j = 0; j < 4; j++)
 {
    cin >> temp;
    n2 = n2 + temp;
 }
 //extra: 
 cout << "o contato esta online? 1 = sim 2 = nao" << endl;
 int on = 0;
 cin >> on;
 if (on != 1 && on != 2){cout << "erro, tente novamente";return;}
 else
 {
 if (on == 1){mylib obj4(name,ddd,n1,n2,"on.txt","pessoa1.txt");}
 else if (on == 2){mylib obj4(name,ddd,n1,n2,"off.txt","pessoa1.txt");}
 }
// encerrar
 pause ( "Apertar ENTER para continuar" );
}
void metodo06 ( )
{
 string temp;
 string ddd;
 string dddr;
 string n1,n2;
 string n1r,n2r;
 string name;
// identificar
 cout << endl << "Metodo6" << endl;
 cout << "de um nome ao objeto: " << endl;
 cin >> name;
 cout << "de um numero de telefone pessoal ao objeto, numero por numero: " << endl;
 cout << "ddd: " << endl;
 for (int i = 0; i < 2; i++)
 {
    cin >> temp;
    ddd = ddd + temp;
 }
  cout << "parte 1: " << endl;
  for (int o = 0; o < 4; o++)
 {
    cin >> temp;
    n1 = n1 + temp;
 }
  cout << "parte 2: " << endl;
  for (int j = 0; j < 4; j++)
 {
    cin >> temp;
    n2 = n2 + temp;
 }
  cout << "de um numero de telefone residencial ao objeto, numero por numero: " << endl;
 cout << "ddd: " << endl;
 for (int a = 0; a < 2; a++)
 {
    cin >> temp;
    dddr = dddr + temp;
 }
  cout << "parte 1: " << endl;
  for (int b = 0; b < 4; b++)
 {
    cin >> temp;
    n1r = n1r + temp;
 }
  cout << "parte 2: " << endl;
  for (int c = 0; c < 4; c++)
 {
    cin >> temp;
    n2r = n2r + temp;
 }
 //extra: 
 cout << "o contato esta online? 1 = sim 2 = nao" << endl;
 int on = 0;
 cin >> on;
 if (on != 1 && on != 2){cout << "erro, tente novamente";return;}
 else
 {
 if (on == 1){mylib obj4(name,ddd,n1,n2,"on.txt","pessoa1.txt"
 ,dddr,n1r,n2r);}
 else if (on == 2){mylib obj4(name,ddd,n1,n2,"off.txt","pessoa1.txt"
 ,dddr,n1r,n2r);}
 }
// encerrar
 pause ( "Apertar ENTER para continuar" );
}
void metodo07 ( )
{
 string temp;
 string ddd;
 string dddr;
 string n1,n2;
 string n1r,n2r;
 string name;
// identificar
 cout << endl << "Metodo7" << endl;
 cout << "de um nome ao objeto: " << endl;
 cin >> name;
 cout << "de um numero de telefone pessoal ao objeto, numero por numero: " << endl;
 cout << "ddd: " << endl;
 for (int i = 0; i < 2; i++)
 {
    cin >> temp;
    ddd = ddd + temp;
 }
  cout << "parte 1: " << endl;
  for (int o = 0; o < 4; o++)
 {
    cin >> temp;
    n1 = n1 + temp;
 }
  cout << "parte 2: " << endl;
  for (int j = 0; j < 4; j++)
 {
    cin >> temp;
    n2 = n2 + temp;
 }
 int numbers = 0;
 cout << "possui numero residencial? 1 = sim 2 = nao" << endl;
 cin >> numbers;
 if (numbers != 1 && numbers != 2){cout << "erro - tente novamente";return;}
 else if (numbers == 1)
 {
 cout << "de um numero de telefone residencial ao objeto, numero por numero: " << endl;
 cout << "ddd: " << endl;
 for (int a = 0; a < 2; a++)
 {
    cin >> temp;
    dddr = dddr + temp;
 }
  cout << "parte 1: " << endl;
  for (int b = 0; b < 4; b++)
 {
    cin >> temp;
    n1r = n1r + temp;
 }
  cout << "parte 2: " << endl;
  for (int c = 0; c < 4; c++)
 {
    cin >> temp;
    n2r = n2r + temp;
 }
  //extra: 
 cout << "o contato esta online? 1 = sim 2 = nao" << endl;
 int on = 0;
 cin >> on;
 if (on != 1 && on != 2){cout << "erro, tente novamente" << endl; return;}
 else
 {
 if (on == 1){mylib obj4(name,ddd,n1,n2,"on.txt","pessoa1.txt"
 ,dddr,n1r,n2r);}
 else if (on == 2){mylib obj4(name,ddd,n1,n2,"off.txt","pessoa1.txt"
 ,dddr,n1r,n2r);}
 }
 }
 else
 {
     //extra: 
 cout << "o contato esta online? 1 = sim 2 = nao" << endl;
 int on = 0;
 cin >> on;
 if (on != 1 && on != 2){cout << "erro, tente novamente" << endl; return;}
 else
 {
 if (on == 1){mylib obj4(name,ddd,n1,n2,"on.txt","pessoa1.txt");}
 else if (on == 2){mylib obj4(name,ddd,n1,n2,"off.txt","pessoa1.txt");}
 }
 }
// encerrar
 pause ( "Apertar ENTER para continuar" );
}
void metodo08 ( )
{
 string temp;
 string ddd;
 string dddr;
 string n1,n2;
 string n1r,n2r;
 string name;
// identificar
 cout << endl << "Metodo8" << endl;
 cout << "de um nome ao objeto: " << endl;
 cin >> name;
 cout << "de um numero de telefone pessoal ao objeto, numero por numero: " << endl;
 cout << "ddd: " << endl;
 for (int i = 0; i < 2; i++)
 {
    cin >> temp;
    ddd = ddd + temp;
 }
  cout << "parte 1: " << endl;
  for (int o = 0; o < 4; o++)
 {
    cin >> temp;
    n1 = n1 + temp;
 }
  cout << "parte 2: " << endl;
  for (int j = 0; j < 4; j++)
 {
    cin >> temp;
    n2 = n2 + temp;
 }
 int numbers = 0;
 cout << "possui numero residencial? 1 = sim 2 = nao" << endl;
 cin >> numbers;
 if (numbers != 1 && numbers != 2){cout << "erro - tente novamente";return;}
 else if (numbers == 1)
 {
 cout << "de um numero de telefone residencial ao objeto, numero por numero: " << endl;
 cout << "ddd: " << endl;
 for (int a = 0; a < 2; a++)
 {
    cin >> temp;
    dddr = dddr + temp;
 }
  cout << "parte 1: " << endl;
  for (int b = 0; b < 4; b++)
 {
    cin >> temp;
    n1r = n1r + temp;
 }
  cout << "parte 2: " << endl;
  for (int c = 0; c < 4; c++)
 {
    cin >> temp;
    n2r = n2r + temp;
 }
  //extra: 
 cout << "o contato esta online? 1 = sim 2 = nao" << endl;
 int on = 0;
 cin >> on;
 if (on != 1 && on != 2){cout << "erro, tente novamente" << endl; return;}
 else
 {
 if (on == 1){mylib obj4(name,ddd,n1,n2,"on.txt","pessoa1.txt"
 ,dddr,n1r,n2r);}
 else if (on == 2){mylib obj4(name,ddd,n1,n2,"off.txt","pessoa1.txt"
 ,dddr,n1r,n2r);}
 }
 }
 else
 {
     //extra: 
 cout << "o contato esta online? 1 = sim 2 = nao" << endl;
 int on = 0;
 cin >> on;
 if (on != 1 && on != 2){cout << "erro, tente novamente" << endl; return;}
 else
 {
 if (on == 1){mylib obj4(name,ddd,n1,n2,"on.txt","pessoa1.txt");}
 else if (on == 2){mylib obj4(name,ddd,n1,n2,"off.txt","pessoa1.txt");}
 }
 }
// encerrar
 pause ( "Apertar ENTER para continuar" );
}
//fiz a mais sem querer denovo entao cobriu dois metodos kkk
void metodo09 ( )
{
 string temp;
 string ddd;
 string dddr;
 string n1,n2;
 string n1r,n2r;
 string name;
// identificar
 cout << endl << "Metodo9" << endl;
 cout << "de um nome ao objeto: " << endl;
 cin >> name;
 cout << "de um numero de telefone pessoal ao objeto, numero por numero: " << endl;
 cout << "ddd: " << endl;
 for (int i = 0; i < 2; i++)
 {
    cin >> temp;
    ddd = ddd + temp;
 }
  cout << "parte 1: " << endl;
  for (int o = 0; o < 4; o++)
 {
    cin >> temp;
    n1 = n1 + temp;
 }
  cout << "parte 2: " << endl;
  for (int j = 0; j < 4; j++)
 {
    cin >> temp;
    n2 = n2 + temp;
 }
 int numbers = 0;
 cout << "possui numero residencial? 1 = sim 2 = nao" << endl;
 cin >> numbers;
 if (numbers != 1 && numbers != 2){cout << "erro - tente novamente";return;}
 else if (numbers == 1)
 {
 cout << "de um numero de telefone residencial ao objeto, numero por numero: " << endl;
 cout << "ddd: " << endl;
 for (int a = 0; a < 2; a++)
 {
    cin >> temp;
    dddr = dddr + temp;
 }
  cout << "parte 1: " << endl;
  for (int b = 0; b < 4; b++)
 {
    cin >> temp;
    n1r = n1r + temp;
 }
  cout << "parte 2: " << endl;
  for (int c = 0; c < 4; c++)
 {
    cin >> temp;
    n2r = n2r + temp;
 }
  //extra: 
 cout << "o contato esta online? 1 = sim 2 = nao" << endl;
 int on = 0;
 cin >> on;
 if (on != 1 && on != 2){cout << "erro, tente novamente" << endl; return;}
 else
 {
 if (on == 1){mylib obj4(name,ddd,n1,n2,"on.txt","pessoa1.txt"
 ,dddr,n1r,n2r,numbers);}
 else if (on == 2){mylib obj4(name,ddd,n1,n2,"off.txt","pessoa1.txt"
 ,dddr,n1r,n2r,numbers);}
 }
 }
 else
 {
     //extra: 
 cout << "o contato esta online? 1 = sim 2 = nao" << endl;
 int on = 0;
 cin >> on;
 if (on != 1 && on != 2){cout << "erro, tente novamente" << endl; return;}
 else
 {
 if (on == 1){mylib obj4(name,ddd,n1,n2,"on.txt","pessoa1.txt");}
 else if (on == 2){mylib obj4(name,ddd,n1,n2,"off.txt","pessoa1.txt");}
 }
 }
// encerrar
 pause ( "Apertar ENTER para continuar" );
}
void metodo10 ( )
{
 string temp;
 string ddd;
 string dddr;
 string n1,n2;
 string n1r,n2r;
 string name;
 int change;
// identificar
 cout << endl << "Metodo10" << endl;
 cout << "de um nome ao objeto: " << endl;
 cin >> name;
 cout << "de um numero de telefone pessoal ao objeto, numero por numero: " << endl;
 cout << "ddd: " << endl;
 for (int i = 0; i < 2; i++)
 {
    cin >> temp;
    ddd = ddd + temp;
 }
  cout << "parte 1: " << endl;
  for (int o = 0; o < 4; o++)
 {
    cin >> temp;
    n1 = n1 + temp;
 }
  cout << "parte 2: " << endl;
  for (int j = 0; j < 4; j++)
 {
    cin >> temp;
    n2 = n2 + temp;
 }
 int numbers = 0;
 cout << "possui numero residencial? 1 = sim 2 = nao" << endl;
 cin >> numbers;
 if (numbers != 1 && numbers != 2){cout << "erro - tente novamente";return;}
 else if (numbers == 1)
 {
 cout << "de um numero de telefone residencial ao objeto, numero por numero: " << endl;
 cout << "ddd: " << endl;
 for (int a = 0; a < 2; a++)
 {
    cin >> temp;
    dddr = dddr + temp;
 }
  cout << "parte 1: " << endl;
  for (int b = 0; b < 4; b++)
 {
    cin >> temp;
    n1r = n1r + temp;
 }
  cout << "parte 2: " << endl;
  for (int c = 0; c < 4; c++)
 {
    cin >> temp;
    n2r = n2r + temp;
 }
  //extra: 
 cout << "o contato esta online? 1 = sim 2 = nao" << endl;
 int on = 0;
 cin >> on;
 if (on != 1 && on != 2){cout << "erro, tente novamente" << endl; return;}
 else
 {
 if (on == 1){mylib obj4(name,ddd,n1,n2,"on.txt","pessoa1.txt"
 ,dddr,n1r,n2r,numbers,change);}
 else if (on == 2){mylib obj4(name,ddd,n1,n2,"off.txt","pessoa1.txt"
 ,dddr,n1r,n2r,numbers,change);}
 }
 }
 else
 {
     //extra: 
 cout << "o contato esta online? 1 = sim 2 = nao" << endl;
 int on = 0;
 cin >> on;
 if (on != 1 && on != 2){cout << "erro, tente novamente" << endl; return;}
 else
 {
 if (on == 1){mylib obj4(name,ddd,n1,n2,"on.txt","pessoa1.txt");}
 else if (on == 2){mylib obj4(name,ddd,n1,n2,"off.txt","pessoa1.txt");}
 }
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
 cout <<  "11/11/2024"   << endl; 
 cout << "Miguel Pessoa - Matricula 867160" << endl;
 // mostrar opcoes
 cout << "Opcoes " << endl;
 cout << " 0 - parar " << endl;
 cout << " -1 - metodo01" << endl;
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
 case -1: metodom1 ( ); break;
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