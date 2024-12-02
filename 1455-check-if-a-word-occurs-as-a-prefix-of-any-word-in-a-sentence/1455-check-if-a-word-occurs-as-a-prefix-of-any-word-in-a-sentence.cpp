class Solution {
public:
    bool check(string s, string word)
    {
        int i = 0, len1 = s.size(), len2 = word.size();
        
        while(i<len1 and i<len2)
        {
            if(s[i]==word[i]) i++;
            else return false;
        }
        
        return i==len2 ? true : false;
    }
    
    int isPrefixOfWord(string sentence, string searchWord) {
        int size = sentence.size(), len = searchWord.size();
        int i=0, cnt=0;
        string res = "";
        
        while(i<size)
        {
            if(sentence[i]!=' ') res+=sentence[i];
            else
            {
                cnt++;
                bool isPresent = check(res,searchWord);
                if(isPresent) return cnt;
                res = "";
            }
            
            i++;
        }
        
        return check(res, searchWord)==true ? cnt+1 : -1;
        
    }
};