class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n=rocks.size();
        int ans=0,d;
        
        vector<int> res;
        
        for(int i=0;i<n;i++)
        {
            d = capacity[i]-rocks[i];
            if(d==0) ans++;
            else res.push_back(d);
        }
        
        sort(res.begin(),res.end());
        
        for(int i=0;i<res.size();i++)
        {
            if(res[i]<=additionalRocks)
            {
                ans++;
                additionalRocks-=res[i];
            }
            else break;
        }
        
        return ans;
    }
};