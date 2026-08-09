#include<iostream>
#include<vector>
using namespace std;
class fibonacci{
  public:
  int solve(int n, vector<int> & dp){
    if(n<=1){
      return n;
    }
    if(dp[n]!=-1){
      return dp[n];
    }
    dp[n]=solve(n-1, dp)+ solve(n-2,dp);
    return dp[n];
  }
  int fib(int n){
    vector<int>dp(n+1,-1);
    return solve(n, dp);
  }
};
int main(){
  int n;
  cout<<"Enter the no. of terms"<<endl;
  cin>>n;
  fibonacci f;
  cout<<"The "<<n<<"th term of fibonacci series is: "<<f.fib(n)<<endl;
  return 0;
}