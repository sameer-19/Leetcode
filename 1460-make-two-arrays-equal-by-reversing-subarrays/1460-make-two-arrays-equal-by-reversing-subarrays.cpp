class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        map<int,int> mp;
        for(int i=0;i<arr.size();i++) {
            mp[arr[i]]++;
        }
        
        for(int i=0;i<arr.size();i++) {
            if(mp[target[i]]==0) return false;
            mp[target[i]]--;
        }
            
        for(auto x: mp) {
            if(x.second>1 || x.second<0) return false;
        }
        
        return true;
    }
};