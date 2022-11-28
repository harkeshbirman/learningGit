#include<bits/stdc++.h>
using namespace std;

int power(int n, int p) {
    int s = 1;

    while(p > 1) {
        if(p % 2) {
            s *= n;
            p--;
        }
        else {
            n *= n;
            p /= 2;
        }        
    }
    
    return  (n * s);
} 


int main(){
    cout << power(3,6);

    cout << endl;
    return 0;
}