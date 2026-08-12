#include<iostream>
using namespace std;
struct Node{
  int data;
  Node* next;
};
Node* deleteHead(Node* head){
  if(head==NULL){
    return NULL;
  }
  Node* temp=head;
  head=head->next;
  delete temp;
  return head;
}