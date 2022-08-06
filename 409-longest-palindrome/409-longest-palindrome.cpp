class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int>mp;
        for(int i=0;i<s.length();i++)
        {
            mp[s[i]]++;
        }
        map<char,int>::iterator it;
        int no_of_odds=0;
        int cnt=0;
        for(it=mp.begin();it!=mp.end();it++)
        {
            if(it->second%2==0)
                cnt=cnt+it->second;
            else
            {
                cnt=cnt+it->second-1;
                no_of_odds++;
            }
        }
        if(no_of_odds)
            return cnt+1;
        else 
            return cnt;
    }
};