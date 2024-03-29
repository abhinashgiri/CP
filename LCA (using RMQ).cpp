#include "bits/stdc++.h"
using namespace std;

template <class T> struct RMQ {
    int n, logn;
    vector <vector <T>> dp1;
    RMQ(int _n) {
        n = _n;
        logn = ceil(log2(n)) + 1;
        dp1.assign(logn, vector <T> (n));
    }
    T comb1(T x, T y) { return min(x, y); }
    void build(vector<T> &a) {
        for(int i = 0; i < n; i ++) {
            dp1[0][i] = a[i];
        }
        for(int j = 1; j < logn; j ++) {
            for(int i = 0; i + (1LL << j) <= n; i ++) {
                dp1[j][i] = comb1(dp1[j - 1][i], dp1[j - 1][i + (1LL << (j - 1))]);
            }
        }
    }
    T query1(int l, int r) {
        int ln = 31 - __builtin_clz(r - l + 1);
        return comb1(dp1[ln][l], dp1[ln][r - (1LL << ln) + 1]);
    }

};

struct LCA{
    int n;
    vector<pair<int,int>> eulerTour;
    vector<int> height;
    vector<int> first;
    vector<int> parent;
    vector<vector<int>> g;
    RMQ<pair<int,int>> rmq;
    LCA(int _n):rmq(_n + _n-2){
        n = _n;
        g.resize(n+1);
        height.resize(n+1);
        parent.resize(n+1);
        first.resize(n+1);;
    }
    void addEdge(int u,int v,bool directional = false){
        g[u].push_back(v);
        if(!directional)g[v].push_back(u);
    }

    void dfs(int node,int par,int h=1){
        height[node] = h;
        parent[node] = par;
        first[node] = (int)eulerTour.size();
        eulerTour.emplace_back(height[node],node);
        for(auto &to:g[node]){
            if(to == par)continue;
            dfs(to,node,h+1);
            eulerTour.emplace_back(height[node],node);
        }
    }
    void build(){
        dfs(1,0,1);
        rmq.build(eulerTour);
    }
    int lca(int u,int v){
        if(u==v)return u;
        if(first[u] > first[v])swap(u,v);
        return rmq.query1(first[u],first[v]).second;
    }
    int distance(int u,int v){
        return height[u] + height[v] - 2*height[lca(u,v)];
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin>>n;
    LCA a(n);
    for (int i = 1; i <=n-1 ; ++i){
        int u,v;
        cin>>u>>v;
        a.addEdge(u,v);
    }
    a.build();
    cout<<a.lca(1,2)<<"\n";
}
