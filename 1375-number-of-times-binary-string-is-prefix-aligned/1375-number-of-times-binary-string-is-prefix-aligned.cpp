class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int ans=0,n=flips.size(),mx=-1,cnt=0;
        
        for(auto x: flips)
        {
            if(mx==-1)
            {
                mx=x;
                cnt=1;
            }
            else if(mx>x)
            {
                cnt++;
            }
            else 
            {
                mx=x;
                cnt++;
            }
            
            if(cnt==mx) ans++;
        }
        
        
        return ans;
    }
};