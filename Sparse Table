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
    void build(vector<T> &a) {
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
        int ln = 31 - __builtin_clz(r - l + 1);
        return comb1(dp1[ln][l], dp1[ln][r - (1LL << ln) + 1]);
    }
    T query2(int l, int r) {
        int ln = 31 - __builtin_clz(r - l + 1);
        return comb2(dp2[ln][l], dp2[ln][r - (1LL << ln) + 1]);
    }
};          
