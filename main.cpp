#include "produto.h"
#include <iostream>

using namespace std;

int main() {
    ListaCompras listaCompras;
    int resposta = -1;

    while (resposta != 0) {
        //tela que aparece pro usuário depois de cada operação com as opções disponiveis
        cout << "\n===== Lista de Compras =====" << endl;
        cout << "1 - Adicionar item na lista" << endl;
        cout << "2 - Remover item da lista" << endl;
        cout << "3 - Consultar itens da lista" << endl;
        cout << "4 - Calcular valor total da lista" << endl;
        cout << "0 - Finalizar programa" << endl;
        cout << "Digite a opcao correspondente ao comando que deseja executar: ";
        cin >> resposta;

        //switch pra executar cada função de acordo com a alternativa escolhida
        switch (resposta) {
            case 1: {
                //pega os dados do novo item (impede codigos que já existam) e adiciona à lista
                item novoItem;
                do {
                    cout << "Digite o codigo do produto: ";
                    cin >> novoItem.codProduto;

                    if (listaCompras.confereRepetido(novoItem.codProduto)) {
                        cout << "Ja ha um produto com esse codigo. Digite outro." << endl;
                    }
                } while (listaCompras.confereRepetido(novoItem.codProduto));

                cout << "Digite o nome do produto: ";
                cin >> novoItem.nome;
                do {
                    cout << "Digite a quantidade a ser comprada: ";

                    if (!(cin >> novoItem.quantidade)) {
                        cout << "Digite apenas um numero inteiro." << endl;
                        cin.clear();
                        cin.ignore(10000, '\n');
                        novoItem.quantidade = 0;
                    }

                     if (novoItem.quantidade <= 0) {
                        cout << "A quantidade deve ser maior que zero." << endl;
                    }

                } while (novoItem.quantidade <= 0);
                do {
                    cout << "Digite o valor unitario do produto: ";

                    if (!(cin >> novoItem.valor)) {
                        cout << "Digite apenas um numero." << endl;
                        cin.clear();
                        cin.ignore(10000, '\n');
                        novoItem.valor = 0;
                    }

                    if (novoItem.valor <= 0) {
                        cout << "O valor deve ser maior que zero." << endl;
                    }

                } while (novoItem.valor <= 0);
                novoItem.proximo = nullptr;

                listaCompras.cadastraProduto(novoItem);
                break;
            }
            
            case 2: {
                //pergunta ao usuário se ele quer remover o ultimo item ou um item qualquer pelo codigo e executa a função para tal
                char alternativa = 'z';
                do {
                    cout << "Digite 'a' para remover o ultimo item da lista ou 'b' para remover um item pelo codigo: ";
                    cin >> alternativa;
                    if (alternativa != 'a' && alternativa != 'b') {
                        cout << "Resposta invalida." << endl;
                    }
                } while (alternativa != 'a' && alternativa != 'b');

                if (alternativa == 'a') {
                    listaCompras.removeUltimo();
                } else {
                    string codigoRemover;
                    cout << "Digite o codigo do produto que deseja remover: ";
                    cin >> codigoRemover;
                    listaCompras.removePorCodigo(codigoRemover);
                }
                break;
            }

            case 3: {
                //pergunta ao usuário se ele quer imprimir toda a lista ou um item qualquer pelo codigo e executa a função para tal
                char alternativa = 'z';
                do {
                    cout << "Digite 'a' para consultar toda a lista ou 'b' para consultar um item especifico: ";
                    cin >> alternativa;
                    if (alternativa != 'a' && alternativa != 'b') {
                        cout << "Resposta invalida." << endl;
                    }
                } while (alternativa != 'a' && alternativa != 'b');

                if (alternativa == 'a') {
                    listaCompras.imprimeLista();
                } else {
                    string codigoImprimir;
                    cout << "Digite o codigo do produto que deseja visualizar: ";
                    cin >> codigoImprimir;
                    listaCompras.imprimePorCodigo(codigoImprimir);
                }
                break;
            }

            case 4:
                //calcula o valor total dos produtos atualmente na lista
                listaCompras.calculaTotal();
                break;

            case 0:
                cout << "Programa encerrado." << endl;
                break;

            default:
                cout << "Opcao nao reconhecida." << endl;
                break;
        }
        atrasaCodigo();
    }
    return 0;
}