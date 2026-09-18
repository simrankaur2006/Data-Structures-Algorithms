#include<iostream>
#include<bits/stdc++.h>
//MADAM- same front nd back
using namespace std;
class Code{
  public:
  bool isValidPalindrome(string &s){
    int n=s.length();
    int i=0;
    int j=n-1;
    while(i<j){
      if(!isalnum(s[i])){
        continue;
        i++;
      }
      if(!isalnum(s[j])){
        continue;
        j++;
      }
      if(tolower(s[i])!=tolower(s[j])){
        return false;
      }
      i++;
      j--;
    }
    return true;
  }
};
int main(){
  
}