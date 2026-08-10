#include<iostream>
using namespace std;
long long pow(int x,int n){
  if(n==0){
    return 1;
  }
  long long half=pow(x,n/2);
  if(n%2==0){
    return half*half;
  }
  else{
    return half*half*x;
  }
}
/** brute force approach---- int pow(int x,int n){
  if(n==0){
    return 1;
  }
  return x* pow(x,n-1);
}*/
int main(){
  int x,n;
  cin>>x>>n;
  cout<<pow(x,n);
}