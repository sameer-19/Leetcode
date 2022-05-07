class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int i,n=nums.size();
        
        if(n<3) return false;
        
        stack<int> st;
        
        int s3=INT_MIN;
        for(i=n-1;i>=0;i--)
        {
            if(nums[i]<s3) return true;
            else
            {
                while(!st.empty() and st.top()<nums[i])
                {
                    s3=st.top();
                    st.pop();
                }
            }
            st.push(nums[i]);
        }
        
        return false;
    }
};