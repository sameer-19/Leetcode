//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> leafNodes(int a[],int n) {
        stack<int> s;
        vector<int> vec;
        s.push(a[0]);
        for(int i=1;i<n;i++){
            if(s.top()<a[i]){
                int pc = 0;
                int ln = s.top();
                while(!s.empty()&&s.top()<a[i]){
                    s.pop();
                    pc++;
                }
                if(pc>1){
                    vec.push_back(ln);
                }
            }
            s.push(a[i]);
        }
        if(!s.empty()){
            vec.push_back(s.top());
        }
        return vec;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for(int i=0;i<N;i++)cin>>arr[i];
        Solution ob;
        vector<int>ans=ob.leafNodes(arr,N);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends