#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main(){	
	double n = 1000;
	double h = 1/(n+1);
	double e = -1.0;

	int w = 1;
	double b[w];

/*
	//Making arrays	
	double b[n];
	double b_temp[n];
	double f[n];
	double f_temp[n];
	double u[n];
 
	//Forward sub
	b_temp = b[1];
	for(int i=2;i<=n-1;i++){
		b_temp[i] = (b[i]-e[i-1]**2)/b_temp[i-1];
		f[i] = (f[i]-f_temp[i-1]*e[i-1])/b_temp[i-1];
	}

	//Backward sub
	u[n-1] = f[n-1]/b_temp[n-1];
	for(int i=n-1; i>=1; i--){
		u[i] = (f[i]**2-e[i]*u[i+1])/b_temp[i];
	}


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
		u[i] = (f[i]**2+u[i+1])/b_temp[i];
	}

*/


    return 0;
}