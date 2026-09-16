#include <iostream>
#include <string>

using namespace std;

//criando o struct do produto
struct item {
    string codProduto;
    int quantidade;
    string nome;
    double valor;
};

//Criando a classe da lista de compras, com as funções que o trabalho pede
class ListaCompras {
private:
    item produtos[100];
    int primeiro = 0;
    int ultimo = primeiro;
public:

    ListaCompras();

    bool listaVazia();
    bool confereRepetido(string codigo);
    bool listaCheia();

    void cadastraProduto(item novoItem);
    void removeItem(int i);
    void removePorCodigo (string codigo);
    void imprimePorCodigo (string codigo);
    void imprimeLista();
    void calculaTotal();
};