class Solution {
public:
    string largestOddNumber(string num) {
        int idx = -1;
        string ans="";
        
        for(int i=num.length()-1;i>=0;i--)
        {
            int number = num[i]-'0';
            if(number%2!=0) 
            {
                idx=i;
                break;
            }
        }
        for(int i=0;i<=idx;i++) ans+=num[i];
        
        return ans;
    }
};