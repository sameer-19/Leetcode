class Solution {
    public int minOperations(String s) {
        int oddOne =0, oddZero = 0, evenOne =0, evenZero = 0;
        
        int ans = 0;
        int n = s.length();
        
        for(int i=0;i<n;i++)
        {
            if(i%2==0) 
            { 
                if(s.charAt(i)=='1')
                {
                    oddOne+= 1; 
                }
                else
                {
                    oddZero+= 1;   
                }
            }
            else 
            {
                if(s.charAt(i)=='1')
                {
                    evenOne+= 1; 
                }
                else
                {
                    evenZero+= 1;   
                }
            }
        }
        
        ans = Math.min(oddOne+evenZero,oddZero+evenOne);
        return ans;
    }
}