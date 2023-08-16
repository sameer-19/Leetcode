//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        int n = nums.size();
        int mx = 0;
        
        for(int i=0;i<n;i++) mx=max(mx,nums[i]);
        
        vector<int> count(mx+2,0);
        
        for(int i=0;i<n;i++)
        {
            count[nums[i]]++;
        }
        
        vector<int> ans;
        
        for(int i=0;i<n;i++)
        {
            if(count[nums[i]]==1) ans.push_back(nums[i]);
        }
        
        if(ans[0]>ans[1]) swap(ans[0],ans[1]);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends