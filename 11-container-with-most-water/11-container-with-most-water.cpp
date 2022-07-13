class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int water=0,L=0,R=height.size()-1;
        
        while(L<R){
            int area;
            if(height[L]<height[R]){
                area = height[L]*(R-L);
                L++;
                
            }
            else{
                area = height[R]*(R-L);
                R--;
            }
            if(area>water){
                water=area;
            }
        }
            
            return water;
            
        
            

    }
};