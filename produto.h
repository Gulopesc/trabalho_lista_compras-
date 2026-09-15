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
    //construtor da classe, inicializando a quantidade atual de produtos como 0
    ListaCompras() : ultimo(0) {}

    //verifica se a lista tá vazia (se o indice do ultimo item for zero igual o primeiro)
    bool listaVazia(){
        return ultimo==primeiro;
    }

    //verifica se há um produto com determinado codigo, percorrendo todos os produtos procurando um com o mesmo codigo
    //retorna true se encontrar, false caso contrario
    bool confereRepetido(string codigo){
        for (int i = 0; i < ultimo; i++){
            if (produtos[i].codProduto == codigo){
                return true;
            }
        }
        return false;
    }

    //verifica se a lista tá cheia (se já tem 100 itens) e retorna true se estiver
    bool listaCheia(){
        return ultimo == 100;
    }

    //cadastra um novo produto no final da lista (só se ela não estiver cheia e o codigo não for repetido)
    void cadastraProduto(item novoItem){
        if (listaCheia()){
            cout << "Lista cheia, remova algum produto antes de cadastrar outro." << endl;
            return;
        }
        if (confereRepetido(novoItem.codProduto)){
            cout << "Ja existe um produto com esse codigo" << endl; 
        }
        produtos[ultimo] = novoItem;
        cout << "Produto cadastrado com sucesso!" << endl;
        return;
    }

    //remove um item de uma posição i, usada nas funções de remover por codigo e remover do fim
    void removeItem(int i){
        if (listaVazia()){
            cout << "Lista vazia, nao ha produtos para remover." << endl;
            return;
        }
        for (i; i < ultimo - 1; i++){
            produtos[i] = produtos[i+1];
        }
        i--;
        cout << "Elemento removido da posicao " << i << endl;
    }

    //remove um item de acordo com o codigo dele, se não achar com o codigo não faz nada
    void removePorCodigo (string codigo){
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
    void imprimePorCodigo (string codigo){
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
    void imprimeLista(){
        if (listaVazia()){
            cout << "Lista vazia, nao ha produtos para imprimir" << endl;
            return;
        }
        for(int i = 0; i < ultimo; i++){
            cout << i+1 << "º produto da lista: " << endl;
            cout << "Produto: " << produtos[i].nome << endl;
            cout << "Codigo: " << produtos[i].codProduto << endl;
            cout << "Quantidade: " << produtos[i].quantidade << endl;
            cout << "Valor: " << produtos[i].valor << endl << endl;
            return;
        }
    }
    //calcula o total da lista, percorrendo item por item até o ultimo e multiplicando a quantidade pelo valor unitario
    //tudo só executa se a lista não estiver vazia
    void calculaTotal(){
        if (listaVazia()){
            cout << "Lista vazia, nao ha produtos para remover." << endl;
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




};