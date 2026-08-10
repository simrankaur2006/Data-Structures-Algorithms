#include<iostream>
#include<vector>
using namespace std;
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
int main(){
vector<int> arr={4,5,2,25};
vector<int> result = nextGreaterNaive(arr);
for (int x : result) {
    cout << x << " ";
}
return 0;
}