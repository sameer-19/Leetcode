class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> a;
        int i;
        for(i=0;i<nums.size();i++) a[nums[i]]++; // Time Complexity - O(N)
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        for(auto x: a) // Time Complexity - O(N)
        {
            pq.push({x.second,x.first});
            if(pq.size()>k) pq.pop();
        }
        // Time complexity of above - O(N*log(K))
        vector<int> v;
        while(!pq.empty()) // Time complexity - O(K)
        {
            v.push_back(pq.top().second);
            pq.pop();
        }
        return v;
    }
};