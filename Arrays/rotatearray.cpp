#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
void rotate(vector<int>nums, int k){
  int n=nums.size();
  if(n==0) return ;
  k=k%n;
  reverse(nums.begin(), nums.end());
  reverse(nums.begin(), nums.begin()+k);
  reverse(nums.begin()+k, nums.end());
}
int main(){
  vector<int>nums={5,10,15,20,25};
  
}