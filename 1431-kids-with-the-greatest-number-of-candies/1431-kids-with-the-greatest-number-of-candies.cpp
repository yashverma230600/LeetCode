class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> res;
        int s=candies.size();
        int maxm=*max_element(candies.begin(),candies.end());
        
        for(int i=0;i<s;i++){
            
            if(candies[i]+extraCandies>=maxm){
                res.push_back(true);
            }
            else{
                res.push_back(false);
            }
            
            
        }
        return res;
        
    }
};