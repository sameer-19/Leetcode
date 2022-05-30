class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> m1,m2;
        
        int i,j;
        
        for(i=0;i<nums1.size();i++) m1[nums1[i]]++;
        for(i=0;i<nums2.size();i++) m2[nums2[i]]++;
        
        vector<int> v;
        
        for(auto x: m1)
        {
            if(x.second>0 and m2[x.first]>0)
            {
                int mn=min(x.second,m2[x.first]);
                for(int j=0;j<mn;j++) v.push_back(x.first);
            }
        }
        
        return v;
    }
};