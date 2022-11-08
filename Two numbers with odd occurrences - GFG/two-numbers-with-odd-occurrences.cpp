//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    bool set(int n,int c){
        while(c>1)
        {
            n = n>>1;
            c--;
        }
        if(n&1) return 1;
        return 0;
    }
    
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        long long int xoR = 0;
        for(int i=0;i<N;i++)
        {
            xoR = xoR^Arr[i];
        }
        
        int c=1;
        long long tmp =xoR;
        
        while(tmp)
        {
            if((tmp&1)!=0) break;
            c++;
            tmp = tmp>>1;
        }
        
        long long int n = xoR;
        
        for(int i=0;i<N;i++)
        {
            if(set(Arr[i],c)){
                n = n^Arr[i];
            }
        }

        vector<long long int> ans;
        ans.push_back(n);
        ans.push_back(xoR^n);
        sort(ans.begin(),ans.end(),greater<>());
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends