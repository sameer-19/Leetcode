class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s;
        for(auto x: nums) s.insert(x);
        
        if(s.size()>=3) 
        {
            int n=s.size(),c=0;
            for(auto x: s) 
            {
                c++;
                if(c==n-2) return x;
            }
        }
        int mx=-1;
        
        for(auto x: s) mx=x;
        
        return mx;
    }
};