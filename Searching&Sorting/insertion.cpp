#include<iostream>
using namespace std;
void insertionSort(int arr[], int n) {

    for(int i = 1; i < n; i++) {

        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key) {

            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}
int main(){
  int arr[7]={7,6,5,4,3,2,1};
  insertionSort(arr,7);
  for(int i=0;i<7;i++){
    cout<<arr[i]<<" ";
  }
}