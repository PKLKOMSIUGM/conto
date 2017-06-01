#include<iostream>
#include<math.h>
using namespace std;

double f(double x,double h0){
   return h0 - pow(x,2);
}
double error;
double getSec(double xa, double xb, double toleransi, int maxIterasi, double h){
    int iterasi=0;
    double xc=1;
    do{
       xc = xb - f(xb,h) * (xb-xa) / (f(xb,h)-f(xa,h));
       xa = xb;
       xb = xc;
       iterasi++;
    }while (fabs(f(xb,h))>toleransi && iterasi<maxIterasi);
    error = f(xb,h);
    return xb;
}

int main(){
	double h;
    double xa=0;
	double xb=0.5;
    double toleransi = 0.1;
    int maxIterasi = 10000;
    //cin >> a >> b >> toleransi >> maxToleransi;
    cin >> h;
    cout << getSec(xa, xb, toleransi, maxIterasi, h) << endl;
    cout << error << endl;
}
