class Solution {
public:
    int getSum(int a, int b) {
        while(b)
        {
            int d=a^b;
            unsigned int e=a&b;
            
            a=d;
            b=e<<1;
        }
        
        return a;
    }
};