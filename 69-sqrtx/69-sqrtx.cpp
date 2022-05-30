class Solution {
public:
    int mySqrt(int x) {
        long i;
        for(i=1;(long)i*i<x;i++)
        {
            continue;
        }
        
        if(i*i<=x) return i;
        return i-1;
        
        // long long ans=0;
        // for(long long i=1;i<=x;i++)
        // {
        //     if(i*i>x) break;
        //     ans=max(ans,i);
        // }
        // return ans;
        // long long int a[100005];
        // a[0]=0;
        // for(long long i=1;i<100005;i++) a[i]=i*i;
        // long l=0,r=100004,ans=1;
        // while(l<r)
        // {
        //     int mid=l+(r-l)/2;
        //     if(a[mid]==x) return mid;
        //     else if(a[mid]<x)
        //     {
        //         ans=mid;l=mid+1;
        //     }
        //     else r=mid-1;
        // }
        // if((ans+1)*(ans+1)<=x) return ans+1;
        // return ans;
    }
};