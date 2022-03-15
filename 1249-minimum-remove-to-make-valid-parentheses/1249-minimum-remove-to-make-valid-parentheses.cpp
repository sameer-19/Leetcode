class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int i,j,n=s.length(),cnt=0;
        i=0;j=n-1;
        stack<int> st;
        vector<int> v;
        for(i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                st.push(i);
            }
            else if(s[i]==')')
            {
                if(st.empty()) continue;
                else{
                    v.push_back(st.top());
                    st.pop();
                    v.push_back(i);
                }
            }
        }
        sort(v.begin(),v.end());
        string res="";
        for(i=0;i<n;i++)
        {
            if(s[i]>='a' && s[i]<='z') res+=s[i];
            else if(binary_search(v.begin(),v.end(),i)){
                res+=s[i];
            }
        }
        return res;
    }
};