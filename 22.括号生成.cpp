/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        queue<string> qS;
        queue<pair<int ,int>> qN;
        qS.push("");
        qN.push(make_pair(n,n));
        while(qN.front().second){
            auto tmpP = qN.front();
            if(tmpP.first == tmpP.second){
                qS.push(qS.front()+'(');
                qS.pop();
                qN.push(make_pair(tmpP.first-1,tmpP.second));
                qN.pop();
            }
            else{
                if(tmpP.first)
                    qS.push(qS.front()+'('),qN.push(make_pair(tmpP.first-1,tmpP.second));
                qS.push(qS.front()+')');
                qS.pop();
                qN.push(make_pair(tmpP.first,tmpP.second-1));
                qN.pop();
            }
        }
        vector<string> re;
        while(!qS.empty())
            re.push_back(qS.front()),qS.pop();
        return re;
    }
};
// @lc code=end

