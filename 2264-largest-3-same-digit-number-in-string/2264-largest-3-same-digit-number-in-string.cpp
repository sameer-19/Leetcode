class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        char ch='\0';
        
        int n=num.length();
        
        for(int i=0;i<(n-2);i++)
        {
            if(num[i]==num[i+1] and num[i]==num[i+2])
            {
                ch = max(ch,num[i]);
            }
        }
        
        if(ch!='\0') {
            ans+=ch;
            ans+=ch;
            ans+=ch;
        }
        
        return ans;
    }
};