class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> ans;
        int i,j;
        priority_queue<pair<int,int>> pq;
        for(i=0;i<mat.size();i++)
        {
            int cnt=0;
            for(j=0;j<mat[i].size();j++)
            {
                if(mat[i][j]==1) cnt++;
                else break;
            }
            pq.push(make_pair(cnt,i));
        }
        while(!pq.empty() && pq.size()>k)
        {
            pq.pop();
        }
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};