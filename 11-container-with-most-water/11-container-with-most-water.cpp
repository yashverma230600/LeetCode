class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int l=0,r=n-1,lmx=height[l],rmx=height[r];
        long long ans=0;
        while(l<r)
        {
            long long t=min(lmx,rmx)*(r-l);
            // cout<<t<<" ";
            ans=max(ans,t);
            if(height[l]<=height[r])
            {
                l++;
                if(height[l]>lmx) lmx=height[l];
            }
            else
            {
                r--;
                if(height[r]>rmx) rmx=height[r];
            }
        }
        return ans;
    }
};