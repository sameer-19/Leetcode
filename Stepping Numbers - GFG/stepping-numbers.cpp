//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
     int solve(int m)
    {
        if(m<0) return 0;
        if(m<10) return m+1;

        queue<int>q;

        for(int i=1;i<=9;i++) q.push(i);
        int ans=1;

        while(!q.empty())
        {
            int digit=q.front();
            q.pop();
            ans++;
            int rem=digit%10;
            int num1=digit * 10 + rem -1;
            int num2=digit * 10 + rem +1;
            //special case
            if(rem==0)
            {   
                if(num2<=m) q.push(num2);
            }
            else if(rem==9)
            {
                if(num1<=m) q.push(num1);
            }
            else
            {
                if(num1<=m)
                q.push(num1);
                if(num2<=m)
                q.push(num2);
            }
        }
        return ans;
    }
    
    int steppingNumbers(int n, int m)
    {
        return solve(m)-solve(n-1);
    }
};


//{ Driver Code Starts.

int main()
{
    Solution obj;
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        cout << obj.steppingNumbers(n,m) << endl;
    }
	return 0;
}


// } Driver Code Ends