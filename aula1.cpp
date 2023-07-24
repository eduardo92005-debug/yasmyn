#include <iostream>
using namespace std;

// Crie um programa que utilize vetores para poder
// pegar 3 notas e fazer a media das notas

// 1 - #include iostream
// 2 - namespace std
// 3 - int main(blabla)
int main() {
    int arranjo[] = {1,2,4,5,6,8,9,10};

    for (int elemento: arranjo){
        cout << elemento << endl;
    }
    
}

// 1 - Puxar bibliotecas <iostream>
// 2 - Bota o std 
// 3 - Cria a constante TAMANHO NOTAS = 5
// 4 - Inicializa a funcao principal main
// 5 - Inicializa o VETOR com tamanho 5 com os seguintes valores: 5,10,8,9,7
// 6 - Entra dentro do for:
// 1 - Iteracao
// 6.1 - Cria a variavel i = 0
// 6.2 - Verifica se i = 0 eh menor que 5
// 6.3 - Printa na tela notas[0]
// 6.4 - Incrementar mais 1 no i
// 2 - Iteracao
// 6.2 - Verifica se i = 1 eh menor que 5 -> SIM
// 6.3 - Printa na tela notas[1]
// 6.4 - Incrementar mais 1 no i
// 3 - Iteracao
// 6.2 - Verifica se i = 2 eh menor que 5 -> SIM
// 6.3 - Printa na tela notas[2]
// 6.4 - Incrementar mais 1 no i
// 5 Iteracao
// 6.2 - Verifica se i = 4 eh menor que 5 -> SIM
// 6.3 - Printa na tela notas[4]
// 6.4 - Incrementar mais 1 no i
// 6 Iteracao
// 6.2 - Verifica se i = 5 eh menor que 5 -> NAO
// PARA O FOR
