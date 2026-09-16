#include "produto.h"
#include <iostream>

using namespace std;

int main() {
    ListaCompras listaCompras;
    int resposta = -1;

    while (resposta != 0) {
        cout << "\n===== Lista de Compras =====" << endl;
        cout << "1 - Adicionar item na lista" << endl;
        cout << "2 - Remover item da lista" << endl;
        cout << "3 - Consultar itens da lista" << endl;
        cout << "4 - Calcular valor total da lista" << endl;
        cout << "0 - Finalizar programa" << endl;
        cout << "Digite a opcao correspondente ao comando que deseja executar: ";
        cin >> resposta;

        switch (resposta) {
            case 1: {
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
                cout << "Digite a quantidade a ser comprada: ";
                cin >> novoItem.quantidade;
                cout << "Digite o valor unitario do produto: ";
                cin >> novoItem.valor;
                novoItem.proximo = nullptr;

                listaCompras.cadastraProduto(novoItem);
                break;
            }

            case 2: {
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
                listaCompras.calculaTotal();
                break;

            case 0:
                cout << "Programa encerrado." << endl;
                break;

            default:
                cout << "Opcao nao reconhecida." << endl;
                break;
        }
    }

    return 0;
}