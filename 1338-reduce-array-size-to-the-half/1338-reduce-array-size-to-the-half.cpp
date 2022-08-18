class Solution {
public:
    
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> mp;
        
        int ans=0,n=arr.size(),i;
        
        for(auto x: arr) mp[x]++;
        
        priority_queue<pair<int,int>> pq;
        
        for(auto x: mp)
        {
            pq.push({x.second,x.first});
        }
        
        int cnt=0;
        while(!pq.empty())
        {
            if(cnt>=n/2) break;
            ans++;
            cnt+=pq.top().first;
            pq.pop();
        }
        
        return ans;
    }
};