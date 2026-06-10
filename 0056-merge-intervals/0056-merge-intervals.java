class Solution {
    public int[][] merge(int[][] intervals) {
        List<List<Integer>> result = new ArrayList<>();
        Arrays.sort(intervals,(a,b)-> Integer.compare(a[0],b[0]));
                if(intervals.length<=1) return intervals;

        int Ps=intervals[0][0];
        int Pe=intervals[0][1];
        for(int i=0;i<intervals.length;i++){
            if(intervals[i][0]<=Pe){
                Pe=Math.max(Pe,intervals[i][1]);
            }
            else{
                result.add(Arrays.asList(Ps,Pe));
                Ps=intervals[i][0];
                Pe=intervals[i][1];
            }
        }
        result.add(Arrays.asList(Ps,Pe));
        int[][] ans = new int[result.size()][2];
        for(int i=0;i<result.size();i++){
            ans[i][0] = result.get(i).get(0);
            ans[i][1] = result.get(i).get(1);
        }

return ans;

    }
}