import java.util.Stack;

class SmartStack{
    private Stack<Integer> mainStack;
    private Stack<Integer> minStack;

    public SmartStack(){
        mainStack = new Stack<>();
        minStack = new Stack<>();
    }

    public void push(int x){
        mainStack.push(x);
        if(minStack.isEmpty()) {
            minStack.push(x);
        }
        else{
            minStack.push(Math.min(x,minStack.peek()));
        }
    }
    public void pop(){
        if(!mainStack.isEmpty()){
            mainStack.pop();
            minStack.pop();
        }
        }
        public int top(){
            if(!mainStack.isEmpty()){
                return mainStack.peek();
            }
            return -1; // or throw an exception
        }
        public int getMin(){
            if(!minStack.isEmpty()){
                return minStack.peek();
    }
            return -1; // or throw an exception
}
public static void main(String[] args) {
    SmartStack stack = new SmartStack();
    stack.push(-2);
    stack.push(0);
    stack.push(-3);
    System.out.println("Minimum: " + stack.getMin()); // Output: -3
    stack.pop();
    System.out.println("Top: " + stack.top()); // Output: 0
    System.out.println("Minimum: " + stack.getMin()); // Output: -2
}


    
}


// “Design a special stack that supports push(), pop(), and getMin() in constant time.”

// This is not just a coding question. It’s testing whether you understand:

// How stacks work internally
// How to maintain extra state efficiently
// How to achieve O(1) time for all operations
