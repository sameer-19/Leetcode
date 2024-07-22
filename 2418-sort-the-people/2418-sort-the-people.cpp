class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int,string>> temp;
        for(int i=0;i<names.size();i++)
        {
            temp.push_back({heights[i],names[i]});
        }
        
        sort(temp.begin(),temp.end());
        reverse(temp.begin(),temp.end());
        
        vector<string> ans;
        
        for(auto x: temp)
        {
            ans.push_back(x.second);
        }
        
        return ans;
    }
};