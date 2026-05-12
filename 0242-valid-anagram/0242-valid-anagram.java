class Solution {
    public boolean isAnagram(String s, String t) {
        if(s.length() != t.length())
            return false;

        int s1=s.length();
        int t1=t.length();
        int[] arr=new int[26];

        for(int i=0;i<s1;i++){
            arr[s.charAt(i)-'a']++;
        }
        for(int i=0;i<t1;i++){
            arr[t.charAt(i)-'a']--;
            if(arr[t.charAt(i)-'a']<0){
                return false;
            }
        }
        return true;
    }
}