#include<iostream>
using namespace std;
struct Node{
  int data;
  Node* next;
};
Node* deleteatPosition(Node* head, int val){
  if(head==nullptr || head->next==nullptr){
    return nullptr;
  }
  if(head->data==val){
    Node* temp=head;
    head=head->next;
    delete temp;
    return head;
  }
  Node* curr=head;
  while(curr->next!=nullptr && curr->data!=val){
    curr=curr->next;
  }
  Node* toDelete= curr->next;
  curr->next=curr->next->next;
  delete toDelete;
  return head;
}