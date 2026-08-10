vector<int> nextGreaterNaive(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n);

    for (int i = 0; i < n; i++) {
        result[i] = -1;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[i]) {
                result[i] = arr[j];
                break;
            }
        }
    }
    return result;
}