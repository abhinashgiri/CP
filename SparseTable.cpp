#include "bits/stdc++.h"
using namespace std;
typedef long long int ll;
typedef vector<ll> vll;
vector<int>LOG;
void build_LOG(int MAX_N)
{
    LOG.resize(MAX_N+3);
    LOG[1]=0;
    for (int i = 2; i <=MAX_N+2 ; ++i)
    {
        LOG[i]=LOG[i/2]+1;
    }
}
template <class T> struct SparseTable {
    int n, logn;
    vector <vector <T>> dp1,dp2;
    SparseTable(int _n) {
        n = _n; 
        logn = ceil(log2(n)) + 1;
        dp1.assign(logn, vector <T> (n, 0));
        dp2.assign(logn, vector <T> (n, 0));
    }
    T comb1(T x, T y) { return min(x, y); }
    T comb2(T x, T y) { return max(x, y); }
    void build(vll &a) {
        for(int i = 0; i < n; i ++) {
            dp1[0][i] = a[i];
            dp2[0][i] = a[i];
        }
        for(int j = 1; j < logn; j ++) {
            for(int i = 0; i + (1LL << j) <= n; i ++) {
                dp1[j][i] = comb1(dp1[j - 1][i], dp1[j - 1][i + (1LL << (j - 1))]);
                dp2[j][i] = comb2(dp2[j - 1][i], dp2[j - 1][i + (1LL << (j - 1))]);
            }
        }
    }
    T query1(int l, int r) {
        int ln = LOG[r - l + 1];
        return comb1(dp1[ln][l], dp1[ln][r - (1LL << ln) + 1]);
    }
    T query2(int l, int r) {
        int ln = LOG[r - l + 1];
        return comb2(dp2[ln][l], dp2[ln][r - (1LL << ln) + 1]);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int MAX_N=1e6;
    // build Log table first
    build_LOG(MAX_N);
    int n;
    cin>>n;
    SparseTable<ll>s(n);
    vector<ll>a(n);
    // take a as input
    s.build(a);
    
    
    return 0;
}