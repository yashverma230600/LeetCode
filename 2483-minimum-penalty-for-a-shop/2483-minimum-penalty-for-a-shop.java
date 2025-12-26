class Solution {
    public int bestClosingTime(String customers) {
        int profit=0;
        int maxProfit=0;
        int bestHour=0;
        for(int i=0;i<customers.length();i++){
            profit+=(customers.charAt(i)=='Y')?1:-1;
            if(profit>maxProfit){
                maxProfit=profit;
                bestHour=i+1;
            }
        }
        return bestHour;
    }
}