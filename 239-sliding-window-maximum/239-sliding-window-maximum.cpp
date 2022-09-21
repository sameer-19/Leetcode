class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        
        deque<int> dq;
        
        int i,n=nums.size();
        
        for(i=0;i<n;i++)
        {
            if(!dq.empty() and dq.front()==i-k) dq.pop_front();
            
            if(dq.empty()) dq.push_back(i);
            else
            {
                while(!dq.empty() and nums[dq.back()]<=nums[i]) dq.pop_back();
                
                dq.push_back(i);
            }
            
            if(i>=k-1) ans.push_back(nums[dq.front()]);
        }
        
        return ans;
    }
};