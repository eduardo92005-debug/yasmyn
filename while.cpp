#include <iostream>

using namespace std;

int main(){
 int vetor[] = {2,3,4,5};
 for(int i = 0; i < 4; i++){
    cout << vetor[i];
 };

 for (int i: vetor){
    cout << "FOR CADA: ";
    cout << i << endl;
 }

}