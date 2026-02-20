import java.util.Stack;

class Solution {
    public String removeDuplicates(String s, int k) {
        Stack<int[]> st = new Stack<>();
        
        for(char ch : s.toCharArray()){
            if(!st.isEmpty() && st.peek()[0] == ch){
                st.peek()[1]++;
                
                if(st.peek()[1] == k){
                    st.pop();
                }
            } else {  // Fixed: paired with outer if
                st.push(new int[]{ch, 1});
            }
        } // Fixed: closing brace for for-loop
        
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < st.size(); i++){
            int[] pair = st.get(i);
            char c = (char)pair[0];
            int count = pair[1];
            for(int j = 0; j < count; j++){
                sb.append(c);
            }
        }
        
        return sb.toString();
    }
}