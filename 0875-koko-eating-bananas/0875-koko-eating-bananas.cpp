class Solution {
public:
    bool check(vector<int>& piles,long long mid,int &h)
    {
        int n=piles.size();
        long long count=0;
        
        for(int i=0;i<n;i++)
        {
            count+=ceil((double)piles[i]/mid);
        }
        
        return count<=h;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        long long n=piles.size(),sum=0;
        
        for(int i=0;i<n;i++) sum+=piles[i];
        
        long long low=1,high=sum,ans=INT_MAX;
        
        while(low<=high)
        {
            long long mid = low+ (high-low)/2;
            
            if(check(piles,mid,h))
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        
        return ans;
    }
};