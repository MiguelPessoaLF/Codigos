#include <iostream> // std::cin, std::cout, std:endl
#include <limits> // std::numeric_limits
#include <string> // para cadeias de caracteres

void pause ( std::string text )
{
 std::string dummy;
 std::cin.clear ( );
 std::cout << std::endl << text;
 std::cin.ignore( );
 std::getline(std::cin, dummy);
 std::cout << std::endl << std::endl;
}
//biblioteca propria
#include "myarray.hpp"
//"retira" o std
using namespace std;
//funcoes de treinamento inicial
void metodo00 ( )
{
    std::cout << "\nPROGRAMA ENCERRADO\n";
}
void metodom1 ( )
{
// identificar
 cout << endl << "Metodo -1" << endl;
 std::cout << "Hello World!" << std::endl;
 std::cout << "Usuario 1" << std::endl;
 std::cout << "Hello World!\n";
 std::cout << "Usuario 2";

// encerrar
 pause ( "Apertar ENTER para continuar" );
}
void metodom2 ( )
{
// identificar
 cout << endl << "Metodo -2" << endl;
 int inteiro = 333;
 cout << inteiro << endl;
 cout << endl;
 double real = 5.2e99;
 cout << real << endl;
 cout << endl;
 bool boole = true;
 cout << boole << endl;
 cout << endl;
 char letra = 'M';
 string palavra = "Miguel";
 cout << palavra << endl;
 cout << endl;
// encerrar
 pause ( "Apertar ENTER para continuar" );
}
void metodom3 ( )
{
// identificar
 cout << endl << "Metodo -3" << endl;
int idade = 0;
cout << "Qual sua idade?" << endl;
cin >> idade;
cout << endl;
cout << idade << endl;
// encerrar
 pause ( "Apertar ENTER para continuar" );
}
#include<math.h>
void metodom4 ( )
{
// identificar
 cout << endl << "Metodo -4" << endl;
 int a = 9, b = 3;
 int soma = a+b;
 cout << "Soma: " << soma << "\n" << endl;
 cout << "Soma: " << a + b << "\n" << endl;
 cout << "Subitracao: " << a - b << "\n" << endl;
 cout << "Multiplicacao: " << a * b << "\n" << endl;
 cout << "Divisao a/b: " << a / b << "\n" << endl;
 double div = (double)b/(double)a;
 cout << "Divisao b/a: " << div << "\n" << endl;
 double resto = b%a;
 cout << "Resto: " << resto << "\n" << endl;
 float pot = pow(a,b);
 cout << "Potencia: " << pot << "\n" << endl;
// encerrar
 pause ( "Apertar ENTER para continuar" );
}
int func (int n)
{
    n = n + 2;
    return(n);
}
void metodom5 ( )
{
    int n = 0;
// identificar
 cout << endl << "Metodo -5" << endl;
 cout << "entre com um valor inteiro: " << "\n" << endl;
 cin >> n;
 int r = func(n);
 cout << "resultado de n + 2: " << r << "\n" << endl;  
// encerrar
 pause ( "Apertar ENTER para continuar" );
}
#include <cstdlib>
#include <fstream>
void metodo01 ( )
{
    int n = 0;
    int random = 0, inferior = 1, superior = 9;
    ofstream arquivo("metodo1.txt");
    int cadeia[20];
// identificar
 cout << endl << "Metodo1" << endl;
 cout << "entre com uma quantidade: " << endl;
 cin >> n;
 for (int i = 0; i < n; i++)
 {
    random = rand() % (superior - inferior + 1 ) + inferior;
    cadeia[i] = random;
    arquivo << cadeia[i] << endl;
 }
arquivo.close();
// encerrar
 pause ( "Apertar ENTER para continuar" );
} 
void metodo02 ( )
{
// identificar
 cout << endl << "Metodo2" << endl;
    ifstream arquivo("metodo1.txt");
    int cadeia[20];
    int i = 0;
    int maior = 0;
 while (arquivo >> cadeia[i])
 {
    if (cadeia[i] % 2 ==0)
    {
        cout << i << ": " << cadeia[i] << endl;
        if (cadeia[i] > maior)
        {
            maior = cadeia[i];
        }
    }
    i++;
 }
 arquivo.close();
 cout << "maior: " << maior << endl;
// encerrar
 pause ( "Apertar ENTER para continuar" );
}
void metodo03 ( )
{
// identificar
 cout << endl << "Metodo3" << endl;
    ifstream arquivo("metodo1.txt");
    int cadeia[20];
    int i = 0;
    int menor = 0;
    int blocker = 0;
 while (arquivo >> cadeia[i])
 {
    if (cadeia[i] % 2 == 0 && cadeia[i] % 3 == 0 && blocker == 0)
    {
        menor = cadeia[i];
        blocker = blocker + 1;
        cout << i << ": " << cadeia[i] << endl;
    }
    else if (cadeia[i] % 2 == 0 && cadeia[i] % 3 == 0)
    {
        cout << i << ": " << cadeia[i] << endl;
        if (cadeia[i] < menor)
        {
            menor = cadeia[i];
        }
    }
    i++;
 }
 arquivo.close();
 cout << "menor: " << menor << endl;
// encerrar
 pause ( "Apertar ENTER para continuar" );
}
void metodo04 ( )
{
// identificar
 cout << endl << "Metodo4" << endl;
    ifstream arquivo("metodo1.txt");
    int cadeia[20];
    int i = 0;
    int inferior = 0;
    int superior = 0;
    int soma = 0;
    cout << "entre com o limite inferior de um intervalo de somas entre 1 a 20:" << endl;
    cin >> inferior;
    cout << "entre com o limite superior de um intervalo de somas entre 1 a 20:" << endl;
    cin >> superior;
 while (arquivo >> cadeia[i])
 {
    if (i >= inferior && i <= superior)
    {
        soma = cadeia[i] + soma;
        cout << "soma na posicao " << i << ": " << soma << endl;
    }
    i++;
 }
 arquivo.close();
// encerrar
 pause ( "Apertar ENTER para continuar" );
}
void metodo05 ( )
{
// identificar
 cout << endl << "Metodo5" << endl;
    ifstream arquivo("metodo1.txt");
    int cadeia[20];
    int i = 0;
    int soma = 0;
 while (arquivo >> cadeia[i])
 {
    soma = cadeia[i] + soma;
    cout << i << ": " << cadeia[i] << endl;
    i++;
 }
 double media = (double)soma/(double)i;
 cout << "media igual a: " << media << endl;
 arquivo.close();
// encerrar
 pause ( "Apertar ENTER para continuar" );
}
bool positivo (string filename)
{
    ifstream arquivo(filename);
    int cadeia [20];
    int i = 0;
    while (arquivo >> cadeia[i])
    {
        if (cadeia[i] < 0)
        {
            return (false);
        }
        i++;
    }
    return (true);
}
void metodo06 ( )
{
// identificar
 cout << endl << "Metodo6" << endl;
 if (positivo("metodo1.txt"))
 {
    cout << "todos os valores sao positivos" << endl;
 }
 else{
    cout << "tem valores negativos" << endl;    
 }
// encerrar
 pause ( "Apertar ENTER para continuar" );
}
bool ordd (string filename)
{
    ifstream arquivo(filename);
    int cadeia [20];
    int i = 0;
    while (arquivo >> cadeia[i])
    {
        if (cadeia[i] < cadeia[i + 1])
        {
            return (false);
        }
        i++;
    }
    return (true);
}
void metodo07 ( )
{
// identificar
 cout << endl << "Metodo7" << endl;
 if (ordd("metodo7.txt"))
 {
    cout << "esta ordenado de forma decrescente" << endl;
 }
 else{
    cout << "nao esta ordenado de forma decrescente" << endl;    
 }
// encerrar
 pause ( "Apertar ENTER para continuar" );
}
bool search (string filename, int n, int inferior, int superior)
{
    ifstream arquivo(filename);
    int cadeia [20];
    int i = 0;
    while (arquivo >> cadeia[i])
    {
        if (i >= inferior && i <= superior && cadeia[i] == n)
        {
            return (true);
        }
        i++;
    }
    return (false);
}
void metodo08 ( )
{
int n = 0;
int inferior = 0;
int superior = 0;
// identificar
 cout << endl << "Metodo8" << endl;
 cout << "me de um valor a ser procurado" << endl;
 cin >> n;
cout << "entre com o limite inferior de um intervalo entre 1 a 20:" << endl;
cin >> inferior;
cout << "entre com o limite superior de um intervalo entre 1 a 20:" << endl;
cin >> superior;
 if (search("metodo1.txt", n, inferior, superior))
 {
    cout << "valor encontrado: " << n << endl;
 }
 else{
    cout << "valor nao encontrado" << endl;    
 }
// encerrar
 pause ( "Apertar ENTER para continuar" );
}
void metodo09 ( )
{
// identificar
 cout << endl << "Metodo9" << endl;
    ifstream arquivo1("metodo1.txt");
    ofstream arquivo2("metodo9.txt");
    int cadeia1[20];
    int cadeia2[20];
    int i = 0;
    int inferior = 0;
    int superior = 0;
    int soma = 0;
    cout << "entre com o limite inferior de um intervalo de somas entre 1 a 20:" << endl;
    cin >> inferior;
    cout << "entre com o limite superior de um intervalo de somas entre 1 a 20:" << endl;
    cin >> superior;
 while (arquivo1 >> cadeia1[i])
 {
    if (i >= inferior && i <= superior)
    {
        cadeia2[i] = cadeia1[i] * 2;
        arquivo2 << cadeia2[i] << endl;
    }
    i++;
 }
 arquivo1.close();
 arquivo2.close();
// encerrar
 pause ( "Apertar ENTER para continuar" );
}
void ordenard (int cad[])
{
    for (int j = 0; j < 20; j = j + 1)
    {
        for (int i = 0; i < 20; i = i + 1)
        {
            if (cad[i] < cad[i + 1])
            {
                int copy = cad[i];
                cad[i] = cad[i + 1];
                cad[i + 1] = copy;
            }
        }
    }
}
void metodo10 ( )
{
    int cad[20];
    ifstream arquivo("metodo7.txt");
    
// identificar
 cout << endl << "Metodo10" << endl;
 cout << "cadeia: ";
 for (int o = 0; o < 20; o = o + 1)
 {
    arquivo >> cad[o];
 }
  arquivo.close();
    for (int i = 0; i < 20; i = i + 1)
    {
        cout << cad[i];
    }
  cout << endl;
  ordenard(cad);
  cout << "nova cadeia: ";
    for (int j = 0; j < 20; j = j + 1)
    {
        cout << cad[j];
    }
 cout << endl;
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
 cout <<  "\n11/11/2024"   << endl; 
 cout << "Miguel Pessoa - Matricula 867160" << endl;
 // mostrar opcoes
 cout << "Opcoes " << endl;
 cout << "  0 - parar " << endl;
 cout << " -1 - metodo -1" << endl;
 cout << " -2 - metodo -2" << endl;
 cout << " -3 - metodo -3" << endl;
 cout << " -4 - metodo -4" << endl;
 cout << " -5 - metodo -5" << endl;
 cout << "-----------------" << endl;
 cout << "  1 - metodo 01" << endl;
 cout << "  2 - metodo 02" << endl;
 cout << "  3 - metodo 03" << endl;
 cout << "  4 - metodo 04" << endl;
 cout << "  5 - metodo 05" << endl;
 cout << "  6 - metodo 06" << endl;
 cout << "  7 - metodo 07" << endl;
 cout << "  8 - metod0 08" << endl;
 cout << "  9 - metodo 09" << endl;
 cout << " 10 - metodo 10" << endl;
 // ler do teclado
 cout << endl << "Entrar com uma opcao: ";
 cin >> x;
 // escolher acao
 switch ( x )
 {
 case 0: metodo00 ( ); break;
 case -1: metodom1 ( ); break;
 case -2: metodom2 ( ); break;
 case -3: metodom3 ( ); break;
 case -4: metodom4 ( ); break;
 case -5: metodom5 ( ); break;
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