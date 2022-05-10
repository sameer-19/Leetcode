// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

    void solve(vector<int>&nums,vector<int>& ans,int left,int right)
    {
        if(left>right) return;
        if(left==right) 
        {
            ans.push_back(nums[left]);
            return;
        }
        int mid=(left+right)/2;
        
        ans.push_back(nums[mid]);
        
        solve(nums,ans,left,mid-1);
        solve(nums,ans,mid+1,right);
        
        return;
    }

    vector<int> sortedArrayToBST(vector<int>& nums) {
        vector<int> v;
        int left=0,right=nums.size()-1;
        solve(nums,v,left,right);
        return v;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int>ans = obj.sortedArrayToBST(nums);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends