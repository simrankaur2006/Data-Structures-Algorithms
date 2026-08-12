#include<iostream>
using namespace std;
struct Node{
  int data;
  Node* next;
};
Node* insertAtPosition(Node* head, int newData, int position){
  Node* newNode= new Node();
  newNode->data=newData;
  if(position==1){
    newNode->next=head;
    return newNode;
  }
  Node* temp=head;
  for(int i=1;i<position-1 && temp!=NULL;i++){
    temp=temp->next;
  }
  if(temp==NULL){
    cout<<"Position out of bounds"<<endl;
    return head;
  }
  newNode->next=temp->next;
  temp->next=newNode;
  return head;
}