class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> res;
        unordered_set<string> dict(words.begin(), words.end());
        for(string word : words){
            int n = word.length();
            vector<int> dp(n + 1, 0);
            dp[0] = 1;
            for(int i = 0; i < n; i++){
                if(dp[i] == 0) continue;
                for(int j = i + 1; j <= n; j++){
                    if(j - i < n && dict.count(word.substr(i, j - i))){
                        dp[j] = 1;
                    }
                }
                if(dp[n]){
                    res.push_back(word);
                    break;
                }
            }
        }
        return res;
    }
};