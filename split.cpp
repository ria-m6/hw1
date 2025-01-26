/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>

/* Add a prototype for a helper function here if you need */
void traverse(Node*& head, Node* newNode);

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE

  //if input is NULL, end
  if(in == nullptr){ 
    return;
  }

  //create pointer to new node with in's value
  Node* newNode = new Node(in->value, nullptr);
  
  //checking if even or odd
  if(in->value % 2 == 0){
      traverse(evens, newNode);
  } else{
    traverse(odds, newNode);
  }

  //moving to the next item in list
  Node* temp = in;
  in = in->next;
  delete temp;

  //recrursively calling
  split(in, odds, evens); 
    
}

/* If you needed a helper function, write it here */
//added a helper function to traverse linked list
void traverse(Node*& head, Node* newNode){
  if(head == nullptr){ //list is empty
    head = newNode;

  } else{
    //moves through the list until end is found
    traverse(head->next, newNode); 

  }
}
