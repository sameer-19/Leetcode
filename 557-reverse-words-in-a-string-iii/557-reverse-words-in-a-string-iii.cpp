class Solution {
public:
    string reverseWords(string s) {
        int left=0,right=0;
        int n=s.length();
        
        while(right<n)
        {
            if(s[right]==' ')
            {
                int end = right-1;
                while(left<=end)
                {
                    swap(s[left++],s[end--]);
                }
                
                left = right+1;
            }
            
            right++;
        }
        right--;
        while(left<=right)
        {
            swap(s[left++],s[right--]);
        }
            
        return s;
    }
};