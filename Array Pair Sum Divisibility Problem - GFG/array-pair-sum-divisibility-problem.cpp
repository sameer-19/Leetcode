//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        map<int,int> mp;
        for(auto x: nums)
        {
            mp[x%k]++;
        }
        
        for(auto x: nums)
        {
            int first = abs(k-(x%k));
            int second = x%k;
            
            if(second==0)
            {
                if(mp[second]>0)
                {
                    if(mp[second]%2!=0) return false;
                    else
                    {
                        mp[second] = 0;
                        continue;
                    }
                }
            }
            
            if(mp[second]>0)
            {
                if(first!=second)
                {
                    if(mp[first]!=mp[second]) 
                    {
                        return false;
                    }
                    else
                    {
                        mp[first]=mp[second]=0;
                    }
                }
                else
                {
                    if(mp[first]%2==0) 
                    {
                        mp[first]=0;
                    }
                    else return false;
                }
            }
        }
        
        return true;   
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends