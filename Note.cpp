#include <iostream>
#include <math.h>

using namespace std;

int isSNT(long long n) {
    if(n == 2) return 1;
    if(n%2 == 0) return 0;
    for(int i = 3; i <= sqrt(n); i+=2) {
        if(n%i==0) return 0;
    }
    return 1;
}

int isSoDep(long long n, long long k) {
    if(!isSNT(n)) return 0;
    long long sum = 0, scs = 0;
    while(n!=0) {
        if(!isSNT(n%10)) return 0;
        sum += n%10;
        scs++;
        n /= 10;
    }
    if(!isSNT(sum) || scs != k) return 0;
    return 1;
}

int main() {
    int n;
    long long k; cin >> k >> n;
    if(isSoDep(k, n)) cout << k << " la so thoa man" << endl;
    else cout << k << " ko thoa man" << endl;

    return 0;
}