#include <iostream>
#include <cmath>
#include <string>



using namespace std;

#define food 5
#define age 3


int foo[food][age];
int n,m;

int main(){
    //for(int i=1;i<4;i++){
    int n = pow(10,1);
    //cout << n;
    //}

    //double u = 1-(1-exp(-10))*x-e**(-10*x)
    double h = 1/(n+1);
    for(int i=0;i>n;i++){
    double a[i] = -1/h**2;
     cout << a[i];
    }
   

/*
    //Forward substitution
    btemp = b[1]
    u[1] = f[1]/btemp;
    for(i=2; i<=n; i++){
        temp[i] = c[i-1]/btemp;
        btemp = b[i]-a[i]*temp[i];
        u[i] = (f[i]-a[i]*u[i-1])/btemp;
    }

    //Backward substitution
    for(i=n-1; i>=1; i--){
        u[i] -= temp[+1]*u[i+1]; 
    }
*/
    

    /*for(n=0;n<food;n++){
        for(m=0; m<age; m++){
            foo[n][m]=(n+1)*(m+1);
        }
    }
    cout << foo[2][1];*/
    return 0;
}