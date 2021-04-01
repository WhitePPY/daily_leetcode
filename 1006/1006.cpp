int clumsy(int N) {
        int arr[4] = {1,2,6,7};
        if(N<=4){
            return arr[N-1];
        }
        if (N % 4 == 0) {
            return N + 1;
        } else if (N % 4 <= 2) {
            return N + 2;
        } else {
            return N - 1;
        }
}