#ifndef _mylib1300_HPP_
#define _mylib_HPP_
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
#include "myerror.hpp"
using namespace std;
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
   erro <int> nome;
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
   erro <int> nome;
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
   erro <int> nome;
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
   erro <int> nome;
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
   erro <int> nome;
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
   erro <int> nome;
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
   erro <int> nome;
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
   erro <int> nome;
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
   erro <int> valor;
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

