class Solution {
    int mod = 1000000007;
public:    
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto x: nums) pq.push(x);
        
        for(int i=0;i<k;i++)
        {
            int top = pq.top();
            pq.pop();
            top++;
            pq.push(top);
        }
        int ans=1;
        while(!pq.empty())
        {
            ans%=mod;
            long long tmp = ((long long)ans*pq.top())%mod;
            pq.pop();
            ans=tmp;
            ans%=mod;
        }
        
        return ans%mod;
    }
};