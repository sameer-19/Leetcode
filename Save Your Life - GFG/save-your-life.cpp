//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
      string maxSum(string w,char x[], int b[],int n){
          map<char,int> mp;
          
          int i,j;
          
          for(i=0;i<n;i++)
          {
              mp[x[i]]=b[i];
          }
          
          int left=0,right=-1,l=0,sum=0,mx=INT_MIN;
          string ans="";
          
          for(i=0;i<w.length();i++)
          {
              if(mp.find(w[i])==mp.end())
              {
                  sum+=(w[i]);
              }
              else
              {
                  sum+=mp[w[i]];
              }
              
              if(sum>mx)
              {
                  left=l;
                  right=i;
                  mx=sum;
              }
              
              if(sum<0)
              {
                  l=i+1;
                  sum=0;
              }
          }
          
        //   if(sum>mx)
        //   {
        //       left=l;
        //       right=i;
        //       mx=sum;
        //   }
          
        //   cout<<left<<" "<<right<<" ";
          
          for(i=left;i<=right;i++) ans+=w[i];
          
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
        string w;
        cin>>w;
        int n;
        cin>>n;
        char x[n];
        int b[n];
        for(int i = 0;i<n;i++)
            cin>>x[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        Solution ob;
        cout << ob.maxSum(w,x,b,n) << endl;
    }
    return 0; 
}
// } Driver Code Ends