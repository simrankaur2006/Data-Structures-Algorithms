#include<bits/stdc++.h>
using namespace std;
class twosum{
  public:
  vector<int> twosum(vector<int> &numbers, int target){
    int n=numbers.size();
    int i=0, j=n-1;
    while(i<j){
      if(numbers[i]+numbers[j]==target){
        return{i+1,j+1};
      }
      else if(numbers[i]+numbers[j]>target){
        j--;
      }else if(numbers[i]+numbers[j]<target){
        i++;
      }
    }
    return {};
  }
};
int main(){
  vector<int> numbers;
  int target;
}