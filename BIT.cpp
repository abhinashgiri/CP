#include "bits/stdc++.h"
using namespace std;

template <typename T>
class BIT{
    int n;
    vector<T> bit;
public :
    BIT(int tree_size){
        n = tree_size;
        bit.resize(n + 5) ;
    }

    bool update(int x, T val){
        if(x>n or x<1)return false;
        for (; x <= n; x += x & -x){
            bit[x] += val;
        }
        return true;
    }

    T query(int x){
        T sum = 0;
        for (; x > 0; x -= x & -x)
            sum += bit[x];
        return sum;
    }

    T query(int l, int r){
        return query(r) - query(l - 1) ;
    }
    T lower_bound(T sum){
        T curr=0,prev=0;
        for (int i = log2(n); i>=0 ; --i){
            if( ((curr+( 1LL<<i))<=n) && (bit[curr+(1LL<<i)]+prev)<sum){
                curr+=(1LL<<i);
                prev+=bit[curr];
            }
        }
        return curr+1;
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    BIT<int>bt(10);
    
    return 0;
}
