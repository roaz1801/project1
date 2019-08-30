#include <iostream>
#include <cmath>
#include <string>

using namespace std;

inline double f(double x){return 100.0*exp(-10.0*x);
}

int main(){	 //int argc, char *argv[]
	/*int exponent;
		string filename;
		if(argc <= 1){
			cout << "Bad usage of " << argv[0] <<
				" read also file name on same line and max power 10^n" << endl;
				exit(1);
		}else{
			filename = argv[1];
			exponent = atoi(argv[2]);
		}
*/

	int n = 1000;
	double h = 1/(n+1);
	//double e = -1.0;

	//Making dynamic arrays
	double *d = new double[n+1];	double *b = new double[n+1];
	double *f = new double[n+1];	double *f_temp = new double[n+1];
	double *u = new double[n+1];	double *e = new double[n+1];

	u[0] = u[1] = 0;
	for(int i =0;i<=n;i++){
		x[i]=i*h;
		b[i] = h*h*f(i*h);
	}

	//Forward sub
	*b_temp = b[1]; 	u[1] = f[1]/(*b_temp);

	for(int i=2;i<=n;i++){
		b_temp[i] = (b[i]-(e[i-1]*e[i-1]))/b_temp[i-1];
		u[i] = (f[i]-f_temp[i-1]*e[i-1])/b_temp[i-1];
	}

	//Backward sub	
	for(int i=n-1; i>=1; i--){
		u[i] -= ((f[i]*f[i])-e[i]*u[i+1])/b_temp[i];
	}

	cout << u[100] << endl;

/*
	//Forward and backward sub with e=1

	//Forward sub
	b_temp = b[1];
	for(int i=2;i<=n-1;i++){
		b_temp[i] = b[i]/b_temp[i-1];
		f[i] = (f[i]+f_temp[i-1])/b_temp[i-1];
	}

	//Backward sub
	u[n-1] = f[n-1]/b_temp[n-1];
	for(int i=n-1; i >= 1; i--){
		u[i] = ((f[i]*f[i])+u[i+1])/b_temp[i];
	}

*/
    return 0;
}