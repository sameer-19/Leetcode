class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>> pq;
        
        int n=arr.size(),i,j;
        
        for(i=0;i<k;i++)
        {
            pq.push({abs(arr[i]-x),arr[i]});
        }
        
        for(i=k;i<n;i++)
        {
            int diff = abs(arr[i]-x);
            if(pq.top().first>diff)
            {
                pq.pop();
                pq.push({diff,arr[i]});
            }
        }
        
        vector<int> ans;
        
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};