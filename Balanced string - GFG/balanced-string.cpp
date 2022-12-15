//{ Driver Code Starts
// Initial template for c++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for c++

class Solution {
  public:
    string BalancedString(int N) {
        int left=N%26;
        
        string ans="";
        string append = "";
        int cnt=0;
        string last="";
        
        if(left%2==0)
        {
            left/=2;
            char ch='a';
            while(cnt<left)
            {
                append+=ch;
                ch++;
                cnt++;
            }
            
            cnt=0;
            ch='z';
            while(cnt<left)
            {
                last+=ch;
                ch--;
                cnt++;
            }
            reverse(last.begin(),last.end());
            
            append+=last;
        }
        else
        {
            int sum=0,tmp=N;
            while(tmp>0) 
            {
                sum+=tmp%10;
                tmp/=10;
            }
            
            int first=0,second=0;
            
            if(sum%2==0)
            {
                first = (left+1)/2;
                second = (left-1)/2;
            }
            else
            {
                first = (left-1)/2;
                second = (left+1)/2;
            }
            
            char ch='a';
                
            while(cnt<first)
            {
                append+=ch; 
                ch++;
                cnt++;
            }
            
            cnt=0;ch='z';
            while(cnt<second)
            {
                last+=ch;
                ch--;
                cnt++;
            }
            reverse(last.begin(),last.end());
            
            append+=last;
        }
        
        string full="";
        for(char c='a';c<='z';c++) full+=c;
        
        cnt=0;
        while(cnt<(N/26))
        {
            ans+=full;
            cnt++;
        }
        
        ans+=append;
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.BalancedString(N) << endl;
    }
    return 0;
}

// } Driver Code Ends