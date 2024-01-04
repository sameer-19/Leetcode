import java.util.*;

class Solution {
    public int minOperations(int[] nums) {
        int ans = 0;
        
        HashMap<Integer,Integer> mp = new HashMap<>();
        
        for(int i=0;i<nums.length;i++)
        {
            int count = mp.containsKey(nums[i]) ? mp.get(nums[i]) : 0;
            mp.put(nums[i], count + 1);            
        }
        
        for (Map.Entry<Integer,Integer> mapElement : mp.entrySet()) {
            int key = mapElement.getKey();
            int value = (mapElement.getValue());
            if(value==1) return -1;
            
            ans += (value/3) + (value%3>0 ? 1 : 0);
        }
        
        return ans;
    }
}