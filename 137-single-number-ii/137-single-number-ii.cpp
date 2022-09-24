
class Solution {
public:
    // #define int 
    int singleNumber(vector<int>& nums) {
        vector<long long> bit(32,0);
        
        long long ans=0,i,n=nums.size();
        long long cnt=0;
        
        for(i=0;i<n;i++)
        {
            int d = nums[i],c=0;
            if(d<0) cnt++;
            
            while(d)
            {
                bit[c]+=d%2;
                c++;
                d/=2;
            }
        }
        
        for(i=0;i<32;i++)
        {
            if(bit[i]%3!=0)
            {  
                ans+=(1<<i); 
            }
        }
        
        if(cnt%3==0) 
        return ans;
        
        return ans*-1;
    }
};