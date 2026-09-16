#include "produto.h"

ListaCompras::ListaCompras() : primeiro(nullptr), ultimo(nullptr), tam(0) {}

ListaCompras::~ListaCompras() {
    while (!listaVazia()) {
        removeUltimo();
    }
}

bool ListaCompras::listaVazia() const {
    return primeiro == nullptr;
}

bool ListaCompras::confereRepetido(string codigo) const {
    for (item* atual = primeiro; atual != nullptr; atual = atual->proximo) {
        if (atual->codProduto == codigo) {
            return true;
        }
    }
    return false;
}

void ListaCompras::cadastraProduto(const item& novoItem) {
    item* novoPtr = new item;
    *novoPtr = novoItem;
    novoPtr->proximo = nullptr;

    if (listaVazia()) {
        primeiro = novoPtr;
        ultimo = novoPtr;
    } else {
        ultimo->proximo = novoPtr;
        ultimo = novoPtr;
    }

    tam++;
    cout << "Produto cadastrado com sucesso!" << endl;
}

void ListaCompras::removeUltimo() {
    if (listaVazia()) {
        cout << "Lista vazia, nao ha produtos para remover." << endl;
        return;
    }

    if (primeiro == ultimo) {
        delete primeiro;
        primeiro = nullptr;
        ultimo = nullptr;
        tam = 0;
        cout << "Ultimo item removido." << endl;
        return;
    }

    item* atual = primeiro;
    while (atual->proximo != ultimo) {
        atual = atual->proximo;
    }

    delete ultimo;
    ultimo = atual;
    ultimo->proximo = nullptr;
    tam--;
    cout << "Ultimo item removido." << endl;
}

void ListaCompras::removePorCodigo(string codigo) {
    if (listaVazia()) {
        cout << "Lista vazia, nao ha produtos para remover." << endl;
        return;
    }

    item* anterior = nullptr;
    item* atual = primeiro;

    while (atual != nullptr && atual->codProduto != codigo) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == nullptr) {
        cout << "Produto nao encontrado." << endl;
        return;
    }

    if (anterior == nullptr) {
        primeiro = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    if (atual == ultimo) {
        ultimo = anterior;
    }

    delete atual;
    tam--;
    cout << "Produto removido com sucesso." << endl;
}

void ListaCompras::imprimePorCodigo(string codigo) const {
    if (listaVazia()) {
        cout << "Lista vazia, nao ha produtos para procurar." << endl;
        return;
    }

    for (item* atual = primeiro; atual != nullptr; atual = atual->proximo) {
        if (atual->codProduto == codigo) {
            cout << "Produto: " << atual->nome << endl;
            cout << "Codigo: " << atual->codProduto << endl;
            cout << "Quantidade: " << atual->quantidade << endl;
            cout << "Valor: " << atual->valor << endl;
            return;
        }
    }

    cout << "Produto nao encontrado." << endl;
}

void ListaCompras::imprimeLista() const {
    if (listaVazia()) {
        cout << "Lista vazia, nao ha produtos para imprimir." << endl;
        return;
    }

    item* atual = primeiro;
    while (atual != nullptr) {
        cout << "Produto: " << atual->nome << endl;
        cout << "Codigo: " << atual->codProduto << endl;
        cout << "Quantidade: " << atual->quantidade << endl;
        cout << "Valor: " << atual->valor << endl << endl;
        atual = atual->proximo;
    }
}

double ListaCompras::calculaTotal() const {
    if (listaVazia()) {
        cout << "Lista vazia, nao ha produtos para calcular." << endl;
        return 0.0;
    }

    double total = 0.0;
    for (item* atual = primeiro; atual != nullptr; atual = atual->proximo) {
        total += atual->valor * atual->quantidade;
    }

    cout << "Valor total da lista: R$ " << total << endl;
    return total;
}