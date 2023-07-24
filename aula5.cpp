#include <iostream>

using namespace std;

int main() {
    int tamanho;
    cout << "Digite o tamanho do vetor de inimigos: ";
    cin >> tamanho;

    int vidaInimigos[tamanho];
    int inimigosDerrotados = 0;

    cout << "Digite a vida dos " << tamanho << " inimigos separados por espaço: ";
    for (int i = 0; i < tamanho; i++) {
        cin >> vidaInimigos[i];
    }

    cout << "Vida dos inimigos: ";
    for (int i = 0; i < tamanho; i++) {
        cout << vidaInimigos[i] << " ";
    }
    cout << endl;

    bool magiaLancada;
    do {
        magiaLancada = false;
        for (int i = 0; i < tamanho; i++) {
            if (vidaInimigos[i] > 0) {
                vidaInimigos[i]--; 
                if (vidaInimigos[i] == 0) {
                    inimigosDerrotados++;
                    cout << "Inimigo " << i << " derrotado!" << endl;
                    magiaLancada = true;
                } else if (vidaInimigos[i] < 0) {
                    vidaInimigos[i] = 0; 
                }
            }
        }
    } while (magiaLancada);

    cout << "Quantidade de inimigos derrotados: " << inimigosDerrotados << endl;

    return 0;
}
