//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int characterReplacement(string s, int k){
		    int n=s.length(),i,j;
		    
		    int ans=0;
		    int t=k;
		    
		    for(char ch='A';ch<='Z';ch++)
		    {
		        int left=0,right=0;
		        k=t;
		        
		        while(right<n)
		        {
		            if(s[right]!=ch)
		            {
		                if(k>0)
		                {
		                    k--;
		                }
		                else
		                {
		                  //  ans=max(ans,right-left+1);
		                    while(left<=right and k==0)
		                    {
		                        if(s[left]==ch) left++;
		                        else
		                        {
		                            left++;
		                            break;
		                        }
		                    }
		                    ans=max(ans,right-left+1);
		                }
		            }
		            ans=max(ans,right-left+1);
		            right++;
		        }
		        ans=max(ans,right-left);
		    }
		    
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		int k;
		cin >> k;
		Solution obj;
		int ans = obj.characterReplacement(s, k);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends