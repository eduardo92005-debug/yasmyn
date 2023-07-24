#include <iostream>
#include <string>
#include <fstream>


using namespace std;

const int MAX_FILMES = 100;
const int MAX_COLUNAS = 8;
const int MAX_LINHAS = 100;

struct Filme {
    string nome;
    string elenco;
    string genero;
    int numero_sala;
    int qntd_assentos;
    bool disponibilidade;
    double preco_inteira;
    double preco_meia;
};

string celula[MAX_LINHAS][MAX_COLUNAS];

struct Cinema {
    Filme filmes[MAX_FILMES];
    string nome;
    string local;
};

enum Colunas {
    Nome = 0,
    Elenco = 1,
    Genero = 2,
    Numero_sala = 3,
    Assentos = 4,
    Excluidos = 5,
    Preco_inteira = 6,
    Preco_meia = 7
};

void processar_arquivo(const string& nomeArquivo) {
    ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo." << endl;
        return;
    }

    string linha;
    int conta_linha = 0;
    // Pula cabecalho
    getline(arquivo,linha);
    while (getline(arquivo, linha)) {
        int pos = 0;
        int i = 0;
        while ((pos = linha.find(',')) != string::npos) {
            celula[conta_linha][i] = linha.substr(0, pos);
            linha.erase(0, pos + 1);
            i++;
        }
        conta_linha++;
    }
    arquivo.close();
    
}
void imprimi_todos_nomes(){
     for (int linha = 0; linha < MAX_LINHAS; linha++) {
        cout << celula[linha][Colunas::Nome] << endl;
    }
}

int main(){
    Cinema cinema;
    cinema.nome = "Cinemark";
    cinema.local = "Setor B, Ala 3F";
    processar_arquivo("filmes.csv");
    cout << celula[8][Colunas::Nome] << endl;
    celula[8][Colunas::Nome] = "Blabla";
}
