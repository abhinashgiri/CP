#include "bits/stdc++.h"
using namespace std;
typedef long long int ll;

const long long mod=1e9+7;
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void factorial(vector<long long> &fact, long long n){
    fact.resize(n + 1, 1);
    fact[0] = 1;
    fact[1] = 1;
    for (int i = 2; i <= n ; ++i){
        fact[i] = ((fact[i - 1] % mod) *1LL* (i % mod)) % mod;
    }
}
long long mod_inv(long long a) {    return (binpow(a, mod - 2, mod)) % mod;    }

long long ncr(long long n, long long r, vector<long long> &fact){
    if (r > n or n < 0 or r < 0) return 0LL;
    return  (((fact[n] % mod) * (mod_inv(fact[n - r]) % mod)) % mod * (mod_inv(fact[r]) % mod)) % mod;
}


void modInv(vector<long long> &inv, long long n, vector<long long> &fact){
    inv.resize(n + 1, 1);
    inv[n] = mod_inv(fact[n]);
    for (int i = n - 1; i >= 0 ; --i){
        inv[i] = ((inv[i + 1]) % mod * ((i + 1)  % mod)) % mod;
    }
}
