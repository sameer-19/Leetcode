class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1=0,cnt2=0;
        int first=INT_MAX,second=INT_MAX;
        int i,n=nums.size();
        for(i=0;i<n;i++)
        {
            if(first==nums[i]) cnt1++;
            else if(second==nums[i]) cnt2++;
            else if(cnt1==0)
            {
                cnt1++;
                first=nums[i];
            }
            else if(cnt2==0) 
            {
                cnt2++;
                second=nums[i];
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1=0;cnt2=0;
        for(i=0;i<n;i++)
        {
            if(nums[i]==first) cnt1++;
            else if(nums[i]==second) cnt2++;
        }
        vector<int> ans;
        if(cnt1>(n/3)) ans.push_back(first);
        if(cnt2>(n/3)) ans.push_back(second);
        return ans;
    }
};