class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int m=arr1.size(),n=arr2.size();
        
        unordered_map<int,int> a1,a2;
        for(auto x: arr1) a1[x]++;
        for(auto x: arr2) a2[x]++;
        
        int i,j;
        
        vector<int> ans;
        vector<int> left;
        
        for(auto x: arr2)
        {
            if(a1[x]>0)
            {
                while(a1[x]>0)
                {
                    ans.push_back(x);
                    a1[x]--;
                }
            }
        }
        
        for(auto x: a1)
        {
            if(x.second>0) 
            {
                while(x.second>0)
                {
                    left.push_back(x.first);
                    x.second--;
                }
            }
        }
        sort(left.begin(),left.end());
        for(auto x: left) ans.push_back(x);
        
        
        return ans;
    }
};