#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

inline double f(double x){return 100.0*exp(-10.0*x);
}

inline double u_val(double x){return 1.0-(1-exp(-10))*x-exp(-10*x);}
ofstream ofile;

int main(int argc, char *argv[]){	
    string filename;

    if( argc <= 1 ){
     cout << "Bad Usage: " << argv[0] <<
        " read also file name on same line and max power 10^n" << endl;
         exit(1);
    }
        else{
        filename = argv[1]; // first command line argument after name of program
    }

	int n = 1000;
    double h = 1.0/(n+1);

      // Declare new file name
      string fileout = filename;
      // Convert the power 10^i to a string
      //string argument = to_string(i);
      // Final filename as filename-i-
      //fileout.append(argument);

    double *x = new double[n+1]; double *g = new double[n+1];
    double *u = new double[n+1]; double *d = new double[n+1];
    double *a = new double[n+1];  double *b = new double[n+1];  double *c = new double[n+1];

    for(int i = 0; i<=n; i++){
        x[i] = i*h;
        g[i] = (h*h)*f(i*h);
        
        a[i] = -1.0;
        b[i] = 2.0;
        c[i] = -1.0;
    }

    u[0]= u[n] = 0; d[1] = d[n] = b[1];
     for(int i = 0; i<=n; i++){
        //cout<<d[i]<<endl;
    }
    
    //Forward sub
    for(int i=2;i<=n-1;i++){
	    d[i] = b[i]-a[i]*c[i-1]/d[i-1];
        u[i] = g[i]-a[i]*g[i-1]/d[i-1];
    }

    //Backward sub
    for(int i=n-2; i>=0; i--){
		u[i] -= (c[i+1]/d[i+1])*u[i+1];
	}

   
    ofile.open(fileout);
    ofile << setiosflags(ios::showpoint | ios::uppercase);
      //      ofile << "       x:             approx:          exact:       relative error" << endl;
      for (int i = 1; i < n;i++) {
    
         ofile << setw(15) << setprecision(8) << u_val(x[i]);
         ofile << setw(15) << setprecision(8) << u[i]<<endl;;
      }
      ofile.close();

    delete[] x; delete[] g; delete[] u; delete[]  d; delete[] a; delete[] b; delete[] c; 
    return 0;
	}
