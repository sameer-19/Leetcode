class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size()==0) return {};
        vector<string> ans;
        int i,prev=nums[0],c=1;
        string s=to_string(nums[0]);
        for(i=1;i<nums.size();i++)
        {
            if(nums[i]==prev+1) { prev=nums[i]; c++; }
            else 
            {
                if(c>1)
                {
                    s+="->"; 
                    s+=to_string(nums[i-1]);   
                }
                else
                {
                    // s+="->"; 
                    // s+=to_string(nums[i-1]);
                }
                c=1;
                ans.push_back(s);
                s=to_string(nums[i]);
                prev=nums[i];
            }
        }
        if(prev==nums[nums.size()-1]) 
        {
            if(c>1)
            {
                s+="->";
                s+=to_string(nums[nums.size()-1]);    
            }
        }
        if(s.size()>0) ans.push_back(s);
        return ans;
    }
};