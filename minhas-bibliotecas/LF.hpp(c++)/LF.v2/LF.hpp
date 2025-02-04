#ifndef _LF_HPP_
#define _LF_HPP_
#include <iostream>
using std::cin ;
using std::cout;
using std::endl;
#include <iomanip>
using std::setw;
#include <string>
using std::string;
#include <fstream>
using std::ofstream;
using std::ifstream ;
#include <cmath>

//mylib
#include "LF_ERROR.hpp"

using namespace std;
//funçoes uteis
class LF
{
private:
int data;
string name;
public:
LF (string name)
{
  this->data = 1;
  this->name = name;
  cout << "OBJETO: " << name << endl;
}
~LF ()
{
  this->data = 0;
}
bool LF_fCharIsUperr(string letter)
{
  if(letter[0] >= 'A' && letter[0] <= 'Z'){return true;}
  else{return false;}
}
bool LF_fCharIsLower(string letter)
{
  if(letter[0] >= 'a' && letter[0] <= 'z'){return true;}
  else{return false;}
}
bool LF_StringHaveUperr(string str)
{
  for (int i = 0; i < str.size(); i = i + 1)
  {
  if(str[i] >= 'A' && str[i] <= 'Z'){return true;}
  }
  return false;
}
bool LF_StringHaveLower(string str)
{
  for (int i = 0; i < str.size(); i = i + 1)
  {
  if(str[i] >= 'a' && str[i] <= 'z'){return true;}
  }
  return false;
}
bool LF_AllIsUpper(string str)
{
  for (int i = 0; i < str.size(); i = i + 1)
  {
  if(str[i] >= 'a' && str[i] <= 'z'){return false;}
  }
  return true;
}
bool LF_AllIsLower(string str)
{
  for (int i = 0; i < str.size(); i = i + 1)
  {
  if(str[i] >= 'A' && str[i] <= 'Z'){return false;}
  }
  return true;
}
bool LF_IsEven(int value)
{
  if (value % 2 == 0){return true;}
  else {return false;}
}
bool LF_IsOdd(int value)
{
  if (value % 3 == 0){return true;}
  else {return false;}
}
int ConvertToInt(float value)
{
  int retorno;
  retorno = value;
  return (retorno);
}
int ConvertToReal(int value)
{
  double retorno;
  retorno = value;
  return (retorno);
}
bool LF_isMult(int x, int y)
{
  if (x % y == 0)
  {
    return true;
  }
  return false;
}
bool LF_isPrimo(int x)
{
  if (x <= 1)
  {
    return false;
  }
  for (int i = 2; i <= sqrt(x); i ++)
  {
    if (x % i == 0)
    {
      return false;
    }
  }
  return true;
}
};
class LF_Matriz
{
  private:
  int data = 0;
  int linhas = 0;
  int colunas = 0;
  int matriz[9][9]; //a biblioteca tem um maximo de linhas e colunas igual a 9
  public:
LF_Matriz()
{
  this->data = 0;
}
LF_Matriz(int linhas, int colunas)
{
  erro error;
  this->data = 1;
  if (error.erro_matriz(linhas, colunas))
  {
    cout << "erro - Matriz invalida" << endl;
    return;
  }
  else
  {
  this->linhas = linhas;
  this->colunas = colunas;
  int matriz[linhas][colunas];
  this->matriz[9][9] = matriz[linhas][colunas];
  }
}
void LF_setLinhas(int linhas)
{
  erro error;
  if (error.erro_linhas(linhas))
  {
  this->linhas = linhas;
  }
  else
  {
    cout << "erro - Matriz invalida" << endl;
    return;
  }
}
void LF_setColunas(int colunas)
{
  erro error;
  if (error.erro_colunas(colunas))
  {
  this->colunas = colunas;
  }
  else
  {
    cout << "erro - Matriz invalida" << endl;
    return;
  }
}
void LF_CreatMatriz()
{
if (this->linhas != 0 && this->colunas != 0)
{
 for (int line = 0; line < linhas; line++)
 {
   for (int collumns = 0; collumns < colunas; collumns++)
   {
    cout << "linha: " << line << ", coluna: " << collumns << ": " << endl;
    cin >> this->matriz[line][collumns];
   }
 }
}
else
{
  cout << "matriz nao criada" << endl;
  return;
}
}
void LF_PrintMatriz()
{
if (this->linhas != 0 && this->colunas != 0)
{
 for (int line = 0; line < linhas; line++)
 {
   for (int collumns = 0; collumns < colunas; collumns++)
   {
    cout << this->matriz[line][collumns] << "\t";
   }
   cout << endl;
 }
}
else
{
  cout << "matriz nao criada" << endl;
  return;
}
} 
~LF_Matriz()
{
  data = 0;
  this->linhas = 0;
  this->colunas = 0;
  int matriz[9][9];
  this->matriz[linhas][colunas] = matriz[9][9];
}
};



//eds:
//ed13
class mylib
{
 private:
 int value;
 int data;
 string name;
 string telefone;
 string telefone_pessoal;
 string telefone_residencial;
 string estado;
 public:
 //variaveis
 //geral
 mylib(string name)
 {
   erro  nome;
   if (nome.erro_name(name)){cout << "construct error" << endl;}
   else
   {
   this-> name = name;
   this->data = 1;
   cout << "nome: " << name << endl;
   }
 }
  mylib(string name,string ddd,string n1,string n2)
 {
   erro  nome;
   if (nome.erro_name(name) || nome.erro_name(ddd) ||
   nome.erro_name(n1) || nome.erro_name(n2)){cout << "construct error" << endl;}
   else
   {
   this-> name = name;
   this->telefone = "(" + ddd + ") " + "9" + n1 + "-" + n2;
   this->data = 1;
   cout << "nome: " << name << endl;
   cout << "telefone: "<< telefone << endl;
   }
 }
   mylib(string name,string ddd,string n1,string n2,string filename)
 {
   string linha;
   ifstream arquivo(filename);
   while (getline(arquivo, linha))
   {
    this->estado = this->estado + linha + "\n";
   }
   erro  nome;
   if (nome.erro_name(name) || nome.erro_name(ddd) ||
   nome.erro_name(n1) || nome.erro_name(n2)){cout << "construct error" << endl;}
   else
   {
   this-> name = name;
   this->telefone = "(" + ddd + ") " + "9" + n1 + "-" + n2;
   this->data = 1;
   cout << "nome: " << name << endl;
   cout << "telefone: "<< telefone << endl;
   cout << "estado: " << estado << endl;
   }
   arquivo.close();
 }
   mylib(string name,string ddd,string n1,string n2,string filename1, string filename2)
 {
   string linha;
   ifstream arquivo1(filename1);
    ofstream arquivo2(filename2);
   while (getline(arquivo1, linha))
   {
    this->estado = this->estado + linha + "\n";
   }
   erro  nome;
   if (nome.erro_name(name) || nome.erro_name(ddd) ||
   nome.erro_name(n1) || nome.erro_name(n2)){cout << "construct error" << endl;}
   else
   {
   this-> name = name;
   this->telefone = "(" + ddd + ") " + "9" + n1 + "-" + n2;
   this->data = 1;
   cout << "nome: " << name << endl;
   cout << "numeros de telefone = 1" << endl;
   cout << "telefone: "<< telefone << endl;
   cout << "estado: " << estado << endl;
   arquivo2 << "nome: " << name << endl;
   arquivo2 << "numeros de telefone = 1" << endl;
   arquivo2 << "telefone: "<< telefone << endl;
   arquivo2 << "estado: " << estado << endl;

   }
   arquivo1.close();
      arquivo2.close();
 }
    mylib(string name,string ddd,string n1,string n2,string filename1,
     string filename2,string dddr,string n1r, string n2r)
 {
   string linha;
   ifstream arquivo1(filename1);
   ofstream arquivo2(filename2);
   while (getline(arquivo1, linha))
   {
    this->estado = this->estado + linha + "\n";
   }
   erro  nome;
   if (nome.erro_name(name) || nome.erro_name(ddd) ||
   nome.erro_name(n1) || nome.erro_name(n2)){cout << "construct error" << endl;}
   else
   {
   this-> name = name;
   this->telefone_pessoal = "(" + ddd + ") " + "9" + n1 + "-" + n2;
   this->telefone_residencial = "(" + dddr + ") " + n1r + "-" + n2r;
   this->data = 1;
   cout << "nome: " << name << endl;
   cout << "numeros de telefone = 2" << endl;
   cout << "telefone pessoal: "<< telefone_pessoal << endl;
   cout << "telefone residencial: "<< telefone_residencial << endl;
   cout << "estado: " << estado << endl;
   arquivo2 << "nome: " << name << endl;
   arquivo2 << "numeros de telefone = 2" << endl;
   arquivo2 << "telefone pessoal: "<< telefone_pessoal << endl;
   arquivo2 << "telefone residencial: "<< telefone_residencial << endl;
   arquivo2 << "estado: " << estado << endl;
   }
   arquivo1.close();
      arquivo2.close();
 }
     mylib(string name,string ddd,string n1,string n2,string filename1,
     string filename2,string dddr,string n1r, string n2r, int numbers)
 {
   string linha;
   string temp;
   ifstream arquivo1(filename1);
   ofstream arquivo2(filename2);
   while (getline(arquivo1, linha))
   {
    this->estado = this->estado + linha + "\n";
   }
   erro  nome;
   if (nome.erro_name(name) || nome.erro_name(ddd) ||
   nome.erro_name(n1) || nome.erro_name(n2)){cout << "construct error" << endl;}
   else
   {
   this-> name = name;
   this->telefone_pessoal = "(" + ddd + ") " + "9" + n1 + "-" + n2;
   this->telefone_residencial = "(" + dddr + ") " + n1r + "-" + n2r;
    cout << "nome: " << name << endl;
    cout << "numeros de telefone = 2" << endl;
    cout << "telefone pessoal: "<< telefone_pessoal << endl;
    cout << "telefone residencial: "<< telefone_residencial << endl;
    cout << "estado: " << estado << endl;
    arquivo2 << "nome: " << name << endl;
    arquivo2 << "numeros de telefone = 2" << endl;
    arquivo2 << "telefone pessoal: "<< telefone_pessoal << endl;
    arquivo2 << "telefone residencial: "<< telefone_residencial << endl;
    arquivo2 << "estado: " << estado << endl;
   if (numbers == 1)
   {
    cout << "deseja alterar os dados do segundo numero? 1 = sim 2 = nao" << endl;
    int chose = 0;
    cin >> chose;
    if (chose != 1 && chose != 2){cout << "erro - valor invalido";}
    else if (chose == 2){}
    else 
    {
    dddr = "";
    n1r = "";
    n2r = "";
    cout << "ddd: " << endl;
       for (int i = 0; i < 2; i++)
    {
    cin >> temp;
    dddr = dddr + temp;
    }
    cout << "parte 1: " << endl;
    for (int o = 0; o < 4; o++)
    {
    cin >> temp;
    n1r = n1r + temp;
    }
    cout << "parte 2: " << endl;
    for (int j = 0; j < 4; j++)
    {
    cin >> temp;
    n2r = n2r + temp;
    }
    this->telefone_residencial = "(" + dddr + ") " + n1r + "-" + n2r;
    }
    this->data = 1;
    cout << "nome: " << name << endl;
    cout << "numeros de telefone = 2" << endl;
    cout << "telefone pessoal: "<< telefone_pessoal << endl;
    cout << "telefone residencial: "<< telefone_residencial << endl;
    cout << "estado: " << estado << endl;
    arquivo2 << "nome: " << name << endl;
    arquivo2 << "numeros de telefone = 2" << endl;
    arquivo2 << "telefone pessoal: "<< telefone_pessoal << endl;
    arquivo2 << "telefone residencial: "<< telefone_residencial << endl;
    arquivo2 << "estado: " << estado << endl;
    }
    arquivo1.close();
      arquivo2.close();
 }
 }
      mylib(string name,string ddd,string n1,string n2,string filename1,
     string filename2,string dddr,string n1r, string n2r, int numbers
     ,int change)//controle da sobrecarga
  {
   string linha;
   string temp;
   ifstream arquivo1(filename1);
   ofstream arquivo2(filename2);
   while (getline(arquivo1, linha))
   {
    this->estado = this->estado + linha + "\n";
   }
   erro nome;
   if (nome.erro_name(name) || nome.erro_name(ddd) ||
   nome.erro_name(n1) || nome.erro_name(n2)){cout << "construct error" << endl;}
   else
   {
   this-> name = name;
   this->telefone_pessoal = "(" + ddd + ") " + "9" + n1 + "-" + n2;
   this->telefone_residencial = "(" + dddr + ") " + n1r + "-" + n2r;
    cout << "nome: " << name << endl;
    cout << "numeros de telefone = 2" << endl;
    cout << "telefone pessoal: "<< telefone_pessoal << endl;
    cout << "telefone residencial: "<< telefone_residencial << endl;
    cout << "estado: " << estado << endl;
    arquivo2 << "nome: " << name << endl;
    arquivo2 << "numeros de telefone = 2" << endl;
    arquivo2 << "telefone pessoal: "<< telefone_pessoal << endl;
    arquivo2 << "telefone residencial: "<< telefone_residencial << endl;
    arquivo2 << "estado: " << estado << endl;
   if (numbers == 1)
   {
    cout << "deseja excluir o segundo numero? 1 = sim 2 = nao" << endl;
    int chose = 0;
    cin >> chose;
    if (chose != 1 && chose != 2){cout << "erro - valor invalido";}
    else if (chose == 2){}
    else 
    {
    this->telefone_residencial = "";
    }
    this->data = 1;
    cout << "nome: " << name << endl;
    if (telefone_residencial != ""){cout << "numeros de telefone = 2" << endl;}
    else {cout << "numeros de telefone = 1" << endl;}
    cout << "telefone pessoal: "<< telefone_pessoal << endl;
    if (telefone_residencial != ""){cout << "telefone residencial: "
    << telefone_residencial << endl;}
    cout << "estado: " << estado << endl;
    arquivo2 << "nome: " << name << endl;
    if (telefone_residencial != ""){arquivo2 << "numeros de telefone = 2" << endl;}
    else{arquivo2<< "numeros de telefone = 1" << endl;}
    arquivo2 << "telefone pessoal: "<< telefone_pessoal << endl;
    if (telefone_residencial != "")
    {
    arquivo2 << "telefone residencial: "<< telefone_residencial << endl;
    }
    arquivo2 << "estado: " << estado << endl;
    }
    arquivo1.close();
      arquivo2.close();
 }
 }
~mylib()
 {
   this->data = 0;
 }
 //metodo1
  void name_test (string name)
 {
   erro  nome;
    if (nome.erro_name(name))
    {
      cout << "nome valido" << endl;
    }
    else
    {
      cout << "nome invalido" << endl;
    }
 }
 //metodo2
 void value_test (int value)
 {
   erro  valor;
    if (valor.erro_value(value))
    {
      cout << "valor valido, obj1 value = " << value << endl;
    }
    else
    {
      cout << "valor invalido" << endl;
    }
 }
};
#endif
//ed14
class ed14 
{
  //metodo 1 e 2 ta nas funcoes uteis
  private: 
  public:
};
class cell
{
  public:
  cell* next;
  int dado;
  cell()
  {
    this->dado = 0;
    this->next = nullptr;
  }
  cell(int x)
  {
    this->dado = x;
    this->next = nullptr;
  }
  ~cell()
  {
    if (this->next != nullptr)
    {
      delete next;
    }
  }
};
class pilha
{
  private:
  void printreverse(cell* atual)
  {
    if(atual->next != nullptr){printreverse(atual->next);}
    cout << "pilha -> " << atual->dado << endl;
  }
  public:
  cell* top;
  cell* tmp;
  pilha ()
  {
  top = nullptr;
  }
  ~pilha()
  {
    if (top)
    {
      delete this->top;
    }
  }
  bool printreverse()
  {
    if (this->top != nullptr)
    {
    printreverse(top);
    return true;
    }
    else return false;
  }
  bool print()
  {
    if (top == nullptr){return false;}
    cell* tmp = top;
    do{
    cout << "pilha -> " << tmp->dado << endl;
    tmp = tmp->next;
    }while(tmp != nullptr);
    return true;
  }
  void add(int x)
  {
  cell* tmp = new cell(x);
  tmp->next = top;
  top = tmp;
  }
  void remove_top()
  {
    if(top==nullptr){return;}
    else
    {
    cell* temp = top;
    top = top->next;
    temp->next = nullptr;
    delete temp;
    }
  }
  void trade_top()
  {
    if(top==nullptr){return;}
    else
    {
    int x = top->next->dado;
    top->next->dado = top->dado;
    top->dado=x;
    }
  }
  void printdouble(cell* atual)
  {
    if(atual->next != nullptr){printdouble(atual->next);}
    cout << "pilha -> " << atual->dado * 2 << endl;
  }
  bool printdouble()
  {
    if (this->top != nullptr)
    {
    printdouble(top);
    return true;
    }
    else return false;
  }
};
