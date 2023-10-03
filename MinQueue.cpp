struct MinQueue{
    deque<pair<int,int>>q;
    int cnt_added=0;
    int cnt_removed=0;
    int size(){
        return cnt_added-cnt_removed;
    }
    void push(int x){
        while(!q.empty() and q.back().first>x){
            q.pop_back();
        }
        q.push_back({x,cnt_added});
        cnt_added++;
    }
    void pop(){
        if(!q.empty() and q.front().second==cnt_removed)q.pop_front();
        cnt_removed++;
    }
    int min(){
        return q.front().first;
    }
};
