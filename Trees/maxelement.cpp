#include<iostream>
#include<climits>
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
int maxElement(Node* root){
  if(root==nullptr) return INT_MIN;
  int leftMax= maxElement(root->left);
  int rightMax= maxElement(root->right);
  return max(root->data, leftMax, rightMax);
}