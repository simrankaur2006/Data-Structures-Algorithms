#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
vector<int> unionArray(vector<int>nums1,vector<int>nums2){
  vector<int>arr;
  for(int x:nums1){
    arr.push_back(x);
  }
  for(int x:nums2){
    arr.push_back(x);
  }
  sort(arr.begin(), arr.end());
  arr.erase(unique(arr.begin(), arr.end()));
  return arr;
}