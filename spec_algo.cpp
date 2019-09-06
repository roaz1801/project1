#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <iomanip>
#include <time.h>

using namespace std;

inline double f(double x){return 100.0*exp(-10.0*x);
}

inline double u_val(double x){return 1.0-(1-exp(-10))*x-exp(-10*x);}
ofstream ofile;

int main(int argc, char *argv[]){	
    string filename;

    if( argc <= 1 ){
     cout << "Bad Usage: " << argv[0] <<
        " read also file name on same line" << endl;
         exit(1);
    }
        else{
        filename = argv[1]; 
    }

	int n = 10000000;
    double h = 1.0/(n);

      string fileout = filename;


    double *x = new double[n+1]; double *g = new double[n+1];
    double *u = new double[n+1]; double *d = new double[n+1];
    clock_t start, finish;
    
    start = clock();

    for (int i = 1; i < n; i++){
       d[i] = (i+1.0)/( (double) i);
        } 
    for(int i = 1; i<=n; i++){
        x[i] = i*h;
        g[i] = (h*h)*f(i*h);
    }

    u[0]= u[n] = 0.0; d[1] = d[n] = 2;

    for (int i = 2; i < n; i++){
       g[i] = g[i] + g[i-1]/d[i-1];
       }

    u[n-1] = g[n-1]/d[n-1];
    for (int i = n-2; i > 0; i--){
       u[i] = (g[i]+u[i+1])/d[i];
       }

    finish = clock();
    cout << ((((double)finish - (double)start)/CLOCKS_PER_SEC));
    
    ofile.open(fileout);
    ofile << setiosflags(ios::showpoint | ios::uppercase);
      //      ofile << "       x:             approx:          exact:       relative error" << endl;
      for (int i = 1; i < n;i++) {
        double epsilon = log10(abs((u_val(x[i])-u[i])/u_val(x[i])));
         ofile << setw(15) << setprecision(8) << u_val(x[i]);
         ofile << setw(15) << setprecision(8) << u[i];
         ofile << setw(15) << setprecision(8) << x[i];
         ofile << setw(15) << setprecision(8) << epsilon <<endl;
      }
      ofile.close();

    delete[] x; delete[] g; delete[] u; delete[]  d; 
    return 0;
	}
