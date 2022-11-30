class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> cnt;
        
        int n=arr.size();
        
        for(int i=0;i<n;i++)
        {
            cnt[arr[i]+1000]++;
        }
        
        set<int> s;
        
        for(auto x: cnt)
        {
            if(s.count(x.second)!=0) return false;
            s.insert(x.second);
        }
        
        return true;
    }
};