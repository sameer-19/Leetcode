class Solution {
    public int minSteps(String s, String t) {
        int ans = 0;
        
        int[] freqFirst = new int[26];
        int[] freqSecond = new int[26];
        
        for(int i=0;i<s.length();i++)
        {
            int idx = (int)s.charAt(i)-(int)'a';
            freqFirst[idx]++;
        }
        
        for(int i=0;i<t.length();i++)
        {
            int idx = t.charAt(i)-'a';
            freqSecond[idx]++;
        }
        
        for(int i=0;i<26;i++)
        {
            ans += Math.abs(freqFirst[i]-freqSecond[i]);
        }
        
        ans/=2;
        return ans;
    }
}