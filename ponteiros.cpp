#include <iostream>
using namespace std;
// Cada byte consiste em 8 bits, ou, um octeto
// 1 bit -> 0 ou 1
// 1 byte -> 8 bits -> OCTETO -> 0010101
// 1 byte -> char
int main(){
    // Numero inteiro -> int possui 4 bytes, ou seja 32 bits, que eh
    // 4 octetos.
    int x = 2049;
    // &x equivale ao endereco de memoria de x
    // arquitetura x86 CISC -> 32 bits -> organizacao dos enderecos de memoria
    // enderecos crescente
    // processadores RISC - endereco
    int* px = &x;
    cout << "O tamanho de x: " << sizeof(int) << endl; 
    cout << "O valor de x: " << x << endl;
    cout << "(hexa) O endereco de x: " << hex << px << endl;
    printf("(decimal) O endereco de x: %d\n", px);
    // // OBtendo o valor de x pelo ponteiro
    // de referencia -> desreferencia
    cout << "O ponteiro de x: " << dec <<  *px << endl;
    // Aritmetica de ponteiros
    // // Incrementando o ponteiro
    // // Quando incrementa o ponteiro, ele anda 4 bytes a frente
    // // Em outras palavras para o proximo inteiro na memoria.
    // // Ou vai para o proximo endereco de memoria.
    printf("(decimal) Soma de x + 1 (pelo ponteiro):  %d\n", px + 1);
    // // Mas e se o proximo nao tiver nada?
    // // Garbage
    printf("Soma de px + 1 (pelo ponteiro):  %d\n", *(px + 1));

    // // Ponteiros sao independentes do tipo
    // // Agora o ponteiro aponta para um bloco de memoria de 1
    // Casting (conversao de tipo)
    char d = '1';
    int k = (char) d;
    char *y = (char*) px;
    //  00001000 00000001 
    cout << "O tamanho de y: " << sizeof(char) << endl; 
    printf("O endereco de y: %p\n",y);
    printf("O valor de y: %d\n",*y);
    printf("Soma de y + 1 (pelo ponteiro):  %d\n", y + 1);

}