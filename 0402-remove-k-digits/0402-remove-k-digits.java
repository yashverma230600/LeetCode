class Solution {
    public String removeKdigits(String num, int k) {
        Stack<Character> s = new Stack<>();
        for(char d:num.toCharArray()){
            while(!s.isEmpty() && k>0 && s.peek()>d){
                s.pop();
                k--;
            }
            s.push(d);
        }


        while(k>0 && !s.isEmpty()){
            s.pop();
            k--;
        }
        StringBuilder str=new StringBuilder();
        while(!s.isEmpty()){
            str.append(s.pop());
        }
        str.reverse();

        while(str.length()>0 && str.charAt(0)=='0'){
            str.deleteCharAt(0);
        }
        return str.length()>0?str.toString():"0";
    }
}