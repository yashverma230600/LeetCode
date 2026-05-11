class Solution {
    public int lengthOfLongestSubstring(String s) {
        Set<Character> set = new HashSet<>();
        int l=0,max=0;
        for(int r=0;r<s.length();r++){
            if(!set.contains(s.charAt(r))){
                set.add(s.charAt(r));
                max=Math.max(r-l+1,max);
            }
            else{
                while(s.charAt(r)!=s.charAt(l)){
                    set.remove(s.charAt(l));
                    l++;
                }
                set.remove(s.charAt(l));
                l++;
                set.add(s.charAt(r));
            }
        }
        return max;
    }
}