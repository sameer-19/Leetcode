class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return a[1]<b[1];
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        int ans = 0,count=1;
        sort(pairs.begin(),pairs.end(),cmp);
        
        // for(auto x: pairs) cout<<x[0]<<" "<<x[1]<<endl;
        // cout<<endl;
        
        int i=1,n=pairs.size(),curEnd = pairs[0][1];
        
        while(i<n)
        {
            if(pairs[i][0]<=curEnd) 
            {
                ans = max(ans,count);
            }
            else
            {
                count++;
                curEnd = pairs[i][1];
            }
            i++;
        }
        ans = max(ans,count);
        
        return ans;
    }
};