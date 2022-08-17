class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n==1) return 0;
        
        int Parent = kthGrammar(n-1,k/2 + k%2);
        
        if(Parent==1)
        {
            if(k%2) return 1;
            return 0;
        }
        else
        {
            if(k%2) return 0;
            return 1;
        }
        
    }
};