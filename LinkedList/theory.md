A Linked List is a linear data structure where elements (nodes) are NOT stored in continuous memory (unlike arrays). Each node stores:

Data — the actual value
Pointer (next) — address of the next node
Why use Linked List over Array?

Array                            	      Linked List
Fixed size (or costly resize)	          Grows/shrinks dynamically
Fast random access O(1)	                No random access, must traverse O(n)
Insert/Delete in middle is costly       Insert/Delete is O(1) if you have the pointer
O(n) shifting	
Contiguous memory	                      Scattered memory, extra space for pointers

Node Structure in linkedlist
#include<iostream>
using namespace std;
struct Node{
  int data;
  Node* next;

Node(int val){
  int data=val;
  next=nullptr;
}
};