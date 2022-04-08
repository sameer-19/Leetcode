class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int z;
    KthLargest(int k, vector<int>& nums) {
        int i;
        for(i=0;i<k && i<nums.size();i++) pq.push(nums[i]);
        for(i=k;i<nums.size();i++) 
        {
            if(pq.top()<nums[i])
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        z=k;
    }
    
    int add(int val) {
        if(pq.empty() || pq.size()<z)
        {
            pq.push(val);
        }
        else
        {
            if(pq.top()<val)
            {
                pq.pop();
                pq.push(val);
            }    
        }
        
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */