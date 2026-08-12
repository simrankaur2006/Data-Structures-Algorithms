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
int maxHeight(Node* root){
  if(root==nullptr) return 0;
  int leftHeight= maxHeight(root->left);
  int rightHeight= maxHeight(root->right);
  return 1 + max(leftHeight, rightHeight);
}