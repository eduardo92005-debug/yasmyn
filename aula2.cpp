#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct Filme {
    string titulo;
    string elenco;
    string genero;
};

int main() {
    ifstream arquivo("base_filmes.csv");
    string linha;

    while (getline(arquivo, linha)) {
        istringstream iss(linha);
        string titulo, elenco, genero;

        if (getline(iss, titulo, ',') &&
            getline(iss, elenco, ',') &&
            getline(iss, genero, ',')) {
            Filme filme;
            filme.titulo = titulo;
            filme.elenco = elenco;
            filme.genero = genero;

            // Utilize o objeto "filme" conforme necessário
            // Por exemplo, exibir as informações na tela
            cout << "Título: " << filme.titulo << endl;
            cout << "Elenco: " << filme.elenco << endl;
            cout << "Genero: " << filme.genero << endl;
        }
    }

    arquivo.close();

    return 0;
}
