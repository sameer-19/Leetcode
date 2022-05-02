class Solution {
public:
    int heightChecker(vector<int>& h) {
        vector<int> v;
        v=h;
        sort(v.begin(),v.end());
        
        int c=0,ans=0;
        
        for(auto x: v)
        {
            if(x!=h[c])
            {
                ans++;
            }
            c++;
        }
        return ans;
    }
};