class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int i,j,n=arr.size();
        
        vector<int> ans;
        
        priority_queue<pair<int,int>> pq;
        
        for(i=0;i<n;i++)
        {
            int distance = abs(arr[i]-x);
            if(pq.empty() || pq.size()<k)
            {
                pq.push({distance,arr[i]});
            }
            else if(pq.top().first>distance)
            {
                pq.pop();
                pq.push({distance,arr[i]});
            }
        }
        
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};