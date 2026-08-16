#include<iostream>
#include<vector>
using namespace std;
int largestElement(vector<int> &nums){
  int n=nums.size();
  int largest=nums[0];
  for(int i=0;i<n;i++){
    if(nums[i]>largest){
      largest=nums[i];
    }
  }
  return largest;
}

int main(){
  vector<int>nums={5,10,15,20,25};
  cout<<largestElement(nums)<<endl;
  return 0;
}