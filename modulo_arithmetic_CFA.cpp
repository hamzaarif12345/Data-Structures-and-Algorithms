/*
cs for all number theory
*/

#include<bits/stdc++.h>
using namespace std;

long long int p = 10e9 + 7;

long long int add(long long int a, long long int b) {
    long long int c = ((a % p) + (b % p)) % p;
    cout << "\nadding result is:" << c;
    return c;
}

long long int sub(long long int a, long long int b) {
    long long int c = (((a % p) - (b % p)) + p) % p;
    cout << "\nsub result is:" << c;
    return c;
}

long long int mul(long long int a, long long int b) {
    long long int c = ((a % p) * (b % p)) % p;
    // cout<<"\nmul result is:"<<c;
    return c;
}

long long int power(long long int a, long long int b) {
    long long int ans = 1;
    while (b) {
        if (b % 2 == 0) {
            a *= a;
            b = b / 2;
        } else {
            ans *= a;
            b--;
        }
    }
    return ans;
}

// for division see the video in sem 7 videos modulo arithmetic
long long int divide(long long int a, long long int b) {
    long long int c = mul(a, power(b, p - 2));
    cout << "\ndiv result is:" << c;
    return c;
}

int main() {
    // add(1000000000,99939993949);
    // sub(1000000000,99939993949);
    long long m = mul(10, 49);
    cout << "\n" << m;
    long long d = divide(100000004545, 20000000213);
    cout << "\n" << d;
    return 0;
}
