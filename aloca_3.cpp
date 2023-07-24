#include <iostream>
#include <cstring>
using namespace std;

int* redimensiona_vetor(int* vetor, int tamanho) {
    int novo_tamanho = tamanho * 2;

    int* novo_vetor = new int[novo_tamanho];
    memcpy(novo_vetor, vetor, tamanho * sizeof(int));

    delete[] vetor;

    return novo_vetor;
}

int main() {
    int tamanho_velho = 5;
    int* vetor = new int[tamanho_velho] {2, 3, 1, 5, 2};

    int* novo = redimensiona_vetor(vetor, 5);
    for (int i = 0; i < 10; i++) {
        cout << novo[i] << endl;
    }

    delete[] novo;

    return 0;
}
