#include<iostream>
using namespace std;
void printN(int n){
  if(n==0){
    return;
  }
  cout<<n<<endl;
  printN(n-1);
}
int main(){
  int n;
  cout<<"Enter a number"<<endl;
  cin>>n;
  printN(n);
}