class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            if(!isValidRow(board,i))
                return false;
        }
        for(int j=0;j<9;j++){
            if(!isValidCol(board,j))
                return false;
        }
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(!isValidGrid(board,i,j))
                    return false;
            }
        }
        return true;
    }
private:
    bool isValidRow(vector<vector<char>> &board, int i){
        unordered_set<char> hashSet;

        for(int j=0;j<9;j++){
            if(board[i][j]=='.')
                continue;
            if(hashSet.find(board[i][j])!=hashSet.end())
                return false;
            hashSet.insert(board[i][j]);
        }
        return true;
    }
private:
    bool isValidCol(vector<vector<char>> &board, int j){
        unordered_set<char> hashSet;

        for(int i=0;i<9;i++){
            if(board[i][j]=='.')
                continue;
            if(hashSet.find(board[i][j])!=hashSet.end())
                return false;
            hashSet.insert(board[i][j]);
        }
        return true;
    }
private:
    bool isValidGrid(vector<vector<char>> &board, int i, int j){
        int startRow = (i/3)*3;
        int startCol = (j/3)*3;

        unordered_set<char> hashSet;

        for(int row = startRow; row < startRow+3; row++){
            for(int col = startCol; col < startCol+3; col++){
                if(board[row][col]=='.')
                    continue;
                if(hashSet.find(board[row][col])!=hashSet.end())
                    return false;
                hashSet.insert(board[row][col]);
            }
        }
        return true;
    }
};
