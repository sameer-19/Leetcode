class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size(),i;
        stack<int> s;
        
        vector<int> tp(m);
        vector<int> ans(n,-1);
        unordered_map<int,int> mp;
        for(i=0;i<n;i++) mp[nums2[i]]=i;
        
        for(i=n-1;i>=0;i--)
        {
            if(s.empty()) 
            {
                ans[i]=-1;
                s.push(nums2[i]);
            }
            else{
                while(!s.empty() && s.top()<=nums2[i]) s.pop();
                if(s.empty()) ans[i]=-1;
                else ans[i]=s.top();
                s.push(nums2[i]);
            }
        }
        for(i=0;i<m;i++)
        {
            tp[i]=ans[mp[nums1[i]]];
        }
        return tp;
    }
};