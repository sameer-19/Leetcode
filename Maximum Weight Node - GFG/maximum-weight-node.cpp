//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  int maxWeightCell(int N, vector<int> edge)
  {
      vector<int> adj[N];
      
      for(int i=0;i<edge.size();i++)
      {
          if(edge[i]!=-1)
          adj[edge[i]].push_back(i);
      }
      
      int res=0,ans=0;
      
      for(int i=0;i<N;i++)
      {
          int sum=0;
          for(auto node: adj[i])
          {
              sum+=node;
          }
          if(ans<sum)
          {
              ans=sum;
              res=i;
          }
          else if(ans==sum) res=i;
      }
      
      return res;    
  }
};

//{ Driver Code Starts.
int main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      int ans=obj.maxWeightCell(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends