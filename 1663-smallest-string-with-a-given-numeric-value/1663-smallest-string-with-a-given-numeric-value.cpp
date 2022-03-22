class Solution {
public:
    string getSmallestString(int n, int k) {
        string s="";
        int i,j;
        for(i=0;i<n;i++) s+='a';
        k-=n;
        for(i=n-1;i>=0;i--)
        {
            if(k==0) break;
            if(k>25)
            {
                s[i]='z';
                k-=25;
            }
            else
            {
                char ch='a';
                ch+=k;
                s[i]=ch;
                k=0;
            }
        }
        return s;
    }
};