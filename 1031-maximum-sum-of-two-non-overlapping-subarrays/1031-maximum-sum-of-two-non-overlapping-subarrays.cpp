class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n=nums.size();
        
        vector<int> prefix(n,0),suffix(n,0);
        
        int sum=0,ans=0;
        
        for(int i=0;i<firstLen;i++) sum+=nums[i];
        prefix[firstLen-1]=sum;
        for(int i=firstLen;i<n;i++)
        {
            sum+=nums[i];
            sum-=nums[i-firstLen];
            prefix[i]=max(sum,prefix[i-1]);
        }
        
        // for(int i=0;i<n;i++) cout<<prefix[i]<<" ";
        
        sum=0;
        for(int i=n-1;i>=n-secondLen;i--) sum+=nums[i];
        
        suffix[secondLen-1]=sum;
        reverse(nums.begin(),nums.end());
        
        for(int i=secondLen;i<n;i++)
        {
            sum+=nums[i];
            sum-=nums[i-secondLen];
            suffix[i] = max(suffix[i-1],sum);
        }
        
        reverse(suffix.begin(),suffix.end());
        reverse(nums.begin(),nums.end());
        // for(int i=0;i<n;i++) cout<<suffix[i]<<" ";
        
        for(int i=firstLen-1;i<n-secondLen;i++)
        {
            ans=max(ans,prefix[i]+suffix[i+1]);
        }
        
        for(int i=0;i<n;i++) 
        {
            prefix[i]=0;
            suffix[i]=0;
        }
        
        sum=0;
        swap(firstLen,secondLen);
        
        for(int i=0;i<firstLen;i++) sum+=nums[i];
        prefix[firstLen-1]=sum;
        for(int i=firstLen;i<n;i++)
        {
            sum+=nums[i];
            sum-=nums[i-firstLen];
            prefix[i]=max(sum,prefix[i-1]);
        }
        
        // for(int i=0;i<n;i++) cout<<prefix[i]<<" ";
        
        sum=0;
        for(int i=n-1;i>=n-secondLen;i--) sum+=nums[i];
        
        suffix[secondLen-1]=sum;
        reverse(nums.begin(),nums.end());
        
        for(int i=secondLen;i<n;i++)
        {
            sum+=nums[i];
            sum-=nums[i-secondLen];
            suffix[i] = max(suffix[i-1],sum);
        }
        
        reverse(suffix.begin(),suffix.end());
        reverse(nums.begin(),nums.end());
        // for(int i=0;i<n;i++) cout<<suffix[i]<<" ";
        
        for(int i=firstLen-1;i<n-secondLen;i++)
        {
            ans=max(ans,prefix[i]+suffix[i+1]);
        }
        
        return ans;
    }
};