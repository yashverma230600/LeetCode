const vector<vector<string>> roman {
    {"", "I", "II", "III", "VI", "V", "IV", "IIV", "IIIV", "XI"},
    {"", "X", "XX", "XXX", "LX", "L", "XL", "XXL", "XXXL", "CX"},
    {"", "C", "CC", "CCC", "DC", "D", "CD", "CCD", "CCCD", "MC"},
    {"", "M", "MM", "MMM"}
};

struct Solution {

    string intToRoman(int n) {
        
        string s = "";
        
        for (int i = 0; n; ++i, n /= 10) {
            s.append(roman[i][n%10]);
        }
        
        reverse(s.begin(), s.end());
        
        return s;
    }
};