class Solution {
private:
    string solve(string &s, int n, string output){
        if(n == 1) return s;
        int cnt = 0, i = 0;
        char ch = s[0];
        while(i <= size(s)){
            while(i < size(s) and ch == s[i]){
                cnt++;
                i++;
            }
            output += to_string(cnt) + ch;
            cnt = 1;
            if(i < size(s)) ch = s[i];
            i++;
        }
        return solve(output, n - 1, "");
    }
public:
    string countAndSay(int n) {
        string s = "1";
        return solve(s, n, "");
    }
};