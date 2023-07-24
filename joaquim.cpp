#include <iostream>

struct Frequencia {
    int numero;
    int frequencia;
};

struct Mapa {
    Frequencia* frequencias;
    int tamanho;

    Mapa(int tam) : tamanho(tam) {
        frequencias = new Frequencia[tamanho];
    }

    ~Mapa() {
        delete[] frequencias;
    }

    void adicionarNumero(int numero) {
        for (int i = 0; i < tamanho; i++) {
            if (frequencias[i].numero == numero) {
                frequencias[i].frequencia++;
                return;
            }
        }

        // Caso o número ainda não esteja no mapa, adiciona-o
        for (int i = 0; i < tamanho; i++) {
            if (frequencias[i].frequencia == 0) {
                frequencias[i].numero = numero;
                frequencias[i].frequencia = 1;
                return;
            }
        }
    }

    void exibirFrequencias() {
        for (int i = 0; i < tamanho; i++) {
            if (frequencias[i].frequencia > 0) {
                std::cout << "Número: " << frequencias[i].numero << " - Frequência: " << frequencias[i].frequencia << std::endl;
            }
        }
    }
};

int main() {
    int tamanho;

    std::cout << "Digite o tamanho do mapa de frequências: ";
    std::cin >> tamanho;

    Mapa mapa(tamanho);

    // Adicionando números ao mapa de frequência
    int numero;
    std::cout << "Digite os números (um por vez):" << std::endl;
    for (int i = 0; i < tamanho; i++) {
        std::cin >> numero;
        mapa.adicionarNumero(numero);
    }

    // Exibindo as frequências dos números
    mapa.exibirFrequencias();

    return 0;
}
