class Solution {
public:
    int maxCoins(vector<int>& piles) {
//  logic- Sort the array, take max two elements and smallest element in single pass.
        sort(piles.begin(),piles.end());
        int n=piles.size();
        
        int ans=0;
        int left=0,right=n-2;
        
        while(left<right)
        {
            ans+=piles[right];
            left++;
            right-=2;
        }
        
        return ans;
    }
};