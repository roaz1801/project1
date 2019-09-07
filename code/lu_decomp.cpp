#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <iomanip>
#include <time.h>
#include "armadillo"

using namespace arma;
using namespace std;

//Need armadillo to run this

inline double f(double x){return 100.0*exp(-10.0*x);}
inline double u_val(double x){return 1.0-(1-exp(-10))*x-exp(-10*x);}

ofstream ofile;

int main()
  {
    string filename;

    filename = "lu_decomp5.txt";

   //Create dynamical matrix and vector
   int n = 100000;
   double h = 1.0/(n);
   double *x = new double[n];

 string fileout = filename;
   mat A(n,n);
   vec b(n);

   //Fill in the diagonal with 2
   for(int i = 0; i<n;i++){
           A(i,i) = 2;
   };

   //Fill in above and below the diagonal with -1.
   for(int j = 1; j<n;j++){
           A(j-1,j) = -1;
           A(j,j-1) = -1;
   };

   for(int k = 1; k<n;k++){
       x[k] = k*h;
       b[k] = (h*h)*f(k*h);
   };

   clock_t start, finish;

   start = clock();
//Doing the LU decomposition
  mat L, U;
  lu(L,U,A);

//L*y = b, we find y
  vec y = solve(L,b);

//U*u = y, with this we find u
  vec u = solve(U,y);

  finish = clock();
  cout << ((((double)finish - (double)start)/CLOCKS_PER_SEC))<< endl;

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

  delete [] x;
    return 0;
  }
