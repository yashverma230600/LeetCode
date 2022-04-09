class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        char curr;
        string res="";
        int z=0;
        for(int j=z; j<strs[z].size();j++)  //to traverse b/w characters
        { 
            curr= strs[0][j]; 
            bool check= false;
            for(int i=0;i<strs.size();i++)  //to  traverse in strings
            {
                char temp= strs[i][j];
                if(temp== curr)
                    check = true;
                else
                {
                    check= false;
                    break;
                }
            }
            if(check == true)
                res+= curr;
            else
                return res;
        
        }
        return res;
    }
};
