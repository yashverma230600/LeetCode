class Solution {
public:

vector<int> findAnagrams(string s2, string s1) {
    vector<int>v1(26,0);
    vector<int>v2(26,0);
    vector<int>ans;
    int n1=s1.size();
    int n2=s2.size();
    if(n2<n1)return ans ;  
    int l=0,r=0;
    while(r<n1){
        v1[s1[r]-'a']++;      
        v2[s2[r]-'a']++;
        r++;
    }r--;
    while(r<n2){
        if(v1==v2)ans.push_back(l);
        r++;
        if(r!=s2.size())//out of bound
        v2[s2[r]-'a']++;   
        v2[s2[l]-'a']--;
        l++;
    }
    return ans;
}
};