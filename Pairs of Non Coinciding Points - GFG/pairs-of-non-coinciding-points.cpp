// { Driver Code Starts

#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

 // } Driver Code Ends

class Solution {
  public:
    int numOfPairs(int x[], int y[], int n) {
        map<int,int> mp1,mp2;
        int i,j,cnt1=0,cnt2=0,cnt3=0;
        
        for(i=0;i<n;i++)
        {
            if(mp1.find(x[i])!=mp1.end()) cnt1+=mp1[x[i]];
            
            mp1[x[i]]++;
        }
        
        for(i=0;i<n;i++)
        {
            if(mp2.find(y[i])!=mp2.end()) cnt2+=mp2[y[i]];
            
            mp2[y[i]]++;
        }
        
        map<pair<int,int>,int> mp3;
        
        for(i=0;i<n;i++)
        {
            if(mp3.find({x[i],y[i]})!=mp3.end()) cnt3+=mp3[{x[i],y[i]}];
            
            mp3[{x[i],y[i]}]++;
        }
        
        return cnt1+cnt2-(2*cnt3);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        int X[N], Y[N];
        
        for(int i=0; i<N; i++)
            cin>>X[i];
        for(int i=0; i<N; i++)
            cin>>Y[i];

        Solution ob;
        cout << ob.numOfPairs(X,Y,N) << endl;
    }
    return 0;
}  // } Driver Code Ends