#include <iostream>
#include <string>

using namespace std;

int main() {
    string nomeCompleto;
    cout << "Digite o nome completo: ";
    getline(cin, nomeCompleto);

    string nome, sobrenome;
    int pos = nomeCompleto.find(' ');
    if (pos != string::npos) {
        nome = nomeCompleto.substr(0, pos);
        sobrenome = nomeCompleto.substr(pos + 1);
    } else {
        nome = nomeCompleto;
    }

    cout << "Nome: " << nome << endl;
    cout << "Sobrenome: " << sobrenome << endl;

    return 0;
}
