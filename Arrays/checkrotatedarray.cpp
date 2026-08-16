#include<iostream>
#include<vector>
using namespace std;
bool check(vector<int>&nums){
  int n=nums.size();
  int count=0;
  for(int i=0;i<nums.size();i++){
    if(nums[i]>nums[(i+1)%n]){
      count++;
    }
  }
  return count <=1;
}
int main(){
  vector<int>nums={5,10,15,20};
  cout<<check(nums)<<endl;
  return 0;
}