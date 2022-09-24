class Solution {
public:
    
    vector<int> zFunction(string s)
    {
        int n=s.length(),i,j,left=0,right=0;
        vector<int> z(n,0);

        for(i=1;i<n;i++)
        {
            if(i>right)
            {
                left=right=i;
                while(right<n and s[right]==s[right-left])
                {
                    right++;
                }
                z[i]=right-left;
                right--;
            }
            else
            {
                j=i-left;

                if(z[j]<right-i+1)
                {
                    z[i] = z[j];
                }
                else{
                    left=i;
                    while(right<n and s[right]==s[right-left])
                    {
                        right++;
                    }
                    z[i]=right-left;
                    right--;
                }
            }
        }

        return z;
    }

    int patternMatch(string text,string pattern)
    {
        string newString = "";
        int i,j;

        for(auto x: pattern) newString+=x;
        newString+='$';

        for(auto x: text) newString+=x;

        vector<int> z = zFunction(newString);

        for(i=0;i<z.size();i++)
        {
            if(z[i]==pattern.size())
            {
                return i-pattern.size()-1;
            }
        }

        return -1;
    }
    
    int strStr(string haystack, string needle) {
        return patternMatch(haystack,needle);
    }
};