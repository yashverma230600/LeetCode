class Solution {
public:

void solve(string digits, int index, string output, vector<string>&ans, string mapping[] ){
    if(index>=digits.size()){
        ans.push_back(output);
        return;
    }
    int number=digits[index]-'0';
    string value=mapping[number];
    for(int i=0; i<value.size(); i++){
        output.push_back(value[i]);
        solve(digits,index+1,output,ans,mapping);
        output.pop_back(); // backtracking step
    }
}

vector<string> letterCombinations(string digits) {
    vector<string>ans;
    if(digits.size()==0){
        return ans;
    }
    string mapping[10] ={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    string output;
    solve(digits,0,output,ans,mapping);
    return ans;
}
};