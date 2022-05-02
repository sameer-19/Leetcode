class Solution {
public:
    static bool cmp(pair<int,int> a,pair<int,int> b)
    {
        if(a.first>b.first) return true;
        else if(a.first==b.first)
        {
            if(a.second>b.second) return true;
            return false;
        }
        return false;
    }
    
    vector<int> filterRestaurants(vector<vector<int>>& a, int vegan, int maxPrice, int maxDistance) {
        vector<int> result;
        vector<pair<int,int>> tmp;
        
        int n=a.size(),i;
        
        for(i=0;i<n;i++)
        {
            if(vegan==1)
            {
                if(a[i][2]==1) 
                {
                    if(a[i][3]<=maxPrice and a[i][4]<=maxDistance)
                    {
                        tmp.push_back({a[i][1],a[i][0]});
                    }    
                }
            }
            else{
                if(a[i][3]<=maxPrice and a[i][4]<=maxDistance)
                {
                    tmp.push_back({a[i][1],a[i][0]});   
                }
            }
        }
        
        sort(tmp.begin(),tmp.end(),cmp);
        
        for(auto x: tmp) result.push_back(x.second);
        
            
        return result;
    }
};