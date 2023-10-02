class DSU{
public:
    vector<int>p;
    vector<int>size;
    DSU(int n){
        p.resize(n+2,0);
        iota(p.begin(),p.end(),0);
        size.resize(n+2,1);
    }
    int get(int x){
        if(p[x]==x)return x;
        return p[x]=get(p[x]);
    }
    void join(int x,int y){
        int px=get(x);
        int py=get(y);
        if(px==py)return;
        if(size[px]>size[py])swap(px,py);
        p[px]=p[py];
        size[py]+=size[px];
    }
};
struct edge{
    ll u,v,w;
    bool operator < (const edge& other )const{
        return w < other.w;
    }
};
struct KRUSKAL{
    int n;
    KRUSKAL(ll _n){ n = _n; }
    vector<edge>E;
    void addEdge(ll u,ll v,ll w){
        edge x = {u,v,w};
        E.emplace_back(x);
    }

    pair<ll,vector<edge>> getMST(){
        vector<edge>ans;
        sort(E.begin(),E.end());
        ll cost=0;
        DSU d(n+2);
        for (int i = 0; i <(int)E.size() ; ++i){
            ll x = E[i].u, y = E[i].v;
            if(d.get(x) == d.get(y))continue;
            ans.emplace_back(E[i]);
            cost+=E[i].w;
            d.join(x,y);
        }
        return make_pair(cost,ans);
    }
};
