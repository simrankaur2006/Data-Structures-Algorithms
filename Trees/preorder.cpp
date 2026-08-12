#include<iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
       data = val; 
       left = nullptr;
       right = nullptr; 
      }
};
void preorder(Node* root){
  if(root==nullptr) return;
  cout<<root->data<<endl;
  preorder(root->left);
  preorder(root->right);
}
