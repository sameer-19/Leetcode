class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ch='*';
        
        for(auto x: letters)
        {
            if(x>target)
            {
                ch=x;
                break;
            }
        }
        
        if(ch!='*') return ch;
        
        return letters[0];
        
    }
};