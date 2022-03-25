/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution {
public:
    bool backTracking(vector<vector<char>>& board, string word, int x, int y, int index){
        if(word[index] == board[x][y]){
            if(index == word.size()-1)
                return true;
            else{
                char tmp = board[x][y];
                board[x][y] = '.';
                if((x-1>=0 && backTracking(board,word,x-1,y,index+1))||(y-1>=0 && backTracking(board,word,x,y-1,index+1))||(x+1 < board.size()&& backTracking(board,word,x+1,y,index+1))||(y+1 < board[0].size()&& backTracking(board,word,x,y+1,index+1)))
                    return true;
                board[x][y] = tmp;
                return false;
            }
        }else{
            return false;
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size();++i){
            for(int j =0;j<board[0].size();++j){
                if(backTracking(board,word,i,j,0))
                    return true;
            }
        }
        return false;
    }
};
// @lc code=end

