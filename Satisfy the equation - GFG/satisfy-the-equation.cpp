//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> satisfyEqn(int a[], int N) {
         unordered_map<int,pair<int,int>> m;
        vector<int> ans = {100000,100000,100000,100000},temp;
        temp = ans;
        for(int i=0;i<N;i++)
            for(int j=i+1;j<N;j++)
            {
                int s = a[i]+a[j];
                if(m.find(s)!=m.end() ){
                    if(m[s].first!=i && m[s].second !=j && m[s].first!=j && m[s].second!=i)
                    ans = min(ans,{m[s].first,m[s].second,i,j});
                }
                else
                m[s] = {i,j};
            }
            
        if(temp==ans)
        return {-1,-1,-1,-1}; 
        else return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        vector<int> ptr = ob.satisfyEqn(A,N);
        
        cout<<ptr[0]<<" "<<ptr[1]<<" "<<ptr[2]<<" "<<ptr[3]<<endl;
    }
    return 0;
}
// } Driver Code Ends