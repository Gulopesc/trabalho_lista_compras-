#include <iostream>
#include <string>

using namespace std;

//criando a classe de produto
class Produto {
public:
    int codigo;
    int quantidade;
    string nome;
    double preco;

    Produto(int c = 0, string n = "", int q = 0, double p = 0.0)
        : codigo(c), nome(n), quantidade(q), preco(p) {}
};

//criando a classe de lista de compras, ainda faltam adicionar todas as funções que serão utilizadas para manipular a lista de compras
class ListaCompras {
private:
    const int capMax = 100;
    Produto produtos[100];
    int qtdAtual;
public:
    //construtor da classe, inicializando a quantidade atual de produtos como 0
    ListaCompras() : qtdAtual(0) {}



};