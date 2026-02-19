package easy.FindRepeatingNumber1;

import java.util.ArrayList;
import java.util.List;

public class findNumber {

    public static List<Integer> findRepeatingSubArray(int[] arr) {
        List<Integer> list = new ArrayList<>();
        int idx = 0;
        for(int i=0;i<arr.length;i++){
            idx = Math.abs(arr[i])-1;
            if(arr[idx]<0){
                list.add(Math.abs(arr[i]));
            } else {
                arr[idx] = -arr[idx];
            }
        }
        return list;

    }


    public static void main(String[] args) {
        int[] arr = {1,3,2,3,1};
        List<Integer> result = findRepeatingSubArray(arr);
        System.out.println("Repeating numbers: " + result); // Output: [3, 1]

    }
    
}
