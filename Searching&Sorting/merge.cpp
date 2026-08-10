#include<iostream>
#include<vector>
using namespace std;
void merge(int arr[], int low, int mid, int high) {

    vector<int> temp;

    int i = low;
    int j = mid + 1;

    while(i <= mid && j <= high) {

        if(arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        }
        else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while(i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    while(j <= high) {
        temp.push_back(arr[j]);
        j++;
    }

    for(int k = 0; k < temp.size(); k++) {
        arr[low + k] = temp[k];
    }
}

void mergeSort(int arr[], int low, int high) {

    if(low >= high)
        return;

    int mid = low + (high - low) / 2;

    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);

    merge(arr, low, mid, high);
}
int main(){
  int arr[7]={7,6,5,4,3,2,1};
  mergeSort(arr,0,6);
  for(int i=0;i<7;i++){
    cout<<arr[i]<<" ";
  }
}