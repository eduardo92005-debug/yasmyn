#include <iostream>

using namespace std;

int busca_binaria(int vetor[], int tamanho, int buscado){
    int esquerda = 0;
    int direita = tamanho - 1;

    while(esquerda <= direita){
        int meio = esquerda + (direita - esquerda) / 2;

        if(vetor[meio] == buscado){
            return meio;
        }

        if(vetor[meio] > buscado){
            direita = meio - 1;
        } else {
            esquerda = meio + 1;
        }
    }

    return -1;
}

int main() {
    int array[] = {1,2,5,6,13};
    int tamanho = sizeof(array) / sizeof(array[0]);
    int buscado = 13;

    int resultado = busca_binaria(array, tamanho, buscado);
    cout << resultado << endl;

}