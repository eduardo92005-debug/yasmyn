//Projeto prático IALG
//Aluna Yasmyn Cristiny
//Ciencia da Computacao - 2023/1 (UFLA)

#include <iostream>
#include <fstream>

using namespace std;

//registro filme
struct filme {
    string titulo;
    string elenco;
    string genero;

    int numeroSala;
    int capacidadeAssentos;
    bool excluido;

    double valorInteira;
    double valorMeia;
};

//procedimento da interface inicial
void start() {
    cout << "----------------- Bem-vindo ao Sistema de Gerenciamento CineY! -----------------" << endl;
    cout << "Digite o número de uma das opções abaixo:" << endl;
    cout << "1. Ver filmes e ingressos" << endl;
    cout << "2. Buscar filme disponível" << endl;
    cout << "3. Adicionar filme" << endl;
    cout << "4. Alterar dados do filme" << endl;
    cout << "5. Excluir filme" << endl;
    cout << "6. Sair" << endl;
}

//funcao que grava as alteracoes no arquivo (é chamada nas funçoes de excluiur, inserir e alterar)
void *gravaArq(filme *basesFilme, string nomeArq, int &tam){
    ofstream gravar (nomeArq);

    for (int i=0; i<tam; i++){
        gravar << basesFilme[i];
    }
}

//funcao que aumenta a capacidade do vetor (é chamada na funcao de inserir)
filme *aumentaVetor (filme *basesFilme, int &tam){
    filme *novoVetor = new filme [tam + tam*0.2];
    for (int i=0; i<tam; i++){
        novoVetor[i] = basesFilme[i]
    }
    delete [] basesFilme;
    basesFilme = novoVetor;
    tam*=0.2;
    return basesFilme;
}

// coringa
// batman
// mulher maravilha -> EXCLUIDADO
// flash
//funcao que preenche o vetor com os dados que estao no arquivo
filme *preencheVetor (string nomeArq, filme *basesFilme, int &tam){
    ifstream preenche (nomeArq);

    string titulo, elenco, genero;
    char = virgula;

    for (int i=0; i<tam; i++){
        getline (preenche, titulo, ',');
        basesFilme[i].titulo = titulo;
        getline (preenche, elenco, ',' );
        basesFilme[i].elenco = elenco;
        getline (preenche, genero, ',');
        basesFilme[i].genero = genero;
        preenche >> basesFilme[i].numeroSala;
        preenche >> virgula;
        preenche >> basesFilme[i].capacidadeAssentos;
        preenche >> virgula;
        preenche >> basesFilme[i].excluido;
        preenche >> virgula;
        preenche >> basesFilme[i].valorInteira;
        preenche >> virgula;
        preenche >> basesFilme[i].valorMeia;
    }

    return basesFilme;
}

//procedimento que mostra os dados presentes no sistema para o usuario
void visualizar (filme *basesFilme, int &tam){
    for (int i=0; i<tam; i++){
        cout << basesFilme[i].titulo << "  " << basesFilme[i].elenco << "  " << basesFilme[i].genero << "  "
        << basesFilme[i].numeroSala << "  " << basesFilme[i].capacidadeAssentos << "  " << basesFilme[i].excluido << "  "
        << basesFilme[i].valorInteira << "  " << basesFilme[i].valorMeia << endl;
    }
}

//procedimento que realiza busca pelos filmes
void realizaBusca (filme *basesFilme, int &tam){
    string procura;
    cout << "Insira a informacao que esta procurando (titulo, elenco ou genero): ";
    cin >> procura;

    for (int i=0; i<tam; i++){
        if (procura == basesFilme[i].titulo or procura == basesFilme[i].elenco or procura == basesFilme[i].genero){
            cout << basesFilme[i];
        }
    }
}

//funcao que adiciona (insere) um novo filme no vetor 
filme *adicionaFilme (string nomeArq, filme *basesFilme, int &tam){
    string titulo, elenco, genero;
    int numero_sala, capacidade;
    float inteira, meia;

    cout << "Digite os dados do novo filme a ser cadastrado: " << endl;
    cout << "- Título: ";
    getline(cin, titulo);
    cout << "- Elenco: ";
    getline (cin, elenco);
    cout << "- Genero: ";
    getline (cin, genero);
    cout << "- Numero da sala: ";
    cin >> numero_sala;
    cout << "- Capacidade de assentos: ";
    cin >> capacidade;
    cout << "- Valor da inteira: ";
    cin >> inteira;
    cout << "- Valor  da meia: ";
    cin >> meia;
    bool inserido = false;

    int cont = 0;
    for (int i=0; i<tam; i++){
        if (!basesFilme[i].excluido){
            while (cont<1){
                basesFilme[i].titulo = titulo;
                basesFilme[i].elenco = elenco;
                basesFilme[i].genero = elenco;
                basesFilme[i].numeroSala = numero_sala;
                basesFilme[i].capacidadeAssentos = capacidade;
                basesFilme[i].excluido = 0;
                basesFilme[i].valorInteira = inteira;
                basesFilme[i].valorMeia = meia;
                inserido=true;
                cont++;
            }
        }
    }

    if (inserido = false){
        //chama aumentaVetor para aumentar a capacidade do vetor e incluir um novo registro
        aumentaVetor(basesFilme, tam);
        basesFilme[tam+1].titulo = titulo;
        basesFilme[tam+1].elenco = elenco;
        basesFilme[tam+1].genero = genero;
        basesFilme[tam+1].numeroSala = numero_sala;
        basesFilme[tam+1].capacidadeAssentos = capacidade;
        basesFilme[tam+1].valorInteira = inteira;
        basesFilme[tam+1].valorMeia = meia;
        basesFilme[tam+1].excluido = 0;
    }

    //chama gravarArq para gravar o novo registro
    gravaArq(basesFilme, nomeArq, tam);

    return basesFilme;
}

//funcao que altera (edita) uma informacao em um registro
filme *alteraFilme (string nomeArq ,filme *basesFilme, int &tam){
    int indice;
    cout << "Qual o indice da informaçao que deseja editar?: ";
    cin >> indice;
    int campo;
    cout << "Qual campo deseja editar?: ";
    cout << "1. Título: " << endl;
    cout << "2. Elenco: " << endl;
    cout << "3. Genero: " << endl;
    cout << "4. Numero de salas: " << endl;
    cout << "5. Capacidade de assentos: " << endl;
    cout << "6. Valor inteira: " << endl;
    cout << "7. Valor Meia: " << endl;
    cin >> campo;

    string titulo, elenco, genero;
    int numSalas, capacidade;
    float vInteira, vMeia;

    switch (campo){
        case 1:
            cout << "Adicione o novo título: ";
            getline(cin, titulo);
            basesFilme[indice-1].titulo = titulo;
            break;
        case 2:
            cout << "Adicione o novo elenco: ";
            getline(cin, elenco);
            basesFilme[indice-1].elenco = elenco;
            break;
        case 3:
            cout << "Adicione o novo genero: ";
            getline(cin, genero);
            basesFilme[indice-1].genero = genero;
            break;
        case 4:
            cout << "Adicione o novo numero de salas: ";
            cin >> numSalas;
            basesFilme[indice-1].numeroSala = numSalas;
            break;
        case 5:
            cout << "Adicione a nova capacidade de assentos: ";
            cin >> capacidade;
            basesFilme[indice-1].capacidadeAssentos = capacidade;
            break;
        case 6:
            cout << "Adicione o novo valor da inteira: ";
            cin >> vInteira;
            basesFilme[indice-1].valorInteira = vInteira;
            break;
        case 7:
            cout << "Adicione o novo valor da meia: ";
            cin >> vMeia;
            basesFilme[indice-1].valorMeia = vMeia;
            break;
        default:
            cout << "Este campo não existe." << endl;
    }

    gravaArq(basesFilme, nomeArq, tam);

    return basesFilme;
}

//funcao que exclui (apaga) um filme no registro
filme *excluiFilme(string nomeArq, filme *basesFilme, int &tam){
    string tituloExcluir;
    cout << "Qual o título do filme que deseja excluir?: ";
    getline(cin, tituloExcluir);

    for (int i=0; i<tam; i++){
        if (tituloExcluir == basesFilme[i].titulo){
            basesFilme[i].excluido = 1;
        }
    }

    gravaArq(basesFilme, nomeArq, tam);

    return basesFilme;
}

//funcao principal
int main(){

    // int tam = 100;
    // filme *basesFilme = new filme [tam];

    // string nomeArq = "base_filmes.csv";

    // start();
    // preencheVetor(nomeArq, basesFilme, tam);

    // int opcao;
    // cin >> opcao;

    // if (opcao == 1){
    //     visualizar(basesFilme, tam);
    // } else if (opcao == 2){
    //     realizaBusca(basesFilme, tam);
    // } else if (opcao == 3){
    //     adicionaFilme(nomeArq, basesFilme, tam); //chama gravarArq
    // } else if (opcao == 4){
    //     alteraFilme(nomeArq, basesFilme, tam); //chama gravarArq
    // } else if (opcao == 5){
    //     excluiFilme(nomeArq, basesFilme, tam); //chama gravarArq
    // } else (opcao == 6){
    //     cout << "Até a próxima!" << endl;
    // }

    return 0;
}

