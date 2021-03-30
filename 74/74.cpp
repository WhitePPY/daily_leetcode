bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    int size = m * n;
    if(size == 0)
        return false;
    int low = 0;
    int up = size - 1;
    while(low<=up){
        int key = low + ((up-low)>>1);
        if(matrix[key/n][key%n] > target){
            up = key-1;
        }
        else if(matrix[key/n][key%n] < target){
            low = key+1;
        }
        else{
            return true;
        }
    }
    return false;
}