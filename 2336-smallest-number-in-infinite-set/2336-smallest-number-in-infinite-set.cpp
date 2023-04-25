class SmallestInfiniteSet {
public:
    bool visited[1002];
    priority_queue<int,vector<int>,greater<int>> pq;
    
    SmallestInfiniteSet() {
        for(int i=1;i<=1000;i++) pq.push(i);
        for(int i=0;i<=1000;i++) visited[i]=true;
        visited[0]=false;
    }
    
    int popSmallest() {
        while(!pq.empty() and visited[pq.top()]==false) pq.pop();
        
        visited[pq.top()]=false;
        int tp = pq.top();
        pq.pop();
        return tp;
    }
    
    void addBack(int num) {
        if(visited[num]==false)
        {
            visited[num]=true;
            pq.push(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */