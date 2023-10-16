#include <iostream>
#include <cmath>
#include <fstream>

#define n 50

using namespace std;

float calc(float x) {
    return (pow(x, 3) - 10);
}

int main() {
    int k = 0;
    float finicio, meio, fmeio, a = 2, b = 3, prec = 0.1;

    ofstream outputFile("output.txt");

    if (outputFile.is_open()) {
        if (fabs(b - a) < prec) {
            cout << a << endl;
        } else {
            while (fabs(b - a) > prec && k < n) {
                k++;
                finicio = calc(a);
                meio = (a + b) / 2;
                fmeio = calc(meio);

                outputFile << "Iteração " << k << ": a = " << a << ", b = " << b << ", meio = " << meio << ", k = " << k << endl;

                if (finicio * fmeio < 0) {
                    b = meio;
                } else {
                    a = meio;
                }
            }
        }

        cout << meio << endl << k << endl;

        outputFile.close(); 
    } else {
        cerr << "Erro ao abrir o arquivo de saída." << endl;
    }

    return 0;
}
