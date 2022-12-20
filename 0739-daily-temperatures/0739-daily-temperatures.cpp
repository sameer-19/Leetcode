class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n=temp.size();
        
        vector<int> ans(n,0);
        
        stack<int> s;
        s.push(0);
        
        for(int i=1;i<n;i++)
        {
            while(!s.empty() and temp[i]>temp[s.top()])
            {
                ans[s.top()]=i-s.top();
                s.pop();
            }
            s.push(i);
        }
        
        return ans;
    }
};