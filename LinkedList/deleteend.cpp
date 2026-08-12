#include<iostream>
using namespace std;
struct Node{
  int data;
  Node* next;
};
Node* deleteTail(Node* head){
  if(head==NULL){
    return NULL;
  }
    Node* temp=head;
    while(temp->next->next!=NULL){
    temp=temp->next;
  }
  delete temp->next;
  temp->next=NULL;
  return head;
}