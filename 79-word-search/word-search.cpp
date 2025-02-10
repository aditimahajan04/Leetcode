class Solution {
public:
    bool dfs(vector<vector<char>> &board, string word,int index,int row, int col,vector<vector<bool>> &visited){
        int m=board.size();
        int n=board[0].size();
        
        // base case if the index reaches to size of word then the word is found

        if (index==word.size())
        return true;

        if (row<0 || col<0 || row==m || col==n || board[row][col]!=word[index] || visited[row][col]==1)
        return false;

        // avoid the repeated matching if once a cell is visited it can't be used again
        visited[row][col]=true;

        //top
        bool top=dfs(board,word,index+1,row-1,col,visited);

        //down
        bool down=dfs(board,word,index+1,row+1,col,visited);

        //right
        bool right=dfs(board,word,index+1,row,col+1,visited);
        
        //left
        bool left=dfs(board,word,index+1,row,col-1,visited);
        
        //during backtracking
        visited[row][col]=false;
        // If we do not reset visited[row][col] = false;, it will remain marked as true, preventing valid future searches from using that cell.


        return top||down||right||left;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        int index=0;

        vector<vector<bool>>visited(m,vector<bool>(n,0));

        // match the first character
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (board[i][j]==word[0]){
                    if (dfs(board,word,index,i,j,visited))
                    return true;
                }
            }
        }
        return false;
    }
};