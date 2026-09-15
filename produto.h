#include <iostream>
#include <string>

using namespace std;

//criando a classe de produto
struct item {
    string codProduto;
    int quantidade;
    string nome;
    double valor;
};

//criando a classe de lista de compras, ainda faltam adicionar todas as funções que serão utilizadas para manipular a lista de compras
class ListaCompras {
private:
    item produtos[100];
    int primeiro = 0;
    int ultimo = primeiro;
public:
    //construtor da classe, inicializando a quantidade atual de produtos como 0
    ListaCompras() : ultimo(0) {}

    bool listaVazia(){
        return ultimo==primeiro;
    }

    bool confereRepetido(string codigo){
        for (int i = 0; i < ultimo; i++){
            if (produtos[i].codProduto == codigo){
                return true;
            }
        }
        return false;
    }

    bool listaCheia(){
        return ultimo == 100;
    }

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

    void imprimePorCodigo (string codigo){
        if (listaVazia){
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




};