#include "produto.h"
#include <iostream>

int main(){
    ListaCompras listaCompras;
    int resposta = 0;

    while(resposta != -1){ 
        cout << "1 - Adicionar item na lista" << endl;
        cout << "2 - Remover item da lista" << endl;
        cout << "3 - Consultar itens da lista" << endl;
        cout << "4 - "Calcular valor total da lista" <<endl;
        cout << "0 - "Finalizar programa" << endl;
        cout << "Digite a opcao correspontente ao comando que deseja executar: " << endl;
        
        cin >> resposta;

        switch(resposta){
            case 1:
                if (listaCompras.listaCheia()){
                    cout << "Lista cheia, remova algum produto antes de cadastrar outro." << endl;
                    break;
                }
                item novoItem;
                do{
                    cout << "Digite o codigo do produto: ";
                    cin >> novoItem.codigo;
                    if (listaCompras.confereRepetido(novoItem.codigo))
                        cout << "Ja ha um produto com esse codigo, digite outro." << endl;
                }while (listaCompras.confereRepetido(novoItem.codigo));

                cout << "Digite o nome do produto: ";
                cin >> novoItem.nome;
                cout << "Digite a quantidade a ser comprada: ";
                cin >> novoItem.quantidade;
                cout << "Digite o valor unitario do produto: ";
                cin >> novoItem.valor;

                listaCompras.cadastraProduto(novoItem);
            }
            case 2: 
                char alternativa = 'z';
                do{
                    cout << "Digite \"a\" para remover o ultimo item da lista ou \"b\" para remover um item qualquer pelo codigo: ";
                    cin >> alternativa;
                    if (alternativa != 'a' || alternativa != 'b')
                        cout << "Resposta invalida.";
                }while (alternativa != 'a' || alternativa != 'b');

                if (alternativa == 'a'){
                    listaCompras.removeItem (listaTeste.getUltimo);
                }
                if (alternativa == 'b')

        }
    return 0;
}