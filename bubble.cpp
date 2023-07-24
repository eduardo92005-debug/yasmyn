#include <iostream>
#include <fstream>

int main() {
    std::ifstream arquivo("modas.txt"); 

    if (!arquivo.is_open()) {
        std::cout << "Erro ao abrir o arquivo." << std::endl;
        return 1;
    }

    int numero;
    int maiorFrequencia = 0;
    int moda = 0;

    int frequencia[1001] = {0}; // Array para armazenar as frequências dos números

    while (arquivo >> numero) {
        std::cout << frequencia[numero] << std::endl;
        frequencia[numero]++;
    }

    arquivo.close();

    for (int i = 0; i <= 1000; i++) {
        if (frequencia[i] > maiorFrequencia) {
            maiorFrequencia = frequencia[i];
            moda = i;
        }
    }

    std::cout << "Moda: " << moda << std::endl;
    std::cout << "Frequência: " << maiorFrequencia << std::endl;

    return 0;
}
