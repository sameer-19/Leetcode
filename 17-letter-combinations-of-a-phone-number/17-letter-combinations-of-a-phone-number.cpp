class Solution {
public:
    vector<string> v;
    void solve(string st,string s,int i)
    {
        if(st.length()==s.length())
        {
            v.push_back(st);
            return;
        }
        if(s[i]=='2')
        {
            solve(st+'a',s,i+1);
            solve(st+'b',s,i+1);
            solve(st+'c',s,i+1);
        }
        else if(s[i]=='3')
        {
            solve(st+'d',s,i+1);
            solve(st+'e',s,i+1);
            solve(st+'f',s,i+1);
        }
        else if(s[i]=='4')
        {
            solve(st+'g',s,i+1);
            solve(st+'h',s,i+1);
            solve(st+'i',s,i+1);
        }
        else if(s[i]=='5')
        {
            solve(st+'j',s,i+1);
            solve(st+'k',s,i+1);
            solve(st+'l',s,i+1);
        }
        else if(s[i]=='6')
        {
            solve(st+'m',s,i+1);
            solve(st+'n',s,i+1);
            solve(st+'o',s,i+1);
        }
        else if(s[i]=='7')
        {
            solve(st+'p',s,i+1);
            solve(st+'q',s,i+1);
            solve(st+'r',s,i+1);
            solve(st+'s',s,i+1);
        }
        else if(s[i]=='8')
        {
            solve(st+'t',s,i+1);
            solve(st+'u',s,i+1);
            solve(st+'v',s,i+1);
        }
        else if(s[i]=='9')
        {
            solve(st+'w',s,i+1);
            solve(st+'x',s,i+1);
            solve(st+'y',s,i+1);
            solve(st+'z',s,i+1);
        }
    }
    vector<string> letterCombinations(string s) {
        int n=s.length();
        if(n==0) return vector<string>();
        solve("",s,0);
        return v;
    }
};