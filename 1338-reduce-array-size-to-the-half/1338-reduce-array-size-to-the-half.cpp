class Solution {
public:
    
    static bool cmp(pair<int,int> a,pair<int,int> b)
    {
        if(a.first>=b.first) return true;
        return false;
    }
    
    int minSetSize(vector<int>& arr) {
        map<int,int> mp;
        
        int ans=0,n=arr.size(),i;
        
        for(i=0;i<n;i++) mp[arr[i]]++;
        
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