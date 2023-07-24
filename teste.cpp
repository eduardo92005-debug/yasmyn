#include <iostream>
#include <string>

int main() {
    std::string linha = "Interstellar,Matthew McCnaoughey Anne Hathaway Jessica Chastain,Ficcao cientifica,15,200,0,30.00,15.00";

    size_t pos = 0;
    std::string palavra;

    while ((pos = linha.find(',')) != std::string::npos) {
        palavra = linha.substr(0, pos);
        std::cout << palavra << std::endl;
        linha.erase(0, pos + 1);
    }

    // Última palavra após a última vírgula
    std::cout << linha << std::endl;

    return 0;
}
