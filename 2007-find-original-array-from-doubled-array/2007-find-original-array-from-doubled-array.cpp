class Solution {
public:
    vector<int> findOriginalArray(vector<int>& arr) {
        map<int,int> mp;
        
        vector<int> ans;
        sort(arr.begin(),arr.end());
        
        for(auto x: arr)
        {
            mp[x]++;
        }
        int flag=0;
        
        for(auto x: arr)
        {
            if(mp[x]>0 and mp[2*x]>0)
            {
                ans.push_back(x);
                mp[2*x]--;
                mp[x]--;
            }
            else if(mp[x]==0) continue;
            else
            {
                flag=1;
            }
        }
        
        int cnt=0;
        
        for(auto x: arr)
        {
            if(x==0) cnt++;
        }
        
        if(flag || cnt%2!=0) 
        {
            ans.clear();
            return ans;
        }
        
        return ans;
    }
};