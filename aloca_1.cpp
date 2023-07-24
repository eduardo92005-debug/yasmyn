#include <iostream>
using namespace std;
int main() {
    int capacidade = 100;
    int tamanho = 0;
    int* vetor = new int[capacidade];

    // Populando o vetor com elementos de exemplo
    for (int i = 0; i < capacidade; i++) {
        vetor[i] = i + 1;
        tamanho++;
    }

    // Verificando se o vetor está cheio
    if (tamanho >= capacidade) {
        int novaCapacidade = capacidade * 2; // Dobrar a capacidade
        int* novoVetor = new int[novaCapacidade];

        // Copiar os elementos do vetor antigo para o novo vetor
        for (int i = 0; i < tamanho; i++) {
            novoVetor[i] = vetor[i];
        }

        // Liberar a memória alocada para o vetor antigo
        delete[] vetor;

        // Atualizar os ponteiros para o novo vetor
        vetor = novoVetor;
        capacidade = novaCapacidade;
    }

    // Imprimir o vetor realocado
    for (int i = 0; i < tamanho; i++) {
        std::cout << vetor[i] << " ";
    }
    cout << endl;

    // Liberar a memória alocada para o vetor
    delete[] vetor;

    return 0;
}
