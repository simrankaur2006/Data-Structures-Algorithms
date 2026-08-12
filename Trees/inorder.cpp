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
void inorder(Node* root){
  if(root==nullptr) return;
  inorder(root->left);
  cout<<root->data;
  inorder(root->right);
}