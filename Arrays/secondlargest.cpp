#include<iostream>
#include<vector>
using namespace std;
int secondLargest(vector<int> &nums){
  int n=nums.size();
  int largest=nums[0];
  int secLargest=-1;
  for(int i=0;i<n;i++){
    if(nums[i]>largest){
      secLargest=largest;
      largest=nums[i];
    }else if(nums[i]<largest && nums[i]>secLargest){
      secLargest=nums[i];
    }
  }
  return secLargest;
}
int main(){
  vector<int>nums={5,10,15,20,25};
  cout<<secondLargest(nums)<<endl;
  return 0;
}