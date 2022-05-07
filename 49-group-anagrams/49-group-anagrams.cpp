class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& str) {
        vector<vector<string>> ans;
        
        vector<pair<string,int>> v;
        
        int i,j,n=str.size();
        
        for(i=0;i<n;i++) v.push_back({str[i],i});
        
        for(i=0;i<n;i++)
        {
            sort(v[i].first.begin(),v[i].first.end());
        }
        sort(v.begin(),v.end());
        
        string prev="";
        int c=0;
        vector<string> tmp;
        
        for(i=0;i<n;i++)
        {
            if(v[i].first==prev)
            {
                tmp.push_back(str[v[i].second]);
            }
            else
            {
                if(tmp.size()>0) 
                {
                    ans.push_back(tmp);
                    tmp.clear();
                }
                prev=v[i].first;
                tmp.push_back(str[v[i].second]);
            }
        }
        // if(tmp.size()>0)
        // {
            ans.push_back(tmp);
        // }
        
        return ans;
    }
};