class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans=0;
        int i;
        vector<int> res;
        while(n)
        {
            res.push_back(n%2);
            n/=2;
        }
        
        int sz=res.size();
        
        for(i=0;i<32-sz;i++) res.push_back(0);
        
        for(i=0;i<res.size();i++)
        {
            ans*=2;
            ans+=res[i];
        }
        cout<<endl;
        return ans;
    }
};