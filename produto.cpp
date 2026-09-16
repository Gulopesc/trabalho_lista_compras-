#include "produto.h"

//construtor da classe, inicializando a quantidade atual de produtos como 0
ListaCompras::ListaCompras() : ultimo(0) {}

//verifica se a lista tá vazia (se o indice do ultimo item for zero igual o primeiro)
bool ListaCompras::listaVazia(){
        return ultimo==primeiro;
    }

//verifica se há um produto com determinado codigo, percorrendo todos os produtos procurando um com o mesmo codigo
//retorna true se encontrar, false caso contrario
bool ListaCompras::confereRepetido(string codigo) {
    for (int i = 0; i < ultimo; i++) {
        if (produtos[i].codProduto == codigo) {
            return true;
        }
    }
    return false;
}

//verifica se a lista tá cheia (se já tem 100 itens) e retorna true se estiver
bool ListaCompras::listaCheia(){
    return ultimo == 100;
}

//cadastra um novo produto no final da lista (só se ela não estiver cheia e o codigo não for repetido, que é verificado na main na hora de por os dados)
void ListaCompras::cadastraProduto(item novoItem){
        produtos[ultimo] = novoItem;
        ultimo++;

        cout << "Produto cadastrado com sucesso!" << endl;
        return;
    }

 //remove um item de uma posição i, usada nas funções de remover por codigo e remover do fim
void ListaCompras::removeItem(int i){
    if (listaVazia()){
            cout << "Lista vazia, nao ha produtos para remover." << endl;
            return;
        }
        for (; i < ultimo - 1; i++){
            produtos[i] = produtos[i+1];
        }
        ultimo--;
        cout << "Elemento removido da posicao " << i << endl;
    }

//remove o ultimo item da lista usando a função padrão de remover
void ListaCompras::removeUltimo(){
        if (listaVazia()){
            cout << "Lista vazia, nao ha produtos para remover." << endl;
            return;
        }

        ultimo--;
        cout << "Ultimo elemento removido." << endl;
    }

//remove um item de acordo com o codigo dele, se não achar com o codigo não faz nada
void ListaCompras::removePorCodigo (string codigo){
        if (listaVazia()){
            cout << "Lista vazia, nao ha produtos para remover." << endl;
            return;
        }
        for (int i = 0; i < ultimo; i++){
            if (produtos[i].codProduto == codigo){
                removeItem(i);
                return;
            }
        }
        cout << "Produto nao encontrado. " << endl;
        return;
    }

//imprime as informações de um produto de acordo com o codigo dele, se não achar com o codigo não faz nada
void ListaCompras::imprimePorCodigo (string codigo){
        if (listaVazia()){
            cout << "Lista vazia, nao ha produtos para procurar." << endl;
            return;
        }
        for (int i = 0; i < ultimo; i++){
            if (produtos[i].codProduto == codigo){
                cout << "Produto: " << produtos[i].nome << endl;
                cout << "Codigo: " << produtos[i].codProduto << endl;
                cout << "Quantidade: " << produtos[i].quantidade << endl;
                cout << "Valor: " << produtos[i].valor << endl;
                return;
            }
        }
        cout << "Produto nao encontrado. " << endl;
        return;
    }

//imprime todos os itens da lista se ela não estiver vazia
void ListaCompras::imprimeLista(){
        if (listaVazia()){
            cout << "Lista vazia, nao ha produtos para imprimir" << endl;
            return;
        }
        for(int i = 0; i < ultimo; i++){
            cout << "Produto " << i+1 << " da lista: " << endl;
            cout << "Nome: " << produtos[i].nome << endl;
            cout << "Codigo: " << produtos[i].codProduto << endl;
            cout << "Quantidade: " << produtos[i].quantidade << endl;
            cout << "Valor: " << produtos[i].valor << endl << endl;
        }
    }

//calcula o total da lista, percorrendo item por item até o ultimo e multiplicando a quantidade pelo valor unitario
//tudo só executa se a lista não estiver vazia
void ListaCompras::calculaTotal(){
        if (listaVazia()){
            cout << "Lista vazia, nao ha produtos para calcular." << endl;
            return;
        }

        double total = 0;
        float valor;
        for(int i = 0; i < ultimo; i++){
            valor = produtos[i].valor * produtos[i].quantidade;
            total += valor;
        }

        cout << "O valor total da lista e de: R$" << total << endl;
        return;
    }