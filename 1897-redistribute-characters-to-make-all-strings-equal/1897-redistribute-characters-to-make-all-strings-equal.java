class Solution {
    public boolean makeEqual(String[] words) {
        char[] arr = new char[26];
        int n = words.length;
        
        for(String word: words)
        {
            for(int i=0;i<word.length();i++)
            {
                int idx = word.charAt(i) - 97;
                arr[idx]+=1;
            }
        }
        
        for(int i=0;i<26;i++)
        {
            if(arr[i]%n!=0) return false; 
        }
        
        return true;
    }
}