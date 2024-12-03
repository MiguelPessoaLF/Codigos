#include <iostream>
#include <string>

using namespace std;

class Livro

{
private:
    string titulo;
    int numeroPaginas;

public:

    Livro(string tituloLivro, int paginasLivro)

{
        titulo = tituloLivro;
        numeroPaginas = paginasLivro;
    }


    string getTitulo() const

{
        return titulo;
    }

    int getNumeroPaginas() const

{
        return numeroPaginas;
    }


    void setTitulo(string novoTitulo)

{
        titulo = novoTitulo;
    }

    void setNumeroPaginas(int novasPaginas)

{
        numeroPaginas = novasPaginas;
    }


    void imprimirDetalhes() const

{
        cout << "titulo: " << titulo << endl;
        cout << "paginas: " << numeroPaginas << endl;
    }
};

int main() {
    string tituloLivro;
    int numeroPaginas;


    cin >> tituloLivro;
    cin >> numeroPaginas;


    cin.ignore();


    Livro livro(tituloLivro, numeroPaginas);


    cout << "detalhes: " << endl;
    livro.imprimirDetalhes();

    string subtitulo;
    getline(cin, subtitulo);    livro.setTitulo(tituloLivro + ": " + subtitulo);    livro.setNumeroPaginas(numeroPaginas + 50);    cout << "novos detalhes:" << endl;
    livro.imprimirDetalhes();

    return 0;
}


//Miguel Pessoa Lima Ferreira