class Solution {
public:
    bool solve(vector<int>& nums,int left,int right){
        vector<int> res;
        for(int i=left;i<=right;i++) res.push_back(nums[i]);
        
        sort(res.begin(),res.end());
        
        for(int i=2;i<res.size();i++)
        {
            if((res[i]-res[i-1])!=(res[1]-res[0])) return false;
        }
        
        return true;
    }
    
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        
        for(int i=0;i<l.size();i++)
        {
            bool res = solve(nums,l[i],r[i]);
            ans.push_back(res);
        }
        
        return ans;
    }
};