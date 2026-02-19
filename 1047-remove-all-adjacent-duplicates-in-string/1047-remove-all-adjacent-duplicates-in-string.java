class Solution {
    public String removeDuplicates(String st) {
        Stack<Character> s=new Stack<>();
        for(char ch:st.toCharArray()){
            if(!s.isEmpty() && ch==s.peek()){
                s.pop();
            }
            else{
                s.push(ch);
            }
        }
        StringBuilder sb=new StringBuilder();
        while(!s.isEmpty()){
            char ch=s.peek();
            sb=sb.append(ch);
            s.pop();
        }
        return sb.reverse().toString();
    }
}