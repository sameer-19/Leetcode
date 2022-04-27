class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        map<int,int> mp;
        mp.clear();
        for(auto x: arr) mp[x]++;
        for(auto x: arr)
        {
            if(x!=0 and mp[2*x]>0) return true;
            else if(x==0)
            {
                if(mp[x]>1) return true;
            }
        }
        return false;
    }
};