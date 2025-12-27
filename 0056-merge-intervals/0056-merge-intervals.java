class Solution {
    public int[][] merge(int[][] intervals) {
       if(intervals.length<=1) return intervals;

       List<List<Integer>> result = new ArrayList<>();

       Arrays.sort(intervals,(a,b) -> Integer.compare(a[0],b[0]));

       int pStart = intervals[0][0];
       int pEnd = intervals[0][1];

       for(int i=1;i<intervals.length;i++){
            // If current interval overlaps with the previous one
            if(intervals[i][0]<=pEnd){
                pEnd=Math.max(intervals[i][1],pEnd);
            }
            else{
                result.add(Arrays.asList(pStart,pEnd));
                pStart=intervals[i][0];
                pEnd=intervals[i][1];
            }}
            result.add(Arrays.asList(pStart,pEnd));

            int[][] ans = new int[result.size()][2];
             for (int i = 0; i < result.size(); i++) {
            ans[i][0] = result.get(i).get(0);
            ans[i][1] = result.get(i).get(1);
        }
        return ans;

       
    }
}