- task

a matrix,in each row its element keeps increasing and between every pair of adjacent rows, the first element from the lower row is always greater than the last one from the upper row,if target number can be searched from the matrix, return true.

- official difficulty rating

medium

- solution

we can manually downsize the dimension of this matrix. imagine this matrix just have one row, and this problem can be solved quickly with dichotomy.