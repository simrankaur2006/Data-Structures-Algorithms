#include<iostream>
#include<vector>
using namespace std;
class climbingStairs{
  public:
  int climbStairs(int n){
    vector<int> dp(n+1);
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++){
      dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
  }
};
int main(){
  int n;
  cout<<"Enter the number of stairs"<<endl;
  cin>>n;
  climbingStairs c;
  cout<<"The number of distinct ways to climb to the top is: "<<c.climbStairs(n)<<endl;
  return 0;
}