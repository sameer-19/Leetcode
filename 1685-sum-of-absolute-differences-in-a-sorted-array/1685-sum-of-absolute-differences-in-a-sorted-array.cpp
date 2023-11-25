class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int> ans;
        vector<int> sumLeft,sumRight;
        
        int n=nums.size();
        int sum=0;
        
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            sumLeft.push_back(sum);
        }
        
        sum=0;
        for(int i=n-1;i>=0;i--)
        {
            sum+=nums[i];
            sumRight.push_back(sum);
        }
        reverse(sumRight.begin(),sumRight.end());
        
        for(int i=0;i<n;i++)
        {
            int left = i, right = n-i-1;
            int resLeft = 0, resRight = 0;
            
            if(left>0) resLeft = abs((nums[i]*left)-sumLeft[i-1]);
            
            if(i<n-1) resRight = abs((nums[i]*right)-sumRight[i+1]); 
            
            ans.push_back(resLeft+resRight);
        }
        
        return ans;
    }
};