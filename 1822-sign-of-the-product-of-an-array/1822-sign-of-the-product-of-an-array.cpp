class Solution {
public:
    int arraySign(vector<int>& nums) {
        int pos=0,neg=0,zero=0;
        for(int &x: nums)
        {
            pos+=x>0;
            neg+=x<0;
            zero+=x==0;
        }
        
        if(zero>0) return 0;
        if(neg%2!=0) return -1;
        return 1;
    }
};