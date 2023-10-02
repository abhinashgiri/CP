struct Dinic{
    int n,s,t;
    int  inf_flow=1e17;
    struct edge{
        int x,y,flow,cap;
        edge(int x,int y,int flow,int cap): x(x),y(y),flow(flow),cap(cap){};
    };
    int lim,Flow;
    vector<bool> vis;
    vector<int> d,cur;
    vector<vector<int>> adj;
    vector<edge> edges;

    Dinic(int n,int l=1): n(n),lim(l){
        adj.resize(n);
        d.resize(n);
        cur.resize(n);
    }
    void addEdge(int from,int to,int cap,bool dir=true){
        adj[from].push_back(edges.size());
        edges.push_back(edge(from,to,0,cap));
        adj[to].push_back(edges.size());
        edges.push_back(edge(to,from,0,((dir) ? 0 : cap)));
    }
    bool bfs(){
        queue<int> q;
        q.push(s);
        for(int i=0;i<n;i++) d[i]=-1;
        d[s]=0;
        while(!q.empty() && d[t]==-1){
            int from=q.front();q.pop();
            for(auto &id:adj[from]){
                int to=edges[id].y;
                if (d[to]!=-1 || edges[id].cap-edges[id].flow<lim) continue;
                d[to]=d[from]+1;
                q.push(to);
            }
        }
        return d[t]!=-1;
    }

    int dfs(int from,int push){
        if (push==0 || from==t) return push;
        for(;cur[from]<adj[from].size();cur[from]++){
            int id=adj[from][cur[from]];
            int to=edges[id].y;
            if (d[to]!=d[from]+1 || edges[id].cap-edges[id].flow<lim) continue;
            if (int pushed=dfs(to,min(push,edges[id].cap-edges[id].flow))){
                edges[id].flow+=pushed;
                edges[id^1].flow-=pushed;
                return pushed;
            }
        }
        return 0;
    }
    int maxFlow(int src,int snk){
        s=src;
        t=snk;
        Flow=0;
        for(;lim>0;lim>>=1){
            while (bfs()){
                fill(cur.begin(),cur.end(),0);
                int pushed=0;
                while ((pushed=dfs(s,inf_flow))){
                    Flow+=pushed;
                }
            }
        }
        return Flow;
    }
};
