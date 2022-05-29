class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num==1) return true;
        
        int i;
        for(i=2;(long)i*i<=num;i++)
        {
            if(num%i==0)
            {
                if(num/i==i) return true;
            }
        }
        return false;
    }
};