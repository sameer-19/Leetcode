class Solution {
    public String destCity(List<List<String>> paths) {
        Set<String> outgoingSet= new HashSet<>();
        for(List<String> path: paths)
        {
            System.out.println(path);
            outgoingSet.add(path.get(0));
        }
        
        for(int i=0;i<paths.size();i++)
        {
            String result = paths.get(i).get(1);
            if(!outgoingSet.contains(result))
            {
                return result;
            }
        }
        
        return "";
    }
}