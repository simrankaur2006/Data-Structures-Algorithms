#include<iostream>
using namespace std;
int selectionSort(int arr[], int n){
  for(int i=0;i<n-1;i++){
    int minindex=i;
  
  for(int j=i+1;j<n-1;j++){
    if(arr[j]<arr[minindex]){
      minindex=j;
    }
  }
  swap(arr[i],arr[minindex]);
}
}
int main(){
  int arr[]={2,9,6,4,7,3};
  selectionSort(arr, 7);
  for(int i=0;i<7;i++){
    cout<<arr[i]<<" ";
  }
}