#include "bits/stdc++.h"
using namespace std;
typedef long long int ll;

template<class T>
struct medianSet
{
public:
    multiset<T>mn_pq;
    multiset<T>mx_pq;

    void insert(T x)
    {

        if(mx_pq.empty() and mn_pq.empty())
        {
            mx_pq.insert(x);
            return;
        }

        if(!mx_pq.empty())
        {
            if(x<=*mx_pq.rbegin())mx_pq.insert(x);
            else mn_pq.insert(x);
        }
        else if(!mn_pq.empty() )
        {
            if(x>=*mn_pq.begin())mn_pq.insert(x);
            else mx_pq.insert(x);
        }

        while(!mx_pq.empty() and  (int)mx_pq.size() - (int)mn_pq.size()>1)
        {
            mn_pq.insert(*mx_pq.rbegin());
            mx_pq.erase(--mx_pq.end());
        }
        while(!mn_pq.empty() and (int)mn_pq.size() - (int)mx_pq.size()>=1)
        {
            mx_pq.insert(*mn_pq.begin());
            mn_pq.erase(mn_pq.begin());
        }
    }

    int getMedian()
    {
        // assumed median to be lower one if even size
        int size=mn_pq.size()+mx_pq.size();
        if(size==0)return -1;
        // odd size
        if(size%2)
        {
            return *mx_pq.rbegin();
        }
        else
        {
            T sum=0;
            if(!mx_pq.empty())sum+=*mx_pq.rbegin();
            if(!mn_pq.empty())sum+=*mn_pq.begin();
            return sum/2;
//            double x=sum*1.0;
//            x/=2.0;
//            return x;
        }

        return *mx_pq.rbegin();
    }

    void erase(T x)
    {
        if(mx_pq.empty() and mn_pq.empty())
        {
            return;
        }
        if(!mn_pq.empty() and x >= *mn_pq.begin())
        {
            auto it=mn_pq.find(x);
            if(it!=mn_pq.end())mn_pq.erase(it);
        }
        else if(!mx_pq.empty() and x<=*mx_pq.rbegin())
        {
            auto it=mx_pq.find(x);
            if(it!=mx_pq.end())mx_pq.erase(it);
        }

        while(!mx_pq.empty() and  (int)mx_pq.size() - (int)mn_pq.size()>1)
        {
            mn_pq.insert(*mx_pq.rbegin());
            mx_pq.erase(--mx_pq.end());
        }
        while(!mn_pq.empty() and (int)mn_pq.size() - (int)mx_pq.size()>=1)
        {
            mx_pq.insert(*mn_pq.begin());
            mn_pq.erase(mn_pq.begin());
        }
    }
    void print()
    {
        cerr<<"MedianSet is :\t";
        for(auto &i:mx_pq)
        {
            cerr<<i<<" ";
        }
        cerr<<"\nNxt\t";
        for(auto &i:mn_pq)
        {
            cerr<<i<<" ";
        }
        cerr<<"\n";
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);









    return 0;
}
