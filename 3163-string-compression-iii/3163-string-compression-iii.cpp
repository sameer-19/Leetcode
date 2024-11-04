class Solution
{
    public:
        void appendCharacter(string &ans, int count, char ch, map<int, char> mp) {
            ans+=mp[count];
            ans+=ch;
            return;
        }
    
        string compressedString(string word)
        {
            map<int, char> mp;
            mp[0] = '0';
            mp[1] = '1';
            mp[2] = '2';
            mp[3] = '3';
            mp[4] = '4';
            mp[5] = '5';
            mp[6] = '6';
            mp[7] = '7';
            mp[8] = '8';
            mp[9] = '9';
            
            int count = 1;
            string ans = "";
            
            int i = 1, length = word.length();
            
            while(i<length) {
                if(word[i]==word[i-1])
                {
                    if(count+1<=9) count++;
                    else{
                        appendCharacter(ans,count,word[i], mp);
                        count = 1;
                    }
                }
                else
                {
                    appendCharacter(ans, count, word[i-1], mp);
                    count = 1;
                }
                i++;
            }
            
            appendCharacter(ans, count, word[i-1], mp);
            
            return ans;
        }
};