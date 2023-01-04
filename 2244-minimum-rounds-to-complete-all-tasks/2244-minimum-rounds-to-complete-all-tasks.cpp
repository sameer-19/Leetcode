class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> mp;
        
        int n=tasks.size();
        
        for(int i=0;i<n;i++)
        {
            mp[tasks[i]]++;
        }
        
        int ans=0;
        
        for(auto x: mp)
        {
            int cnt=x.second;
            if(cnt==1) return -1;
                
            if(cnt%3==0)
            {
                ans+=cnt/3;
            }
            else
            {
                ans+=(cnt/3)+1;
            }
        }
        
        return ans;
    }
};