class Solution {
public:
    vector<vector<int>> mergeIntervals(vector<vector<int>> &a)
        {
            vector<vector<int>> ans;
            
            int n=a.size();
            
            int start=a[0][0],end=a[0][1];
            
            int i,j;
            
            for(i=1;i<n;i++)
            {
                if(a[i][0]<=end)
                {
                    end=max(end,a[i][1]);
                }
                else
                {
                    ans.push_back({start,end});
                    start=a[i][0];
                    end=a[i][1];
                }
            }
            ans.push_back({start,end});
            
            return ans;
        }
    
        vector<vector < int>> insert(vector<vector < int>> &a,
                                                        vector< int > &b) {
            vector<vector<int>> ans;
            int n=a.size(),i,j;
            
            if(n==0)
            {
                ans.push_back(b);
                return ans;
            }
            
            int idx=n;
            
            for(i=0;i<n;i++)
            {
                if(b[1]<=a[i][0])
                {
                    idx=i;
                    break;
                }
            }
            
            vector<vector<int>> res;
            
            for(i=0;i<n;i++)
            {
                if(i==idx) res.push_back(b);
                res.push_back(a[i]);
            }
            
            if(i==idx) res.push_back(b);
            
            sort(res.begin(),res.end());
            
            ans = mergeIntervals(res);
            
            return ans;
        }
};