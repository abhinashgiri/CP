
#include "bits/stdc++.h"
using namespace std;

//DSU with union by size / rank, but without path compression works in O(logn) time per query
class DSU
{
public:
    vector<int>p;
    vector<int>size;

    DSU(int n)
    {
       p.resize(n+2,0);
       iota(p.begin(),p.end(),0);
       size.resize(n+2,1);
    }
    int get(int x)
    {
        if(p[x]==x)return x;
        return p[x]=get(p[x]);
    }
    void join(int x,int y)
    {
        int px=get(x);
        int py=get(y);
        if(px==py)return;
        if(size[px]>size[py])swap(px,py);
        p[px]=p[py];
        size[py]+=size[px];
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    DSU d(10);





    return 0;
}