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
using namespace std;

class pokemon //ideia do antonio
{
    private: //so é usada pelas funcoes de dentro da class

    string nome;
    string tipo;
    int geracao;
    double peso;
    double altura;

    public: //usado em todo o codigo

//metodo-1 e metodo-4
    void atack (int who)
    {
        if (who == 1)
        {
        cout << "Gengar, use Shadow Ball!!" << endl;
        cout << " ^ ^" << endl;
        cout << " ___" << endl;
        cout << "/o o\\" << endl;
        cout << "|'v'|=========>  <O>  " << endl;
        cout << "\\   / " << endl;
        cout << " ---" << endl;
        cout << "/   \\" << endl;
        }
        else if (who == 2)
        {
        cout << "Rayquaza, use Dragon Tail!!" << endl;
        cout << " />    __" << endl;
        cout << "//    | _o_> " << endl;
        cout << " __   //\\" << endl;
        cout << "//\\\\//\\" << endl;
        cout << "// \\_/" << endl;
        }
    }
//metodo-2
    void def_status (string nome, string tipo, int geracao, double peso, double altura )
    {
        this->nome = nome;
                this->tipo = tipo;
                        this->geracao = geracao;
                                this->peso = peso;
                                        this->altura = altura;
    }
//metodo-3 e metodo-5
    string show_status_name ()
    {
        return (nome);
    }
        string show_status_type ()
        {
            return (tipo);
        }
            int show_status_gem ()
            {
                return (geracao);
            }
                float show_status_weight ()
                {
                    return (peso);
                }
                    float show_status_height ()
                        {
                        return (altura);
                        }
};
    
void metodom1 ( )
{
// identificar
 cout << endl << "Metodo -1" << endl;
 pokemon gengar;
 gengar.atack(1);
// encerrar
 pause ( "Apertar ENTER para continuar" );
}
 void metodom2 ( )
{
// identificar
 cout << endl << "Metodo1 -2" << endl;
 pokemon gengar;
 gengar.def_status("Gengar","Fantasma",1,20.8,1.25);
 cout << "Status definido" << endl;
// encerrar
 pause ( "Apertar ENTER para continuar" );
}
 void metodom3 ( )
{
// identificar
 cout << endl << "Metodo -3" << endl;
 pokemon gengar;
 gengar.def_status("Gengar","Fantasma",1,20.8,1.25);
 cout << "Status definido" << endl;
 cout << "Nome: " << gengar.show_status_name() << endl;
  cout << "Tipo: " << gengar.show_status_type() << endl;
   cout << "Geracao: " << gengar.show_status_gem() << endl;
    cout << "Peso: " << gengar.show_status_weight() << endl;
     cout << "Altura: " << gengar.show_status_height() << endl;
// encerrar
 pause ( "Apertar ENTER para continuar" );
}
 void metodom4 ( )
{
// identificar
 cout << endl << "Metodo -4" << endl;
 pokemon rayquaza;
 rayquaza.atack(2);
 // encerrar
 pause ( "Apertar ENTER para continuar" );
}
 void metodom5 ( )
{
// identificar
 cout << endl << "Metodo -5" << endl;
 pokemon rayquaza;
 rayquaza.def_status("Rayquaza","Dragao",3,206.5,7.0);
 cout << "Status definido" << endl;

 cout << "Nome: " << rayquaza.show_status_name() << endl;
  cout << "Tipo: " << rayquaza.show_status_type() << endl;
   cout << "Geracao: " << rayquaza.show_status_gem() << endl;
    cout << "Peso: " << rayquaza.show_status_weight() << endl;
     cout << "Altura: " << rayquaza.show_status_height() << endl;
// encerrar
 pause ( "Apertar ENTER para continuar" );
} 
void metodo00 ( )
{
}
//uso de class: especie de struct com capacidade de guardar funcoes e caracteristicas de
//objetos, pode ser desenvolvida em um arquivo separado ou no mesmo arquivo
template <typename M>
class matrix
{
private: 
M** matriz;
M** matrizp;
int colunas;
int linhas;
public:
//geral:
void make (int colunas, int linhas)
{
    this->colunas = colunas;
    this->linhas = linhas;
    M valor = 0;
    matriz = new M*[linhas];
    for (int i = 0; i < linhas; ++i) 
    {
        matriz[i] = new M[colunas];
    }
    for (int cont1 = 0; cont1 < linhas; cont1= cont1 + 1)
    {
        for (int cont2 = 0; cont2 < colunas; cont2 = cont2 + 1)
        {
            cout << "linha " << cont1 << "," << "coluna " << cont2 << ":" << endl;
            cin >> valor;
            this->matriz [cont1][cont2] = valor;
        }
    }
}
void call (int colunas, int linhas)
{
    cout << "quantidade de valores: " << colunas * linhas << endl;
    for (int cont1 = 0; cont1 < linhas; cont1= cont1 + 1)
    {
        for (int cont2 = 0; cont2 < colunas; cont2 = cont2 + 1)
        {
            cout << "   " << matriz [cont1][cont2];
        }
        cout << endl;
    }
}
void fcall (int colunas, int linhas, string filename)
{
    ofstream arquivo(filename);
    arquivo << "quantidade de valores: " << colunas * linhas << endl;
    for (int cont1 = 0; cont1 < linhas; cont1= cont1 + 1)
    {
        for (int cont2 = 0; cont2 < colunas; cont2 = cont2 + 1)
        {
            arquivo << "   " << matriz [cont1][cont2];
        }
        arquivo << endl;
    }
    arquivo.close();
}
void fcall_clean (int colunas, int linhas, string filename)
{
    ofstream arquivo(filename);
    for (int cont1 = 0; cont1 < linhas; cont1= cont1 + 1)
    {
        for (int cont2 = 0; cont2 < colunas; cont2 = cont2 + 1)
        {
            arquivo << "   " << matriz [cont1][cont2];
        }
        arquivo << endl;
    }
    arquivo.close();
}
~matrix()
    {
        for (int i = 0; i < linhas; ++i) 
        {
            delete[] matriz[i];
        }
    delete[] matriz;
    }
//metodo 1
void make_random (int colunas, int linhas, int inferior, int superior)
{
    this->colunas = colunas;
    this->linhas = linhas;
    M valor = 0;
    matriz = new M*[linhas];
    for (int i = 0; i < linhas; ++i) 
    {
        matriz[i] = new M[colunas];
    }
    for (int cont1 = 0; cont1 < linhas; cont1= cont1 + 1)
    {
        for (int cont2 = 0; cont2 < colunas; cont2 = cont2 + 1)
        {
            valor = rand () % (superior - inferior + 1) + inferior;
            this->matriz [cont1][cont2] = valor;
        }
    }
}
//metodo2
void read (int colunas, int linhas, string filename)
{
    ifstream arquivo(filename);
    this->colunas = colunas;
    this->linhas = linhas;
    M valor = 0;
    matriz = new M*[linhas];
    for (int i = 0; i < linhas; ++i) 
    {
        matriz[i] = new M[colunas];
    }
    for (int cont1 = 0; cont1 < linhas; cont1= cont1 + 1)
    {
        for (int cont2 = 0; cont2 < colunas; cont2 = cont2 + 1)
        {
            arquivo >> this->matriz[cont1][cont2];
        }
    }
    arquivo.close();
}
void call_multi (int colunas, int linhas, int n)
{
    cout << "quantidade de valores: " << colunas * linhas << endl;
    for (int cont1 = 0; cont1 < linhas; cont1= cont1 + 1)
    {
        for (int cont2 = 0; cont2 < colunas; cont2 = cont2 + 1)
        {
            cout << "   " << matriz [cont1][cont2] * n;
        }
        cout << endl;
    }
}
//metodo3
bool isID (int colunas, int linhas)
{
    cout << "quantidade de valores: " << colunas * linhas << endl;
    for (int cont1 = 0; cont1 < linhas; cont1= cont1 + 1)
    {
        for (int cont2 = 0; cont2 < colunas; cont2 = cont2 + 1)
        {
            if (cont2 == cont1)
            {
                if (matriz[cont1][cont2] != 1)
                {
                    return (false);
                }
            }
            else
            {
                if (matriz[cont1][cont2] != 0)
                {
                    return (false);
                }
            }
        }
        cout << endl;
    }
    return (true);
}
//metodo4
bool isEqual (int colunas, int linhas, string filename)
{
    ifstream arquivo(filename);
    this->colunas = colunas;
    this->linhas = linhas;
    M valor = 0;
    for (int cont1 = 0; cont1 < linhas; cont1= cont1 + 1)
    {
        for (int cont2 = 0; cont2 < colunas; cont2 = cont2 + 1)
        {
            arquivo >> valor;
            if (this->matriz[cont1][cont2] != valor)
            {
                return (false);
            }
        }
    }
    arquivo.close();
    return (true);
}
//metodo5
void fcall_cleanp (int colunas, int linhas, string filename)
{
    ofstream arquivo(filename);
    for (int cont1 = 0; cont1 < linhas; cont1= cont1 + 1)
    {
        for (int cont2 = 0; cont2 < colunas; cont2 = cont2 + 1)
        {
            arquivo << "   " << matrizp [cont1][cont2];
        }
        arquivo << endl;
    }
    arquivo.close();
}
void Plus (int colunas, int linhas, string filename)
{
    ifstream arquivo(filename);
    this->colunas = colunas;
    this->linhas = linhas;
    M valor = 0;
    M valorm = 0;
    matrizp = new M*[linhas];
    for (int i = 0; i < linhas; ++i) 
    {
        matrizp[i] = new M[colunas];
    }
    for (int cont1 = 0; cont1 < linhas; cont1= cont1 + 1)
    {
        for (int cont2 = 0; cont2 < colunas; cont2 = cont2 + 1)
        {
            arquivo >> valor;
            valorm = this->matriz[cont1][cont2];
            this->matrizp[cont1][cont2] = valorm + valor;
        }
    }
    arquivo.close();
    string name = "metodo5R.txt";
    fcall_cleanp(colunas, linhas,name);
}
//metodo6
void Plus_Multi_Line (int colunas, int linhas, string filename)
{
    ifstream arquivo(filename);
    this->colunas = colunas;
    this->linhas = linhas;
    M valor = 0;
    M valorp = 0;
    matrizp = new M*[linhas];
    for (int i = 0; i < linhas; ++i) 
    {
        matrizp[i] = new M[colunas];
    }
    for (int cont1 = 0; cont1 < linhas; cont1= cont1 + 1)
    {
        for (int cont2 = 0; cont2 < colunas; cont2 = cont2 + 1)
        {
            arquivo >> this->matriz[cont1][cont2];
            valor = this->matriz[cont1][cont2];
            if (cont1==0)
            {
            valorp = this->matriz[cont1 + 1][cont2];
            this->matrizp[cont1][cont2] = valor + valorp * 2;
            }
            else
            {
                this->matrizp[cont1][cont2] = valor;
            }
        }
    }
    arquivo.close();
}
//metodo7
void Less_Multi_Line (int colunas, int linhas, string filename)
{
    ifstream arquivo(filename);
    this->colunas = colunas;
    this->linhas = linhas;
    M valor = 0;
    M valorp = 0;
    matrizp = new M*[linhas];
    for (int i = 0; i < linhas; ++i) 
    {
        matrizp[i] = new M[colunas];
    }
    for (int cont1 = 0; cont1 < linhas; cont1= cont1 + 1)
    {
        for (int cont2 = 0; cont2 < colunas; cont2 = cont2 + 1)
        {
            arquivo >> this->matriz[cont1][cont2];
            valor = this->matriz[cont1][cont2];
            if (cont1==0)
            {
            valorp = this->matriz[cont1 + 1][cont2];
            this->matrizp[cont1][cont2] = valor - valorp * 2;
            }
            else
            {
                this->matrizp[cont1][cont2] = valor;
            }
        }
    }
    arquivo.close();
}
//metodo8 e 9
void searchl (int colunas, int linhas, string filename, int n)
{
        ifstream arquivo(filename);
    this->colunas = colunas;
    this->linhas = linhas;
    M valor = 0;
    M valorp = 0;
    matrizp = new M*[linhas];
    for (int i = 0; i < linhas; ++i) 
    {
        matrizp[i] = new M[colunas];
    }
    for (int cont1 = 0; cont1 < linhas; cont1= cont1 + 1)
    {
        for (int cont2 = 0; cont2 < colunas; cont2 = cont2 + 1)
        {
            arquivo >> this->matriz[cont1][cont2];
            valor = this->matriz[cont1][cont2];
            if(valor == n)
            {
                cout << "valor encontrado na linha " << cont1 << endl;
            }
        }
    }
    arquivo.close();
}
void searchc (int colunas, int linhas, string filename, int n)
{
        ifstream arquivo(filename);
    this->colunas = colunas;
    this->linhas = linhas;
    M valor = 0;
    M valorp = 0;
    matrizp = new M*[linhas];
    for (int i = 0; i < linhas; ++i) 
    {
        matrizp[i] = new M[colunas];
    }
    for (int cont1 = 0; cont1 < linhas; cont1= cont1 + 1)
    {
        for (int cont2 = 0; cont2 < colunas; cont2 = cont2 + 1)
        {
            arquivo >> this->matriz[cont1][cont2];
            valor = this->matriz[cont1][cont2];
            if(valor == n)
            {
                cout << "valor encontrado na coluna " << cont2 << endl;
            }
        }
    }
    arquivo.close();
}
//metodo10
void fcall_clean_trans (int colunas, int linhas, string filename)
{
    ofstream arquivo(filename);
    for (int cont1 = 0; cont1 < linhas; cont1= cont1 + 1)
    {
        for (int cont2 = 0; cont2 < colunas; cont2 = cont2 + 1)
        {
            arquivo << "   " << matriz [cont2][cont1];
        }
        arquivo << endl;
    }
    arquivo.close();
}
};
void metodo01 ( )
{
// identificar
 cout << endl << "Metodo1" << endl;
 int linhas = 0;
 int colunas = 0;
 int inferior = 0;
 int superior = 0;
 string name = "metodo1.txt";
 matrix <int> m1;
 cout << "entrar com um numero de linhas: " << endl;
 cin >> linhas;
 cout << "entrar com um numero de colunas: " << endl;
 cin >> colunas;
 cout << "entrar com o numero inferior do intervalo: " << endl;
 cin >> inferior;
 cout << "entrar com o numero superior do intervalo: " << endl;
 cin >> superior;
 if (inferior > superior)
 {
    cout << "intervalo invalido" << endl;
 }
 else
 {
 m1.make_random(colunas,linhas,inferior,superior);
 m1.fcall(colunas,linhas,name);
 }
// encerrar
 pause ( "Apertar ENTER para continuar" );
} 
void metodo02 ( )
{
// identificar
 cout << endl << "Metodo2" << endl;
 int linhas = 2;
 int colunas = 2;
 string name = "metodo2.txt";
 int n = 0;
 matrix <int> m2;
 cout << "entre com um valor para multiplicar: " << endl;
 cin >> n;
 m2.read(colunas,linhas,name);
 m2.call_multi(colunas,linhas,n);
// encerrar
 pause ( "Apertar ENTER para continuar" );
}
void metodo03 ( )
{
// identificar
 cout << endl << "Metodo3" << endl;
  int linhas = 0;
 int colunas = 0;
 string name = "metodo1.txt";
 matrix <int> m3;
 cout << "entrar com um numero de linhas: " << endl;
 cin >> linhas;
 cout << "entrar com um numero de colunas: " << endl;
 cin >> colunas;
 m3.make(colunas,linhas);
 if (m3.isID(colunas,linhas))
 {
    cout << "matriz identidade" << endl;
 }
 else
 {
    cout << "nao e uma matriz indentidade" << endl;
 }
// encerrar
 pause ( "Apertar ENTER para continuar" );
}
void metodo04 ( )
{
// identificar
 cout << endl << "Metodo4" << endl;
 int linhas = 0;
 int colunas = 0;
 string name = "metodo4.txt";
 matrix <int> m4;
 cout << "entrar com um numero de linhas: " << endl;
 cin >> linhas;
 cout << "entrar com um numero de colunas: " << endl;
 cin >> colunas;
 m4.make(colunas,linhas);
 m4.fcall_clean(colunas,linhas,name);
 name = "metodo2.txt";
 if (m4.isEqual(colunas,linhas,name))
    {
        cout << "matrizes iguais" << endl;
    }
    else
    {
        cout << "matrizes diferentes" << endl;
    }
// encerrar
 pause ( "Apertar ENTER para continuar" );
}
void metodo05 ( )
{
// identificar
 cout << endl << "Metodo5" << endl;
  int linhas = 0;
 int colunas = 0;
 string name = "metodo5.txt";
 matrix <int> m5;
 cout << "entrar com um numero de linhas: " << endl;
 cin >> linhas;
 cout << "entrar com um numero de colunas: " << endl;
 cin >> colunas;
 m5.make(colunas,linhas);
 m5.fcall_clean(colunas,linhas,name);
 name = "metodo2.txt";
 m5.Plus(colunas,linhas,name);
// encerrar
 pause ( "Apertar ENTER para continuar" );
}
void metodo06 ( )
{
// identificar
 cout << endl << "Metodo6" << endl;
 int linhas = 0;
 int colunas = 0;
 string name = "metodo6.txt";
 matrix <int> m6;
 cout << "entrar com um numero de linhas: " << endl;
 cin >> linhas;
 cout << "entrar com um numero de colunas: " << endl;
 cin >> colunas;
 m6.make(colunas,linhas);
 m6.fcall_clean(colunas,linhas,name);
 m6.Plus_Multi_Line(colunas,linhas,name);
 name = "metodo6R.txt";
 m6.fcall_cleanp(colunas,linhas,name);
// encerrar
 pause ( "Apertar ENTER para continuar" );
}
void metodo07 ( )
{
// identificar
 cout << endl << "Metodo7" << endl;
  int linhas = 0;
 int colunas = 0;
 string name = "metodo7.txt";
 matrix <int> m7;
 cout << "entrar com um numero de linhas: " << endl;
 cin >> linhas;
 cout << "entrar com um numero de colunas: " << endl;
 cin >> colunas;
 m7.make(colunas,linhas);
 m7.fcall_clean(colunas,linhas,name);
 m7.Less_Multi_Line(colunas,linhas,name);
 name = "metodo7R.txt";
 m7.fcall_cleanp(colunas,linhas,name);
// encerrar
 pause ( "Apertar ENTER para continuar" );
}
void metodo08 ( )
{
// identificar
 cout << endl << "Metodo8" << endl;
 int linhas = 0;
 int colunas = 0;
 int n = 0;
 string name = "metodo8.txt";
 matrix <int> m8;
 cout << "entrar com um numero de linhas: " << endl;
 cin >> linhas;
 cout << "entrar com um numero de colunas: " << endl;
 cin >> colunas;
 cout << "entrar com um numero a ser procurado: " << endl;
 cin >> n;
 m8.make(colunas,linhas);
 m8.fcall_clean(colunas,linhas,name);
 m8.searchl(colunas,linhas,name,n);
// encerrar
 pause ( "Apertar ENTER para continuar" );
}
void metodo09 ( )
{
// identificar
 cout << endl << "Metodo9" << endl;
  int linhas = 0;
 int colunas = 0;
 int n = 0;
 string name = "metodo9.txt";
 matrix <int> m9;
 cout << "entrar com um numero de linhas: " << endl;
 cin >> linhas;
 cout << "entrar com um numero de colunas: " << endl;
 cin >> colunas;
 cout << "entrar com um numero a ser procurado: " << endl;
 cin >> n;
 m9.make(colunas,linhas);
 m9.fcall_clean(colunas,linhas,name);
 m9.searchl(colunas,linhas,name,n);
// encerrar
 pause ( "Apertar ENTER para continuar" );
}
void metodo10 ( )
{
// identificar
 cout << endl << "Metodo10" << endl;
 int linhas = 0;
 int colunas = 0;
 int n = 0;
 string name = "metodo10.txt";
 matrix <int> m10;
 cout << "entrar com um numero de linhas: " << endl;
 cin >> linhas;
 cout << "entrar com um numero de colunas: " << endl;
 cin >> colunas;
 cout << "entrar com um numero a ser procurado: " << endl;
 cin >> n;
 m10.make(colunas,linhas);
 m10.fcall_clean_trans(colunas,linhas,name);
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