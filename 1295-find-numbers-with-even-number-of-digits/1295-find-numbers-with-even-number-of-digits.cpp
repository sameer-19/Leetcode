class Solution {
public:
    bool even(int n)
    {
        int cnt=0;
        while(n>0) { cnt++; n/=10;}
        return (cnt%2==0);
    }
    
    int findNumbers(vector<int>& nums) {
        int ans=0;
        
        for(auto x: nums)
        {
            if(even(x)) ans++;
        }
        return ans;
    }
};