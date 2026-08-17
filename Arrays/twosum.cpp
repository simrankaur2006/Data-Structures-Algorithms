#include<iostream>
#include<vector>
using namespace std;
vector<int> twoSum(vector<int> &nums, int target){
  int n=nums.size();
  for(int i=0;i<n;i++){
    for(int j=0;i<n;j++){
      if(nums[i]+nums[j]==target){
        return {i,j};
      }
    }
    return {};
  }
}