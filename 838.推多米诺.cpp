/*
 * @lc app=leetcode.cn id=838 lang=cpp
 *
 * [838] 推多米诺
 */

// @lc code=start
class Solution
{
public:
    string pushDominoes(string dominoes)
    {
        int length = dominoes.length();
        for (int i = 0; i < length; ++i)
        {
            if (dominoes[i] == '.')
            {
                int j;
                for (j = i; j < length && dominoes[j] == '.'; ++j)
                    ;
                if (j != length && dominoes[j] == 'L' && (i == 0 || dominoes[i - 1] == 'L'))
                    for (int k = i; k < j; ++k)
                        dominoes[k] = 'L';
                else if (j != length && dominoes[j] == 'L' && i != 0 && dominoes[i - 1] == 'R')
                {
                    if (j - i >= 2)
                    {
                        for (int k = i; k < i + (j - i) / 2; ++k)
                            dominoes[k] = 'R';
                        for (int k = j - (j - i) / 2; k < j; ++k)
                            dominoes[k] = 'L';
                    }
                }
                else if (i != 0 && dominoes[i - 1] == 'R' && (j == length || dominoes[j] == 'R'))
                    for (int k = i; k < j; ++k)
                        dominoes[k] = 'R';
                if ((j == length && i == 0) || (j == length && dominoes[i - 1] == 'L') || (i != length && dominoes[j] == 'R' && i == 0) || (i != 0 && j != length && dominoes[i - 1] == 'L' && dominoes[j] == 'R'))
                    ;
                i = j;
            }
        }
        return dominoes;
    }
};
// @lc code=end
