#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}

void stat(const double arr[], int n, double ans[]){
    double mx = arr[0], mn = arr[0], sum = 0, geo_m = 1, fraction_sum = 0;
    for(int i = 0 ; i < n ; ++i){
        mx = max(mx,arr[i]);
        mn = min(mn,arr[i]);
        
        sum += arr[i];
        geo_m *= arr[i];
        fraction_sum += 1/arr[i];
    }

    double Mean = sum/n;

    double sumSD = 0;
    for(int i = 0 ; i < n ; ++i){
        sumSD += pow(arr[i] - Mean,2);
    }

    ans[0] = Mean; 
    ans[1] = sqrt(sumSD/n);
    ans[2] = pow(geo_m, 1/n);
    ans[3] = n/fraction_sum;
    ans[4] = mx;
    ans[5] = mn;
}