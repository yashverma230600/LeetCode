class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer,Integer> map = new HashMap<>();
        for(int num:nums){
            map.put(num,map.getOrDefault(num,0)+1);
        }

        List<Integer>[] buckets = new List[nums.length+1];
        for(int i=0;i<buckets.length;i++){
            buckets[i] = new ArrayList<>();
        }

        for(int n:map.keySet()){
            buckets[map.get(n)].add(n);
        }

        int[] res=new int[k];
        int idx=0;
        for(int i=buckets.length-1;i>=0;i--){
            for(int n:buckets[i]){
                res[idx++]=n;
                if(idx==k) return res;
            }

        }
        return res;
    }
}