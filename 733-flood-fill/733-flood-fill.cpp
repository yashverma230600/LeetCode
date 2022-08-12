class Solution {
public:
    void floodFill(int i, int j, vector<vector<int>>& image, int oldColor, int newColor){
        // base case
        if(i>=image.size() or i<0 or j>=image[0].size() or j<0 or image[i][j]!=oldColor){
            return;
        }
        
        //rec cases
        image[i][j] = newColor;
        
        // going down
        floodFill(i+1,j,image,oldColor,newColor);
        
        // going up
        floodFill(i-1,j,image,oldColor,newColor);
        
        // going right
        floodFill(i,j+1,image,oldColor,newColor);
        
        // going left
        floodFill(i,j-1,image,oldColor,newColor);
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];
        if(color==oldColor)return image;
        floodFill(sr,sc,image,oldColor,color);
        return image;
    }
};