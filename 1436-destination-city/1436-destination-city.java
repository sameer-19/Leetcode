class Solution {
    public String destCity(List<List<String>> paths) {
        Map<String,String> mp= new HashMap<>();
        for(List<String> path: paths)
        {
            System.out.println(path);
            mp.put(path.get(0),path.get(1));
        }
        
        for(Map.Entry<String,String> entry : mp.entrySet())
        {
            if(!mp.containsKey(entry.getValue()))
            {
                return entry.getValue();
            }
        }
        
        return "";
    }
}