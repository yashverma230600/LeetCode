class Solution {
public:

    int divide(int dd, int d) {
        long long a=d,aa=dd,f=1;
        bool ok=0;
        if(a<0){a=-a;ok^=1;}
        if(aa<0){aa=-aa;ok^=1;}
        long long ans=0;
        vector<long long> v,vv;
        while(a<=aa){
            v.push_back(a);
            vv.push_back(f);
            a=a+a;f=f+f;
        }
        for(int i=v.size()-1;i>=0;i--){
            if(aa>=v[i]){
                aa=aa-v[i];
                ans=ans+vv[i];
            }
        }
        if(ok){ans=-ans;}
        if(ans>INT_MAX){ans=INT_MAX;}
        if(ans<INT_MIN){ans=INT_MIN;}
        return ans;
    }
};