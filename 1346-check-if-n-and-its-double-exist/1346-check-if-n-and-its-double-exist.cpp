class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
     map<int, int> mp;
        
        for(auto x: arr) mp[x]++;
        
        for(auto x: mp)
        {
            int element = 2*(x.first);
            
            if(mp.find(element)!=mp.end())
            {
                if(element == x.first) 
                {
                    if(mp[element]>1) return true;
                }
                else
                return true;
            }
        }
        
        return false;   
    }
};