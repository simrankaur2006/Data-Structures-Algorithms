#include<iostream>
using namespace std;
int linearSearch(int arr[], int n, int target){
  for(int i=0;i<n;i++){
    if(arr[i]==target){
      return i;
    }
  }
return -1;
}
int main(){
  int arr[5]={1,2,3,4,5};
  cout<<linearSearch(arr,5, 2);
  return 0;
}