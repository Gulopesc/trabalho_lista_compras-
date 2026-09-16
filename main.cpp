#include "produto.h"
#include <iostream>

int main(){
    ListaCompras listaCompras;
    int resposta = 200;

    //ui basica dando pro usuario as opções que o programa tem
    do {
        cout << "1 - Adicionar item na lista" << endl;
        cout << "2 - Remover item da lista" << endl;
        cout << "3 - Consultar itens da lista" << endl;
        cout << "4 - Calcular valor total da lista" <<endl;
        cout << "0 - Finalizar programa" << endl;
        cout << "Digite a opcao correspontente ao comando que deseja executar: " << endl;
        
        cin >> resposta;

        switch(resposta){
            //case para inserir itens se a lista não estiver cheia
            //o código não pode ser repetido
            case 1:{
                if (listaCompras.listaCheia()){
                    cout << "Lista cheia, remova algum produto antes de cadastrar outro." << endl;
                    break;
                }
                item novoItem;
                do{
                    cout << "Digite o codigo do produto: ";
                    cin >> novoItem.codProduto;
                    if (listaCompras.confereRepetido(novoItem.codProduto))
                        cout << "Ja ha um produto com esse codigo, digite outro." << endl;
                }while (listaCompras.confereRepetido(novoItem.codProduto));

                cout << "Digite o nome do produto: ";
                cin >> ws;
                getline(cin, novoItem.nome);
                cout << "Digite a quantidade a ser comprada: ";
                cin >> novoItem.quantidade;
                cout << "Digite o valor unitario do produto: ";
                cin >> novoItem.valor;

                listaCompras.cadastraProduto(novoItem);
                break;
            }
            //case pra englobar as duas formas de remover itens da lista(fim ou qualquer posicao)
            case 2:{ 
                char alternativa = 'z';
                do{
                    cout << "Digite \"a\" para remover o ultimo item da lista ou \"b\" para remover um item qualquer pelo codigo: ";
                    cin >> alternativa;
                    if (alternativa != 'a' && alternativa != 'b')
                        cout << "Resposta invalida.";
                }while (alternativa != 'a' && alternativa != 'b');

                if (alternativa == 'a'){
                    listaCompras.removeUltimo();
                }
                if (alternativa == 'b'){
                    string codigoRemover;
                    cout << "Digite o codigo do produto que deseja remover: ";
                    cin >> codigoRemover;
                    listaCompras.removePorCodigo(codigoRemover);
                }
                break;
            }
            //case englobando os dois tipos de consulta (todos os elementos ou pelo codigo)
            case 3:{ 
                char alternativa = 'z';
                do{
                    cout << "Digite \"a\" para consultar toda a lista ou \"b\" para consultar um item especifico: ";
                    cin >> alternativa;
                    if (alternativa != 'a' && alternativa != 'b')
                        cout << "Resposta invalida.";
                }while (alternativa != 'a' && alternativa != 'b');

                if (alternativa == 'a'){
                    listaCompras.imprimeLista();
                }
                if (alternativa == 'b'){
                    string codigoImprimir;
                    cout << "Digite o codigo do produto que deseja visualizar: ";
                    cin >> codigoImprimir;
                    listaCompras.imprimePorCodigo(codigoImprimir);
                }
                break;
            }
            
            //case pra exibir o valor total da lista
            case 4:{
                listaCompras.calculaTotal();
                break;
            }
            //case pra finalizar
            case 0:{
                cout << "Programa finalizado." << endl;
                break;  
            }
            //case caso a opção dada pelo usuario não seja reconhecida
            default:{
                cout << "Opcao nao reconhecida. " << endl;
                break;
            }
        }

        cout << endl;
    } while (resposta != 0);
    return 0;
}