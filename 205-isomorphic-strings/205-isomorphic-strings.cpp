class Solution {
public:
bool isIsomorphic(string s, string t) {
map<char,char>mp1,mp2;
for(int i=0;i<s.size();i++){

if(mp1[s[i]]!=0){ // if char in s is already present then check int other if char in t is equal to char in s (a->g thn g->a bcz
//s=at
//t=ga a must not equal to g, t; only equal to one char
           
           if(mp2[t[i]]!=s[i]) return false;
   }else{// else part is if char in s not present
if(mp2[t[i]]!=0) return false;//then check if char in t at same pos is present or not because if t is alredy belongs to other char then it wil not satisfy our qs cond.
           else{//otherwise put values;
                 mp1[s[i]]=t[i];
                  mp2[t[i]]=s[i]; 
           }
   }        
 
 }
        
        return true;
}
};