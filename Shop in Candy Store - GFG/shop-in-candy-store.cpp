// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int a[], int n, int k)
    {
        vector<int> ans;
        
        int d = (n/(k+1)),s1=0,s2=0,i;
        
        if(n%(k+1)!=0) d++;
        
        sort(a,a+n);
        
        for(i=0;i<d;i++) s1+=a[i];
        for(i=n-1;i>=0 && d>0;i--) s2+=a[i],d--;
        
        ans.push_back(s1);
        ans.push_back(s2);
        
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}  // } Driver Code Ends