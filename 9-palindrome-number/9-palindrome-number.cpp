class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        string sr = to_string(x);
        reverse(s.begin(), s.end());
        if (sr == s) 
            return true;
        return false;
    }
};