class Solution {
public:
    string frequencySort(string s) {
        map<char,int> mp;
        for(auto x: s) mp[x]++;
        
        string ans = "";
        
        priority_queue<pair<int,char>> pq;
        for(auto x: mp)
        {
            pq.push({x.second,x.first});
        }
        
        while(!pq.empty())
        {
            pair<int, char> p = pq.top();
            pq.pop();
            // cout<<p.first<<" "<<p.second<<" ";
            for(int i=0;i<p.first;i++) ans+=p.second;
        }
        
        return ans;
    }
};