
#include "bits/stdc++.h"
using namespace std;
typedef long long int ll;
const int N = 10000000;
int lp[N+1];
vector<int> pr;


template <typename T>
T  gcd_extended(T  a, T  b, T&x , T&y) {
    if (b == 0){
        x = 1;
        y = 0;
        return a;
    }
    T x1, y1;
    T d = gcd_extended(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool find_solution(ll a, ll b, ll c, ll &x, ll &y){
    ll g = gcd_extended<ll>(a, b, x, y);
    if (c % g){
        return false;
    }
    x = x * (c / g);
    y = y * (c / g);
    if (a < 0)x *= (-1);
    if (b < 0)y *= (-1);
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for (int i=2; i<=N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back (i);
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
            lp[i * pr[j]] = pr[j];
    }

    return 0;
}
