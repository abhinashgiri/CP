#include "bits/stdc++.h"
using namespace std;
typedef long long int ll;
int mx_bit=30;
class Trie{
public:
    int cnt;
    Trie* child[2];
    Trie()
    {
        this->cnt=0;
        this->child[0] = nullptr;
        this->child[1] = nullptr;
    }

    void insert(ll x,Trie* &p)
    {
        Trie *root = p;
        for (int i = mx_bit; i >=0 ; --i)
        {
            int d = (x>>i)&1;
            if(root->child[d]== nullptr)root->child[d] = new Trie();
            root=root->child[d];
            root->cnt++;
        }
    }

    int remove(ll x,Trie* root,int i=mx_bit)
    {
        if(i<0)return 1;
        if(root== nullptr)return 0;
        int d=(x>>i)&1;
        if(root->child[d])
        {
            int g=remove(x,root->child[d],i-1);
            root->child[d]->cnt-=g;
            if(root->child[d]->cnt==0)
            {
                delete root->child[d];
                root->child[d] = nullptr;
                return 1;
            }
            return g;
        }
        return 0;
    }

    int maxXOR(int a,Trie* &p)
    {
        Trie*root =p;
        int ans=0;
        for (int i = mx_bit; i >=0 ; --i)
        {
            if((1<<i)&a)
            {
                if(root->child[0]!= nullptr)
                {
                    ans|=(1<<i);
                    root=root->child[0];
                }
                else root=root->child[1];
            }
            else
            {
                if(root->child[1]!= nullptr)
                {
                    ans|=(1<<i);
                    root=root->child[1];
                }
                else root=root->child[0];
            }
        }
        return ans;
    }

    int minXOR(int a,Trie* &p)
    {
        Trie*root =p;
        int ans=0;
        for (int i = mx_bit; i >=0 ; --i)
        {
            if((1<<i)&a)
            {
                if(root->child[1]!= nullptr)
                {

                    root=root->child[1];
                }
                else
                {
                    ans|=(1<<i);
                    root=root->child[0];
                }
            }
            else
            {
                if(root->child[0]!= nullptr)
                {
                    root=root->child[0];
                }
                else
                {
                    ans|=(1<<i);
                    root=root->child[1];
                }
            }
        }
        return ans;
    }

    // count of entries a s.t  ( a xor x ) >=k
    long long int greaterThan(Trie* root,int x,int k)
    {
        long long int ans=0;
        for (int i = mx_bit; i >=0 ; --i)
        {
            int bit = ((x&(1<<i))!=0);
            // ith bit is set on both x and k
            if((x&(1<<i)) and (k&(1<<i)))
            {
                if(root->child[0]== nullptr)return ans;
                root=root->child[0];
            }
            else if((x&(1<<i)) and !(k&(1<<i)))
            {
                if(root->child[0]!= nullptr) ans+=root->child[0]->cnt;
                if(root->child[1]== nullptr)return ans;
                root=root->child[1];
            }
            else if(!(x&(1<<i)) and (k&(1<<i)))
            {
                if(root->child[1]== nullptr)return ans;
                root=root->child[1];
            }
            else if(!(x&(1<<i)) and !(k&(1<<i)))
            {
                if(root->child[1]!= nullptr) ans+=root->child[1]->cnt;
                if(root->child[0]== nullptr)return ans;
                root=root->child[0];
            }
        }
        ans+=root->cnt;
        return ans;
    }

    void printAll(Trie*p,long long int ans=0,int i=mx_bit)
    {
        if(p == nullptr)
        {
            return;
        }
        if(i<0)
        {
            cerr<<ans<<" ";
            return;
        }
        if(p->child[0]!= nullptr)
        {
            printAll(p->child[0],ans,i-1);
        }
        if(p->child[1]!= nullptr)
        {
            printAll(p->child[1],ans|(1LL<<i),i-1);
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    
    
    
    
    
    
    
    
    return 0;
}
