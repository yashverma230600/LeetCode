class Solution {
    public int characterReplacement(String s, int k) {
        int l=0,maxF=0,maxL=0;
        HashMap<Character,Integer> map = new HashMap<>();
        for(int r=0;r<s.length();r++){
            char ch=s.charAt(r);
            map.put(ch,map.getOrDefault(ch,0)+1);
            maxF=Math.max(maxF,map.get(ch));
            while(r-l+1-maxF>k){
                map.put(s.charAt(l),map.get(s.charAt(l))-1);
                l++;
            }
            maxL=Math.max(maxL,r-l+1);
        }
        return maxL;
    }
}