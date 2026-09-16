#ifndef PRODUTO_H
#define PRODUTO_H

#include <iostream>
#include <string>

using namespace std;

struct item {
    string codProduto;
    int quantidade;
    string nome;
    double valor;
    item* proximo;
};

class ListaCompras {
private:
    item* primeiro;
    item* ultimo;
    int tam;

public:
    ListaCompras();
    ~ListaCompras();

    bool listaVazia() const;
    bool confereRepetido(string codigo) const;
    void cadastraProduto(const item& novoItem);
    void removeUltimo();
    void removePorCodigo(string codigo);
    void imprimePorCodigo(string codigo) const;
    void imprimeLista() const;
    double calculaTotal() const;
};

    void cadastraProduto(item novoItem);
    void removePorCodigo (string codigo);
    void imprimePorCodigo (string codigo);
    void imprimeLista();
    void removeUltimo();
};
#endif
