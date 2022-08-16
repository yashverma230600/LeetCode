class Solution {
public:
    bool helper(vector<vector<char>>& board, int row, int col){
        for(int i=0;i<9;i++){
            if(i!=col && board[row][i]==board[row][col])return 0;
            if(i!=row && board[i][col]==board[row][col])return 0;
            if((3*(row/3)+i/3)!=row && (3*(col/3)+i%3)!=col && board[3*(row/3)+i/3][3*(col/3)+i%3]==board[row][col])return 0;
        }
        return 1;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    if(helper(board,i,j)){
                        continue;
                    }else{
                        return 0;
                    }
                }
            }
        }
        return 1;
    }
};