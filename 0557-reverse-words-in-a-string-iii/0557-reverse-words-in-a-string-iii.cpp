class Solution {
public:
    void reverse(string &s,int i,int j)
    {
        while(i<j)
        {
            swap(s[i],s[j]);
            i++;
            j--;
        }
        return;
    }
    
    string reverseWords(string s) {
        int n = s.length();
        
        int left = 0, right = 0;
        
        while(right<n)
        {
            if(s[right]==' ')
            {
                int cur = right+1;
                reverse(s,left,right-1);
                left = cur;
                right = cur;
            }
            else right++;
        }
        
        reverse(s,left,right-1);
        
        return s;
    }
};