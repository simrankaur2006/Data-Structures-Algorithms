#include<iostream>
using namespace std;
struct Node{
  int data;
  Node* left;
  Node* right;

  Node(int val){
    data=val;
    left=nullptr;
    right=nullptr;
  }
};
void printAtKdistance(Node* root,int k){
  if(root==nullptr) return ;
  if(k==0){
    cout<<root->data<<endl;
    return;
  }
  printAtKdistance(root->left,k-1);
  printAtKdistance(root->right, k-1);
}