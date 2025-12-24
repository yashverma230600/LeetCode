
public class array {
    public static void arr(int[] a){
        for(int i=0;i<a.length;i+=2){
            if(  i>=1&&a[i] < a[i-1]){
                swap(a, i, i-1);
            }
            if(a[i]< a[i+1] && i+1 < a.length){
                swap(a, i, i+1);
            }
        }
    }

    private static void swap(int[] a, int i, int j) {
    
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;}
        public static void main(String[] args) {
        int[] a = {1, 2, 3, 4};
        arr(a);
        for(int num : a){
            System.out.print(num + " ");
        }
        }
}
/*
Given an array of integers, sort the array into a wave like array and return it,
In other words, arrange the elements into a sequence such that a1 >= a2 <= a3 >= a4 <= a5.....

Example:

Given [1, 2, 3, 4]

One possible answer : [2, 1, 4, 3]
Another possible answer : [4, 1, 3, 2]

NOTE : If there are multiple answers possible, return the one thats lexicographically smallest.
So, in example case, you will return [2, 1, 4, 3]

I know the O(nlogn) approach. Sort and swap in pair.
*/
