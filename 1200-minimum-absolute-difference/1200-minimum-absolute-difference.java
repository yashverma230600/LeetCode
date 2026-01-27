class Solution {
    public List<List<Integer>> minimumAbsDifference(int[] arr) {
        Arrays.sort(arr);
        List<List<Integer>> result = new ArrayList<>();
        int minDiff=Integer.MAX_VALUE;

        for(int i=0;i<arr.length-1;i++){
            int currDiff=arr[i+1]-arr[i];
            if(currDiff<minDiff){
                minDiff=currDiff;
                result.clear();
                result.add(Arrays.asList(arr[i],arr[i+1]));
            }
            else if(currDiff==minDiff){
                result.add(Arrays.asList(arr[i],arr[i+1]));
            }
            
        }
        return result;

    }
}