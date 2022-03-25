/*
 * @lc app=leetcode.cn id=537 lang=cpp
 *
 * [537] 复数乘法
 */

// @lc code=start
class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int plusPos = num1.find('+',1);
        int plusPos2 = num2.find('+',1);
        complex<int> c1(stoi(num1.substr(0,plusPos)), stoi(num1.substr(plusPos+1)));
        complex<int> c2(stoi(num2.substr(0,plusPos2)), stoi(num2.substr(plusPos2+1)));
        return to_string((c1*c2).real()) + '+' + to_string((c1*c2).imag())+'i';
    }
};
// @lc code=end

