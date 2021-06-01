#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define ll unsigned long long int
using namespace std;


int main() {
    int t;
    cin>>t;
    while(t--){
        ll a, b, n, sum=0, y;
        cin>>n;
        a=1;
        b=2;
        do{
            sum+=b;
            y=2*a+3*b;
            if(y>n){
                break;
            }
            a=y-(a+b);
            b=y;
        }while(1);
        cout<<sum<<endl;
    }
    return 0;
}
