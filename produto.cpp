#include "produto.h"

//método para criar a lista, que começa com primeiro e ultimo apontando pra nada e tamanho 0
ListaCompras::ListaCompras() : primeiro(nullptr), ultimo(nullptr), tam(0) {}

//metodo pra destruir os itens da lista, vai apagando o ultimo até que a lista fique totalmente vazia
ListaCompras::~ListaCompras() {
    while (!listaVazia()) {
        removeUltimo();
    }
}

//verifica se a lista está totalmente vazia, olhando se o ponteiro primeiro aponta pra nada (ou seja, não há item algum)
bool ListaCompras::listaVazia() const {
    return primeiro == nullptr;
}

//percorre cada item do primeiro ao ultimo usando o ponteiro "Proximo" pra ver se já tem algum item com o codigo
bool ListaCompras::confereRepetido(string codigo) const {
    for (item* atual = primeiro; atual != nullptr; atual = atual->proximo) {
        if (atual->codProduto == codigo) {
            return true;
        }
    }
    return false;
}

//cadastra um produto com os dados inseridos na main, como ele chega no final da lista o ponteiro do que era o ultimo aponta pra ele e o ponteiro dele aponta pra nada
//a contagem tambem é atualizada e o ponteiro "ultimo" passa a apontar pra ele
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

//se a lista não estiver vazia vai deletar o ultimo item
//se o ultimo for igual ao primeiro só tem um item e vai deletar ele
//se não for vai percorrer cada item até chegar no que aponta pro ultimo, então define esse como ultimo e deleta o ultimo
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

//se a lista não estiver vazia vai procurar o item com determinado codigo pra deletar
//percorre item por item, sempre guardando o item anterior, até chegar no final da lista ou achar o código
//se achar e for o primeiro, redefine o primeiro como o próximo, se for o ultimo redefine o ultimo como o anterior
//se estiver no meio, faz o anterior apontar pro próximo
//em qualquer caso, deleta o atual no final
//ou, se não achar nenhum item com código, só informa ao usuario e retorna
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

//procura e imprime o item com o mesmo codigo que o passado na função (não existem codigos repetidos)
//se estuver vazio só avisa e retorna
//se não estiver faz um for pra percorrer toda a lista e imprimir o item com o código, e retornar
//se chegar no fim sem achar o código, avisa e também retorna
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

//imprime toda a lista de compras, todos os itens com seus dados
//primeiro verifica se tá fazia, se estiver avisa do erro e retorna
//percorre toda a lista até chegar no fim (quando o ponteiro "proximo") apontar pra nada, e imprime os dados do item
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

//calcula o valor total da lista de acordo com a quantidade e preço de cada item
//primeiro verifica se não está vazia, se etiver ele avisa e retorna
//depois percorre item por item até chegar no fim, a cada item ele multiplica quantidade e preço e adiciona a uma soma total
//depois de percorrer tudo ele imprime o valor total da lista
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