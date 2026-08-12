#include<iostream>
using namespace std;
struct Node{
  int data;
  Node* next;
};
Node* insertAtEnd(Node* head, int newData){
  Node* newNode= new Node();
  if(head==NULL){
    return newNode;
  }
  Node* temp=head;
  while(temp->next!=NULL){
    temp=temp->next;
  }
  temp->next=newNode;
  return head;
}