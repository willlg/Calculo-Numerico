#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

double f(double x){
        //return pow(x,3) - 9*x +3;
        return exp(-pow(x,2)) - cos(x);
    }
    
double dfx(double x){
    // return 3*pow(x,2) -9;
    return sin(x) - 2*x*exp(-pow(x,2));
}
    
    double newton (double x0, double prec, int max_iter){
        double x1 = x0 -f(x0) / dfx(x0);
    
    
    ofstream file;
    file.open("metodoNewton.txt");
    
    int i=1;
    
    file << "K " << "\t " << " X" << endl;
    
    while(i<max_iter){
        double fx1 = f(x1);
        double dfx1= dfx(x1);
        
        
        file << i << "\t" << x1 << endl;
        
        if (abs(fx1) < prec){
            file.close();
            return x1;
        }
        
        i++;
        
        x0=x1;
        x1=x0 - fx1 / dfx1;
    }
    file.close();
    
    return x1;
    }


int main()
{
    int max_iter;
    double x0,prec,raiz;
    
    cout << "informe o valor de x0" << endl;
    cin >> x0;
    
    cout << "informe o valor da precisão" << endl;
    cin >> prec;
    
    cout << "informe o valor maximo de itereações" << endl;
    cin >> max_iter;
    
    raiz = newton (x0,prec,max_iter);
    cout << "Raiz = " << raiz << endl;
}

