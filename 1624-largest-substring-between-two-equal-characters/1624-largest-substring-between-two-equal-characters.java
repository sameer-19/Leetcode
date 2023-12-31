class Solution {
    public int maxLengthBetweenEqualCharacters(String s) {
        int ans = -1;
        
        int[] arr = new int[26];
        
        for(int i=0;i<26;i++) arr[i]=-1;
        
        for(int i=0;i<s.length();i++)
        {
            int index = s.charAt(i);
            index-='a';
            if(arr[index]==-1)
            {
                arr[index]=i;
            }
        }
        
        for(int i=s.length()-1;i>=0;i--)
        {
            int index = s.charAt(i);
            index-='a';
            int leftIndex = arr[index];
            if(leftIndex!=-1)
            {
                ans = Math.max(ans,i-leftIndex-1);
            }
        }
        
        return ans;
    }
}