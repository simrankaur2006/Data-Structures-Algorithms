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
void postorder(Node* root){
  if(root==nullptr) return;
  postorder(root->left);
  postorder(root->right);
  cout<<root->data<<endl;
}