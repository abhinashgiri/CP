template<class T>
T dijkstra(T src,  vector<vector<pair<T,T>>> &g,T &destination,int totalNodes){
    vector<T> dist(totalNodes+1,inf);
    set<pll>s;
    dist[src]=0;
    s.insert(pair<T,T>{0,src});
    while(!s.empty()){
        auto p =*s.begin();
        T node_dis = p.first;
        T node = p.second;
        s.erase(s.begin());
        for(auto &child:g[node]){
            if(node_dis+child.second<dist[child.first]){
                auto f = s.find(pair<T,T>{dist[child.first],child.first});
                if(f!=s.end()){
                    s.erase(f);
                }
                dist[child.first]=node_dis+child.second;
                s.insert(pll{dist[child.first],child.first});
            }
        }
    }
    return dist[destination];
}
