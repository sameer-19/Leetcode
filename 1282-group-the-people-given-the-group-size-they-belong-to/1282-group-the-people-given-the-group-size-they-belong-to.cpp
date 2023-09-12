class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& gs) {
        vector<pair<int,int>> v;
        int n= gs.size();
        
        for(int i=0;i<n;i++)
        {
            v.push_back({gs[i],i});
        }
        
        sort(v.begin(),v.end());
        
        int i=0,cnt=1;
        vector<vector<int>> ans;
        vector<int> res;
        // res.push_back(v[0].second);
        
        while(i<n)
        {
            if(v[i].first==1)
            {
                if(res.size()>0)
                {
                    ans.push_back(res);
                    vector<int> tmp;
                    res = tmp;
                    res.push_back(v[i].second);
                }
                else
                {
                    ans.push_back({v[i].second});
                }
            }
            else
            {
                if(res.size()<v[i].first)
                {
                    res.push_back(v[i].second);
                }
                else
                {
                    ans.push_back(res);
                    vector<int> tmp;
                    res = tmp;
                    res.push_back(v[i].second);
                }
                
                if(res.size()==v[i].first)
                {
                    ans.push_back(res);
                    vector<int> tmp;
                    res = tmp;   
                }
            }
            i++;
        }
        
        if(res.size()>0) ans.push_back(res);
        
        return ans;
    }
};