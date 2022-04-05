class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        
        sort(nums.begin(),nums.end());
        
        int n=nums.size(),i;
        
        for(i=0;i<n;i++)
        {
            int target=-nums[i];
            int front=i+1;
            int back=n-1;
            while(front<back)
            {
                int sum=nums[front]+nums[back];
                
                if(sum<target) front++;
                else if(sum>target) back--;
                else  // sum==target
                {
                    vector<int> triplet={ nums[i],nums[front],nums[back] };
                    ans.push_back(triplet);
                    
                    // removing duplicates
                    while(front<n && nums[front]==triplet[1]) front++;
                    
                    while(back>=0 && nums[back]==triplet[2]) back--;
                }
            }
            
            while(i+1<n && nums[i+1]==nums[i]) i++;
            
        }
        
        return ans;
    }
};