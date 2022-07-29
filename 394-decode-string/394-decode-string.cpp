class Solution {
public:
    string decode(string &s,int &i)
    {
        string result;
        while(i<s.length() and s[i]!=']')
        {
            if(isdigit(s[i])) // digit
            {
                int k=0;
                while(i<s.length() and isdigit(s[i]))
                {
                    k=(k*10)+(s[i]-'0');
                    i++;
                }
                i++; // for '['
                string res = decode(s,i);
                
                while(k--)
                {
                    result+=res;
                }
                i++; // for ']'
            }
            else // alphabet
            {
                result+=s[i++];
            }
        }
        
        return result;
    }
    
    string decodeString(string s) {
        int i=0;
        return decode(s,i);
    }
};