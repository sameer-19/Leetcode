class Solution {
public:
    bool bruteSolution(vector<int> &nums){
        unordered_map<int,int> mp;
        
        for(auto &x: nums){
            mp[x]++;
        }
        
        for(auto x: mp){
            if(x.second>1) return true;
        }
        
        return false;
    }
    
    bool containsDuplicate(vector<int>& nums) {
        return bruteSolution(nums);    
    }
};