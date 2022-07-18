class Solution {
public:
    double average(vector<int>& salary) {
        
        
        sort(salary.begin(), salary.end());
        int max=salary[0];
        
        int s=salary.size();
        int min=salary[s-1];
        double sum=0;
        int c=0;
        
        for(int i=1;i<s-1;i++){
            if(salary[i]!=max&&salary[i]!=min){
            sum=sum+salary[i];
                c++;
            }
        }
        
        return sum/c;
        
        
        
    }
};