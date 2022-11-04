class Solution {
public:
    bool check(char ch)
    {
        if(ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U') return true;
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') return true;
        
        return false;
    }
    
    string reverseVowels(string s) {
        
        int left=0,right=s.length()-1;
        
        while(left<right)
        {
            if(check(s[left]) and check(s[right]))
            {
                swap(s[left],s[right]);
                left++;
                right--;
            }
            else if(check(s[left]))
            {
                right--;
            }
            else if(check(s[right]))
            {
                left++;
            }
            else
            {
                left++;right--;
            }
        }
        
        return s;
    }
};