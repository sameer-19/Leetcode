class Solution {
public:
    
    bool check(int mid,vector<int> &arr,int n,int m,int k)
    {
        int ans=0,cnt=0,mx=INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]<=mid) 
            {
                cnt++;
                mx=max(mx,arr[i]);
            }
            else
            {
                cnt=0;
                mx=INT_MIN;
            }
            
            if(cnt==k)
            {
                ans++;
                cnt=0;
                mx=INT_MIN;
            }
        }
        
        return ans>=m;
    }
    
    int minDays(vector<int>& arr, int m, int k) {
        int n=arr.size();
        int mn=INT_MAX,mx=INT_MIN;
        
        for(int i=0;i<n;i++) 
        {
            mx=max(mx,arr[i]);
            mn=min(mn,arr[i]);
        }
        
        int ans=-1;
        int left=mn,right=mx;
        
        while(left<=right)
        {
            int mid = left + (right-left)/2;
            
            if(check(mid,arr,n,m,k))
            {
                ans=mid;
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
        
        return ans;
    }
};