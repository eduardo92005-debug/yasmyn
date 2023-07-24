#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

const int MAX_FILMES = 100;

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

struct Cinema {
    Filme filmes[MAX_FILMES];
    string nome;
    string local;
};

void processa_linha(const string& linha, Filme& filme ){
    istringstream iss(linha);
    getline(iss, filme.nome, ',');
    getline(iss, filme.elenco, ',');
    getline(iss, filme.genero, ',');
    string aux_numero_sala,aux_qntd_assentos, aux_disponibilidade, aux_preco_inteiro, aux_preco_meia;
    getline(iss, aux_numero_sala, ',');
    getline(iss, aux_qntd_assentos, ',');
    getline(iss, aux_disponibilidade, ',');
    getline(iss, aux_preco_inteiro, ',');
    getline(iss, aux_preco_meia, ',');
    filme.numero_sala = stoi(aux_numero_sala);
    filme.qntd_assentos = stoi(aux_qntd_assentos);
    filme.disponibilidade = stoi(aux_disponibilidade);
    filme.preco_inteira = stof(aux_preco_inteiro);
    filme.preco_meia = stof(aux_preco_meia);
}
int main(){
    Cinema cinema;
    cinema.nome = "Cinemark";
    cinema.local = "Setor B, Ala 3F";
    ifstream arquivo("filmes.csv");
    if(!arquivo.is_open()){
        cout << "Erro ao abrir o arquivo.";
    }

    string linha;
    getline(arquivo,linha);

    int indice_filmes = 0;
    while(getline(arquivo,linha)){
        Filme& filme = cinema.filmes[indice_filmes];
        processa_linha(linha, filme);
        cout << "Nome: " << filme.nome << endl;
        cout << "Elenco: " << filme.elenco << endl;
        cout << "Genero: " << filme.genero << endl;
        cout << "Num. da Sala: " << filme.numero_sala << endl;
        cout << "Assentos: " << filme.qntd_assentos << endl;
        cout << "Preco inteira: " << filme.preco_inteira << endl;
        cout << "Preco meia: " << filme.preco_meia << endl; 
        indice_filmes++;
    }
    arquivo.close();

    return 0;
}