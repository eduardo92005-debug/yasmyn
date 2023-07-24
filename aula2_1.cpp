#include <iostream>

using namespace std;
// Criacao de buscar
// 1 - Passo: Saber o tamanho dos dados que iremos iterar sobre
// 2 - Passo: Verificar se o dado que esta sendo buscado bate
// com o dado que tem no vetor
// 3 - Passo: Se foi encontrado, retornar o indice
// 4 - Passo: Se nao foi encontrado, retornar -1
// Dado o numero 2 e 4
// Fazer a soma dos dois e depois dividir a soma pelo segundo
// 2 + 4 = 6 -> 6/4
// Criando duas funcoes, funcao soma e funcao dividir (2 parametros)


int buscar_numero(int vetor[], int tamanho, int numero_buscar){
    for(int i = 0; i < tamanho; i++){
        if(vetor[i] == numero_buscar){
            return i;
        }
    }
    return -1;
}

int main() {
    // Passo 1 - Criar o nosso vetor de dados
    // Passo 2 - Determinar o tamanho do tipo de dado principal
    // Passo 3 - Obter do usuario o numero a ser buscado
    // Passo 4 - Criar a funcao de buscar numero
    int vetor[] = {5, 10, 2, 7, 8, 12};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int numero;
    cout << "Digite o numero a ser buscado: ";
    cin >> numero;
    int buscado = buscar_numero(vetor, tamanho, numero);
    if(buscado != -1){
        cout << "Encontrado no indice: " << buscado << endl;
    } else {
        cout << "Nao encontrado" << endl;
    }
    return 0;
}
